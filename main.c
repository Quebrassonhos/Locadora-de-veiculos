#include <stdio.h>
#include "cliente.h"
#include "carro.h"
#include "aluguel.h"
#include "filemanager.h"
#include "telas.h"

#define TAM 1000 // Tamanho máximo dos vetores;

/* Posições já ocupadas nos vetores */
int indexCliente = 0;
int indexCarro = 0;
int indexAluguel = 0;

Cliente clientes[TAM];
Carro carros[TAM];
Aluguel alugueis[TAM];


void carregarDadosTXT() {
    lerArqCliente(clientes, &indexCliente);
    lerArqCarro(carros, &indexCarro);
}

int main(void) {
    int opcao;
    
    carregarDadosTXT();
    
    while((opcao = mostrarMenu()) < 11) {
        switch(opcao) {
            case 1:
                cadastrarClientesTela(clientes, &indexCliente);
                break;
            case 2:
                cadastrarCarrosTela(carros, &indexCarro);
                break;
            case 3:
                atualizarClientesTela(clientes, indexCliente);
                break;
            case 4:
                atualizarCarrosTela(carros, indexCarro);
                break;
            case 5:
                excluirClientesTela(clientes, &indexCliente);
                break;
            case 6:
                excluirCarrosTela(carros, &indexCarro);
                break;
            case 9:
                exibirClientesTela(clientes, indexCliente);
                break;
            case 10:
                exibirCarrosTela(carros, indexCarro);
                break;
        }
    }
    
    return 0;
}