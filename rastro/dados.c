/**
@file logica.c
Construção do código correspondente às funções que dizem respeito ao estado.
*/

#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "listas.h"
#include <math.h>
ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->num_jogagas_por_j = 0;
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

/**e->tab[][] == PRETA
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
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->num_jogagas_por_j = 0;
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

/**
\brief Obtem o número de comandos.
@return um inteiro.
*/
int obter_numero_de_comandos(ESTADO *e){
    return e->num_comando;
}
/**
\brief Cria coordenadas através dos inteiros
@return Uma COORDENADA
*/
COORDENADA criar_coordenada(int col, int lin){
    COORDENADA c = {col,lin};
    return c;
}

/**
\brief Cria coordenadas através dos chars
@return Uma COORDENADA
*/
COORDENADA transforma_jogada(char col, char lin){
    COORDENADA c = {col - 96, lin - 48};
    return c;
}

nodo *init_nodo (nodo *nodol,COORDENADA inicial, COORDENADA final, double peso){
    nodol->final = final;
    nodol->inicial = inicial;
    nodol->peso = peso;
    for (int i = 0; i < 8 ; i++)
        nodol->nodos[i] = malloc(sizeof(nodo));
    }

double calcular_peso_nodo(COORDENADA i, COORDENADA f){
    float distx = abs(i.coluna - f.coluna);
    float disty = abs(i.linha - f.linha);
    float distinit = distx*distx + disty*disty;
    return sqrt(distinit);
}



void criar_rede (nodo *nodol,ESTADO *e) {

    COORDENADA c = nodol->final;
    caminh [c.coluna-1][c.linha-1] = TRUE;

    int k = 0;
    for (int i = c.coluna - 1; i < c.coluna + 2; i++) {
            for (int j = c.linha - 1; j < c.linha + 2; ++j) {
                COORDENADA coord1 = {i,j};
                if ((j > 0 && j < 9) && (i > 0 && i < 9) && (caminh[i-1][j-1] == FALSE) && (i != c.coluna || j != c.linha)) {
                    COORDENADA coord2 = {8,8};
                    init_nodo(nodol->nodos[k],c,coord1,calcular_peso_nodo(coord1,coord2));
                    // debug: printf("%d: de %d %d para %d %d: ",k,c.coluna,c.linha, i, j);
                    //        printf("%lf\n",nodol->nodos[k]->peso);
                    k++;
                } else{
                    init_nodo(nodol->nodos[k],c,coord1,-1.0);
                    printf("%d: de %d %d para %d %d: ",k,c.coluna,c.linha, i, j);
                    printf("%lf\n",nodol->nodos[k]->peso);
                    if (caminh[i-1][j-1] != TRUE)
                        k++;
                }
            }
    }
    nodo *nodog = menor_peso(nodol->nodos,k);
    if( nodog->peso != 0.0 )//{
        criar_rede(nodog,e);
        // debug: printf("nodo escolhido: %d %d\n",nodog->final.coluna,nodog->final.linha);
    //          } else printf("fim no nodo: %d %d\n",nodog->final.coluna,nodog->final.linha);
}

nodo *menor_peso(nodo *rede[],int k) {
    int nodo = 0;
    while(rede[nodo]->peso == -1.0) nodo += 1;
    for (int i = 1; i < k; i++){
        if (rede[i]->peso != -1.0)
            if (rede[nodo]->peso > rede[i]->peso) nodo = i;
    }
    return rede[nodo];
}

void iguala_tab(ESTADO *e){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(e->tab[i][j] == PRETA)
                caminh[i][j] = TRUE;
        }
    }
}



