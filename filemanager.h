#ifndef FILEMANAGER_H   // Evita as inclusões cíclicas
#define FILEMANAGER_H

#include "cliente.h"
#include "carro.h"
#include "aluguel.h"

void salvarArqCliente(Cliente *clientes, int idx);

void lerArqCliente(Cliente* clientes, int *idx);

void salvarArqCarro(Carro* carros, int idx);

void lerArqCarro(Carro* carros, int *idx);

void salvarArqAluguel(Aluguel* aluguel, int idx);

void lerArqAluguel(Aluguel* aluguel, int *idx);

#endif