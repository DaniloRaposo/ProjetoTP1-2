#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <stdio.h>

using namespace std;

class Codigo_de_evento {
    //3 digitos de 0 a 9
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Codigo_de_apresentacao {
    //4 digitos de 0 a 9
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Codigo_de_ingresso {
    //5 digitos de 0 a 9
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Nome_de_evento {
    //20 digitos
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Data {
    //8 digitos DD/MM/AA
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Horario {
    //5 digitos HH:MM
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Preco {
    // de 0 a 1000,00
    private:
        float info;

        void Validar(float input) throw(invalid_argument);

    public:
        void Set(float input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline float Get() const {
                return info;
        };
};

class Numero_de_sala {
    // 1 a 10
    private:
        int info;

        void Validar(int input) throw(invalid_argument);

    public:
        void Set(int input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline int Get() const {
                return info;
        };
};

class Cidade {
    //16 digitos
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Estado {
    //2 letras
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Disponibilidade {
    // 0 a 250
    private:
        int info;

        void Validar(int input) throw(invalid_argument);

    public:
        void Set(int input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline int Get() const {
                return info;
        };
};

class Classe_de_evento {
    // 1 a 4
    /* 1 Teatro
       2 Esporte
       3 Show Nacional
       4 Show Internacional*/
    private:
        int info;

        void Validar(int input) throw(invalid_argument);

    public:
        void Set(int input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline int Get() const {
                return info;
        };
};

class Faixa_etaria {
    // L, 10, 12, 14, 16, 18
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Cpf {
    // XXX.XXX.XXX-XX
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Senha {
    // 6 digitos
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Numero_de_cartao_de_credito {
    // 16 digitos
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Codigo_de_seguranca {
    // 3 digitos
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};

class Data_de_validade {
    // 5 digitos DD/MM
    private:
        std::string info;

        void Validar(string input) throw(invalid_argument);

    public:
        void Set(string input) throw(invalid_argument){
            Validar(input);
            this->info = input;
        };
        inline std::string Get() const {
                return info;
        };
};
#endif // DOMINIOS_H_INCLUDED
