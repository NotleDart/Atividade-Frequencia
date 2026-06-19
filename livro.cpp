#include <iostream>
#include "livro.h"

Livro::Livro(std::string t, std::string a, std::string i)
    : titulo(t), autor(a), isbn(i), disponivel(true) {}

std::string Livro::getIsbn() const { return isbn; }
void Livro::setIsbn(std::string i) { isbn = i; }

std::string Livro::getTitulo() const { return titulo; }
void Livro::setTitulo(std::string t) { titulo = t; }

std::string Livro::getAutor() const { return autor; }
void Livro::setAutor(std::string a) { autor = a; }

bool Livro::isDisponivel() const { return disponivel; }
void Livro::setDisponivel(bool d) { disponivel = d; }

// ADICIONADO: emprestar() — método do diagrama UML
void Livro::emprestar() {
    if (disponivel) {
        disponivel = false;
        std::cout << "Livro \"" << titulo << "\" emprestado com sucesso." << std::endl;
    } else {
        std::cout << "Livro \"" << titulo << "\" nao esta disponivel para emprestimo." << std::endl;
    }
}

// ADICIONADO: devolver() — método do diagrama UML
void Livro::devolver() {
    disponivel = true;
    std::cout << "Livro \"" << titulo << "\" devolvido com sucesso." << std::endl;
}

// CORRIGIDO: agora declarado no .h; removido 'return 0' de função void
void Livro::exibirInfo() const {
    std::cout << "Titulo:     " << titulo << std::endl;
    std::cout << "Autor:      " << autor  << std::endl;
    std::cout << "ISBN:       " << isbn   << std::endl;
    std::cout << "Disponivel: " << (disponivel ? "Sim" : "Nao") << std::endl;
}
