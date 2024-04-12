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

// Função para cadastrar um novo contato
Contato cadastrar_contato() {
    string email, nome, telefone;
    int dia, mes, ano;
    cout << "Digite o e-mail do contato: ";
    cin >> email;
    cout << "Digite o nome do contato: ";
    cin >> nome;
    cout << "Digite o telefone do contato: ";
    cin >> telefone;
    cout << "Digite o dia de nascimento do contato: ";
    cin >> dia;
    cout << "Digite o mês de nascimento do contato: ";
    cin >> mes;
    cout << "Digite o ano de nascimento do contato: ";
    cin >> ano;
    Data dtnasc(dia, mes, ano);
    Contato novo_contato(email, nome, telefone, dtnasc);
    return novo_contato;
}
// Função para exibir os detalhes de um contato
void exibir_contato(Contato contato) {
    cout << "Nome: " << contato.nome << endl;
    cout << "E-mail: " << contato.email << endl;
    cout << "Telefone: " << contato.telefone << endl;
    cout << "Idade: " << contato.idade() << endl;
}


