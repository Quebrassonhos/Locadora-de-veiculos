#ifndef CARRO_H   // Evita as inclusões cíclicas
#define CARRO_H

//Declaração de struct

typedef struct carro {
    char modelo[128];
    char placa[8];
} Carro;

// Declaração das funções aqui

Carro criarCarro();

void atualizarDadosCarro(Carro *carros, int pos);

void excluirCarro(Carro *carros, int *indexCarro, int pos);

void printCarro(Carro carro);     

int buscarCarro(Carro *carros, int indexCarro, char placa[8]);

#endif 