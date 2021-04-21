#include "telas.h"

void pausar() {
    printf("\n#pressione qualquer tecla para continuar...");
    getchar();
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
        printf("4 - Excluir clientes\n");
        printf("5 - Alugar veículo.\n");
        printf("6 - Exibir clientes.\n");
        printf("7 - Sair.\n");
        
        printf("Opção: ");
        scanf("%d%*c", &opcao);
    } while(opcao > 7);
    
    return opcao;
}

void cadastrarClientesTela(Cliente *clientes, int *indexCliente) {
    char flag;
    
    do {
        system("clear || cls");
        printf("\n============ TELA - Cadastrar Clientes ============\n");
    
        clientes[*indexCliente] = criarCliente();
        *indexCliente = *indexCliente + 1;
        
        printf("\n-> Deseja cadastrar outro cliente (S/N): ");
        scanf("%c%*c", &flag);
        
    } while(flag == 'S' || flag == 's');
    
    salvarArqCliente(clientes, *indexCliente);
}

void atualizarClientesTela(Cliente *clientes, int indexCliente) {
    char flag;
    
    do {
        system("clear || cls");
        printf("\n========== TELA - Atualizar dados Clientes ==========\n");
        //atualiza Cliente
        
        printf("\n-> Deseja atualizar outro cliente (S/N): ");
        scanf("%c%*c", &flag);
        
    } while(flag == 'S' || flag == 's');
    
    salvarArqCliente(clientes, indexCliente);
}

void excluirClientesTela(Cliente *clientes, int *indexCliente) {
    char flag;
    
    do {
        system("clear || cls");
        printf("\n========== TELA - Excluir Clientes ==========\n");
    
        excluirCliente(clientes, indexCliente);
        
        printf("\n-> Deseja excluir outro cliente (S/N): ");
        scanf("%c%*c", &flag);
        
    } while(flag == 'S' || flag == 's');
    
    salvarArqCliente(clientes, *indexCliente);
}

void exibirClientesTela(Cliente *clientes, int indexCliente) {
    system("clear || cls");
    printf("\n============ TELA - Clientes cadastrados ============\n");
    
    for(int i = 0; i < indexCliente; i++) {
        printCliente(clientes[i]);
        printf("\n");
    }
    
    if(indexCliente == 0) {
        printf("\n@Nenhum cliente cadastrado!!!\n");
    }
    
    pausar();
}