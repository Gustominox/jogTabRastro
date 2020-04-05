/**
@file logica.h
Definição da lógica do programa e das funções que a manipulam.
*/

#ifndef RASTRO_LOGICA_H
#define RASTRO_LOGICA_H
#include "dados.h"

/**
\brief Modifica o estado ao jogar na casa correta se a jogada for válida.
@param e Apontador para o estado
@param c A coordenada
@returns O se a jogada for possível, 1 se a jogada não for possível, 2 quando o jogo dever acabar.
*/
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Verifica se a jogada é válida.
@param e Apontador para o estado
@param jogada A coordenada
@returns 0 se é valida, 1 se é invalida.
*/
int jogada_invalida(ESTADO *e, COORDENADA jogada);

#endif //RASTRO_LOGICA_H