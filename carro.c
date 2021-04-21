#include <stdio.h>
#include <string.h>
#include "carro.h"

void printCarro(Carro carro) {
    printf("-> Modelo: %s\n", carro.modelo);
    printf("-> Placa: %s\n", carro.placa);
}

int buscarCarro(Carro *carros, int indexCarro, char placa[8]) {
	int i;
	
	for (i = 0; i < indexCarro; i++) {
		if (strcmp(placa, carros[i].placa) == 0){
			return i;
		}
	}
	
	return -1;
}

Carro criarCarro() {
    Carro carro;
	
    printf("=> Digite o modelo: ");
    scanf("%[^\n]%*c", carro.modelo);

    printf("=> Digite a Placa: ");
    scanf("%s%*c", carro.placa);
    
    return carro;
}

void atualizarDadosCarro(Carro *carros, int pos) {
    char flag;
    
    printCarro(carros[pos]);
    printf("-------------------------------\n");
    
    printf("@ Deseja realmente atualizar os dados? (S/N): ");
    scanf("%c%*c", &flag);
    
    if(flag == 's' || flag == 'S') {
	    printf("\n=> Digite o NOVO modelo do carro: ");
	    scanf("%[^\n]%*c", carros[pos].modelo);
		
	    printf("=> Digite o NOVA placa do carro: ");
	    scanf("%s%*c", carros[pos].placa);
	
	    printf("\n@ Carro atualizado.\n");
    } else {
        printf("\n@ Cancelado!\n");
    }
}

void excluirCarro(Carro *carros, int *indexCarro, int pos) {
    Carro novoArray[1000];
    int indice = 0;
    char flag;
    
    printf("=> Deseja realmente excluir(S/N): ");
    scanf("%c%*c", &flag);
    
    if(flag != 's' && flag != 'S') {
        printf("\n@ Cancelado!\n");
        return;
    }
    
    for(int i = 0; i < *indexCarro; i++) {
        if(i != pos) {
            novoArray[indice] = carros[i];
            indice = indice + 1;
        }
    }
    
    printf("\n@ Item apagado:\n");
}
