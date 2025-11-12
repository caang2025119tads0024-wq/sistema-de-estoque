#ifndef CONTROLEESTOQUE_HPP
#define CONTROLEESTOQUE_HPP

#include <string>

struct Produto {
    int codigo;
    std::string nome;
    double preco;
    int quantidade;
};

const int MAX_PRODUTOS = 1000; // Define um tamanho máximo para o estoque

class ControleEstoque {
private:
    Produto produtos[MAX_PRODUTOS]; // Array C-style para armazenar produtos
    int numProdutos; // Para controlar o número atual de produtos

public:
    ControleEstoque();
    
    // Adiciona um novo produto ao estoque
    void adicionarProduto(int codigo, std::string nome, double preco, int quantidade);
    // Remove um produto do estoque pelo código
    bool removerProduto(int codigo);
    
    // Atualiza a quantidade de um produto
    bool atualizarQuantidade(int codigo, int novaQuantidade);
    
    // Lista todos os produtos
    void listarProdutos();

    // Busca um produto pelo código e exibe seus detalhes
    void buscarProduto(int codigo);
};

#endif // CONTROLEESTOQUE_HPP