#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "pessoa.h"
#include "usuario.h"
#include "bibliotecario.h"
#include "livro.h"
#include "emprestimo.h"


void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void cabecalho(const std::string& titulo) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << titulo                              << std::endl;
    std::cout << "========================================" << std::endl;
}

void cadastrarLivro(std::vector<Livro>& livros, const Bibliotecario& bib) {
    cabecalho("Cadastrar Livro");
    bib.cadastrarLivro();

    std::string titulo, autor, isbn;
    std::cin.ignore();
    std::cout << "Titulo: ";   std::getline(std::cin, titulo);
    std::cout << "Autor:  ";   std::getline(std::cin, autor);
    std::cout << "ISBN:   ";   std::getline(std::cin, isbn);

    for (const Livro& l : livros) {
        if (l.getIsbn() == isbn) {
            std::cout << "\nErro: ja existe um livro cadastrado com o ISBN \"" << isbn << "\"." << std::endl;
            pausar();
            return;
        }
        if (l.getTitulo() == titulo && l.getAutor() == autor) {
            std::cout << "\nErro: ja existe um livro com o titulo \"" << titulo
                      << "\" do autor \"" << autor << "\" cadastrado." << std::endl;
            pausar();
            return;
        }
    }

    livros.emplace_back(titulo, autor, isbn);
    std::cout << "\nLivro cadastrado com sucesso!" << std::endl;
    pausar();
}

void cadastrarUsuario(std::vector<Usuario>& usuarios) {
    cabecalho("Cadastrar Usuario");

    std::string nome, cpf;
    int matricula;
    std::cin.ignore();
    std::cout << "Nome:      ";  std::getline(std::cin, nome);
    std::cout << "CPF:       ";  std::getline(std::cin, cpf);
    std::cout << "Matricula: ";  std::cin >> matricula;

    usuarios.emplace_back(nome, cpf, matricula);
    std::cout << "\nUsuario cadastrado com sucesso!" << std::endl;
    pausar();
}

void realizarEmprestimo(std::vector<Livro>& livros,
                        std::vector<Usuario>& usuarios,
                        std::vector<Emprestimo>& emprestimos,
                        const Bibliotecario& bib) {
    cabecalho("Realizar Emprestimo");
    bib.realizarEmprestimo();

    if (livros.empty()) {
        std::cout << "Nenhum livro cadastrado." << std::endl;
        pausar(); return;
    }
    if (usuarios.empty()) {
        std::cout << "Nenhum usuario cadastrado." << std::endl;
        pausar(); return;
    }

    std::cout << "\nLivros disponiveis:" << std::endl;
    bool algumDisponivel = false;
    for (int i = 0; i < (int)livros.size(); i++) {
        if (livros[i].isDisponivel()) {
            std::cout << "  [" << i << "] " << livros[i].getTitulo()
                      << " - " << livros[i].getAutor() << std::endl;
            algumDisponivel = true;
        }
    }
    if (!algumDisponivel) {
        std::cout << "Nenhum livro disponivel no momento." << std::endl;
        pausar(); return;
    }

    int idxLivro;
    std::cout << "Escolha o numero do livro: ";
    std::cin >> idxLivro;
    if (idxLivro < 0 || idxLivro >= (int)livros.size() || !livros[idxLivro].isDisponivel()) {
        std::cout << "Opcao invalida." << std::endl;
        pausar(); return;
    }

    
    std::cout << "\nUsuarios cadastrados:" << std::endl;
    for (int i = 0; i < (int)usuarios.size(); i++) {
        std::cout << "  [" << i << "] " << usuarios[i].getNome()
                  << " (Matricula: " << usuarios[i].getMatricula() << ")" << std::endl;
    }
    int idxUsuario;
    std::cout << "Escolha o numero do usuario: ";
    std::cin >> idxUsuario;
    if (idxUsuario < 0 || idxUsuario >= (int)usuarios.size()) {
        std::cout << "Opcao invalida." << std::endl;
        pausar(); return;
    }

    std::string dataEmp, dataPrev;
    std::cin.ignore();
    std::cout << "Data do emprestimo (dd/mm/aaaa): ";  std::getline(std::cin, dataEmp);
    std::cout << "Data prevista de devolucao (dd/mm/aaaa): "; std::getline(std::cin, dataPrev);

    livros[idxLivro].emprestar();

    emprestimos.emplace_back(&livros[idxLivro], &usuarios[idxUsuario], dataEmp, dataPrev);

    emprestimos.back().registrar();
    pausar();
}

