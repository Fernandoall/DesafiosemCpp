#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

// Função para converter um nome para o formato de citação bibliográfica
std::string nomeParaCitacao(const std::string& nome) {
    std::istringstream iss(nome);
    std::string token;
    std::vector<std::string> partes;
    
    // Separar o nome em partes (por espaços)
    while (std::getline(iss, token, ' ')) {
        partes.push_back(token);
    }
    
    // Construir a citação bibliográfica
    std::string citacao;
    citacao += partes.back(); // Sobrenome
    citacao += ", ";
    
    // Adicionar as iniciais dos outros nomes
    for (size_t i = 0; i < partes.size() - 1; ++i) {
        if (i != 0) {
            citacao += " ";
        }
        if (partes[i].size() > 0) {
            citacao += std::toupper(partes[i][0]);
            citacao += ".";
        }
    }
    
    return citacao;
}

int main() {
    std::ifstream arquivo("nomes.txt");
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }
    
    std::ofstream arquivo_saida("nomes_citacao.txt");
    if (!arquivo_saida) {
        std::cerr << "Erro ao criar o arquivo de saída." << std::endl;
        return 1;
    }
    
    std::string linha;
    while (std::getline(arquivo, linha)) {
        // Processar cada linha do arquivo
        std::string citacao = nomeParaCitacao(linha);
        arquivo_saida << citacao << std::endl;
        std::cout << citacao << std::endl; // Exibir na tela (opcional)
    }
    
    arquivo.close();
    arquivo_saida.close();
    
    return 0;
}
