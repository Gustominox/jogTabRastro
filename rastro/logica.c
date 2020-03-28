//
// Created by gusto on 3/10/20.
//

#include "dados.h"
#include "logica.h"
#include <stdio.h>
// A jogada é válida se a casa onde se pretende jogar está vazia e se a mesma é vizinha da peça branca.
// Na coordenada anterior, é colocado uma peça preta e, na coordenada atual, uma peça branca.
// Consoante o jogador atual, são guardados os valores da coluna e da linha atuais.
// Se o jogador anterior for o 1, então muda para o 2, e vice-versa.
// Se o jogador atual for o 1, então o número de jogadas mantém-se. Caso contrário, aumenta.
// Se a peça branca acabar na casa (0,0), ganha o jogador 1. Se acabar na casa (7,7), ganha o jogador 2.

int jogar(ESTADO *e, COORDENADA c) {

    int r = 0;
    r = jogada_invalida(e,c);
    if (r == 1)
        return r;

    printf("jogar %d %d\n", c.coluna, c.linha);
    e->tab [e->ultima_jogada.coluna - 1][e->ultima_jogada.linha - 1] = PRETA;
    e->tab [c.coluna - 1][c.linha - 1] = BRANCA;
    e->ultima_jogada.coluna = c.coluna;
    e->ultima_jogada.linha = c.linha;
    if (obter_jogador_atual(e) == 1) {
        e->jogadas[obter_numero_de_jogadas(e)].jogador1.coluna = c.coluna;
        e->jogadas[obter_numero_de_jogadas(e)].jogador1.linha = c.linha;
        e->jogador_atual = 2;
    } else {
        e->jogadas[obter_numero_de_jogadas(e)].jogador2.coluna = c.coluna;
        e->jogadas[obter_numero_de_jogadas(e)].jogador2.linha = c.linha;
        e->jogador_atual = 1;
        e->num_jogadas++;
    }

    if (obter_estado_casa(e,0,0) == BRANCA){
        printf ("Venceu o jogador 1.\n");
        return 2;
    }
    if (obter_estado_casa(e,7,7) == BRANCA) {
        printf ("Venceu o jogador 2.\n");
        return 2;
    }
    return 0;
}

int jogada_invalida(ESTADO *e, COORDENADA jogada) {
    int r = 1;
    int x = e->ultima_jogada.coluna;
    int y = e->ultima_jogada.linha;

    if ((jogada.coluna <= 8) && (jogada.coluna > 0) && (jogada.linha <= 8) && (jogada.linha > 0))
        if (e->tab[jogada.coluna-1][jogada.linha-1] != PRETA)
            for (int i = x - 1; i < x + 2; i++)
                if (i == jogada.coluna)
                    for (int j = y - 1; j < y + 2; j++)
                        if (j == jogada.linha) {
                            r = 0;
                            break;
                        }

    return r;
}