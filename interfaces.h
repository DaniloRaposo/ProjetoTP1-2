#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include <stdexcept>

#include "dominios.h"
#include "entidades.h"

class ISVendas{ // interface que permite a comunicação com o módulo de vendas da camada de serviço

    public: // Tarefas feitas pelo módulo de vendas da camada de serviço:
        virtual bool comprar_ingresso(std::string codigo, int  quantidade_ingressos, std::vector<Ingresso> *Ingressos) throw(runtime_error) = 0;
};

class IAVendas{ // interface que permite a comunicação com o módulo de vendas da camada de apresentação

    public:
        virtual void comprar_ingresso() = 0; // método que executa o módulo que herda dessa interface

        virtual void setCSVendas(ISVendas *) = 0; // método que liga o módulo de apresentação com um módulo de serviço
};

class ISEventos{ // interface que permite a comunicação com o módulo de eventos da camada de serviço

  public: // Tarefas feitas pelo módulo de eventos da camada de serviço:

    virtual bool cadastrar_evento(std::string cpf, std::string senha, std::string codigo_evento, std::string nome_evento, std::string cidade, std::string estado, std::string classe, std::string faixa_etaria, std::vector<std::string> codigo_apresentacao, std::vector<std::string> data, std::vector<std::string> horario, std::vector<float> preco, std::vector<int> sala) throw(runtime_error) = 0;

    virtual bool obter_dados_eventos(std::string datainit, std::string dataend, std::string cidade, std::string estado, std::vector<Evento> *eventos, std::vector<Apresentacao> *apresentacoes) throw(runtime_error) = 0;
};

class IAEventos{ // interface que permite a comunicação com o módulo de eventos da camada de apresentação

public:
  //virtual void executar() = 0; // método que executa o módulo que herda dessa interface

  virtual void cadastrar_evento(std::string cpf, std::string senha) = 0; // método que cadastra um evento de um usuário

  virtual void obter_dados_eventos() = 0; // método para obter os dados dos eventos pedidos pelo usuário

  virtual void setCSEventos(ISEventos *) = 0; // método que liga o módulo de apresentação com um módulo de serviço
};

class ISUsuario{ // interface que permite a comunicação com o módulo de usuário da camada de serviço

  public: // Tarefas feitas pelo módulo de usuário da camada de serviço:
    virtual bool descadastrar_usuario(std::string cpf, std::string senha) throw(runtime_error) = 0;
    virtual bool cadastrar_usuario(std::string cpf, std::string senha, std::string numero_cartao, std::string codigo_seguranca, std::string data_validade) throw(runtime_error) = 0;
};

class IAUsuario{ // interface que permite a comunicação com o módulo de usuário da camada de apresentação

  public:
    virtual void cadastrar_usuario() = 0; // método que cadastra o usuário

    virtual void executar(std::string cpf, std::string senha) = 0; // método que executa o módulo que herda dessa interface

    virtual void setCSUsuario(ISUsuario *) = 0; // método que liga o módulo de apresentação com um módulo de serviço

    virtual void setCAEventos(IAEventos *) = 0; // método que lida o módulo de usuário com o módulo de eventos

    virtual void setCAVendas(IAVendas *) = 0; // método que lida o módulo de usuário com o módulo de vendas
};

class ISAutenticacao{ // interface que permite a comunicação com o módulo de autenticação da camada de serviço
    public: // Tarefas feitas pelo módulo de autenticação da camada de serviço:
      virtual bool autenticar(std::string cpf, std::string senha) throw(runtime_error) = 0; // método de autenticação de usuário
};

class IAAuteuticacao { // interface que permite a comunicação com o módulo de autenticação da camada de apresentação

    public:
        virtual void autenticar_usuario() = 0; // método que executa o módulo que herda dessa interface

        virtual void setCSAutenticacao(ISAutenticacao *) = 0; // método que liga o módulo de apresentação com um módulo de serviço

        virtual void setCAUsuario(IAUsuario *) = 0; // método que liga o módulo de autenticação com o de usuário
};

#endif
