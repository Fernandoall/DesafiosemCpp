#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // Para usar a função transform

using namespace std;

// Função para reorganizar o nome no formato de agenda telefônica
string transformarNome(const string& nome) {
    // Copiar o nome para evitar alterar o original
    string nomeFormatado = nome;

    // Encontrar o último espaço (separador entre o último sobrenome e o primeiro nome)
    size_t posUltimoEspaco = nomeFormatado.find_last_of(" ");
    
    // Reorganizar o nome
    if (posUltimoEspaco != string::npos) {
        // Extrair último sobrenome
        string ultimoSobrenome = nomeFormatado.substr(posUltimoEspaco + 1);
        
        // Remover o último sobrenome do nome original
        nomeFormatado.erase(posUltimoEspaco);
        
        // Adicionar o último sobrenome seguido de uma vírgula e um espaço
        nomeFormatado = ultimoSobrenome + ", " + nomeFormatado;
    }
    
    return nomeFormatado;
}

