#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contato {
public:
    string nome;
    string email;
    string telefone;
    int idade;

    Contato() {
        nome = "";
        email = "";
        telefone = "";
        idade = 0;
    }
};

//Funcão para transformar o nome em citação bibliografica
string formatarCitacaoBibliografica(string nomeCompleto) {
    int posEspaco = nomeCompleto.find_last_of(' ');
    if (posEspaco == -1) return nomeCompleto; 

    string sobrenome = nomeCompleto.substr(posEspaco + 1);
    string primeiroNomes = nomeCompleto.substr(0, posEspaco);
    return sobrenome + ", " + primeiroNomes;
}

int main() {
    const int TAMANHO = 3;
    vector<Contato> contatos(TAMANHO);

    for (int i = 0; i < TAMANHO; i++) {
        cout << "\nContato " << i + 1 << ":\n";
        cout << "Nome: ";
        getline(cin, contatos[i].nome);
        cout << "Email: ";
        getline(cin, contatos[i].email);
        cout << "Telefone: ";
        getline(cin, contatos[i].telefone);
        cout << "Idade: ";
        cin >> contatos[i].idade;
        cin.ignore(); 
    }

    int somaIdades = 0;
    for (int i = 0; i < TAMANHO; i++) {
        somaIdades += contatos[i].idade;
    }
    float mediaIdade = (float)somaIdades / TAMANHO;
    cout << "\nMédia das idades: " << mediaIdade << endl;

    cout << "\nContatos com idade acima da média:\n";
    for (int i = 0; i < TAMANHO; i++) {
        if (contatos[i].idade > mediaIdade) {
            cout << formatarCitacaoBibliografica(contatos[i].nome) << endl;
        }
    }

    int maioresDeIdade = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (contatos[i].idade >= 18) {
            maioresDeIdade++;
        }
    }
    cout << "\nQuantidade de contatos maiores de idade: " << maioresDeIdade << endl;
    
    int maiorIdade = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (contatos[i].idade > maiorIdade) {
            maiorIdade = contatos[i].idade;
        }
    }

    cout << "\nContato(s) mais velho(s):\n";
    for (int i = 0; i < TAMANHO; i++) {
        if (contatos[i].idade == maiorIdade) {
            cout << "Nome: " << formatarCitacaoBibliografica(contatos[i].nome) << endl;
            cout << "Email: " << contatos[i].email << endl;
            cout << "Telefone: " << contatos[i].telefone << endl;
        }
    }

    return 0;
}
