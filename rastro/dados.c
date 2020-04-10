/**
@file logica.c
Construção do código correspondente às funções que dizem respeito ao estado.
*/

#include <stdlib.h>
#include "dados.h"
#include "interface.h"

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    for (int j = 0; j < 8; j++)
        for (int i = 0; i < 8 ; i++)
            e->tab [i][j] = VAZIO;
    e-> ultima_jogada.coluna = 5;
    e-> ultima_jogada.linha = 5;
    e->tab[4][4] = BRANCA;
    e->tab[7][7] = DOIS;
    e->tab[0][0] = UM;
    e->num_comando = 0;
    return e;
}

/**
\brief Obtem o jogador atual.
@returns 1 jogador atual, 2 jogador atual.
*/
int obter_jogador_atual(ESTADO *estado){
    return estado->jogador_atual;
}

/**
\brief Obtem o número de jogadas.
@return um inteiro.
*/
int obter_numero_de_jogadas(ESTADO *estado){
    return estado->num_jogadas;
}

void set_casa (ESTADO *e, COORDENADA c, CASA casa){
    e->tab[c.coluna-1][c.linha-1] = casa;
}

CASA obter_estado_casa(ESTADO *e, int i, int j){
    CASA casa = e->tab[i] [j];
    return casa;
}

void set_jogador_atual (ESTADO *e,int n){
    e->jogador_atual = 1;
}

void limpa_estado(ESTADO *e){
    /** # O jogador atual */
    e->jogador_atual = 1;
    /** ## O número de jogadas */
    e->num_jogadas = 0;
    /** > A colocação da peça VAZIA em todas as casas */
    for (int j = 0; j < 8; j++)
        for (int i = 0; i < 8 ; i++) {
            e->tab [i][j] = VAZIO;
/**
A posição da __última jogada__ nas colunas

    e-> ultima_jogada.coluna = 5;
*/
        }
    e-> ultima_jogada.coluna = 5;
    /** A posição da última jogada nas linhas */
    e-> ultima_jogada.linha = 5;
    /** Na casa (4,4), está uma peça BRANCA */
    e->tab[4][4] = BRANCA;
    /** Na casa (7,7), está uma peça DOIS */
    e->tab[7][7] = DOIS;
    /** Na casa (0,0), está uma peça UM */
    e->tab[0][0] = UM;
    /** O número de comandos */
    e->num_comando = 0;
}

/**
\brief Obtem o número de comandos.
@return um inteiro.
*/
int obter_numero_de_comandos(ESTADO *e){
    return e->num_comando;
}