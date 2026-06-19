#ifndef BIBLIOTECARIO_H
#define BIBLIOTECARIO_H
#include "pessoa.h"

class Bibliotecario : public Pessoa {
private:
    int codigoFuncionario;  // CORRIGIDO: UML usa 'codigoFuncionario : int'

public:
    Bibliotecario(std::string n, std::string c, int cod);
    int getCodigoFuncionario() const;
    void setCodigoFuncionario(int cod);
    void cadastrarLivro() const;    // ADICIONADO: método do diagrama UML
    void realizarEmprestimo() const; // ADICIONADO: método do diagrama UML
    void exibirInfo() const override;
};

#endif
