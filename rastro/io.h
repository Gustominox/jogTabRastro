/**
@file io.h
Definição das funções referentes à interação do utilizador com o jogo
*/

#ifndef RASTRO_IO_H
#define RASTRO_IO_H
#include "dados.h"
#include <stdio.h>

/** Comando que grava o estado atual do tabuleiro
 *
 * @param e Estado atual
 * @param fp Apontador para o ficheiro
 * */
void comando_gr (ESTADO *e, FILE *fp);

/** Comando que imprime a lista dos movimentos do jogo
 *
 * @param e Estado atual
 * @param fp Apontador para o ficheiro
 * */
void comando_movs(ESTADO *e,FILE *fp);

/** Comando que imprime o tabuleiro
 *
 * @param e Estado atual
 * @param fp Apontador para o ficheiro
 * */
void comando_tab(ESTADO *e, FILE *fp);

/** Comando que acaba o programa
 *
 * @param e Estado atual
 * @returns 2 Acaba o programa
 * */
int comando_q();

/** Comando que lê o estado do tabuleiro a partir do ficheiro
 *
 * @param e Estado atual
 * @param nome[] Nome do ficheiro
 * */
void comando_ler(ESTADO *e, char nome[]);

/** Comando que permite mudar para uma posição anterior através do seu número
 *
 * @param e Estado atual
 * @param n Numero da posição anterior
 * */
void comando_pos (ESTADO *e, int n);


#endif //RASTRO_IO_H
