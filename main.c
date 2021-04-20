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


int main(void) {
    int opcao;
    
    lerArqCliente(clientes, &indexCliente);
    
    while((opcao = mostrarMenu()) < 5) {
        switch(opcao) {
            case 1:
                cadastrarClientes(clientes, &indexCliente);
                break;
            case 4:
                exibirRelatorioClientes(clientes, indexCliente);
                break;
        }
    }
    
    return 0;
}