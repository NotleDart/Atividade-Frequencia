#ifndef LIVRO_H
#define LIVRO_H
#include <string>

class Livro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    bool disponivel;

public:
    Livro(std::string titulo, std::string autor, std::string isbn);
    std::string getIsbn() const;
    void setIsbn(std::string i);
    std::string getTitulo() const;
    void setTitulo(std::string t);
    std::string getAutor() const;
    void setAutor(std::string a);
    bool isDisponivel() const;
    void setDisponivel(bool d);

    void emprestar();  // ADICIONADO: método do diagrama UML
    void devolver();   // ADICIONADO: método do diagrama UML
    void exibirInfo() const; // ADICIONADO: declaração que faltava no .h
};

#endif
