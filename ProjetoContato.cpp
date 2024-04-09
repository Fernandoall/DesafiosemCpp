#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Data {
public:
    int dia;
    int mes;
    int ano;

    Data() {} // Construtor padrão

    Data(int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }
};

class Contato {
public:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

    Contato() {} // Construtor padrão

    Contato(string e, string n, string t, Data d) {
        email = e;
        nome = n;
        telefone = t;
        dtnasc = d;
    }
    int idade() {
        time_t now = time(0);
        tm *local_time = localtime(&now);
        int ano_atual = local_time->tm_year + 1900;
        int idade = ano_atual - dtnasc.ano;
        return idade;
    }
};


