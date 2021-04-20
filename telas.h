#ifndef TELA_H   // Evita as inclusões cíclicas
#define TELA_H

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "carro.h"
#include "aluguel.h"
#include "filemanager.h"


int mostrarMenu();

void cadastrarClientes(Cliente *cliente, int *indexCliente);

void atualizarClientes(Cliente *cliente, int indexCliente);

void exibirRelatorioClientes(Cliente *cliente, int indexCliente);        

#endif