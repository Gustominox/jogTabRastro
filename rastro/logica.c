//
// Created by gusto on 3/10/20.
//

#include "dados.h"
#include <stdio.h>

// Primeiramente, é definido a alteração do jogador (se o jogador anterior for o 1, então muda para o 2, e vice-versa).
// A seguir, é colocada uma peça preta na coordenada anterior e uma peça branca na coordenada atual.
// Consoante o jogador atual, são guardados os valores da coluna e da linha atuais.
// Se o jogador atual for o 1, então o número de jogadas mantém-se. Caso contrário, aumenta.

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    if (e->jogador_atual = 1) e->jogador_atual = 2;
    else e->jogador_atual = 1;
    e->tab [e->ultima_jogada.coluna - 1][e->ultima_jogada.linha - 1] = PRETA;
    e->tab [c.coluna - 1][c.linha - 1] = BRANCA;
    if (e->jogador_atual = 1) {
        e->jogadas->jogador1.coluna = c.coluna;
        e->jogadas->jogador1.linha = c.linha;
        e->num_jogadas;
    }
    if (e->jogador_atual = 2) {
        e->jogadas->jogador2.coluna = c.coluna;
        e->jogadas->jogador2.linha = c.linha;
        e->num_jogadas = e->num_jogadas + 1;
    }
    return 1;
}
