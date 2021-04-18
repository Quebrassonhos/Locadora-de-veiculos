#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "carro.h"
#include "aluguel.h"
#include "filemanager.h"

#define TAM 1000 // Tamanho máximo dos vetores;

/* Posições já ocupadas nos vetores */
int indexCliente = 0;
int indexCarro = 0;
int indexAluguel = 0;

Cliente clientes[TAM];
Carro carros[TAM];
Aluguel alugueis[TAM];


int main(void) {
    /*Carrega os dados se existir */
    lerArqCliente(clientes, &indexCliente);
    lerArqCarro(carros, &indexCarro);
    lerArqAluguel(alugueis, &indexAluguel);
    
    
    printf("Tudo ok!\n");
    
    return 0;
}