#include <ncurses.h>
#include <cstdlib>
#include <string.h>
#include <vector>

#include "controladoras.h"
#include "entidades.h"
#include "dominios.h"

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
      autenticou = controladora_servico->autenticar(cpfstr, senhastr);
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

void CntrAUsuario::cadastrar_usuario(){
    int linha, coluna;
    char resposta[2];
    char cpf[15], senha[7], numero[17], codigo[4], data[6];
    bool retorno  = false;
    bool cadastrou;
    std::string cpfstr, senhastr, numerostr, codigostr, datastr;

    while(true){
      initscr();
      getmaxyx(stdscr,linha,coluna);
      mvprintw(0,0,"%s","Usuário\n");
      mvprintw(linha/4,(coluna - 15)/3,"%s","Digite Cpf do Usuário: ");
      getstr(cpf);
      cpfstr = cpf;
      mvprintw(linha/4 + 2,(coluna - 15)/3,"%s","Digite a Senha do Usuário: ");
      getstr(senha);
      senhastr = senha;
      mvprintw(linha/4 + 4,(coluna - 15)/3,"%s","Digite a Número do Cartão de Crédito: ");
      getstr(numero);
      numerostr = numero;
      mvprintw(linha/4 + 6,(coluna - 15)/3,"%s","Digite o Código de Segurança do Cartão de Crédito: ");
      getstr(codigo);
      codigostr = codigo;
      mvprintw(linha/4 + 8,(coluna - 15)/3,"%s","Digite a Data de Validade do Cartão de Crédito: ");
      getstr(data);
      datastr = data;
      clear();
      endwin();

      cadastrou = controladora_servico->cadastrar_usuario(cpfstr, senhastr, numerostr, codigostr, datastr);

      if(cadastrou == true)
        retorno = true;
      else{
        initscr();
        mvprintw(0,0,"%s","Usuário\n");
        mvprintw(linha/2,(coluna - 35)/2,"%s","Erro nos dados Informados\n");
        mvprintw(linha/2 + 2,(coluna - 35)/2,"%s","Deseja retornar? (Se sim digite 'S') : ");
        getstr(resposta);
        if(!strcmp(resposta, "s") || !strcmp(resposta, "S"))
          retorno = true;
        clear();
        endwin();
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
              controladora_vendas->comprar_ingresso();
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

void CntrAEventos::obter_dados_eventos(){
  int linha, coluna;
  char resposta[2];
  char datainit[9], dataend[9], cidade[17], estado[3];
  bool retorno = false;
  bool obteve;
  std::string datainitstr, dataendstr, cidadestr, estadostr;
  Evento auxevento;
  Apresentacao auxapresentacao;
  // variaveis mudadas por referência
  std::vector<Evento> eventos;
  std::vector<Apresentacao> apresentacoes;

  while(true){
    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(0,0,"%s","Eventos\n");
    mvprintw(linha/3, coluna/5, "%s", "Digite a Data de Início do Periodo Desejado: ");
    scanw("%s", datainit);
    datainitstr = datainit;
    mvprintw(linha/3 + 2, coluna/5, "%s", "Digite a Data de Termino do Periodo Desejado: ");
    scanw("%s", dataend);
    dataendstr = dataend;
    mvprintw(linha/3 + 4, coluna/5, "%s", "Digite a Cidade Desejada: ");
    scanw("%s", cidade);
    cidadestr = cidade;
    mvprintw(linha/3 + 6, coluna/5, "%s", "Digite o Estado Desejado: ");
    scanw("%s", estado);
    estadostr = estado;
    clear();
    endwin();

    obteve = controladora_servico->obter_dados_eventos(datainitstr, dataendstr, cidadestr, estadostr, &eventos, &apresentacoes);

    if(obteve == false){
      initscr();
      mvprintw(0,0,"%s","Eventos\n");
      mvprintw(linha/4,coluna/4,"%s","Erro nos dados Informados\n");
      mvprintw(linha/4 + 2,coluna/4, "%s", "Aperte Alguma Tecla: ");
      getch();
      retorno = true;
      clear();
      endwin();
    }
    else{
      if(eventos.size() == 0){
        initscr();
        mvprintw(0,0,"%s","Eventos\n");
        mvprintw(linha/4,coluna/4,"%s","Nenhum Evento Encontrado\n");
        mvprintw(linha/4 + 2,coluna/4, "%s", "Aperte Alguma Tecla: ");
        getch();
        clear();
        endwin();
      }
      else{
        for(int i = 0; i < eventos.size(); i++){
          auxevento = eventos[i];
          auxapresentacao = apresentacoes[i];
          initscr();
          mvprintw(0,0,"%s","Eventos\n");
          mvprintw(linha/4, coluna/4, "%s %d %s", "Apresentação", i + 1, ":\n");
          mvprintw(linha/4 + 1, coluna/4, "%s%s%s", "Nome do Evento: ",auxevento.GetNome().Get().c_str() ,"\n");
          mvprintw(linha/4 + 2, coluna/4, "%s%s%s", "Código da Apresentação: ", auxapresentacao.GetCodigo().Get().c_str(),"\n");
          mvprintw(linha/4 + 3, coluna/4, "%s%s%s", "Data da Apresentação: ", auxapresentacao.GetData().Get().c_str(),"\n");
          mvprintw(linha/4 + 4, coluna/4, "%s%s%s", "Horário: ", auxapresentacao.GetHorario().Get().c_str(),"\n");
          mvprintw(linha/4 + 5, coluna/4, "%s%.2f%s", "Preço: ", auxapresentacao.GetPreco().Get(),"\n");
          mvprintw(linha/4 + 6, coluna/4, "%s%d%s", "Numero da Sala: ", auxapresentacao.GetSala().Get(),"\n");
          mvprintw(linha/4 + 7, coluna/4, "%s%d%s", "Disponibilidade: ", auxapresentacao.GetDisponibilidade().Get(),"\n");
          mvprintw(linha/4 + 8, coluna/4, "%s%d%s", "Classe de Evento: ", auxevento.GetClasse().Get(),"\n");
          mvprintw(linha/4 + 9, coluna/4, "%s%s%s", "Faixa Etária: ", auxevento.GetFaixa().Get().c_str(),"\n");
          mvprintw(linha/4 + 11, coluna/4, "%s", "Aperte Alguma Tecla: ");
          getch();
          clear();
          endwin();
        }
      }
      retorno = true;
    }

    if(retorno)
      break;
  }
}

void CntrAVendas::comprar_ingresso(){
  int linha, coluna;
  bool retorno = false;
  bool compra;// booleano que indica se a compra foi feita
  char codigo_apresentacao[5];
  int quantidade_ingressos;
  std::string codigo;
  // Variavel que vai ser modificada ao ser passada por parametro no método comprar_ingresso();
  std::vector<Ingresso> Ingressos;

  while (true){
    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(0,0,"%s","Vendas\n");
    mvprintw(linha/3, coluna/4, "%s", "Digite o Código da Apresentação Desejada: ");
    scanw("%s", codigo_apresentacao);
    codigo = codigo_apresentacao;
    mvprintw(linha/3 + 2, coluna/4, "%s", "Digite a Quantidade de Ingressos Desejados: ");
    scanw("%d", &quantidade_ingressos);
    clear();
    endwin();
    compra = controladora_servico->comprar_ingresso(codigo, quantidade_ingressos, &Ingressos);

    if(compra == false){
      initscr();
      mvprintw(0,0,"%s","Vendas\n");
      mvprintw(linha/3,coluna/4,"%s","Erro nos dados Informados\n");
      mvprintw(linha/3 + 2,coluna/4, "%s", "Aperte Alguma Tecla: ");
      getch();
      retorno = true;
      clear();
      endwin();
    }
    else{
      if(Ingressos.size() == 0){
        initscr();
        mvprintw(0,0,"%s","Vendas\n");
        mvprintw(linha/3,coluna/4,"%s%d%s","Não há ", quantidade_ingressos," ingressos disponiveis\n");
        mvprintw(linha/3 + 2,coluna/4, "%s", "Aperte Alguma Tecla: ");
        getch();
        clear();
        endwin();
      }
      else{
        for(int i = 0; i < Ingressos.size(); i++){
          initscr();
          mvprintw(0,0,"%s","Vendas\n");
          mvprintw(linha/3,coluna/4,"%s %d%s %s\n","Código do Ingresso", i + 1, ":", Ingressos[i].GetCodigo().Get().c_str());
          mvprintw(linha/3 + 2,coluna/4, "%s", "Aperte Alguma Tecla: ");
          getch();
          clear();
          endwin();
        }
      }
      retorno = true;
    }

    if(retorno)
      break;
  }
}
