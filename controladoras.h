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

    public:
        void executar(std::string cpf, std::string senha);

        void setCSUsuario(ISUsuario *controladora_servico){
            this->controladora_servico = controladora_servico;
        }

        void setCAEventos(IAEventos *controladora_eventos){
            this->controladora_eventos = controladora_eventos;
        }
};

class CntrAEventos:public IAEventos{

    private:
      ISEventos *controladora_servico;

    public:
      //void executar();

      void cadastrar_evento(std::string cpf, std::string);

      void setCSEventos(ISEventos * controladora_servico){
          this->controladora_servico = controladora_servico;
      }
};

#endif
