/**
@file logica.c
Construção do código correspondente às funções que dizem respeito à lógica do programa.
*/

#include "dados.h"
#include "logica.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA c) {

    int r = 0;
    r = jogada_invalida(e,c);
    if (r == 1)
        return r;
    printf("jogar %d %d\n", c.coluna, c.linha);
    set_casa(e,get_ult_jog(e).coluna-1,get_ult_jog(e).linha-1,PRETA);
    //e->tab [e->ultima_jogada.coluna - 1][e->ultima_jogada.linha - 1] = PRETA;
    set_casa(e,c.coluna - 1,c.linha - 1, BRANCA);
    //e->tab [c.coluna - 1][c.linha - 1] = BRANCA;
    set_ult_jog(e,c.coluna,c.linha);
    //e->ultima_jogada.coluna = c.coluna;
    //e->ultima_jogada.linha = c.linha;
    if (get_num_jog(e) == 1) {
        set_arr_jog_j1(e,get_num_jog(e),c);
        //e->jogadas[get_num_jog(e)].jogador1.coluna = c.coluna;
        //e->jogadas[get_num_jog(e)].jogador1.linha = c.linha;
        set_jog_atual(e,2);
        //e->jogador_atual = 2;
        set_num_jog(e,get_num_jog(e)+1);
        //e->num_jogadas++;
    }
    else {
        set_arr_jog_j2(e,get_num_jog(e),c);
        //e->jogadas[get_num_jog(e)-1].jogador2.coluna = c.coluna;
        //e->jogadas[get_num_jog(e)-1].jogador2.linha = c.linha;
        set_jog_atual(e,1);
        //e->jogador_atual = 1;
    }
    r = jogo_terminado(e);
    return r;
}
int jogo_terminado(ESTADO *e){
    int x = get_ult_jog (e).coluna-1;
    int y = get_ult_jog (e).linha-1;

    if (get_casa(e,0,0) == BRANCA) return 2;

    if (get_casa(e,7,7) == BRANCA) return 3;

    int flag = 0;
    for (int i = x - 1; i < x + 2; i++)
        for (int j = y - 1; j < y + 2; j++)
            if ((i <= 8) && (i > 0) && (j <= 8) && (j > 0))
                if((get_casa(e,i,j) != PRETA) && (i != x && j != y) )
                    flag = 1;


    if (flag == 0){
        if (get_jog_atual(e) == 1) return 2;
        if (get_jog_atual(e) == 2) return 3;
    }

    return 0;

}

int jogada_invalida(ESTADO *e, COORDENADA jogada) {
    int r = 1;
    int x = get_ult_jog (e).coluna;
    int y = get_ult_jog (e).linha;

    if ((jogada.coluna <= 8) && (jogada.coluna > 0) && (jogada.linha <= 8) && (jogada.linha > 0))

        if (get_casa(e,jogada.coluna-1,jogada.linha-1) != PRETA)
            for (int i = x - 1; i < x + 2; i++)
                if (i == jogada.coluna)
                    for (int j = y - 1; j < y + 2; j++)
                        if (j == jogada.linha) {
                            r = 0;
                            break;
                        }
    return r;
}