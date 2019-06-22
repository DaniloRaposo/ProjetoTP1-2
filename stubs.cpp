#include <stdexcept>

#include "dominios.h"
#include "entidades.h"
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

const std::string StubSUsuario::TRIGGER_FALHA_CPF = "123.123.123.44";
const std::string StubSUsuario::TRIGGER_ERRO_CPF_DESCADASTRAR = "000.000.000-00";
const std::string StubSUsuario::TRIGGER_ERRO_CPF_CADASTRAR = "123.456.789-00";
const std::string StubSUsuario::TRIGGER_FALHA_SENHA = "AAAAAA";
const std::string StubSUsuario::TRIGGER_ERRO_SENHA_DESCADASTRAR = "123456";
const std::string StubSUsuario::TRIGGER_ERRO_SENHA_CADASTRAR = "121212";
const std::string StubSUsuario::TRIGGER_FALHA_NUMERO_CARTAO = "123123123123123A";
const std::string StubSUsuario::TRIGGER_ERRO_NUMERO_CARTAO = "0000000000000000";
const std::string StubSUsuario::TRIGGER_FALHA_CODIGO_SEGURANCA = "ABC";
const std::string StubSUsuario::TRIGGER_ERRO_CODIGO_SEGURANCA = "123";
const std::string StubSUsuario::TRIGGER_FALHA_DATA = "13/22";
const std::string StubSUsuario::TRIGGER_ERRO_DATA = "12/12";

bool StubSUsuario::descadastrar_usuario(std::string cpf, std::string senha) throw(runtime_error){
  if(cpf == TRIGGER_ERRO_CPF_DESCADASTRAR || senha == TRIGGER_ERRO_SENHA_DESCADASTRAR)
    throw runtime_error("Erro de sistema");
  else
    return true;
}

bool StubSUsuario::cadastrar_usuario(std::string cpf, std::string senha, std::string numero_cartao, std::string codigo_seguranca, std::string data_validade) throw(runtime_error){
  if(cpf == TRIGGER_FALHA_CPF || senha == TRIGGER_FALHA_SENHA || numero_cartao == TRIGGER_FALHA_NUMERO_CARTAO || codigo_seguranca == TRIGGER_FALHA_CODIGO_SEGURANCA || data_validade == TRIGGER_FALHA_DATA)
    return false;
  else if(cpf == TRIGGER_ERRO_CPF_CADASTRAR || senha == TRIGGER_ERRO_SENHA_CADASTRAR || numero_cartao == TRIGGER_ERRO_NUMERO_CARTAO || codigo_seguranca == TRIGGER_ERRO_CODIGO_SEGURANCA || data_validade == TRIGGER_ERRO_DATA)
    throw runtime_error("Erro de sistema");
  else
    return true;
}

const std::string StubSEventos::TRIGGER_CIDADE_SEM_EVENTOS = "natal";
const std::string StubSEventos::TRIGGER_FALHA_DATA = "02/09/99";
const std::string StubSEventos::TRIGGER_ERRO_DATA = "02/09/00";
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

bool StubSEventos::obter_dados_eventos(std::string datainit, std::string dataend, std::string cidade, std::string estado, std::vector<Evento> *eventos, std::vector<Apresentacao> *apresentacoes) throw(runtime_error){
  if(datainit == TRIGGER_FALHA_DATA || dataend == TRIGGER_FALHA_DATA || cidade == TRIGGER_FALHA_CIDADE || estado == TRIGGER_FALHA_ESTADO)
    return false;
  else if(datainit == TRIGGER_ERRO_DATA || dataend == TRIGGER_ERRO_DATA || cidade == TRIGGER_ERRO_CIDADE || estado == TRIGGER_ERRO_ESTADO)
    throw runtime_error("Erro no sistema");
  else if(cidade == TRIGGER_CIDADE_SEM_EVENTOS)
    return true;
  else{
    // inicializar as classes do domínio para setar os valores no vector de entidades
    Nome_de_evento nome;
    Codigo_de_apresentacao codigo;
    Data data;
    Horario horario;
    Preco preco;
    Numero_de_sala numero;
    Disponibilidade disponibilidade;
    Classe_de_evento classe;
    Faixa_etaria faixa;
    // inicializar as classes de entidade que serão colocadas no vector
    Evento evento;
    Apresentacao apresentacao;
    // set dos valores nos dominios
    nome.Set("A bela e a fera");
    codigo.Set("1234");
    data.Set("01/01/01");
    horario.Set("12:00");
    preco.Set(10.10);
    numero.Set(2);
    disponibilidade.Set(30);
    classe.Set(2);
    faixa.Set("10");
    // set dos dominios nas entidades
    evento.Set(nome);
    evento.Set(classe);
    evento.Set(faixa);
    apresentacao.Set(codigo);
    apresentacao.Set(data);
    apresentacao.Set(horario);
    apresentacao.Set(preco);
    apresentacao.Set(numero);
    apresentacao.Set(disponibilidade);
    // push nos vectors
    eventos->push_back(evento);
    apresentacoes->push_back(apresentacao);
    // set dos valores nos dominios
    nome.Set("Boku no Hero");
    codigo.Set("1233");
    data.Set("01/02/01");
    horario.Set("15:00");
    preco.Set(25.00);
    numero.Set(1);
    disponibilidade.Set(13);
    classe.Set(3);
    faixa.Set("L");
    // set dos dominios nas entidades
    evento.Set(nome);
    evento.Set(classe);
    evento.Set(faixa);
    apresentacao.Set(codigo);
    apresentacao.Set(data);
    apresentacao.Set(horario);
    apresentacao.Set(preco);
    apresentacao.Set(numero);
    apresentacao.Set(disponibilidade);
    // push nos vectors
    eventos->push_back(evento);
    apresentacoes->push_back(apresentacao);

    return true;
  }
}

const int StubSVendas::LIMITE_INGRESSOS = 250;
const std::string StubSVendas::TRIGGER_FALHA_CODIGO = "2233";
const std::string StubSVendas::TRIGGER_ERRO_CODIGO = "1112";

bool StubSVendas::comprar_ingresso(std::string codigo, int  quantidade_ingressos, std::vector<Ingresso> *Ingressos) throw(runtime_error){
  if(codigo == TRIGGER_FALHA_CODIGO)
    return false;
  else if(codigo == TRIGGER_ERRO_CODIGO)
    throw runtime_error("Erro de sistema");
  else if(quantidade_ingressos > LIMITE_INGRESSOS)
   return true;
  else{
    // inicializando as variaveis auxiliares para setar os codigos de ingresso nos ingressos
    Codigo_de_ingresso codigo_ingresso;
    // inicializando os ingressos que serão colocados no vector
    Ingresso ingresso;

    codigo_ingresso.Set("12345");
    ingresso.Set(codigo_ingresso);
    Ingressos->push_back(ingresso);

    codigo_ingresso.Set("11111");
    ingresso.Set(codigo_ingresso);
    Ingressos->push_back(ingresso);

    codigo_ingresso.Set("12222");
    ingresso.Set(codigo_ingresso);
    Ingressos->push_back(ingresso);

    codigo_ingresso.Set("98989");
    ingresso.Set(codigo_ingresso);
    Ingressos->push_back(ingresso);

    return true;
  }

}
