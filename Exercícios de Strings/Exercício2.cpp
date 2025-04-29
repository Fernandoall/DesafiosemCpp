#include <iostream>
#include <string>
#include <algorithm> // Para usar a função transform

using namespace std;

// Função para remover os espaços de uma string
string removerEspacos(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

// Função para verificar se uma string é um palíndromo
bool ehPalindromo(string str) {
    // Remover os espaços da string
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 

    int inicio = 0;
    int fim = str.length() - 1;

    while (inicio < fim) {
        if (str[inicio] != str[fim]) {
            return false;
        }
        inicio++;
        fim--;
    }
    return true;
}

int main() {
    // Passo 1: Receber a mensagem digitada pelo usuário
    cout << "Digite a mensagem: ";
    string mensagem;
    getline(cin, mensagem);

    // Passo 2: Remover os espaços da mensagem
    mensagem = removerEspacos(mensagem);

    // Passo 3: Verificar se a mensagem é um palíndromo
    bool palindromo = ehPalindromo(mensagem);

    // Passo 4: Informar o resultado ao usuário
    if (palindromo) {
        cout << "A mensagem digitada e um palindromo." << endl;
    } else {
        cout << "A mensagem digitada nao e um palindromo." << endl;
    }

    return 0;
}
 

 // A função ehPalindromo não está considerando letras em caixa alta, portanto se a frase
 // iniciar com letra maiscula, ele não irá reconhece como Palindromo, a exemplo de:
 // Ame o poema, nesse caso não seria considerado um Palindromo. 