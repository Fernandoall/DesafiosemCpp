#include <iostream>
#include <vector>
#include <algorithm>

struct Funcionario {
    int prontuario;
    std::string nome;
    double salario;
};

void incluirFuncionario(std::vector<Funcionario>& funcionarios) {
    Funcionario novoFuncionario;
    std::cout << "Digite o prontuario: ";
    std::cin >> novoFuncionario.prontuario;
    std::cout << "Digite o nome: ";
    std::cin.ignore(); // Limpar o buffer do teclado
    std::getline(std::cin, novoFuncionario.nome);
    std::cout << "Digite o salario: ";
    std::cin >> novoFuncionario.salario;

    // Verificar se já existe um funcionário com o mesmo prontuário
    for (const auto& funcionario : funcionarios) {
        if (funcionario.prontuario == novoFuncionario.prontuario) {
            std::cout << "Já existe um funcionário com o mesmo prontuário." << std::endl;
            return;
        }
    }

    funcionarios.push_back(novoFuncionario);
    std::cout << "Funcionário incluído com sucesso." << std::endl;
}
