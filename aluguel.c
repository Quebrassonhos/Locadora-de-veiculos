/* Definições de funções aqui */
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "aluguel.h"
#include "carro.h"
#include "cliente.h"

//Realizar um aluguel de um carro para um cliente
void alugarCarro(Carro* arrayCarro, int indiceCarro, Cliente* arrayCliente, int* indiceCliente, Aluguel* arrayAlugueis, int* indiceAlugueis){
    
    time_t mytime;
    mytime = time(NULL);
    //tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900   referência

    //Bloco que mostra a disponibilidade de veículos
    printf("Carros disponiveis: "); 
    for (size_t i=0; i<indiceCarro; i++){
        //strmp retorna 0 a placa do carro já estiver alugada.
        if(strcmp(arrayCarro[indiceCarro].placa, arrayAlugueis[*indiceCliente].placaCarro) != 0){
            printf("%s\n%s\n", arrayCarro[indiceCarro].modelo, arrayCarro[indiceCarro].placa);
        }
    }
    
    //Bloco que efetua o aluguel
    arrayAlugueis->dataAluguel = *localtime(&mytime);
    printf("%d/%d/%d", arrayAlugueis->dataAluguel.tm_mday, arrayAlugueis->dataAluguel.tm_mon+1, arrayAlugueis->dataAluguel.tm_year+1900);
    indiceAlugueis++;
}

void devolverCarro(Aluguel* arrayAlugueis){
    int valor_diaria, dias, meses, anos;
    int total;
    time_t mytime;
    mytime = time(NULL);

    struct tm dataatual = *localtime(&mytime);
    arrayAlugueis->dataEntrega = *localtime(&mytime);

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
    
    total = dias*valor_diaria;
}
