#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

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
      const static std::string TRIGGER_ERRO_CPF;
      const static std::string TRIGGER_ERRO_SENHA;

    public:
      bool descadastrar_usuario(std::string cpf, std::string senha) throw(runtime_error);
      bool comprar_ingresso() throw(runtime_error);
      bool descadastrar_evento() throw(runtime_error);
      bool alterar_evento() throw(runtime_error);
};

class StubSEventos:public ISEventos{
    private:
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
};
#endif
