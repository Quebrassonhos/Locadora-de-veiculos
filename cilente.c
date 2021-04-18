#include <stdio.h>
// alterado por jose


void cadastrarCliente(Cliente* clientes; int* indexCliente) {
	
	printf("Digite seu nome: ");
	scanf("%[^\n]s%*c", &clientes[indexCliente]->nome);
	printf("Digite seu cpf: ");
	scanf("%d", &clientes[indexCliente]->cpf);
	printf("Digite o número de telefone: "); //nao esquecer de colocar a funcao que habilita acentuacao.
	scanf("%d", &clientes[indexCliente]->telefone);
    indexCliente = indexCliente + 1;
    
    
}








