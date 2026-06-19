#ifndef PESSOA_H
#define PESSOA_H
#include <string>

class Pessoa {
protected:
    std::string nome;
    std::string cpf;

public:
    Pessoa(std::string n, std::string c);
    virtual ~Pessoa() {}  // CORRIGIDO: remover ';' antes de '{}'
    std::string getNome() const;
    void setNome(std::string n);
    std::string getCpf() const;
    void setCpf(std::string c);
    virtual void exibirInfo() const;
};

#endif
