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

    
    