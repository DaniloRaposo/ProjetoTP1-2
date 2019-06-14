#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>
#include <algorithm>

using namespace std;

// Declaração de classe container de usuários.

class ContainerCartao{

    private:
        //dado principal
        list<Cartao_de_Credito> LCartao; //lista de cartoes de credito

        //relacoes de grafo
        list<*Usuario> LPUsuario;   //Usuario do cartao

        //referencias pra containers
        ContainerUsuario *PCUsuario; //ponteiro pra container de usuario

        public;

        //set referencias pra containers
        void setCUsuario(ContainerUsuario *input)
        {
            this->PCUsuario = input;
        };
};

class ContainerUsuario{

    private:
        //dado principal
        list<Usuario> listUsuario;

        //relacoes de grafo
        list<*Cartao_de_Credito>    LPCartao;  //Cartao do usuario
        list<list<*Evento>>         LLPEvento;//Eventos de cada usuario (no max 5)
        list<list<*Ingresso>>       LLPIngresso;//Ingressos do usuario

        //referencias pra containers
        ContainerCartao     *PCCartao;
        ContainerEvento     *PCEvento;
        ContainerIngresso   *PCIngresso;

    public:

        // Métodos por meio dos quais são solicitados os serviços.

        void incluir(Usuario input)
        {
            listUsuario.push_back(input);
        };
        void remover(Usuario input)
        {
            listUsuario.remove(input);
        };
        bool (Usuario input)
        {
            listUsuario::iterator it;
            for(it = listUsuario.begin(); it != listUsuario.end(); ++it)
            {
                if (it.isEqualTo(input))
                    break;
            }
            return (it != listUsuario.end());
        };

        void setCCartao(ContainerCartao *input)
        {
            this->PCCartao = input;
        };
        void setCEvento(ContainerEvento *input)
        {
            this->PCEvento = input;
        };
        void setCIngresso(ContainerIngresso *input)
        {
            this->PCIngresso = input;
        };

};

class ContainerEvento{

    private:
        //dado principal
        list<Evento> LEvento;   //lista de eventos

        //relacoes de grafo
        list<list<*Apresentacao>> LLPApresentacao;   //no max 10 por evento
        list<*Usuario> LPUsuario;                   //lista de ponteiro pra usuario;

        //referencias pra containers
        ContainerApresentacao *PCApresentacao   //ponteiro pra container de apresentacao
        ContainerUsuario *PCUsuario;            //ponteiro pra container de usuario

        public;

        //set referencias pra containers
        void setCApresentacao(ContainerApresentacao *input)
        {
            this->PCApresentacao = input;
        };
        void setCUsuario(ContainerUsuario *input)
        {
            this->PCUsuario = input;
        };
};

class ContainerApresentacao{

    private:
        //dado principal
        list<Apresentacao> LApresentacao;   //lista de apresentacao

        //relacoes de grafo
        list<*Evento> LPEvento;              //lista de ponteiro pra usuario;
        list<list<*Ingresso>> LLPIngresso;   //no max 250 por apresentacao

        //referencias pra containers
        ContainerEvento *PCEvento           //ponteiro pra container de evento
        ContainerIngresso *PCIngresso;      //ponteiro pra container de ingresso

        public;

        //set referencias pra containers
        void setCEvento(ContainerEvento *input)
        {
            this->PCEvento = input;
        };
        void setCApresentacao(ContainerIngresso *input)
        {
            this->PCIngresso = input;
        };
};

class ContainerIngresso{
    private:
        //dado principal
        list<Ingresso> LIngresso;   //lista de eventos

        //relacoes de grafo
        list<*Usuario> LPUsuario;             //Usuario do ingresso
        list<*Apresentacao> LPApresentacao;   //Apresentacao do ingresso

        //referencias pra containers
        ContainerApresentacao *PCApresentacao   //ponteiro pra container de apresentacao
        ContainerUsuario *PCUsuario;            //ponteiro pra container de usuario

        public;

        //set referencias pra containers
        void setCUsuario(ContainerUsuario *input)
        {
            this->PCUsuario = input;
        };
        void setCApresentacao(ContainerApresentacao *input)
        {
            this->PCApresentacao = input;
        };
};


#endif // CONTROLADORAS_H_INCLUDED
