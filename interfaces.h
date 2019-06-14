#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include <stdexcept>

#include "dominios.h"
#include "entidades.h"

class ISEventos{ // interface que permite a comunicação com o módulo de eventos da camada de serviço

  public: // Tarefas feitas pelo módulo de eventos da camada de serviço:

    virtual bool cadastrar_evento(std::string cpf, std::string senha, std::string codigo_evento, std::string nome_evento, std::string cidade, std::string estado, std::string classe, std::string faixa_etaria, std::vector<std::string> codigo_apresentacao, std::vector<std::string> data, std::vector<std::string> horario, std::vector<float> preco, std::vector<int> sala) throw(runtime_error) = 0;
};

class IAEventos{ // interface que permite a comunicação com o módulo de eventos da camada de apresentação

public:
  //virtual void executar() = 0; // método que executa o módulo que herda dessa interface

  virtual void cadastrar_evento(std::string cpf, std::string senha) = 0;

  virtual void setCSEventos(ISEventos *) = 0; // método que liga o módulo de apresentação com um módulo de serviço
};

class ISUsuario{ // interface que permite a comunicação com o módulo de usuário da camada de serviço

  public: // Tarefas feitas pelo módulo de usuário da camada de serviço:
    virtual bool descadastrar_usuario(std::string cpf, std::string senha) throw(runtime_error) = 0;
    virtual bool comprar_ingresso() throw(runtime_error) = 0;
    virtual bool descadastrar_evento() throw(runtime_error) = 0;
    virtual bool alterar_evento() throw(runtime_error) = 0;

    void setContainer(Container <Usuario> *cInput);
    void setContainer(Container <Cartao_de_Credito> *cInput);
    void setContainer(Container <Evento> *cInput);
};

class IAUsuario{ // interface que permite a comunicação com o módulo de usuário da camada de apresentação

  public:
    virtual void executar(std::string cpf, std::string senha) = 0; // método que executa o módulo que herda dessa interface

    virtual void setCSUsuario(ISUsuario *) = 0; // método que liga o módulo de apresentação com um módulo de serviço

    virtual void setCAEventos(IAEventos *) = 0; // método que lida o módulo de usuário com o módulo de eventos
};

class ISAutenticacao{ // interface que permite a comunicação com o módulo de autenticação da camada de serviço
    public: // Tarefas feitas pelo módulo de autenticação da camada de serviço:
      virtual bool autenticar_usuario(std::string cpf, std::string senha) throw(runtime_error) = 0; // método de autenticação de usuário
};

class IAAuteuticacao { // interface que permite a comunicação com o módulo de autenticação da camada de apresentação

    public:
        virtual void autenticar_usuario() = 0; // método que executa o módulo que herda dessa interface

        virtual void setCSAutenticacao(ISAutenticacao *) = 0; // método que liga o módulo de apresentação com um módulo de serviço

        virtual void setCAUsuario(IAUsuario *) = 0; // método que liga o módulo de autenticação com o de usuário
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
