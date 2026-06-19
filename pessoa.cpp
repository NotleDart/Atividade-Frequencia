#include <iostream>
#include "pessoa.h"

Pessoa::Pessoa(std::string n, std::string c) : nome(n), cpf(c) {}

std::string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setNome(std::string n) {
    nome = n;
}

std::string Pessoa::getCpf() const {
    return cpf;
}

void Pessoa::setCpf(std::string c) {
    cpf = c;
}

void Pessoa::exibirInfo() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "CPF:  " << cpf  << std::endl;
    // CORRIGIDO: removido 'return 0' de função void
}
