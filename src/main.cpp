#include "controleestoque.hpp"
#include <iostream>
#include <string>
#include <limits>

#ifdef _WIN32
#include <windows.h> // Necessário para as funções de console do Windows
#endif

int main() {

#ifdef _WIN32
    SetConsoleCP(CP_UTF8);        // Define a página de código de entrada do console para UTF-8
    SetConsoleOutputCP(CP_UTF8); // Define a página de código de saída do console para UTF-8
#endif
    ControleEstoque estoque; // A criação do objeto estoque deve vir depois da configuração do console
    int opcao;

    do {
        // 1. Exibe o menu de opções para o usuário
        std::cout << "\n===== SISTEMA DE ESTOQUE =====\n";
        std::cout << "1 - Adicionar produto\n";
        std::cout << "2 - Listar produtos\n";
        std::cout << "3 - Atualizar quantidade\n";
        std::cout << "4 - Remover produto\n";
        std::cout << "5 - Buscar produtos\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha uma opcao: ";

        // 2. Lê a opção do usuário e valida se é um número
        while (!(std::cin >> opcao)) {
            std::cout << "Opção inválida. Por favor, digite um número: ";
            std::cin.clear(); // Limpa o estado de erro do std::cin
            // Descarta a entrada inválida que ficou no buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // 3. Executa a ação com base na opção escolhida
        switch (opcao) {
            case 1: {
                int codigo;
                std::string nome;
                double preco;
                int quantidade;
                
                std::cout << "Digite o código do produto: ";
                while (!(std::cin >> codigo)) {
                    std::cout << "Entrada inválida. Digite um número para o código: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer para o getline
                
                std::cout << "Digite o nome do produto: ";
                std::getline(std::cin, nome);

                std::cout << "Digite o preço do produto: R$ ";
                while (!(std::cin >> preco)) {
                    std::cout << "Entrada inválida. Digite um número para o preço: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                std::cout << "Digite a quantidade do produto: ";
                while (!(std::cin >> quantidade)) {
                    std::cout << "Entrada inválida. Digite um número para a quantidade: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                estoque.adicionarProduto(codigo, nome, preco, quantidade);
                break;
            }
            case 2:
                estoque.listarProdutos();
                break;
            case 3: {
                int codigo, novaQuantidade;
                std::cout << "Digite o código do produto: ";
                while (!(std::cin >> codigo)) {
                    std::cout << "Entrada inválida. Digite um número para o código: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                std::cout << "Digite a nova quantidade: ";
                while (!(std::cin >> novaQuantidade)) {
                    std::cout << "Entrada inválida. Digite um número para a quantidade: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                estoque.atualizarQuantidade(codigo, novaQuantidade);
                break;
            }
            case 4: {
                int codigo;
                std::cout << "Digite o código do produto a ser removido: ";
                while (!(std::cin >> codigo)) {
                    std::cout << "Entrada inválida. Digite um número para o código: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                estoque.removerProduto(codigo);
                break;
            }
            case 5: {
                int codigo;
                std::cout << "Digite o código do produto que deseja buscar: ";
                while (!(std::cin >> codigo)) {
                    std::cout << "Entrada inválida. Digite um número para o código: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                estoque.buscarProduto(codigo);
                break;
            }
            case 0:
                std::cout << "Encerrando o sistema...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }

    } while (opcao != 0);


    return 0;
}