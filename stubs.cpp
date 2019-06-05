#include <stdexcept>

#include "stubs.h"

const std::string StubSAutenticacao::TRIGGER_FALHA_CPF = "106.506.924-37";
const std::string StubSAutenticacao::TRIGGER_ERRO_CPF = "106.506.924-33";
const std::string StubSAutenticacao::TRIGGER_FALHA_SENHA = "111111";
const std::string StubSAutenticacao::TRIGGER_ERRO_SENHA = "222222";

bool StubSAutenticacao::autenticar(std::string cpf, std::string senha) throw(runtime_error){
  if( cpf == TRIGGER_FALHA_CPF || senha == TRIGGER_FALHA_SENHA)
    return false;
  else if(cpf == TRIGGER_ERRO_CPF || senha == TRIGGER_ERRO_SENHA)
    throw runtime_error("Erro de sistema");
  else
    return true;
}
