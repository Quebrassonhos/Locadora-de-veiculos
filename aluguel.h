#ifndef ALUGUEL_H   // Evita as inclusões cíclicas
#define ALUGUEL_H

#include <time.h>
#include "carro.h"
#include "cliente.h"


//Declaração de struct

typedef struct aluguel {
    char placaCarro[8];
    char cpfCliente[10];
    long long dataAluguel;
    long long dataEntrega;
} Aluguel;

// Declaração das funções aqui
Aluguel alugarCarro(Carro* carros, int indiceCarro, 
                 Cliente* clientes, int indiceCliente, 
                 Aluguel* alugueis, int *indiceAluguel);

void devolverCarro(Aluguel* alugueis);

#endif 