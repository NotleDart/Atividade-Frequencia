# Sistema de Biblioteca em C++

## Sobre o Projeto

Este projeto consiste em um sistema de gerenciamento de biblioteca desenvolvido na linguagem C++, utilizando os principais conceitos de Programação Orientada a Objetos (POO). O objetivo é simular o funcionamento básico de uma biblioteca, permitindo o cadastro e gerenciamento de livros, usuários e empréstimos.

O trabalho foi desenvolvido como atividade acadêmica para praticar conceitos fundamentais da orientação a objetos, como herança, encapsulamento, polimorfismo e composição.

---

## Funcionalidades

O sistema oferece as seguintes funcionalidades:

* Cadastro de livros.
* Cadastro de usuários.
* Visualização do acervo.
* Realização de empréstimos.
* Registro de devoluções.
* Controle de disponibilidade dos livros.
* Consulta de informações dos usuários e empréstimos.

---

## Conceitos de Programação Orientada a Objetos Utilizados

### Encapsulamento

Os atributos das classes são protegidos e acessados por meio de métodos específicos, garantindo maior segurança e organização do código.

### Herança

A classe `Pessoa` serve como classe base para outras classes do sistema, permitindo reutilização de código e melhor organização.

### Polimorfismo

Métodos virtuais são utilizados para permitir comportamentos diferentes em classes derivadas.

### Composição

A relação entre livros, usuários e empréstimos é implementada através da composição de objetos.

---

## Estrutura do Sistema

O sistema é composto pelas seguintes classes:

### Pessoa

Classe base contendo informações comuns como nome e CPF.

### Usuario

Representa os usuários da biblioteca e herda características da classe Pessoa.

### Bibliotecario

Responsável pelas operações administrativas da biblioteca.

### Livro

Armazena informações sobre os livros disponíveis no acervo.

### Emprestimo

Gerencia os empréstimos realizados pelos usuários.

---

## Tecnologias Utilizadas

* C++
* Programação Orientada a Objetos (POO)
* Biblioteca STL (`vector`, `string`, entre outras)

---

## Como Compilar

Utilizando o compilador g++:

```bash
g++ *.cpp -o biblioteca
```

---

## Como Executar

No Linux:

```bash
./biblioteca
```

No Windows:

```bash
biblioteca.exe
```

---

## Exemplo de Uso

1. Cadastrar um livro.
2. Cadastrar um usuário.
3. Realizar um empréstimo.
4. Consultar os livros disponíveis.
5. Registrar a devolução do livro.

---

## Autor

**Elton Junior**

Estudante de Ciência da Computação.

---

## Considerações Finais

Este projeto foi desenvolvido com fins educacionais para reforçar os conhecimentos adquiridos na disciplina de Programação Orientada a Objetos. A implementação demonstra a aplicação prática dos conceitos estudados em sala de aula por meio de um sistema simples de gerenciamento de biblioteca.
