#include <cstdlib> 
#include <iostream>
#include <string>
#include <unistd.h> // Para usar a função usleep (sleep em microssegundos)

using namespace std;

int main() {
    // Passo 1: Receber a mensagem digitada pelo usuário
    cout << "Digite a mensagem: ";
    string mensagem;
    getline(cin, mensagem);
    
    // Passo 2: Centralizar a mensagem na linha 5 da tela
    int espacosAntes = (80 - mensagem.length()) / 2;
    for (int i = 0; i < espacosAntes; ++i) {
        cout << " ";
    }
    cout << mensagem << endl;

    // Passo 3: Fazer as letras "caírem" da linha 5 até a linha 20
    for (int linha = 6; linha <= 20; ++linha) {
        usleep(100000); // Aguarda 100.000 microssegundos (100ms)
        system("cls"); // Limpa a tela (funciona em sistemas UNIX-like)
        for (int i = 0; i < espacosAntes; ++i) {
            cout << " ";
        }
        cout << mensagem << endl;
        for (int i = 0; i < linha; ++i) {
            cout << endl;
        }
    }

    // Passo 4: Apresentar a mensagem completa na linha 20
    system("cls"); // Limpa a tela (funciona em sistemas UNIX-like)
    for (int i = 0; i < espacosAntes; ++i) {
        cout << " ";
    }
    cout << mensagem << endl;
    return 0;
}
