#include <iostream>
#include <string>
using namespace std;

// Estrutura do nó para fila com ponteiros
struct No {
    int senha;
    No* prox;
};

// Fila dinâmica (ponteiro)
struct Fila {
    No* inicio;
    No* fim;
};

// Inicializar fila dinâmica
void inicializarFila(Fila &f) {
    f.inicio = NULL;
    f.fim = NULL;
}

// Verifica se a fila está vazia
bool filaVazia(Fila &f) {
    return f.inicio == NULL;
}

// Enfileirar senha na fila de senhas geradas
void enfileirar(Fila &f, int senha) {
    No* novo = new No;
    novo->senha = senha;
    novo->prox = NULL;

    if (filaVazia(f)) {
        f.inicio = novo;
    } else {
        f.fim->prox = novo;
    }
    f.fim = novo;
}

// Desenfileirar senha (para atendimento)
int desenfileirar(Fila &f) {
    if (filaVazia(f)) {
        cout << "Fila vazia!" << endl;
        return -1;
    }
    No* temp = f.inicio;
    int senha = temp->senha;
    f.inicio = temp->prox;
    delete temp;
    if (f.inicio == NULL) f.fim = NULL;
    return senha;
}

// Vetor fixo para senhas atendidas
const int TAM_MAX = 1000;
int senhasAtendidas[TAM_MAX];
int atendidas = 0;

// Função para exibir menu
void exibirMenu(int aguardando) {
    cout << "\n==== MENU DE ATENDIMENTO ====" << endl;
    cout << "0 - Sair" << endl;
    cout << "1 - Gerar senha" << endl;
    cout << "2 - Realizar atendimento" << endl;
    cout << "Senhas na fila: " << aguardando << endl;
    cout << "Escolha uma opcao: ";
}


int main() {
    Fila senhasGeradas;
    inicializarFila(senhasGeradas);

    int senhaAtual = 1;
    int opcao;

    do {
        int aguardando = filaVazia(senhasGeradas) ? 0 : 1;
        exibirMenu(aguardando);
        cin >> opcao;

        switch (opcao) {
            case 1:
                enfileirar(senhasGeradas, senhaAtual);
                cout << "Senha " << senhaAtual << " gerada com sucesso!" << endl;
                senhaAtual++;
                break;

            case 2:
                if (!filaVazia(senhasGeradas)) {
                    int senha = desenfileirar(senhasGeradas);
                    cout << "Atendendo senha: " << senha << endl;
                    if (atendidas < TAM_MAX) {
                        senhasAtendidas[atendidas++] = senha;
                    } else {
                        cout << "Erro: limite de senhas atendidas atingido." << endl;
                    }
                } else {
                    cout << "Nenhuma senha aguardando atendimento." << endl;
                }
                break;

            case 0:
                if (!filaVazia(senhasGeradas)) {
                    cout << "Ainda há senhas aguardando. Atenda todas antes de sair." << endl;
                    opcao = -1; // Força repetição
                } else {
                    cout << "Encerrando sistema." << endl;
                    cout << "Total de senhas atendidas: " << atendidas << endl;
                }
                break;

            default:
                cout << "Opção inválida." << endl;
        }

    } while (opcao != 0);

    return 0;
}
