#include <ncurses.h>

#include "controladoras.h"

void CntrAAutenticacao::executar(){

    char cpf[15];
    char senha[7];
    char resposta;
    int linha, coluna;
    bool autenticou;

    while(true){
      initscr();
      getmaxyx(stdscr,linha,coluna);
      mvprintw(linha/2,(coluna - 15)/2,"%s","Digite o Cpf: ");
      getstr(cpf);
      mvprintw(linha/2 + 2,(coluna - 15)/2,"%s","Digite a Senha: ");
      getstr(senha);
      clear();
      endwin();


      std::string cpfstr = cpf;
      std::string senhastr = senha;
      autenticou = controladora_servico->autenticar(cpfstr, senhastr);
      if(autenticou == true){
        controladora_usuario->executar(cpf, senha);
        break;
      }
      else{
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/2,(coluna - 15)/2,"%s","Erro na autenticacao\n");
        mvprintw(linha/2 + 2,(coluna - 35)/2,"%s","Deseja retornar? (Se sim digite 'S') :");
        resposta = (char) getch();
        clear();
        endwin();

        if(resposta == 'S' || resposta == 's')
          break;
      }
    }
}

void CntrAUsuario::executar(std::string cpf, std::string senha){
    char resposta;
    int linha, coluna;
    int opcao;

    while(true){
        initscr();
        getmaxyx(stdscr,linha,coluna);
        mvprintw(linha/4,(coluna - 25)/2,"%s","Escolha uma das opções\n");
        mvprintw(linha/4 + 2,(coluna - 25)/2,"%s","Descasdastra Usuário - 1\n");
        mvprintw(linha/4 + 3,(coluna - 25)/2,"%s","Comprar Ingresso - 2\n");
        mvprintw(linha/4 + 4,(coluna - 25)/2,"%s","Cadastrar Evento - 3\n");
        mvprintw(linha/4 + 5,(coluna - 25)/2,"%s","Descadastrar Evento - 4\n");
        mvprintw(linha/4 + 6,(coluna - 25)/2,"%s","Alterar Evento - 5\n");
        mvprintw(linha/4 + 7,(coluna - 25)/2,"%s","Retornar - 6\n");
        mvprintw(linha/4 + 9,(coluna - 25)/2,"%s","Escolha um dos números: ");
        resposta = (char) getch();
        opcao = atoi(&resposta);
        clear();
        endwin();

        switch (opcao){
            case(DESCADASTRAR_USUARIO):
              //controladora_servico->descadastrar_usuario();
              break;

            case(COMPRAR_INGRESSO):
              //controladora_servico->comprar_ingresso();
              break;

            case(CADASTRAR_EVENTO):
              //controladora_servico->cadastrar_evento();
              break;

            case(DESCADASTRAR_EVENTO):
              //controladora_servico->descadastrar_evento();
              break;

            case(ALTERAR_EVENTO):
              //controladora_servico->alterar_evento();
              break;

            case(RETORNAR):
              break;

            default:
              initscr();
              getmaxyx(stdscr,linha,coluna);
              mvprintw(linha/2,(coluna - 15)/2,"%s","Opção não válida\n");
              mvprintw(linha/2 + 2,(coluna - 35)/2,"%s","Deseja retornar? (Se sim digite 'S') :");
              resposta = (char) getch();
              clear();
              endwin();
              if(resposta == 'S' || resposta == 's')
                break;
              else
                this->executar(cpf, senha);
              break;
        }

        break;
    }
}
