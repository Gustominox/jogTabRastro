//
// Created by gusto on 3/10/20.
//

#ifndef RASTRO_INTERFACE_H
#define RASTRO_INTERFACE_H

#include "dados.h"
#include <stdio.h>
int interpretador(ESTADO *e);
void prompt (ESTADO *e);
/** Comando que grava o estado atual do tabuleiro
 *
 * @param e Estado a gravar
 * @param fp Apontador para o ficheiro
 * */
void comando_gr (ESTADO *e, FILE *fp);
void comando_movs(ESTADO *e,FILE *fp);
void comando_tab(ESTADO *e, FILE *fp);
int comando_q(ESTADO *e);
void comando_ler(ESTADO *e, char nome[]);

void comando_pos (ESTADO *e, int n);
#endif //RASTRO_INTERFACE_H
