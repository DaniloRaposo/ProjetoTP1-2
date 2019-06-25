#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>

#include "dominios.h"
#include "interfaces.h"

class ControladoraSistema{
    private:
        const static int CADASTRAR_USUARIO = 1;
        const static int AUTENTICAR_USUARIO = 2;
        const static int OBTER_DADOS_EVENTOS = 3;
        const static int RETORNAR = 4;

        IAAuteuticacao *controladora_autenticacao;
        IAUsuario *controladora_usuario;
        IAEventos *controladora_eventos;

    public:
        void executar();

        void setCAAutenticacao(IAAuteuticacao *controladora_autenticacao){
          this->controladora_autenticacao = controladora_autenticacao;
        }

        void setCAUsuario(IAUsuario *controladora_usuario){
          this->controladora_usuario = controladora_usuario;
        }

        void setCAEventos(IAEventos *controladora_eventos){
          this->controladora_eventos = controladora_eventos;
        }
};

class CntrAAutenticacao:public IAAuteuticacao{

    private:
        ISAutenticacao *controladora_servico;
        IAUsuario *controladora_usuario;

    public:
        void autenticar_usuario();

        void setCSAutenticacao(ISAutenticacao *controladora_servico){
            this->controladora_servico = controladora_servico;
        }

        void setCAUsuario(IAUsuario *controladora_usuario){
            this->controladora_usuario = controladora_usuario;
        }
};

class CntrSAutenricacao:public ISAutenticacao{

    private:

        ContainerUsuario *cUsuario;

    public:
        bool autenticar (std::string cpfInput, std::string senhaInput) throw(runtime_error){
            return this->cUsuario.pesquisar(cpfInput, senhaInput);
        };

        void setContUsuario(ContainerUsuario *input)
        {
            this->cUsuario = input;
        };
};

class CntrAUsuario:public IAUsuario{

    private:
        const static int DESCADASTRAR_USUARIO = 1;
        const static int COMPRAR_INGRESSO = 2;
        const static int CADASTRAR_EVENTO = 3;
        const static int DESCADASTRAR_EVENTO = 4;
        const static int ALTERAR_EVENTO = 5;
        const static int RETORNAR = 6;

        ISUsuario *controladora_servico;
        IAEventos *controladora_eventos;
        IAVendas *controladora_vendas;

    public:

        void executar(std::string cpf, std::string senha);

        void cadastrar_usuario();

        void setCSUsuario(ISUsuario *controladora_servico){
            this->controladora_servico = controladora_servico;
        }

        void setCAEventos(IAEventos *controladora_eventos){
            this->controladora_eventos = controladora_eventos;
        }

        void setCAVendas(IAVendas *controladora_vendas){
            this->controladora_vendas = controladora_vendas;
        }
};

class CntrSUsuario:public ISUsuario{

    private:

        ContainerUsuario *cUsuario;
        ContainerCartao *cCartao;
        ContainerEvento *cEvento;

    public:

        //funcoes de servico
        bool cadastrar_usuario(std::string cpfstr, std::string senhastr,
                              std::string numerostr, std::string codigostr, std::string datastr) {
            
            Usuario* usuarioAux;
            Cartao_de_Credito* cartaoAux;

            try
            usuarioAux = this->cUsuario.incluir(cpfstr, senhastr);
            cartaoAux = this->cCartao.incluir(numerostr, codigostr, datastr);

            this->cUsuario.linkCartao(cartaoAux);
            this->cCartao.linkUsuario(usuarioAux);

            return 
        };

        void descadastrar_usuario(std::string cpf, std::string senha){
            
            Usuario* usuarioAux;
            Cartao_de_Credito* cartaoAux;

            usuarioAux = this->cUsuario.retornar(cpf,senha);
            cartaoAux = this->cUsuario.removerLinkCartao(usuarioAux);

            this->cCartao.remover(cartaoAux);
            this->cCartao.removerLinkUsuario(usuarioAux);

            this->cUsuario.remover(usuarioAux);
        };

        void descadastrar_evento()

        //funcoes set containers
        void setContUsuario(ContainerUsuario *input){
            this->cUsuario = input;
        };

        void setContCartao(ContainerCartao *input){
            this->cCartao = input;
        };

        void setContEvento(ContainerEvento *input){
            this->cEvento = input;
        };

};

class CntrAEventos:public IAEventos{

    private:
      ISEventos *controladora_servico;

    public:
      void obter_dados_eventos();

      void cadastrar_evento(std::string cpf, std::string);

      void setCSEventos(ISEventos * controladora_servico){
          this->controladora_servico = controladora_servico;
      }
};

class CntrAVendas:public IAVendas{

    private:
      ISVendas *controladora_servico;

    public:
      void comprar_ingresso();

      void setCSVendas(ISVendas *controladora_servico){
        this->controladora_servico = controladora_servico;
      }
};

class CntrSVendas:public ISVendas{
    
    ContainerApresentacao *cApresentacao;
    ContainerIngresso *cIngresso;

    public:
      bool comprar_ingresso(std::string codigo, int quantidade_ingressos, std::vector<Ingresso> &Ingressos){
          Apresentacao *apresentacaoAux;
          
          apresentacaoAux = this->cApresentacao.pesquisar(codigo);
          if(apresentacaoAux == NULL) return false;
          
          if ( quantidade_ingressos <= apresentacaoAux.GetDisponibilidade().Get() ){
              
              //atualizar a disponibilidade da apresentacao
              Disponibilidade nova_disponibilidade;
              nova_disponibilidade.Set( apresentacaoAux.GetDisponibilidade().Get() - quantidade_ingressos );
              apresentacaoAux.Set( nova_disponibilidade );
              
              //listar os codigos de ingressos vendidos (modificar vetor input)
              //codigo sao 5 digitos numericos
              Ingresso *novo_ingresso;

              for(int n = 0; n< quantidade_ingressos; n++){

                  novo_ingresso = this->cIngresso.incluir();
                  Ingressos.push_back(novo_ingresso);
                  
              }
          }
      };

      void setContApresentacao(ContainerApresentacao *input){
            this->cApresentacao = input;
      };

      void setContIngresso(ContainerIngresso *input){
            this->cIngresso = input;
      };


};

#endif
