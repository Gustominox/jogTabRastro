/**
@file logica.h
Definição da lógica do programa e das funções que a manipulam
*/

#ifndef RASTRO_LOGICA_sH
#define RASTRO_LOGICA_H
#include "dados.h"

/**
\brief Modifica o estado ao jogar na casa correta se a jogada for válida

@param e Apontador para o estado
@param c A coordenada a jogar

@returns Um inteiro, 0, 1 ou 2
> **0** se a jogada **for possível**,
> \n **1** se a jogada **não for possível**,
> \n **2** quando o **jogo deve acabar** e o jogador é **1**
> \n **3** quando o **jogo deve acabar** e o jogador é **2**

@see jogada_invalida(ESTADO *e, COORDENADA jogada);

 */
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Verifica se a jogada é válida
@param e Apontador para o estado
@param jogada A coordenada a validar
@returns Um inteiro, 0 ou 1
> **0** se a jogada **valida**,
> \n **1** se a jogada **invalida**
*/
int jogada_invalida(ESTADO *e, COORDENADA jogada);

/**
\brief Verifica se o jogo terminou ou não
@param e Apontador para o estado
@returns Um inteiro, 0, 2 ou 3
> **2** se o jogador 1 ganhou
> \n **3** se o jogador 2 ganhou
*/
int jogo_terminado(ESTADO *e);

#endif //RASTRO_LOGICA_H
