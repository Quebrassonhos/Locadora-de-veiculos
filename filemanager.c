#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cliente.h"
#include "carro.h"
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
    *idx = 0;
    
    arq = fopen("dados/clientes.txt", "rt");
    
    if(arq == NULL)
        return;
    
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
    *idx = 0;
    
    arq = fopen ("dados/carros.txt", "rt");
    
    if(arq == NULL)
        return;
    
    result = fscanf(arq, "modelo: %[^\n]\n", carros[*idx].modelo);
    while(result != EOF) {
        fscanf(arq, "placa: %s\n", carros[*idx].placa);
        *idx = *idx + 1;
        
        result = fscanf(arq, "modelo: %[^\n]\n", carros[*idx].modelo);
    }
    
    fclose(arq);
}

void salvarArqAluguel(Aluguel* al, int idx) {
    FILE *arq;
    arq = fopen("dados/alugueis.txt", "wt");
    
    for(int i = 0; i < idx; i++) {
        fprintf(arq, "placaCarro: %s\n", al[i].placaCarro);
        fprintf(arq, "cpfCliente: %s\n", al[i].cpfCliente);
        
        fprintf(arq, "dataAluguel: %lld\n", al[i].dataAluguel);
        fprintf(arq, "dataEntrega: %lld\n", al[i].dataEntrega);
    }
    
    fclose(arq);
    printf("-> Dados salvos com sucesso!\n");

}

void lerArqAluguel(Aluguel* al, int *idx) {
    FILE *arq;
    int result;
    *idx = 0;
    
    arq = fopen("dados/alugueis.txt", "rt");
    
    if(arq == NULL)
        return;
    
    result = fscanf(arq, "placaCarro: %s\n", al[*idx].placaCarro);
    while(result != EOF) {
        
        fscanf(arq, "cpfCliente: %s\n", al[*idx].cpfCliente);
        
        fscanf(arq, "dataAluguel: %lld\n", &al[*idx].dataAluguel);
        
        fscanf(arq, "dataEntrega: %lld\n", &al[*idx].dataEntrega);
        
        *idx = *idx + 1;
        
        result = fscanf(arq, "placaCarro: %s\n", al[*idx].placaCarro);
    }
    
    fclose(arq);
}