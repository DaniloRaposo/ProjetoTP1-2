#include <stdexcept>

#include "stubs.h"

const std::string StubSAutenticacao::TRIGGER_FALHA_CPF = "106.506.924-37";
const std::string StubSAutenticacao::TRIGGER_ERRO_CPF = "106.506.924-33";
const std::string StubSAutenticacao::TRIGGER_FALHA_SENHA = "111111";
const std::string StubSAutenticacao::TRIGGER_ERRO_SENHA = "222222";

bool StubSAutenticacao::autenticar(std::string cpf, std::string senha) throw(runtime_error){
  if(cpf == TRIGGER_FALHA_CPF || senha == TRIGGER_FALHA_SENHA)
    return false;
  else if(cpf == TRIGGER_ERRO_CPF || senha == TRIGGER_ERRO_SENHA)
    throw runtime_error("Erro de sistema");
  else
    return true;
}

const std::string StubSUsuario::TRIGGER_ERRO_CPF = "000.000.000-00";
const std::string StubSUsuario::TRIGGER_ERRO_SENHA = "123456";

bool StubSUsuario::descadastrar_usuario(std::string cpf, std::string senha) throw(runtime_error){
  if(cpf == TRIGGER_ERRO_CPF || senha == TRIGGER_ERRO_SENHA)
    throw runtime_error("Erro de sistema");
  else
    return true;
}

bool StubSUsuario::comprar_ingresso() throw(runtime_error){}

bool StubSUsuario::descadastrar_evento() throw(runtime_error){}

bool StubSUsuario::alterar_evento() throw(runtime_error){}

const std::string StubSEventos::TRIGGER_FALHA_CODIGO_EVENTO = "111";
const std::string StubSEventos::TRIGGER_ERRO_CODIGO_EVENTO = "222";
const std::string StubSEventos::TRIGGER_FALHA_NOME = "a bela e a fera";
const std::string StubSEventos::TRIGGER_ERRO_NOME = "o rei leao";
const std::string StubSEventos::TRIGGER_FALHA_CIDADE = "recife";
const std::string StubSEventos::TRIGGER_ERRO_CIDADE = "manaus";
const std::string StubSEventos::TRIGGER_FALHA_ESTADO = "12";
const std::string StubSEventos::TRIGGER_ERRO_ESTADO = "DF";
const std::string StubSEventos::TRIGGER_FALHA_CLASSE = "5";
const std::string StubSEventos::TRIGGER_ERRO_CLASSE = "2";
const std::string StubSEventos::TRIGGER_FALHA_FAIXA = "15";
const std::string StubSEventos::TRIGGER_ERRO_FAIXA = "L";

bool StubSEventos::cadastrar_evento(std::string cpf, std::string senha, std::string codigo_evento, std::string nome_evento, std::string cidade, std::string estado, std::string classe, std::string faixa_etaria, std::vector<std::string> codigo_apresentacao, std::vector<std::string> data, std::vector<std::string> horario, std::vector<float> preco, std::vector<int> sala) throw(runtime_error){
  if(codigo_evento == TRIGGER_FALHA_CODIGO_EVENTO || nome_evento == TRIGGER_FALHA_NOME || cidade == TRIGGER_FALHA_CIDADE || estado == TRIGGER_FALHA_ESTADO || classe == TRIGGER_FALHA_CLASSE || faixa_etaria == TRIGGER_FALHA_FAIXA)
    return false;
  else if(codigo_evento == TRIGGER_ERRO_CODIGO_EVENTO || nome_evento == TRIGGER_ERRO_NOME || cidade == TRIGGER_ERRO_CIDADE || estado == TRIGGER_ERRO_ESTADO || classe == TRIGGER_ERRO_CLASSE || faixa_etaria == TRIGGER_ERRO_FAIXA)
    throw runtime_error("Erro no sistema");
  else
    return true;
}
