#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "carro.h"
#include "aluguel.h"
#include "aluguel.h"


void salvarArqCliente(Cliente* clientes, int idx) {
    FILE *arq;
    arq = fopen("dados/clientes.txt", "w");
    
    for(int i = 0; i < idx; i++) {
        fprintf(arq, "nome: %s\n", clientes[i].nome);
        fprintf(arq, "cpf: %s\n", clientes[i].cpf);
        fprintf(arq, "telefone: %d\n", clientes[i].telefone);
    }
    
    fclose(arq);
    printf("-> Dados salvos com sucesso!\n");
}

void lerArqCliente(Cliente* clientes, int *idx) {
    FILE *arq;
    int result;
    
    arq = fopen("dados/clientes.txt", "rt");
    
    if(arq == NULL)
        return;
        
    *idx = 0;
    
    result = fscanf(arq, "nome: %[^\n]\n", clientes[*idx].nome);
    while(result != EOF) {
        fscanf(arq, "cpf: %s\n", clientes[*idx].cpf);
        fscanf(arq, "telefone: %d\n", &clientes[*idx].telefone);   
        *idx = *idx + 1;
        
        result = fscanf(arq, "nome: %[^\n]\n", clientes[*idx].nome);
    }
    
    fclose(arq);
}

void salvarArqCarro(Carro* carros, int idx) {
    FILE *arq;
    arq = fopen("dados/carros.txt", "wt");
    
    for(int i = 0; i < idx; i++) {
        fprintf(arq, "modelo: %s\n", carros[i].modelo);
        fprintf(arq, "placa: %s\n", carros[i].placa);
    }
    
    fclose(arq);
    printf("-> Dados salvos com sucesso!\n");
}

void lerArqCarro(Carro* carros, int *idx) {
    FILE *arq;
    int result;
    
    arq = fopen ("dados/carros.txt", "rt");
    
    if(arq == NULL)
        return;

    *idx = 0;
    
    result = fscanf(arq, "modelo: %[^\n]\n", carros[*idx].modelo);
    while(result != EOF) {
        fscanf(arq, "placa: %s\n", carros[*idx].placa);
        *idx = *idx + 1;
        
        result = fscanf(arq, "modelo: %[^\n]\n", carros[*idx].modelo);
    }
}

void salvarArqAluguel(Aluguel* al, int idx) {
    FILE *arq;
    arq = fopen("dados/alugueis.txt", "wt");
    
    for(int i = 0; i < idx; i++) {
        fprintf(arq, "placaCarros: %s\n", al[i].placaCarro);
        fprintf(arq, "cpfCliente: %s\n", al[i].cpfCliente);
        fprintf(arq, "dataAluguel: %ld\n", (long)al[i].dataAluguel);
        fprintf(arq, "dataEntrega: %ld\n", (long)al[i].dataEntrega);
    }
    
    fclose(arq);
    printf("-> Dados salvos com sucesso!\n");

}

void lerArqAluguel(Aluguel* al, int *idx) {
    FILE *arq;
    int result;
    
    arq = fopen ("dados/alugueis.txt", "rt");
    
    if(arq == NULL)
        return;

    *idx = 0;
    
    result = fscanf(arq, "placaCarro: %[^\n]\n", al[*idx].placaCarro);
    while(result != EOF) {
        long int tempo;
        
        fscanf(arq, "cfpCliente: %s\n", al[*idx].cpfCliente);
        fscanf(arq, "dataAluguel: %ld\n", &tempo);
        al[*idx].dataAluguel = (time_t)tempo;
        
        fscanf(arq, "dataEntrega: %ld\n", &tempo);
        al[*idx].dataEntrega = (time_t)tempo;
        
        *idx = *idx + 1;
        
        result = fscanf(arq, "placaCarro: %[^\n]\n", al[*idx].placaCarro);
    }
}