#include <iostream>
#include "usuario.h"

Usuario::Usuario(std::string n, std::string c, int mat)
    : Pessoa(n, c), matricula(mat) {}

int Usuario::getMatricula() const {
    return matricula;
}

void Usuario::setMatricula(int mat) {
    matricula = mat;
}

// ADICIONADO: implementação de consultarLivros (UML)
// A lógica real de listagem fica no main, pois Usuario não possui
// referência ao acervo. Este método exibe uma mensagem orientadora.
void Usuario::consultarLivros() const {
    std::cout << "[Usuario " << nome << "] Solicitando consulta ao acervo..." << std::endl;
}

void Usuario::exibirInfo() const {
    Pessoa::exibirInfo();
    std::cout << "Matricula: " << matricula << std::endl;
    // CORRIGIDO: removido 'return 0' de função void
}
