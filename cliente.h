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
void printCliente(Cliente cliente);
void atualizarDadosCliente(Cliente *clientes, int pos);
void excluirCliente(Cliente *clientes, int *indexCliente);    
int buscarCliente(Cliente *clientes, int indexCliente, char cpf[10]);

#endif
