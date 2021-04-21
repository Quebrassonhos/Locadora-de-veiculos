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

void atualizarClientesTela(Cliente *cliente, int indexCliente);

void excluirClientesTela(Cliente *cliente, int *indexCliente);

void exibirClientesTela(Cliente *cliente, int indexCliente);        

#endif