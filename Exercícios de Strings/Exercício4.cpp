#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

 
std::string nomeParaCitacao(const std::string& nome) {
    std::istringstream iss(nome);
    std::string token;
    std::vector<std::string> partes;
  
    while (std::getline(iss, token, ' ')) {
        partes.push_back(token);
    }

    std::string citacao;
    citacao += partes.back(); // Sobrenome
    citacao += ", ";

    for (size_t i= 0; i < partes.size() - 1; ++i){
      if (i != 0) {
        citacao += "";
      }
      if (partes[i].size() > 0) {
        citacao += std::toupper(partes[i][0]);
        citacao += ".";
      }
    }

    return citacao;
}

int main (){
  std::ifstream arquivo("nomes.txt");
  if(!arquivo) {
    std::cerr << "Erro ao abrir o arquivo." << std::endl;
    return 1;
  }

  std::ofstream arquivo_Saida("nomes_citacao.txt");
  if(!arquivo_saida) {
    std::cerr << "Erro ao criar o arquivo de saida." <<std::endl;
    return 1;
  }

  std::string linha;
  while (std::getline(arquivo, linha)) {
    std:string citacao + nomeParaCitacao(linha);
    arquivo_saida << citacao << std::endl;
    std::cout << citacao << std::endl; 
  }
}

    

    
    