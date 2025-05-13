#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h> // Para permitir acentuação

using namespace std;

const int MAX_FUNCIONARIOS = 100;

struct Funcionario {
    int prontuario;
    string nome;
    double salario;
};

bool prontuarioExiste(Funcionario lista[], int qtd, int prontuario) {
    for (int i = 0; i < qtd; i++) {
        if (lista[i].prontuario == prontuario) {
            return true;
        }
    }
    return false;
}

void incluir(Funcionario lista[], int &qtd) {
    if (qtd >= MAX_FUNCIONARIOS) {
        cout << "Limite de funcionários atingido.\n";
        return;
    }

    Funcionario novo;
    cout << "Digite o prontuário: ";
    cin >> novo.prontuario;

    if (prontuarioExiste(lista, qtd, novo.prontuario)) {
        cout << "Erro: prontuário já cadastrado.\n";
        return;
    }

    cin.ignore(); // Limpar buffer do teclado
    cout << "Digite o nome: ";
    getline(cin, novo.nome);
    cout << "Digite o salário: ";
    cin >> novo.salario;

    lista[qtd] = novo;
    qtd++;
    cout << "Funcionário incluído com sucesso!\n";
}

void excluir(Funcionario lista[], int &qtd) {
    int prontuario;
    cout << "Digite o prontuário do funcionário a excluir: ";
    cin >> prontuario;

    for (int i = 0; i < qtd; i++) {
        if (lista[i].prontuario == prontuario) {
            for (int j = i; j < qtd - 1; j++) {
                lista[j] = lista[j + 1];
            }
            qtd--;
            cout << "Funcionário excluído com sucesso.\n";
            return;
        }
    }
    cout << "Funcionário não encontrado.\n";
}

void pesquisar(Funcionario lista[], int qtd) {
    int prontuario;
    cout << "Digite o prontuário do funcionário a pesquisar: ";
    cin >> prontuario;

    for (int i = 0; i < qtd; i++) {
        if (lista[i].prontuario == prontuario) {
            cout << "Nome: " << lista[i].nome << endl;
            cout << "Salário: R$ " << lista[i].salario << endl;
            return;
        }
    }
    cout << "Funcionário não encontrado.\n";
}

void listar(Funcionario lista[], int qtd) {
    if (qtd == 0) {
        cout << "Nenhum funcionário cadastrado.\n";
        return;
    }

    double totalSalarios = 0;
    for (int i = 0; i < qtd; i++) {
        cout << "Prontuário: " << lista[i].prontuario << endl;
        cout << "Nome: " << lista[i].nome << endl;
        cout << "Salário: R$ " << lista[i].salario << endl;
        cout << "-----------------------\n";
        totalSalarios += lista[i].salario;
    }

    cout << "Total de salários: R$ " << totalSalarios << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    SetConsoleOutputCP(CP_UTF8); 

    Funcionario lista[MAX_FUNCIONARIOS];
    int qtd = 0;
    int opcao;

    do {
        cout << "\nMENU:\n";
        cout << "0 - Sair\n";
        cout << "1 - Incluir\n";
        cout << "2 - Excluir\n";
        cout << "3 - Pesquisar\n";
        cout << "4 - Listar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando o programa...\n";
                break;
            case 1:
                incluir(lista, qtd);
                break;
            case 2:
                excluir(lista, qtd);
                break;
            case 3:
                pesquisar(lista, qtd);
                break;
            case 4:
                listar(lista, qtd);
                break;
            default:
                cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}
