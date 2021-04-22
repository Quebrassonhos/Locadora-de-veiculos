#ifndef CARRO_H   // Evita as inclusÃµes cÃ­clicas
#define CARRO_H

//DeclaraÃ§Ã£o de struct

typedef struct carro {
    char modelo[128];
    char placa[8];
} Carro;

// DeclaraÃ§Ã£o das funÃ§Ãµes aqui

Carro criarCarro();

void atualizarDadosCarro(Carro *carros, int pos);

void excluirCarro(Carro *carros, int *indexCarro, int pos);

void printCarro(Carro carro);     

int buscarCarro(Carro *carros, int indexCarro, char placa[8]);

void validaPlaca(Carro *carros, int *indexCarro, int pos);

#endif 
