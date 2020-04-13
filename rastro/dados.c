/**
@file logica.c
Construção do código correspondente às funções que dizem respeito ao estado.
*/

#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include <math.h>
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
        }
    /** A posição da __última jogada__ nas colunas */
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

COORDENADA criar_coordenada(int col, int lin){
    COORDENADA c;
    c.coluna = col;
    c.linha = lin;
    return c;
}

nodo *init_nodo (nodo *nodol,COORDENADA inicial, COORDENADA final, double peso){
    nodol->final = final;
    nodol->inicial = inicial;
    if (peso != -1) {
        nodol->peso = peso;
        for (int i = 0; i < 8 ; i++)
            nodol->nodos[i] = malloc(sizeof(nodo));
    }else {
        nodol->peso = -1;
        for (int i = 0; i < 8 ; i++)
            nodol->nodos[i] = NULL;
    }
    }

double calcular_peso_nodo(COORDENADA i, COORDENADA f){
    float distx;
    float disty;
    distx = abs(i.coluna - f.coluna) ;
    disty = abs(i.linha - f.linha) ;
    float distinit = distx*distx + disty*disty;
    double dist = sqrt(distinit);
    return dist;
}

void criar_rede (nodo *nodol) {
    COORDENADA c = nodol->final;
    //64*63/2 = 2016
    /*
    COORDENADA tdsNodos[2016];
    int coordPtr = 0;
    tdsNodos[coordPtr] = c;
    coordPtr ++;
    */
    int k = 0;
    for (int i = c.coluna - 1; i < c.coluna + 2; i++) {
            for (int j = c.linha - 1; j < c.linha + 2; ++j) {
                COORDENADA coord1 = {i,j};
                if ((j > 0 && j < 9) && (i > 0 && i < 9) && (i != c.coluna || j != c.linha)) {
                    COORDENADA coord2 = {7,7};
                    printf("de %d %d para %d %d: ",c.coluna,c.linha, i, j);
                    init_nodo(nodol->nodos[k],c,coord1,calcular_peso_nodo(coord1,coord2));
                    printf("%lf\n",nodol->nodos[k]->peso);
                    //criar_rede(nodol->nodos[k]);
                    //criar_rede(init_nodo(nodol->nodos[k],coord1,calcular_peso_nodo(coord1,coord2)));
                } else{
                    init_nodo(nodol->nodos[k],c,coord1,-1);
                }
            }
        k++;
    }
}