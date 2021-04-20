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


//acrescentei isso aqui: a ideia é a funcao receber o array onde os clientes estao e o indice que cada cliente representa, logo atualizar os dados

void atualizarDados(Cliente *clientes; int indexCliente) {

//seria bom mostrar os clientes aqui, ou seja, chamar a funcao que exiba os clientes atentando aos indices para podermos atualizar o cliente certo
int var, i;
pritnf("Digite o numero do cliente que desejar atualizar: ");
scanf("%d", &var);

//nao sei se precisaria de um for, nao to conseguindo executar por isso nao testei. precisa mudar os dados por referencia. uma duvida que tenho?
	if (var == indexCliente) {
		printf("Digite o NOVO nome do cliente: ");
		scanf("%[^\n]s%*c", *cliente[indexCliente].nome);
		
		printf("Digite o NOVO cpf do cliente: ");
		scanf("%s%*c", *cliente[indexCliente].cpf);
		
		printf("Digite o NOVO cpf do cliente: ");
		scanf("%d", *cliente[indexCliente].telefone);
	}
	
	
}






