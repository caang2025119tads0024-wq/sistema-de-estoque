#include "controleestoque.hpp"
#include <iostream>
#include <iomanip>

ControleEstoque::ControleEstoque() {
    numProdutos = 0; // Inicializa o contador de produtos
}

// Adiciona um novo produto ao estoque
void ControleEstoque::adicionarProduto(int codigo, std::string nome, double preco, int quantidade) {
    // Verifica se o estoque está cheio
    if (numProdutos >= MAX_PRODUTOS) {
        std::cout << "Erro: Estoque cheio! Não é possível adicionar mais produtos." << std::endl;
        return;
    }

    // Verifica se já existe um produto com o mesmo código
    for (int i = 0; i < numProdutos; ++i) {
        if (produtos[i].codigo == codigo) {
            std::cout << "Erro: Já existe um produto com este código!" << std::endl;
            return;
        }
    }
    
    // Adiciona o novo produto na próxima posição livre
    produtos[numProdutos].codigo = codigo;
    produtos[numProdutos].nome = nome;
    produtos[numProdutos].preco = preco;
    produtos[numProdutos].quantidade = quantidade;
    numProdutos++; // Incrementa o contador de produtos

    std::cout << "Produto adicionado com sucesso!" << std::endl;
}

// Implementação do método para remover produto
bool ControleEstoque::removerProduto(int codigo) {
    int indiceParaRemover = -1;
    // Encontra o índice do produto a ser removido
    for (int i = 0; i < numProdutos; ++i) {
        if (produtos[i].codigo == codigo) {
            indiceParaRemover = i;
            break;
        }
    }

    if (indiceParaRemover != -1) {
        // Desloca os elementos para a esquerda para preencher o espaço
        for (int i = indiceParaRemover; i < numProdutos - 1; ++i) {
            produtos[i] = produtos[i + 1];
        }
        numProdutos--; // Decrementa o número de produtos
        std::cout << "Produto removido com sucesso!" << std::endl;
        return true;
    }
 
    std::cout << "Produto não encontrado!" << std::endl;
    return false;
}

// Implementação do método para atualizar quantidade
bool ControleEstoque::atualizarQuantidade(int codigo, int novaQuantidade) {
    for (int i = 0; i < numProdutos; ++i) {
        if (produtos[i].codigo == codigo) {
            produtos[i].quantidade = novaQuantidade;
            std::cout << "Quantidade atualizada com sucesso!" << std::endl;
            return true;
        }
    }
 
    std::cout << "Produto não encontrado!" << std::endl;
    return false;
}

// Implementação do método para listar produtos
void ControleEstoque::listarProdutos(){
    if (numProdutos == 0) {
        std::cout << "Não há produtos no estoque!" << std::endl;
        return;
    }
    
    std::cout << "\nLista de Produtos:\n";
    std::cout << std::left
              << std::setw(6) << "ID"
              << std::setw(20) << "Nome"
              << std::setw(10) << "Preco"
              << std::setw(8) << "Qtd" << std::endl;

    for (int i = 0; i < numProdutos; ++i) {
        std::cout << std::left
                  << std::setw(6) << produtos[i].codigo
                  << std::setw(20) << produtos[i].nome
                  << std::fixed << std::setprecision(2) << std::setw(10) << produtos[i].preco
                  << std::setw(8) << produtos[i].quantidade << std::endl;
    }
    std::cout << "----------------------------------------\n";
}

// Implementação do método para buscar produto por código
void ControleEstoque::buscarProduto(int codigo) {
    for (int i = 0; i < numProdutos; ++i) {
        if (produtos[i].codigo == codigo) {
            std::cout << "\n--- Detalhes do Produto ---\n";
            std::cout << "Código:     " << produtos[i].codigo << std::endl;
            std::cout << "Nome:       " << produtos[i].nome << std::endl;
            std::cout << "Preço:      R$ " << std::fixed << std::setprecision(2) << produtos[i].preco << std::endl;
            std::cout << "Quantidade: " << produtos[i].quantidade << std::endl;
            std::cout << "---------------------------\n";
            return; // Encerra a função pois o produto foi encontrado
        }
    }

    // Se o laço terminar, o produto não foi encontrado
    std::cout << "Produto com o código " << codigo << " não encontrado!" << std::endl;
}
