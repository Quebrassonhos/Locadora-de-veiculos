#ifndef TELA_H   // Evita as inclusões cíclicas
#define TELA_H

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "carro.h"
#include "aluguel.h"
#include "filemanager.h"


int mostrarMenu();

void cadastrarClientesTela(Cliente *cliente, int *indexCliente);

void cadastrarCarrosTela(Carro *carros, int *indexCarro);

void atualizarClientesTela(Cliente *cliente, int indexCliente);

void atualizarCarrosTela(Carro *carros, int indexCarro);

void excluirClientesTela(Cliente *cliente, int *indexCliente);

void excluirCarrosTela(Carro *carros, int *indexCarro);

void exibirCarrosTela(Carro *carros, int indexCarro);

void exibirClientesTela(Cliente *cliente, int indexCliente);        

void alugarCarroTela(Carro *carros, int indexCarro,
                     Cliente *Clientes, int indexCliente,
                     Aluguel *alugueis, int *indexAluguel);
#endif