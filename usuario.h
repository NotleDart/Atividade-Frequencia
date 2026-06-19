#ifndef USUARIO_H
#define USUARIO_H
#include "pessoa.h"

class Usuario : public Pessoa {
private:
    int matricula;  // CORRIGIDO: UML define 'matricula : int', não 'idUsuario'

public:
    Usuario(std::string n, std::string c, int mat);
    int getMatricula() const;
    void setMatricula(int mat);
    void consultarLivros() const; // ADICIONADO: método do diagrama UML
    void exibirInfo() const override;
};

#endif
