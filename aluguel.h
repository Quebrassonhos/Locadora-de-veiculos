#ifndef ALUGUEL_H   // Evita as inclusões cíclicas
#define ALUGUEL_H

#include <time.h>

//Declaração de struct

typedef struct aluguel {
    char placaCarro[8];
    char cpfCliente[10];
    struct tm dataAluguel;
    struct tm dataEntrega;
} Aluguel;

// Declaração das funções aqui
void alugarCarro();
void devolverCarro();

#endif 