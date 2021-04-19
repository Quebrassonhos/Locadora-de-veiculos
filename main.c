#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "carro.h"
#include "aluguel.h"
#include "filemanager.h"

#define TAM 1000 // Tamanho máximo dos vetores;

/* Posições já ocupadas nos vetores */
int indexCliente = 0;
int indexCarro = 0;
int indexAluguel = 0;

Cliente clientes[TAM];
Carro carros[TAM];
Aluguel alugueis[TAM];


/********* Protótipos de funções *********/
int mostrarMenu();
void cadastrarClientes();
void exibirRelatorioClientes();

int main(void) {
    int opcao;
    
    while((opcao = mostrarMenu()) < 5) {
        switch(opcao) {
            case 1:
               cadastrarClientes();
        }
    }
    
    return 0;
}

int mostrarMenu() {
    int opcao;
    do {
        system("clear || cls");
        printf("\n======= SISTEMA DE LOCADORA DE VEÍCULOS ========\n");
        printf("====================== MENU ===================\n");
        printf("1 - Cadastrar Clientes.\n");
        printf("2 - Cadastrar Carros.\n");
        printf("3 - Atualizar dados do Cliente\n");
        printf("3 - Alugar veículo.\n");
        printf("4 - Exibir clinetes\n");
        printf("5 - Sair.\n");
        
        printf("Opção: ");
        scanf("%d%*c", &opcao);
    } while(opcao > 5);
    
    return opcao;
}

void cadastrarClientes() {
    char flag;
    
    do {
        system("clear || cls");
        printf("\n============ TELA - Cadastrar Clientes ============\n");
    
        clientes[indexCliente] = criarCliente();
        indexCliente = indexCliente + 1;
        
        printf("-> Deseja cadastrar outro cliente (S/N)");
        scanf("%c%*c", &flag);
        
    } while(flag == 'S' || flag == 'N');
    
    //Salva os arquivos
    salvarArqCliente(clientes, indexCliente);
}

void exibirRelatorioClientes() {
    system("clear || cls");
    printf("\n============ TELA - Clientes cadastrados ============\n");
    
    for(int i = 0; i < indexCliente; i++) {
        printCliente(clientes[indexCliente]);
        printf("\n");
    }
}