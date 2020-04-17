/**
@file logica.c
Construção do código correspondente às funções que dizem respeito à lógica do programa.
*/

#include "dados.h"
#include "logica.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA c) {

    int r = 0;
    /** Validade da jogada*/
    r = jogada_invalida(e,c);
    /** Caso da jogada ser válida */
    if (r == 1)
        return r;
    printf("jogar %d %d\n", c.coluna, c.linha);
    /** Na coordenada anterior, é colocada uma peça PRETA */
    e->tab [e->ultima_jogada.coluna - 1][e->ultima_jogada.linha - 1] = PRETA;
    /** Na coordenada anterior, é colocada uma peça BRANCA */
    e->tab [c.coluna - 1][c.linha - 1] = BRANCA;
    e->ultima_jogada.coluna = c.coluna;
    e->ultima_jogada.linha = c.linha;
    /** Se o jogador atual for o 1, então é alterado para o 2 e aumenta-se o número de jogadas */
    if (obter_jogador_atual(e) == 1) {
        e->jogadas[obter_numero_de_jogadas(e)].jogador1.coluna = c.coluna;
        e->jogadas[obter_numero_de_jogadas(e)].jogador1.linha = c.linha;
        e->jogador_atual = 2;
        e->num_jogadas++;
    }
    /** Se o jogador atual for o 2, então é alterado para o 1 e mantém-se o número de jogadas */
    else {
        e->jogadas[obter_numero_de_jogadas(e)-1].jogador2.coluna = c.coluna;
        e->jogadas[obter_numero_de_jogadas(e)-1].jogador2.linha = c.linha;
        e->jogador_atual = 1;
    }
     r = jogo_terminado(e);
    return r;
}
int jogo_terminado(ESTADO *e){
    int x = e->ultima_jogada.coluna-1;
    int y = e->ultima_jogada.linha-1;

    if (obter_estado_casa(e,0,0) == BRANCA) return 2;

    if (obter_estado_casa(e,7,7) == BRANCA) return 3;

    int flag = 0;
    for (int i = x - 1; i < x + 2; i++)
            for (int j = y - 1; j < y + 2; j++)
                if ((i <= 8) && (i > 0) && (j <= 8) && (j > 0))
                    if((obter_estado_casa(e,i,j) != PRETA) && (i != x && j != y) )
                        flag = 1;


    if (flag == 0){
        if (obter_jogador_atual(e) == 1) return 2;
        if (obter_jogador_atual(e) == 2) return 3;
    }

    return 0;

}

int jogada_invalida(ESTADO *e, COORDENADA jogada) {
    /** A abcissa da jogada anterior */
    /** A ordenada da jogada anterior */
    /** Para a jogada ser válida, a abcissa e a ordenada têm de estar entre 0 e 9 */
    /** Na casa da coordenada para onde queremos jogar, não pode estar uma peça preta */
    /** A jogada tem estar próxima da jogada anterior */
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