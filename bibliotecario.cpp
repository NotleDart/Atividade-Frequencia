#include <iostream>
#include "bibliotecario.h"

Bibliotecario::Bibliotecario(std::string n, std::string c, int cod)
    : Pessoa(n, c), codigoFuncionario(cod) {}

int Bibliotecario::getCodigoFuncionario() const {
    return codigoFuncionario;
}

void Bibliotecario::setCodigoFuncionario(int cod) {
    codigoFuncionario = cod;
}


void Bibliotecario::cadastrarLivro() const {
    std::cout <<"] Iniciando cadastro de livro..." << std::endl;
}

void Bibliotecario::realizarEmprestimo() const {
    std::cout << "[Bibliotecario " << nome << "Iniciando registro de emprestimo..." << std::endl;
}

void Bibliotecario::exibirInfo() const {
    Pessoa::exibirInfo();
    std::cout << "Codigo Funcionario: " << codigoFuncionario << std::endl;
}
