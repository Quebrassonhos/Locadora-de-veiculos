#include <stdio.h>
#include "cliente.h"

// alterado por jose


Cliente criarCliente() {
	Cliente cliente;
	
    printf("-> Digite o nome: ");
    scanf("%[^\n]s%*c", cliente.nome);

    printf("-> Digite o cpf: ");
    scanf("%s%*c", cliente.cpf);

    printf("-> Digite o número de telefone: ");
    scanf("%d", &cliente.telefone);
    
    return cliente;

}

void printCliente(Cliente cliente) {
    printf("-> Nome: %s\n", cliente.nome);
    printf("-> CPF: %s\n", cliente.cpf);
    printf("-> Telefone: %d\n", cliente.telefone);
}








