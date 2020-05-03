/**
@file interface.h
Definição das funções referentes à interface
*/

#ifndef RASTRO_INTERFACE_H
#define RASTRO_INTERFACE_H

#include "dados.h"
#include <stdio.h>

/** Interpreta os comandos e instruções dados pelos jogadores
 *
 * @param e Estado atual
 * @returns Um inteiro, 0, 1, 2 ou 3

> **0** Sucesso
> \n **1** Se a jogada for inválida
> \n **2** Se o jogador 1 ganhar
> \n **3** Se o jogador 2 ganhar
 * */
int interpretador(ESTADO *e);

/** Comando usado para receber o input do user, mostrando a informação do jogo
 *
 * @param e Estado atual
 * */
void prompt (ESTADO *e);

#endif //RASTRO_INTERFACE_H
