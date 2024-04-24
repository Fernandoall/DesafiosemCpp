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
    