//
// Created by gusto on 3/10/20.
//

#ifndef RASTRO_INTERFACE_H
#define RASTRO_INTERFACE_H

#include "dados.h"
#include <stdio.h>
int interpretador(ESTADO *e);
void comando_gr (ESTADO *e, FILE *fp);
int comando_q(ESTADO *e);
void comando_ler(ESTADO *e, char nome[]);
void comando_movs(ESTADO *e,FILE *fp);
COORDENADA transforma_jogada(char x, char y);
void comando_pos (ESTADO *e, int n);
#endif //RASTRO_INTERFACE_H
