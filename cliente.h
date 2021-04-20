#ifndef CLIENTE_H   // Evita as inclusões cíclicas
#define CLIENTE_H

// Declaração de struct

typedef struct cliente {
    char nome[128];
    char cpf[10];
    int telefone;
} Cliente;

// Declaração das funções aqui

Cliente criarCliente();
void printCliente();
void atualizarDadosCliente(Cliente *clientes, int pos);

#endif
