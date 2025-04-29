#include <iostream>
#include <string>
#include <windows.h> // Biblioteca para manipula��o da tela no Windows

using namespace std;

// Fun��o para centralizar a mensagem na linha 5
void centralizarMensagem(string mensagem) {
    // Obt�m a largura da tela
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int larguraTela;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    larguraTela = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    
    // Calcula o espa�o em branco para centralizar a mensagem
    int espacoBranco = (larguraTela - mensagem.length()) / 2;
    
    // Imprime o espa�o em branco antes da mensagem
    for (int i = 0; i < espacoBranco; i++) {
        cout << " ";
    }
    
    // Imprime a mensagem
    cout << mensagem << endl;
}

// Fun��o para simular a cascata das letras
void cascataMensagem(string mensagem) {
    // Imprime as letras da mensagem uma por uma com um pequeno atraso
    for (int linha = 6; linha <= 20; linha++) {
        system("cls"); // Limpa a tela
        centralizarMensagem(mensagem); // Imprime a mensagem centralizada na nova linha
        
        // Imprime espa�os em branco para deslocar a pr�xima letra para baixo
        for (int i = 0; i < linha - 5; i++) {
            cout << endl;
        }
        
        // Aguarda um pequeno atraso para criar o efeito de cascata
        Sleep(200); // Atraso de 200 milissegundos
    }
}

int main() {
    string mensagem;
    
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);
    
    system("cls"); // Limpa a tela antes de come�ar a cascata
    centralizarMensagem(mensagem); // Imprime a mensagem centralizada na linha 5
    
    cascataMensagem(mensagem); // Simula a cascata das letras
    
    return 0;
}
