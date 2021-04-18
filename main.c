#include <stdio.h>
#include "cliente.h"
#include "carro.h"
#include "aluguel.h"

#define TAM 1000 // Tamanho máximo dos vetores;

/* Posições já ocupadas nos vetores */
int indexCliente = 0;
int indexCarro = 0;
int indexAluguel = 0;

Cliente clientes[TAM];
Carro carros[TAM];
Aluguel alugueis[TAM];


int main(void) {
    // funcao para o menu veem aqui
    
    printf("Tudo ok!\n");
    printf("Valor: %d", teste());
    
    return 0;
}