#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Estrutura para representar uma carta
struct Carta {
    int naipe;    // Naipe da carta (1-Copas / 2-Paus / 3-Ouro / 4-Espada)
    int numero;   // Número da carta (1-Ás / 13-Rei)
    int baralho;  // Baralho da carta (1 ou 2)
};

// Função para inicializar o baralho com 2 baralhos de 52 cartas cada
vector<Carta> inicializarBaralho() {
    vector<Carta> baralho;
    for (int b = 1; b <= 2; ++b) {
        for (int n = 1; n <= 4; ++n) {
            for (int num = 1; num <= 13; ++num) {
                Carta carta;
                carta.naipe = n;
                carta.numero = num;
                carta.baralho = b;
                baralho.push_back(carta);
            }
        }
    }
    return baralho;
}

// Função para embaralhar o baralho
void embaralhar(vector<Carta>& baralho) {
    srand(time(0)); // Use o tempo atual como semente para a função rand()
    for (int i = 0; i < baralho.size(); ++i) {
        int j = rand() % baralho.size();
        swap(baralho[i], baralho[j]);
    }
}

// Função para distribuir cartas para os jogadores
void distribuirCartas(const vector<Carta>& baralho, vector<vector<Carta> >& maos) { // Corrigindo a declaração de maos
    int cartaIndex = 0;
    for (int j = 0; j < 4; ++j) {
        for (int c = 0; c < 11; ++c) {
            maos[j].push_back(baralho[cartaIndex]);
            cartaIndex++;
        }
    }
}

// Função para imprimir as mãos dos jogadores
void imprimirMaos(const vector<vector<Carta> >& maos) { // Corrigindo a declaração de maos
    for (int j = 0; j < 4; ++j) {
        cout << "Mão do jogador " << j + 1 << ":" << endl;
        for (int c = 0; c < 11; ++c) {
            cout << maos[j][c].naipe << "-" << maos[j][c].numero << "-" << maos[j][c].baralho << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<Carta> baralho = inicializarBaralho();
    embaralhar(baralho);
    
    vector<vector<Carta> > maos(4, vector<Carta>(11)); // Corrigindo a declaração de maos

    distribuirCartas(baralho, maos);
    
    imprimirMaos(maos);
    
    return 0;
}
