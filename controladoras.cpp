#include <ncurses.h>
#include <cstdlib>
#include <string.h>
#include <vector>

#include "controladoras.h"

void ControladoraSistema::executar(){

  char resposta[2];
  int linha, coluna, opcao;
  bool retorno = false;

  while(true){
    initscr();
    getmaxyx(stdscr, linha, coluna);
    mvprintw(0,0,"%s","Início\n");
    mvprintw(linha/4,(coluna - 25)/2,"%s","Escolha uma das opções\n");
    mvprintw(linha/4 + 2,(coluna - 25)/2,"%s","Cadastrar Usuário - 1\n");
    mvprintw(linha/4 + 3,(coluna - 25)/2,"%s","Autenticar Usuário - 2\n");
    mvprintw(linha/4 + 4,(coluna - 25)/2,"%s","Obter Dados dos Eventos - 3\n");
    mvprintw(linha/4 + 5,(coluna - 25)/2,"%s","Retornar - 4\n");
    mvprintw(linha/4 + 7,(coluna - 25)/2,"%s","Escolha um dos números : ");
    getstr(resposta);
    opcao = atoi(resposta);
    clear();
    endwin();

    switch(opcao){
      case(CADASTRAR_USUARIO):
      controladora_usuario->cadastrar_usuario();
      break;

      case(AUTENTICAR_USUARIO):
      controladora_autenticacao->autenticar_usuario();
      break;

      case(OBTER_DADOS_EVENTOS):
      controladora_eventos->obter_dados_eventos();
      break;

      case(RETORNAR):
      retorno = true;
      break;

      default:
      initscr();
      getmaxyx(stdscr,linha,coluna);
      mvprintw(0,0,"%s","Início\n");
      mvprintw(linha/2,(coluna - 15)/2,"%s","Opção não válida\n");
      mvprintw(linha/2 + 2,(coluna - 35)/2,"%s","Deseja retornar? (Se sim digite 'S') : ");
      getstr(resposta);
      clear();
      endwin();

      if(!strcmp(resposta, "S") || !strcmp(resposta, "s"))
        retorno = true;

      break;

    }

    if(retorno == true)
      break;
  }
}

void CntrAAutenticacao::autenticar_usuario(){

    char cpf[15];
    char senha[7];
    char resposta[2];
    int linha, coluna;
    bool autenticou, retorno = false;

    while(true){
      initscr();
      getmaxyx(stdscr,linha,coluna);
      mvprintw(0,0,"%s","Autenticação\n");
      mvprintw(linha/3,(coluna - 15)/3,"%s","Digite o Cpf: ");
      getstr(cpf);
      mvprintw(linha/3 + 2,(coluna - 15)/3,"%s","Digite a Senha: ");
      getstr(senha);
      clear();
      endwin();


      std::string cpfstr = cpf;
      std::string senhastr = senha;
      autenticou = controladora_servico->autenticar_usuario(cpfstr, senhastr);
      if(autenticou == true){
        controladora_usuario->executar(cpf, senha);
        retorno = true;
      }
      else{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(0,0,"%s","Autenticação\n");
        mvprintw(linha/2,(coluna - 15)/2,"%s","Erro na autenticacao\n");
        mvprintw(linha/2 + 2,(coluna - 35)/2,"%s","Deseja retornar? (Se sim digite 'S') : ");
        getstr(resposta);
        clear();
        endwin();

        if(!strcmp(resposta, "S") || !strcmp(resposta, "s"))
          retorno = true;
      }

      if(retorno)
        break;
    }
}

void CntrAUsuario::executar(std::string cpf, std::string senha){
    char resposta[2];
    int linha, coluna;
    int opcao;
    bool retorno  = false;

    while(true){
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(0,0,"%s","Usuário\n");
        mvprintw(linha/4,(coluna - 25)/2,"%s","Escolha uma das opções\n");
        mvprintw(linha/4 + 2,(coluna - 25)/2,"%s","Descasdastra Usuário - 1\n");
        mvprintw(linha/4 + 3,(coluna - 25)/2,"%s","Comprar Ingresso - 2\n");
        mvprintw(linha/4 + 4,(coluna - 25)/2,"%s","Cadastrar Evento - 3\n");
        mvprintw(linha/4 + 5,(coluna - 25)/2,"%s","Descadastrar Evento - 4\n");
        mvprintw(linha/4 + 6,(coluna - 25)/2,"%s","Alterar Evento - 5\n");
        mvprintw(linha/4 + 7,(coluna - 25)/2,"%s","Retornar - 6\n");
        mvprintw(linha/4 + 9,(coluna - 25)/2,"%s","Escolha um dos números : ");
        getstr(resposta);
        opcao = atoi(resposta);
        clear();
        endwin();

        switch (opcao){
            case(DESCADASTRAR_USUARIO):
              controladora_servico->descadastrar_usuario(cpf, senha);
              initscr();
              getmaxyx(stdscr,linha,coluna);
              mvprintw(0,0,"%s","Usuário\n");
              mvprintw(linha/2, (coluna - 35)/4,"%s", "Usuario descadastrado, aperte algum botão para continuar : ");
              getch();
              clear();
              endwin();
              retorno = true;
              break;

            case(COMPRAR_INGRESSO):
              //controladora_servico->comprar_ingresso();
              break;

            case(CADASTRAR_EVENTO):
              controladora_eventos->cadastrar_evento(cpf, senha);
              break;

            case(DESCADASTRAR_EVENTO):
              //controladora_servico->descadastrar_evento();
              break;

            case(ALTERAR_EVENTO):
              //controladora_servico->alterar_evento();
              break;

            case(RETORNAR):
              retorno = true;
              break;

            default:
              initscr();
              getmaxyx(stdscr,linha,coluna);
              mvprintw(0,0,"%s","Usuário\n");
              mvprintw(linha/2,(coluna - 15)/2,"%s","Opção não válida\n");
              mvprintw(linha/2 + 2,(coluna - 35)/2,"%s","Deseja retornar? (Se sim digite 'S') : ");
              getstr(resposta);
              clear();
              endwin();

              if(!strcmp(resposta, "S") || !strcmp(resposta, "s"))
                retorno = true;

              break;
        }
        if(retorno)
          break;
    }
}

