#include <stdio.h>
#include <string.h>
#include "cliente.h"

// alterado por jose


Cliente criarCliente() {
    Cliente cliente;
	
    printf("-> Digite o nome: ");
    scanf("%[^\n]%*c", cliente.nome);

    printf("-> Digite o cpf: ");
    scanf("%s%*c", cliente.cpf);

    printf("-> Digite o número de telefone: ");
    scanf("%d%*c", &cliente.telefone);
    
    return cliente;

}

void printCliente(Cliente cliente) {
    printf("-> Nome: %s\n", cliente.nome);
    printf("-> CPF: %s\n", cliente.cpf);
    printf("-> Telefone: %d\n", cliente.telefone);
}

int buscarCliente(Cliente *clientes, int indexCliente, char cpf[10]) {
	int i;
	
	for (i = 0; i < indexCliente; i++) {
		if (strcmp(cpf, clientes[i].cpf) == 0){
			//O cpf foi encontrado !\n", cpf;
			return i;
		}
	}
	return -1;
}

void atualizarDadosCliente(Cliente *clientes, int pos) {
    char flag;
    
    printCliente(clientes[pos]);
    printf("-------------------------------\n");
    
    printf("Deseja realmente atualizar os dados? (S/N): ");
    scanf("%c%*c", &flag);
    
    if(flag == 's' || flag == 'S') {
	    printf("\n-> Digite o NOVO nome do cliente: ");
	    scanf("%[^\n]%*c", clientes[pos].nome);
		
	    printf("-> Digite o NOVO CPF do cliente: ");
	    scanf("%s%*c", clientes[pos].cpf);
		
	    printf("-> Digite o NOVO Telefone do cliente: ");
	    scanf("%d%*c", &clientes[pos].telefone);
	    
	    printf("#Cliente atualizado.");
    } else {
        printf("\n@Cancelado!");
    }
}

void excluirCliente(Cliente *clientes, int *indexCliente) {
    Cliente novoArray[1000];
    int indice = 0;
    int excluiu = -1;
    char cpf[9];
    
    printf("-> Digite o CPF: ");
    scanf("%s%*c", cpf);
    
    for(int i = 0; i < *indexCliente; i++) {
        if(strcmp(clientes[i].cpf, cpf) == 0) {
            excluiu = i;
        }
        else {
            novoArray[indice] = clientes[i];
            indice = indice + 1;
        }
    }
    
    if(excluiu > -1) {
 
      printf("@ Item apagado:\n");
       printCliente(clientes[excluiu]);
       
       *indexCliente = indice;
       clientes = novoArray;
    }
    else {
        printf("@Item não encontrado!\n");
    }
}






