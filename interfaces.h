#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include <stdexcept>

#include "dominios.h"
#include "entidades.h"

class ISUsuario{ // interface que permite a comunicação com o módulo de usuário da camada de serviço

  public: // Tarefas feitas pelo módulo de usuário da camada de serviço:
  virtual void descadastrar_usuario() throw(runtime_error)= 0;
  virtual void comprar_ingresso(std::string codigo_apresentacao, int n_ingrecos) throw(runtime_error) = 0;
  virtual void cadastrar_evento() throw(runtime_error) = 0;
  virtual void descadastrar_evento() throw(runtime_error) = 0;
  virtual void alterar_evento() throw(runtime_error) = 0;
};

class IAUsuario{ // interface que permite a comunicação com o módulo de usuário da camada de apresentação

public:
  virtual void executar(std::string cpf, std::string senha) = 0; // método que executa o módulo que herda dessa interface

  virtual void setCSUsuario(ISUsuario *) = 0; // método que liga o módulo de apresentação com um módulo de serviço
};

class ISAutenticacao{ // interface que permite a comunicação com o módulo de autenticação da camada de serviço
    public: // Tarefas feitas pelo módulo de autenticação da camada de serviço:
        virtual bool autenticar(std::string cpf, std::string senha) throw(runtime_error) = 0; // método de autenticação de usuário
};

class IAAuteuticacao { // interface que permite a comunicação com o módulo de autenticação da camada de apresentação

    public:
        virtual void executar() = 0; // método que executa o módulo que herda dessa interface

        virtual void setCSAutenticacao(ISAutenticacao *) = 0; // método que liga o módulo de apresentação com um módulo de serviço

        virtual void setCAUsuario(IAUsuario *) = 0; // método que liga o módulo de autenticação com o de usuário
};

class ISEventos{ // interface que permite a comunicação com o módulo de eventos da camada de serviço

    public: // Tarefas feitas pelo módulo de eventos da camada de serviço:
};

class IAEventos{ // interface que permite a comunicação com o módulo de eventos da camada de apresentação

    public:
        virtual void executar() = 0; // método que executa o módulo que herda dessa interface

        virtual void setCSEventos(ISEventos *) = 0; // método que liga o módulo de apresentação com um módulo de serviço
};

class ISVendas{ // interface que permite a comunicação com o módulo de vendas da camada de serviço

    public: // Tarefas feitas pelo módulo de vendas da camada de serviço:
};

class IAVendas{ // interface que permite a comunicação com o módulo de vendas da camada de apresentação

    public:
        virtual void executar() = 0; // método que executa o módulo que herda dessa interface

        virtual void setCSVendas(ISVendas *) = 0; // método que liga o módulo de apresentação com um módulo de serviço
};

#endif
