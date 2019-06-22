#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "entidades.h"
#include "dominios.h"
#include "interfaces.h"


class StubSAutenticacao:public ISAutenticacao{
    private:
        const static std::string TRIGGER_FALHA_CPF;
        const static std::string TRIGGER_ERRO_CPF;
        const static std::string TRIGGER_ERRO_SENHA;
        const static std::string TRIGGER_FALHA_SENHA;

    public:
        bool autenticar(std::string cpf, std::string senha) throw(runtime_error);
};

class StubSUsuario:public ISUsuario{
    private:
      const static std::string TRIGGER_FALHA_CPF;
      const static std::string TRIGGER_ERRO_CPF_DESCADASTRAR;
      const static std::string TRIGGER_ERRO_CPF_CADASTRAR;
      const static std::string TRIGGER_FALHA_SENHA;
      const static std::string TRIGGER_ERRO_SENHA_DESCADASTRAR;
      const static std::string TRIGGER_ERRO_SENHA_CADASTRAR;
      const static std::string TRIGGER_FALHA_NUMERO_CARTAO;
      const static std::string TRIGGER_ERRO_NUMERO_CARTAO;
      const static std::string TRIGGER_FALHA_CODIGO_SEGURANCA;
      const static std::string TRIGGER_ERRO_CODIGO_SEGURANCA;
      const static std::string TRIGGER_FALHA_DATA;
      const static std::string TRIGGER_ERRO_DATA;


    public:
      bool descadastrar_usuario(std::string cpf, std::string senha) throw(runtime_error);
      bool cadastrar_usuario(std::string cpf, std::string senha, std::string numero_cartao, std::string codigo_seguranca, std::string data_validade) throw(runtime_error);
};

class StubSEventos:public ISEventos{
    private:
      const static std::string TRIGGER_CIDADE_SEM_EVENTOS;
      const static std::string TRIGGER_FALHA_DATA;
      const static std::string TRIGGER_ERRO_DATA;
      const static std::string TRIGGER_FALHA_CODIGO_EVENTO;
      const static std::string TRIGGER_ERRO_CODIGO_EVENTO;
      const static std::string TRIGGER_FALHA_NOME;
      const static std::string TRIGGER_ERRO_NOME;
      const static std::string TRIGGER_FALHA_CIDADE;
      const static std::string TRIGGER_ERRO_CIDADE;
      const static std::string TRIGGER_FALHA_ESTADO;
      const static std::string TRIGGER_ERRO_ESTADO;
      const static std::string TRIGGER_FALHA_CLASSE;
      const static std::string TRIGGER_ERRO_CLASSE;
      const static std::string TRIGGER_FALHA_FAIXA;
      const static std::string TRIGGER_ERRO_FAIXA;

    public:
      bool cadastrar_evento(std::string cpf, std::string senha, std::string codigo_evento, std::string nome_evento, std::string cidade, std::string estado, std::string classe, std::string faixa_etaria, std::vector<std::string> codigo_apresentacao, std::vector<std::string> data, std::vector<std::string> horario, std::vector<float> preco, std::vector<int> sala) throw(runtime_error);
      bool obter_dados_eventos(std::string datainit, std::string dataend, std::string cidade, std::string estado, std::vector<Evento> *eventos, std::vector<Apresentacao> *apresentacoes) throw(runtime_error);
};

class StubSVendas:public ISVendas{
    private:
      const static int LIMITE_INGRESSOS;
      const static std::string TRIGGER_FALHA_CODIGO;
      const static std::string TRIGGER_ERRO_CODIGO;

    public:
        bool comprar_ingresso(std::string codigo, int  quantidade_ingressos, std::vector<Ingresso> *Ingressos) throw(runtime_error);
};
#endif
