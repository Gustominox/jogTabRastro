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
void comando_ler(ESTADO *e, char nome[]);
void comando_movs(ESTADO *e);
COORDENADA transforma_jogada(char x, char y);
#endif //RASTRO_INTERFACE_H
