#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#include <string>
#include "livro.h"
#include "usuario.h"

// Composição: Emprestimo possui referências a Livro e Usuario (UML: 1 para *)
class Emprestimo {
private:
    Livro* livro;                      // ponteiro — requisito do PDF
    Usuario* usuario;                  // ponteiro — requisito do PDF
    std::string dataEmprestimo;        // CORRIGIDO: UML define como string
    std::string dataPrevistaDevolucao; // CORRIGIDO: UML define como string

public:
    Emprestimo(Livro* l, Usuario* u,
               std::string dataEmp, std::string dataPrevDev);

    Livro*    getLivro()   const;
    Usuario*  getUsuario() const;
    std::string getDataEmprestimo()        const;
    std::string getDataPrevistaDevolucao() const;
    void setDataPrevistaDevolucao(std::string d);

    void registrar() const; // ADICIONADO: método do diagrama UML
    void exibirInfo() const;
};

#endif