bool CntrSUsuario::descadastrar_usuario(std::string cpf, std::string senha) throw(runtime_error){
    Cpf cpfteste;


    Usuario usuarioteste;
}

bool CntrSUsuario::comprar_ingresso() throw(runtime_error){
}

bool CntrSUsuario::descadastrar_evento() throw(runtime_error){

}

bool CntrSUsuario::alterar_evento() throw(runtime_error){

}

void CntrAEventos::cadastrar_evento(std::string cpf, std::string senha){
  int linha, coluna;
  int numero_apresentacoes;
  int sala;
  float preco;
  bool retorno  = false;
  bool cadastrou;
  char resposta[2];
  char codigo_evento[4], nome[21], cidade[17], estado[3], classe[2], faixa[3];
  char codigo_apresentacao[5], data[9], horario[6];
  std::string codigo_eventostr, nomestr, cidadestr, estadostr, classestr, faixastr;
  std::vector<std::string> codigovec, datavec, horariovec;
  std::vector<int> salavec;
  std::vector<float> precovec;


  while(true){
    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(0,0,"%s","Eventos\n");
    mvprintw(linha/4,(coluna - 15)/3,"%s","Digite o Código de Evento: ");
    getstr(codigo_evento);
    codigo_eventostr = codigo_evento;
    mvprintw(linha/4 + 2,(coluna - 15)/3,"%s","Digite o Nome do Evento: ");
    getstr(nome);
    nomestr = nome;
    mvprintw(linha/4 + 4,(coluna - 15)/3,"%s","Digite a Cidade do Evento: ");
    getstr(cidade);
    cidadestr = cidade;
    mvprintw(linha/4 + 6,(coluna - 15)/3,"%s","Digite o Estado do Evento: ");
    getstr(estado);
    estadostr = estado;
    mvprintw(linha/4 + 8,(coluna - 15)/3,"%s","Digite a Classe do Evento: ");
    getstr(classe);
    classestr = classe;
    mvprintw(linha/4 + 10,(coluna - 15)/3,"%s","Digite a Faixa Etária do Evento: ");
    getstr(faixa);
    faixastr = faixa;
    mvprintw(linha/4 + 12,(coluna - 15)/3, "%s", "Digite a Quantidade de Apresentações Desejadas: ");
    getstr(resposta);
    numero_apresentacoes = atoi(resposta);
    clear();
    endwin();

    for(int iterator = 0; iterator < numero_apresentacoes; iterator++){
      initscr();
      mvprintw(0,0,"%s","Eventos\n");
      mvprintw(linha/3, (coluna - 15)/4, "%s%d%s","Digite o Código de Apresentação da Apresentação ", iterator + 1,": ");
      scanw("%s", codigo_apresentacao);
      codigovec.push_back(codigo_apresentacao);
      mvprintw(linha/3 + 2, (coluna - 15)/4, "%s%d%s","Digite a Data da Apresentação ", iterator + 1,": ");
      scanw("%s", data);
      datavec.push_back(data);
      mvprintw(linha/3 + 4, (coluna - 15)/4, "%s%d%s","Digite o Horário da Apresentação ", iterator + 1,": ");
      scanw("%s", horario);
      horariovec.push_back(horario);
      mvprintw(linha/3 + 6, (coluna - 15)/4, "%s%d%s","Digite o Preço da Apresentação ", iterator + 1,": ");
      scanw("%.2f", &preco);
      precovec.push_back(preco);
      mvprintw(linha/3 + 8, (coluna - 15)/4, "%s%d%s","Digite a Sala da Apresentação ", iterator + 1,": ");
      scanw("%d", &sala);
      salavec.push_back(sala);
      clear();
      endwin();
    }

    cadastrou = controladora_servico->cadastrar_evento(cpf, senha, codigo_eventostr, nomestr, cidadestr, estadostr,  classestr, faixastr, codigovec, datavec, horariovec, precovec, salavec);
    if(cadastrou == true)
      retorno = true;
    else{
      initscr();
      mvprintw(0,0,"%s","Eventos\n");
      mvprintw(linha/2,(coluna - 35)/2,"%s","Erro nos dados Informados\n");
      mvprintw(linha/2 + 2,(coluna - 35)/2,"%s","Deseja retornar? (Se sim digite 'S') : ");
      getstr(resposta);
      if(!strcmp(resposta, "s") || !strcmp(resposta, "S"))
        retorno = true;
      clear();
      endwin();
    }

    if(retorno == true)
      break;
  }
}
