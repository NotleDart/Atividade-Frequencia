#include <iostream>
#include "emprestimo.h"

Emprestimo::Emprestimo(Livro* l, Usuario* u,
                       std::string dataEmp, std::string dataPrevDev)
    : livro(l), usuario(u),
      dataEmprestimo(dataEmp), dataPrevistaDevolucao(dataPrevDev) {}

Livro* Emprestimo::getLivro() const {
    return livro;
}

Usuario* Emprestimo::getUsuario() const {
    return usuario;
}

std::string Emprestimo::getDataEmprestimo() const {
    return dataEmprestimo;
}

std::string Emprestimo::getDataPrevistaDevolucao() const {
    return dataPrevistaDevolucao;
}

void Emprestimo::setDataPrevistaDevolucao(std::string d) {
    dataPrevistaDevolucao = d;
    // CORRIGIDO: removido 'return 0' de função void
}

// ADICIONADO: registrar() — método do diagrama UML
void Emprestimo::registrar() const {
    std::cout << "Emprestimo registrado:" << std::endl;
    exibirInfo();
}

void Emprestimo::exibirInfo() const {
    std::cout << "  Livro:             " << livro->getTitulo()          << std::endl;
    std::cout << "  Usuario:           " << usuario->getNome()          << std::endl;
    std::cout << "  Data Emprestimo:   " << dataEmprestimo              << std::endl;
    std::cout << "  Prev. Devolucao:   " << dataPrevistaDevolucao       << std::endl;
}
