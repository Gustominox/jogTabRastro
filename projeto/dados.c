/**
@file dados.c
Construção do código correspondente às funções que dizem respeito ao estado.
*/

#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "listas.h"
#include <math.h>
#define nodoInv NAN
ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->num_jogadas_por_j = 0;
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

int get_jog_atual(ESTADO *e){
    return e->jogador_atual;
}

void set_jog_atual (ESTADO *e,int n){
    e->jogador_atual = n;
}

COORDENADA get_ult_jog(ESTADO *e){
    return e->ultima_jogada;
}

void set_ult_jog (ESTADO *e,int i,int j){
    e->ultima_jogada.coluna = i;
    e->ultima_jogada.linha = j;
}

int get_num_jog(ESTADO *e){
    return e->num_jogadas;
}

void set_num_jog(ESTADO *e,int nov_jog){
    e->num_jogadas = nov_jog ;
}

int get_num_jog_joga(ESTADO *e){
    return e->num_jogadas_por_j;
}

void set_num_jog_joga(ESTADO *e, int nov_jog_por_j){
    e->num_jogadas_por_j = nov_jog_por_j;
}

int get_num_com(ESTADO *e){
    return e->num_comando;
}

void set_num_com(ESTADO *e, int nov_com){
    e->num_comando = nov_com;
}

CASA get_casa(ESTADO *e, int i, int j){
    CASA casa = e->tab[i] [j];
    return casa;
}

void set_casa (ESTADO *e, int i,int j, CASA casa){
    e->tab[i][j] = casa;
}

COORDENADA get_arr_jog_j1 (ESTADO *e,int n){
    return e->jogadas[n].jogador1;
}

void set_arr_jog_j1 (ESTADO *e,int n, COORDENADA c){
    e->jogadas[n].jogador1 = c;
}

COORDENADA get_arr_jog_j2 (ESTADO *e,int n){
    return e->jogadas[n].jogador2;
}

void set_arr_jog_j2 (ESTADO *e,int n, COORDENADA c){
    e->jogadas[n].jogador2 = c;
}

void limpa_estado(ESTADO *e){
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->num_jogadas_por_j = 0;
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8 ; i++) {
            e->tab [i][j] = VAZIO;
        }
    }
    e-> ultima_jogada.coluna = 5;
    e-> ultima_jogada.linha = 5;
    e->tab[4][4] = BRANCA;
    e->tab[7][7] = DOIS;
    e->tab[0][0] = UM;
    e->num_comando = 0;
}

COORDENADA criar_coordenada(int col, int lin){
    COORDENADA c = {col,lin};
    return c;
}

COORDENADA transforma_jogada(char col, char lin){
    COORDENADA c = {col - 96, lin - 48};
    return c;
}
