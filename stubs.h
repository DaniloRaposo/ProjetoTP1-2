#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

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
    public:
      void descadastrar_usuario() throw(runtime_error);
      void comprar_ingresso(std::string codigo_apresentacao, int n_ingrecos) throw(runtime_error);
      void cadastrar_evento() throw(runtime_error);
      void descadastrar_evento() throw(runtime_error);
      void alterar_evento() throw(runtime_error);
};

#endif
