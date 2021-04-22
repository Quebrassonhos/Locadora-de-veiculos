/*Definições de funções aqui */
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "aluguel.h"
#include "filemanager.h"


// Retorna 1 se o carro já estiver alugado e 0 se NAO estiver.
int estaAlugado(Carro carro, Aluguel *alugueis, int indiceAlugueis) {
    for(int i = 0; i < indiceAlugueis; i++) {
        
        if(strcmp(carro.placa, alugueis[i].placaCarro) != 0){
            return 1; // já está alugado.
        }
    }
    return 0; // não está alugado.
}

int calcularPreco(int dias) {
    return 100 * dias;
}

//Realizar um aluguel de um carro para um cliente
Aluguel alugarCarro(Carro* arrayCarro, int indiceCarro, 
                 Cliente* arrayCliente, int indiceCliente, 
                 Aluguel* arrayAlugueis, int* indiceAlugueis) {
                     
    char cpf[10], modelo[128];
    int i, idCliente, j;
    int dias;
    time_t systemtime;
    systemtime = time(NULL);
    //tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900   referência

                                                                    //Bloco que mostra a disponibilidade de veículos

    printf("\n@ Carros disponiveis:\n"); 
    for (i = 0; i < indiceCarro; i++){
        if(estaAlugado(arrayCarro[i], arrayAlugueis, *indiceAlugueis) == 0) {
            printCarro(arrayCarro[i]);
            printf("\n");
        }
    }
    
    printf("---------------------------\n");
    
    printf("\nClientes cadastrados:\n");
    for(int c = 0; c < indiceCliente; c++) {
        printCliente(arrayCliente[c]);
        printf("\n");
    }
    printf("--------------------------\n");


                                                                    //Bloco que efetua o aluguel

    //checa qual carro vai ser escolhido
    printf("Modelo do Carro de escolha: ");
    scanf("%[^\n]%*c", modelo);
    
    for (j = 0; j < indiceCarro; j++){
        if(strcmp(modelo, arrayCarro[j].modelo) == 0){
            break;
        }
    }

    do{ //pega os dados do cliente
        printf("=> Cpf do Cliente: ");
        scanf("%s%*c", cpf);
        idCliente = buscarCliente(arrayCliente, indiceCliente, cpf);
        
    } while (idCliente == -1);

    //data de entrega
    printf("=> Quatdade de dias: ");
    scanf("%d%*c", &dias);
    
    Aluguel aluguel;
    strcpy(aluguel.placaCarro, arrayCarro[j].placa);
    strcpy(aluguel.cpfCliente, arrayCliente[idCliente].cpf);
    aluguel.dataAluguel = (long long)systemtime;
    aluguel.dataEntrega = (long long)systemtime + (dias * 24 * 60 * 60);
    
    printf("O valor a ser pago no dia da devolução\n");
    printf("Valor: %d + multa por atraso.", calcularPreco(dias));
    printf("\n @ Carro alugado.\n");
    
    return aluguel;
}

/*void devolverCarro(Aluguel* arrayAlugueis){
    int valor_diaria, dias, meses, anos;
    int total, valor_multa;
    time_t systemtime;
    systemtime = time(NULL);

    struct tm dataatual = *localtime(&systemtime);
    arrayAlugueis->dataEntrega = *localtime(&systemtime);

    //Trecho que calcula o total a ser pago
    anos = dataatual.tm_year+1900 - arrayAlugueis->dataEntrega.tm_year+1900 - arrayAlugueis->dataAluguel.tm_year+1900;

    if (anos>0){
        meses = dataatual.tm_mon+1+anos*12 - arrayAlugueis->dataEntrega.tm_mon+1 - arrayAlugueis->dataAluguel.tm_mon+1;
    } else{
        meses = dataatual.tm_mon+1 - arrayAlugueis->dataEntrega.tm_mon+1 - arrayAlugueis->dataAluguel.tm_mon+1;
    }
    
    if (meses>0){
        dias = dataatual.tm_mday*meses*30 - arrayAlugueis->dataEntrega.tm_mday - arrayAlugueis->dataAluguel.tm_mday;
    }
    else{
        dias = dataatual.tm_mday - arrayAlugueis->dataEntrega.tm_mday - arrayAlugueis->dataAluguel.tm_mday;
    }
    
    if (dataatual.tm_mday > arrayAlugueis->dataEntrega.tm_mday){
        total=dias*valor_multa;
    }
    total = dias*valor_diaria;
}*/