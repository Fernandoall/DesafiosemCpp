#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int NUM_FILEIRAS = 15;
const int POLTRONAS_POR_FILEIRA = 40;

// Estrutura para representar uma poltrona
struct Poltrona {
    bool ocupada;
};

// Classe para representar o Teatro
class Teatro {
private:
    vector<vector<Poltrona>> lugares;

public:
    // Construtor
    Teatro() {
        lugares.resize(NUM_FILEIRAS, vector<Poltrona>(POLTRONAS_POR_FILEIRA, {false}));
    }

    // Método para reservar uma poltrona
    void reservarPoltrona(int fileira, int poltrona) {
        if (fileira < 1 || fileira > NUM_FILEIRAS || poltrona < 1 || poltrona > POLTRONAS_POR_FILEIRA) {
            cout << "Poltrona inválida!" << endl;
            return;
        }

        if (lugares[fileira - 1][poltrona - 1].ocupada) {
            cout << "Poltrona ocupada!" << endl;
        } else {
            lugares[fileira - 1][poltrona - 1].ocupada = true;
            cout << "Poltrona reservada com sucesso!" << endl;
        }
    }

    // Método para exibir o mapa de ocupação
    void exibirMapaOcupacao() {
        cout << "Mapa de ocupação:" << endl;
        for (int i = 0; i < NUM_FILEIRAS; ++i) {
            for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
                cout << (lugares[i][j].ocupada ? '#' : '.') << " ";
            }
            cout << endl;
        }
    }

    // Método para calcular o faturamento
    void calcularFaturamento() {
        int qtdeOcupados = 0;
        float valorTotal = 0.0;

        for (int i = 0; i < NUM_FILEIRAS; ++i) {
            for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
                if (lugares[i][j].ocupada) {
                    qtdeOcupados++;
                    if (i < 5) {
                        valorTotal += 50.0;
                    } else if (i < 10) {
                        valorTotal += 30.0;
                    } else {
                        valorTotal += 15.0;
                    }
                }
            }
        }

        cout << "Quantidade de lugares ocupados: " << qtdeOcupados << endl;
        cout << fixed << setprecision(2);
        cout << "Valor da bilheteria: R$ " << valorTotal << endl;
    }
};

int main() {
    Teatro teatro;

    int opcao;
    do {
        cout << "\nSelecione uma opção:" << endl;
        cout << "0. Finalizar" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mapa de ocupação" << endl;
        cout << "3. Faturamento" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int fileira, poltrona;
                cout << "Informe a fileira e a poltrona desejadas: ";
                cin >> fileira >> poltrona;
                teatro.reservarPoltrona(fileira, poltrona);
                break;
            }
            case 2:
                teatro.exibirMapaOcupacao();
                break;
            case 3:
                teatro.calcularFaturamento();
                break;
            case 0:
                cout << "Finalizando o programa." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}
