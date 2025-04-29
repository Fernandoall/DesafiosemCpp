#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // Para usar a função transform

using namespace std;

// Função para reorganizar o nome no formato de agenda telefônica
string transformarNome(const string& nome) {
    // Copiando o nome para evitar alterar o original
    string nomeFormatado = nome;

    // Encontrando o último espaço (separador entre o último sobrenome e o primeiro nome)
    size_t posUltimoEspaco = nomeFormatado.find_last_of(" ");
    
    // Reorganizando nome
    if (posUltimoEspaco != string::npos) {
        // Extraindo último sobrenome
        string ultimoSobrenome = nomeFormatado.substr(posUltimoEspaco + 1);
        
        // Removendo o último sobrenome do nome original
        nomeFormatado.erase(posUltimoEspaco);
        
        // Adicionando o último sobrenome seguido de uma vírgula e um espaço
        nomeFormatado = ultimoSobrenome + ", " + nomeFormatado;
    }
    
    return nomeFormatado;
}

int main() {
    // Importando o arquivo nome.txt salvo no diretório da aplicação
    ifstream arquivoEntrada("nomes.txt");
    if (!arquivoEntrada) {
        cerr << "Erro ao abrir o arquivo de entrada." << endl;
        return 1;
    }

    // Abrir o arquivo de saída para escrever os nomes no formato de agenda telefônica
    ofstream arquivoSaida("nomes_agenda.txt");
    if (!arquivoSaida) {
        cerr << "Erro ao abrir o arquivo de saída." << endl;
        return 1;
    }

    // Processando cada nome no arquivo de entrada
    string nome;
    while (getline(arquivoEntrada, nome)) {
        // Transformando o nome para o formato de agenda telefônica
        string nomeFormatado = transformarNome(nome);

        // Escrevendo o nome no arquivo de saída
        arquivoSaida << nomeFormatado << endl;
    }   

    // Fechar os arquivos
    arquivoEntrada.close();
    arquivoSaida.close();

    cout << "Nomes transformados com sucesso!" << endl;

    return 0;

}

