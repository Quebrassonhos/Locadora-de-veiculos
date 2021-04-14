#include <stdio.h>
struct carrinho{
    char nome[30];
    int km;
    char tipoaluguel;
    int valor;
} carrinho;

void CalculaPreco(){
    int preco;
    if (carrinho.tipoaluguel==d){
        preco=dias*carro.valor;
    }
    if(carrinho.tipoaluguel==k){
        preco=carrinho.km*carrinho.valor;
    }
    print("O valo final do aluguel é: %d", preco);
}
