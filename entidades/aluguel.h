#ifndef ALUGUEL_H   // Evita as inclusões cíclicas
#define ALUGUEL_H

#include <time.h>

//Declaração de struct

typedef struct aluguel {
    char placaCarro[8];
    char cpfCliente[10];
    time_t dataAluguel;
    time_t dataEntrega;
} Aluguel;

// Declaração das funções aqui
int teste();

#endif 