/* Definições de funções aqui */
#include <string.h>
#include <stdio.h>
#include "aluguel.h"
#include "carro.h"
#include "cliente.h"

int teste() {
    return 10;
}

//Realizar um aluguel de um carro para um cliente
void alugarCarro(Carro* arrayCarro, int indiceCarro, Cliente* arrayCliente, int* indiceCliente, Aluguel* arrayAlugueis, int* indiceAlugueis){
    
    printf("Carros disponiveis: "); //Bloco que mostra a disponibilidade de veículos
    for (size_t i=0; i<indiceCarro; i++){
        //strcmp retorna 0 a placa do carro já estiver alugada.
        if(strcmp(arrayCarro[indiceCarro].placa, arrayAlugueis[*indiceCliente].placaCarro) != 0){
            printf("%s\n%s\n", arrayCarro[indiceCarro].modelo, arrayCarro[indiceCarro].placa);
        }
    }
    printf("Kowalski");
    indiceAlugueis++;
    indiceCliente++;
}