void realizarDevolucao(std::vector<Emprestimo>& emprestimos) {
    cabecalho("Realizar Devolucao");

    std::vector<int> abertos;
    for (int i = 0; i < (int)emprestimos.size(); i++) {
        if (!emprestimos[i].getLivro()->isDisponivel()) {
            abertos.push_back(i);
        }
    }

    if (abertos.empty()) {
        std::cout << "Nenhum emprestimo em aberto." << std::endl;
        pausar(); return;
    }

    std::cout << "\nEmprestimos em aberto:" << std::endl;
    for (int i = 0; i < (int)abertos.size(); i++) {
        const Emprestimo& e = emprestimos[abertos[i]];
        std::cout << "  [" << i << "] Livro: " << e.getLivro()->getTitulo()
                  << " | Usuario: " << e.getUsuario()->getNome()
                  << " | Prev. dev.: " << e.getDataPrevistaDevolucao() << std::endl;
    }

    int escolha;
    std::cout << "Escolha o emprestimo para devolucao: ";
    std::cin >> escolha;
    if (escolha < 0 || escolha >= (int)abertos.size()) {
        std::cout << "Opcao invalida." << std::endl;
        pausar(); return;
    }

    emprestimos[abertos[escolha]].getLivro()->devolver();
    pausar();
}

void consultarLivros(const std::vector<Livro>& livros, const Usuario& u) {
    cabecalho("Consultar Livros");
    u.consultarLivros();

    if (livros.empty()) {
        std::cout << "Nenhum livro no acervo." << std::endl;
        pausar(); return;
    }

    std::cout << "\nAcervo completo:" << std::endl;
    for (int i = 0; i < (int)livros.size(); i++) {
        std::cout << "\n[" << i + 1 << "]" << std::endl;
        livros[i].exibirInfo();
    }
    pausar();
}

int main() {
    std::vector<Livro>        livros;
    std::vector<Usuario>      usuarios;
    std::vector<Bibliotecario> bibliotecarios;
    std::vector<Emprestimo>   emprestimos;

    bibliotecarios.emplace_back("Bibliotecario", "000.000.000-00", 1);

    int opcao;
    do {
        limparTela();
        cabecalho("Sistema de Biblioteca - UESPI");
        std::cout << "\n  [1] Cadastrar Livro"      << std::endl;
        std::cout << "  [2] Cadastrar Usuario"     << std::endl;
        std::cout << "  [3] Realizar Emprestimo"   << std::endl;
        std::cout << "  [4] Realizar Devolucao"    << std::endl;
        std::cout << "  [5] Consultar Livros"      << std::endl;
        std::cout << "  [6] Listar Usuarios"       << std::endl;
        std::cout << "  [7] Listar Emprestimos"    << std::endl;
        std::cout << "  [0] Sair"                  << std::endl;
        std::cout << "\nEscolha: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarLivro(livros, bibliotecarios[0]);
                break;

            case 2:
                cadastrarUsuario(usuarios);
                break;

            case 3:
                realizarEmprestimo(livros, usuarios, emprestimos, bibliotecarios[0]);
                break;

            case 4:
                realizarDevolucao(emprestimos);
                break;

            case 5:
                if (!usuarios.empty())
                    consultarLivros(livros, usuarios[0]);
                else
                    std::cout << "E necessario um usuario cadastrado para a consulta." << std::endl;
                

            case 6: {
                cabecalho("Usuarios Cadastrados");
                if (usuarios.empty()) {
                    std::cout << "Nenhum usuario." << std::endl;
                } else {
                    for (auto& u : usuarios) {
                        u.exibirInfo();
                        std::cout << std::endl;
                    }
                }
                pausar();
                break;
            }

            case 7: {
                cabecalho("Emprestimos Registrados");
                if (emprestimos.empty()) {
                    std::cout << "Nenhum emprestimo registrado." << std::endl;
                } else {
                    for (int i = 0; i < (int)emprestimos.size(); i++) {
                        std::cout << "\n[" << i + 1 << "]" << std::endl;
                        emprestimos[i].exibirInfo();
                        std::cout << "  Status: "
                                  << (emprestimos[i].getLivro()->isDisponivel()
                                      ? "Devolvido" : "Em aberto")
                                  << std::endl;
                    }
                }
                pausar();
                break;
            }

            case 0:
                std::cout << "\nEncerrando o sistema. Ate logo!" << std::endl;
                break;

            default:
                std::cout << "Opcao invalida." << std::endl;
                pausar();
        }
    } while (opcao != 0);

    return 0;
}
