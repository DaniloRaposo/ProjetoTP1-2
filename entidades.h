#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include <stdexcept>

#include "dominios.h"

class Usuario{
// cada objeto do tipo usuário vai possuir como atributo um objeto do tipo cpf e um objeto do tipo senha
    private:
        Cpf cpf; // objeto da classe cpf
        Senha senha; // objeto da classe senha

    public:
        // nos consideramos que o objeto imput da classe cpf possui valor válido, já que ele foi setado apartir do método cpf::Set
        void Set(const Cpf &input) throw (invalid_argument){ // seta o valor do cpf, imput é o cpf que será setado
            this->cpf = input;
        }

        inline Cpf GetCpf(){
            return cpf;
        }

        void Set(const Senha &input) throw (invalid_argument){ // seta o valor da senha, imput é a senha a ser setada
            this->senha = input;
        }

        inline Senha GetSenha(){
            return senha;
        }
};

class Evento{
// cada objeto do tipo evento vai possuir como atributos objetos do tipo Codigo_de_evento, Nome_de_evento, cidade, estado, classe_de_evento e faixa_etaria
    private:
        Codigo_de_evento codigo;
        Nome_de_evento nome;
        Cidade cidade;
        Estado estado;
        Classe_de_evento classe;
        Faixa_etaria faixa;

    public:
  
        void Set(const Codigo_de_evento &input) throw (invalid_argument){ // seta o valor do código de evento, o input é o código a ser setado
            this->codigo= input;
        }

        inline Codigo_de_evento GetCodigo(){
            return codigo;
        }

        void Set(const Nome_de_evento &input) throw (invalid_argument){ // seta o nome do evento, o input é o nome a ser setado
            this->nome = input;
        }

        inline Nome_de_evento GetNome(){
            return nome;
        }

        void Set(const Cidade &input) throw (invalid_argument){ // seta a cidade do evento, o input é a cidade a ser setada
            this->cidade = input;
        }

        inline Cidade GetCidade(){
            return cidade;
        }

        void Set(const Estado &input) throw (invalid_argument){ // seta o estado do evento, o input é o estado a ser setado
            this->estado = input;
        }

        inline Estado GetEstado(){
            return estado;
        }

        void Set(const Classe_de_evento &input) throw (invalid_argument){ // seta a classe de evento do evento, o input é a classe a ser setada
            this->classe = input;
        }

        inline Classe_de_evento GetClasse(){
            return classe;
        }

        void Set(const Faixa_etaria &input) throw (invalid_argument){ // seta a faixa etária do evento, o input é a faixa a ser setada
            this->faixa = input;
        }

        inline Faixa_etaria GetFaixa(){
            return faixa;
        }
};

class Apresentacao{
// cada objeto da classe Apresentação possui como atributo um objeto da classe Codigo_de_Apresentação, Data, Horario, Preço, Número_de_Sala e Disponibilidade
    private:
        Codigo_de_apresentacao codigo;
        Data data;
        Horario horario;
        Preco preco;
        Numero_de_sala sala;
        Disponibilidade disponibilidade;

    public:
  
        void Set(const Codigo_de_apresentacao &input) throw (invalid_argument){ // seta o codigo de apresentação da apresentação, o input é o código a ser setado
            this->codigo = input;
        }

        inline Codigo_de_apresentacao GetCodigo(){
            return codigo;
        }

  
        void Set(const Data &input) throw (invalid_argument){ // seta a data da apresentação, o input é a data a ser setada
            this->data = input;
        }

        inline Data GetData(){
            return data;
        }

        void Set(const Horario &input) throw (invalid_argument){ // seta o horário da apresentação, o input é o horário a ser setado
            this->horario = input;
        }

        inline Horario GetHorario(){
            return horario;
        }

        void Set(const Preco &input) throw (invalid_argument){ // seta o preço da apresentação, o input é o preço setado
            this->preco = input;
        }

        inline Preco GetPreco(){
            return preco;
        }

        void Set(const Numero_de_sala &input) throw (invalid_argument){ // seta o número da sala da apresentação, o input é o número setado
            this->sala = input;
        }

        inline Numero_de_sala GetSala(){
            return sala;
        }

        void Set(const Disponibilidade &input) throw (invalid_argument){ // seta a disponibilidade da apresentação, o input é a disponibilidade setada
            this->disponibilidade = input;
        }

        inline Disponibilidade GetDisponibilidade(){
            return disponibilidade;
        }
};

class Ingresso{
// a classe ingresso possui como único atributo um objeto da classe código_de_ingresso
    private:
        Codigo_de_ingresso codigo;

    public:
  
        void Set(const Codigo_de_ingresso &input) throw (invalid_argument){ // seta o código do ingresso, o iput é o código a ser setado
            this->codigo = input;
        }

        inline Codigo_de_ingresso GetCodigo(){
            return codigo;
        }
};

class Cartao_de_Credito{
// a classe Cartao_de_Credito possui como atributos objetos das classer numero_de_cartao, codigo_de_seguranca e data_de_validade
    private:
        Numero_de_cartao_de_credito numero;
        Codigo_de_seguranca codigo;
        Data_de_validade data;

    public:
  
        void Set(const Numero_de_cartao_de_credito &input) throw (invalid_argument){ // seta o número de cartão do cartão, o input é o número setado

            this->numero = input;
        }

        inline Numero_de_cartao_de_credito GetNumero(){
            return numero;
        }

        void Set(const Codigo_de_seguranca &input) throw (invalid_argument){ // seta o código de segurança do cartão, o input é o código setado

            this->codigo = input;
        }

        inline Codigo_de_seguranca GetCodigo(){
            return codigo;
        }

        void Set(const Data_de_validade &input) throw (invalid_argument){// seta a data de  validade do cartão, o input é a data a ser setada

            this->data = input;
        }

        inline Data_de_validade GetData(){
            return data;
        }
};

#endif //ENTIDADES_H_INCLUDED
