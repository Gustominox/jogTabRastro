//
// Created by gusto on 3/10/20.
//

#include <stdlib.h>
#include "dados.h"

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
    return e;
}

int obter_jogador_atual(ESTADO *estado){
    return estado->jogador_atual;
}

int obter_numero_de_jogadas(ESTADO *estado){
    return estado->num_jogadas;
}

CASA obter_estado_casa(ESTADO *e, int i, int j){
    CASA casa = e->tab[i] [j];
    return casa;
}