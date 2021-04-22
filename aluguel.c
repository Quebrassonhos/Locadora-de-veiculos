/* Definições de funções aqui */
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "aluguel.h"
#include "carro.h"
#include "cliente.h"
#include "filemanager.h"

//Realizar um aluguel de um carro para um cliente
void alugarCarro(Carro* arrayCarro, int indiceCarro, Cliente* arrayCliente, int* indiceCliente, Aluguel* arrayAlugueis, int* indiceAlugueis){
    char cpf[10], modelo[128];
    int i, j, tag=0;
    int entregaDia, entregaMes, entregaAno;
    time_t systemtime;
    systemtime = time(NULL);
    //tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900   referência

                                                                    //Bloco que mostra a disponibilidade de veículos

    printf("Carros disponiveis: "); 
    for (i=0; i<indiceCarro; i++){
        //strcmp retorna 0 se a placa do carro já estiver alugada.
        if(strcmp(arrayCarro[indiceCarro].placa, arrayAlugueis[*indiceCliente].placaCarro) != 0){
            printf("%s\n%s\n", arrayCarro[indiceCarro].modelo, arrayCarro[indiceCarro].placa);
        }
    }

                                                                    //Bloco que efetua o aluguel

    //checa qual carro vai ser escolhido
    printf("Modelo do Carro de escolha: ");
    scanf("%[^\n]s%*c", modelo);
    for (j=0; j<indiceCarro; j++){
        if(strcmp(modelo, arrayCarro->modelo)==0){
            break;
        }
    }

    do{ //pega os dados do cliente
        printf("Cpf do Cliente: ");
        scanf("%[^\n]s%*c", cpf);
        for (i=0; i<indiceCliente; i++){
            if (strcmp(cpf, arrayCliente->cpf)==0){
                tag++;
                break;
            }
        }
    } while (tag!=1);

    //data de entrega
    printf("digite só os numeros no formato DD/MM/ANO como em 23 06 1912)\n");
    printf("Qual a data de entrega: ");
    scanf("%d %d %d", entregaDia, entregaMes, entregaAno);

    for (size_t k=0; k<indiceAlugueis; k++){
        if (arrayAlugueis[k].placaCarro == NULL){
            arrayAlugueis[k].dataEntrega.tm_mday = entregaDia;
            arrayAlugueis[k].dataEntrega.tm_mon = entregaMes+1;
            arrayAlugueis[k].dataEntrega.tm_year = entregaAno+1900;
            strcpy(arrayAlugueis[k].placaCarro, arrayCarro[j].placa);
            strcpy(arrayAlugueis[k].cpfCliente, arrayCliente[i].cpf);
            arrayAlugueis[k].dataAluguel = *localtime(&systemtime);
        }
    }

    indiceAlugueis++;
    salvarArqAluguel(arrayAlugueis, indiceAlugueis);
}

void devolverCarro(Aluguel* arrayAlugueis, int* indiceCliente){
    int  dias, meses, anos;
    double total, valor_diaria, valor_multa;
    int i;
    char cpf[10];
    time_t systemtime;
    systemtime = time(NULL);

    printf("CPF do cliente: ");
    scanf("%[^\n]s%*c", cpf);
    for (i=0; i<indiceCliente; i++){
        if(strcmp(cpf, arrayAlugueis->cpfCliente)==0){
            break;
        }
    }

    struct tm dataatual = *localtime(&systemtime);

    //Trecho que calcula o total a ser pago
    anos = dataatual.tm_year+1900 - arrayAlugueis[i].dataEntrega.tm_year+1900 - arrayAlugueis[i].dataAluguel.tm_year+1900;

    if (anos>0){
        meses = dataatual.tm_mon+1+anos*12 - arrayAlugueis[i].dataEntrega.tm_mon+1 - arrayAlugueis[i].dataAluguel.tm_mon+1;
    } else{
        meses = dataatual.tm_mon+1 - arrayAlugueis[i].dataEntrega.tm_mon+1 - arrayAlugueis[i].dataAluguel.tm_mon+1;
    }
    
    if (meses>0){
        dias = dataatual.tm_mday*meses*30 - arrayAlugueis[i].dataEntrega.tm_mday - arrayAlugueis[i].dataAluguel.tm_mday;
    }
    else{
        dias = dataatual.tm_mday - arrayAlugueis[i].dataEntrega.tm_mday - arrayAlugueis[i].dataAluguel.tm_mday;
    }
    
    if (dataatual.tm_mday > arrayAlugueis[i].dataEntrega.tm_mday){
        total=dias*valor_multa;
    }
    total = dias*valor_diaria;
    printf("Valor a ser pago: %.2f", total);
    getchar();


    //trecho que apaga o espaço no vetor-struct de aluguéis
    Aluguel* novoArray;
    int indice;
    for(int j=0; j < indiceCliente; j++) {
        if(j != i) {
            novoArray[indice] = arrayAlugueis[i];
            indice++;
        }
    }
    arrayAlugueis=novoArray;
}
