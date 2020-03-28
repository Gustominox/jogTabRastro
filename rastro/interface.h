//
// Created by gusto on 3/10/20.
//

#ifndef RASTRO_INTERFACE_H
#define RASTRO_INTERFACE_H

#include "dados.h"
int interpretador(ESTADO *e);
void mostrar_tabuleiro(ESTADO *e);
void comando_gr (ESTADO *e, char nome[]);
int comando_q(ESTADO *e);
void comando_ler(ESTADO *e);
void lista_movs(ESTADO *e);
#endif //RASTRO_INTERFACE_H
