/**
@file redes.c
Construção do código correspondente às funções que dizem respeito à criação de uma rede neural para a implementação da AI.
*/
#include "redes.h"
#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include <math.h>
#define nodoInv NAN
COORDENADA *coor_create(int col, int lin) {
    COORDENADA *c = (COORDENADA*)malloc(sizeof(COORDENADA));
    c -> coluna = col;
    c -> linha = lin;
    return c;
}

double max(double val1,double val2){
    if (isnan(val1)) return val2;
    if (isnan(val2)) return val1;
    if (val1 > val2) return val1;
    else return val2;
}

double min(double val1,double val2){
    if (isnan(val1)) return val2;
    if (isnan(val2)) return val1;
    if (val1 < val2) return val1;
    else return val2;
}

nodo *init_nodo (double peso_nd_ant,nodo *nodol, COORDENADA place, double peso){
    nodol->place = place;
    if (isnan(peso_nd_ant) || isnan(peso)) nodol->peso = NAN;
    else nodol->peso = peso_nd_ant+peso;
    for (int i = 0; i < 8 ; i++)
        nodol->nodos[i] = (nodo*)malloc(sizeof(nodo));
    return nodol;
}

int criar_rede (nodo *nodol,ESTADO *e,BOOL caminh[8][8]) {

    COORDENADA c = nodol->place;
    caminh [c.coluna-1][c.linha-1] = TRUE;
    COORDENADA coord2;
    if (e->jogador_atual == 1){
        coord2.coluna = 1;
        coord2.linha = 1;
    } else{
        coord2.coluna = 8;
        coord2.linha = 8;
    }

    int k = 0;
    for (int i = c.coluna - 1; i < c.coluna + 2; i++) {
        for (int j = c.linha - 1; j < c.linha + 2; ++j) {
            COORDENADA coord1 = {i,j};
            if ((j > 0 && j < 9) && (i > 0 && i < 9) && (caminh[i-1][j-1] == FALSE) && (i != c.coluna || j != c.linha)) {
                init_nodo(nodol->peso,nodol->nodos[k],coord1,calcular_peso_nodo(coord1,coord2));
                k++;
            }
        }
    }
    return k;
}
double minimax(nodo *nodol, ESTADO *e, int depth, double alpha, double beta, BOOL player, BOOL caminh[8][8]) {

    if (depth == 0) {
        return nodol->peso;
    }

    int num_nodos_val = criar_rede(nodol, e, caminh);

    if (player == TRUE) {
        double mineval = nodoInv;
        for (int i = 0; i < num_nodos_val; ++i) {
            double eval = minimax(nodol->nodos[i], e, depth - 1, alpha, beta, FALSE,caminh);
            if (!isnan(eval)) mineval = min(mineval, eval);
            alpha = min(alpha,eval);
            if (beta <= alpha) break;
        }
        nodol->peso = mineval;
        return mineval;
    } else {
        double maxeval = nodoInv;
        for (int i = 0; i < num_nodos_val; ++i) {
            double eval = minimax(nodol->nodos[i], e, depth - 1, alpha, beta, TRUE,caminh);
            if (!isnan(eval)) maxeval = max(maxeval, eval);
            beta = max(beta,eval);
            if (beta <= alpha) break;
        }
        nodol->peso = maxeval;
        return maxeval;
    }
}


double calcular_peso_nodo(COORDENADA i, COORDENADA f){
    float distx = abs(i.coluna - f.coluna);
    float disty = abs(i.linha - f.linha);
    float distinit = distx*distx + disty*disty;
    return sqrt(distinit);
}

COORDENADA print_rede(nodo *rede[],int num_nodos,double res){
    for (int i = 0; i < num_nodos; ++i) {
        if (rede[i]->peso == res) return rede[i]->place;
    }
    return rede[0]->place;
}


void iguala_tab(ESTADO *e,BOOL caminh[8][8]){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(e->tab[i][j] == PRETA) caminh[i][j] = TRUE;
            else caminh[i][j] = FALSE;
        }
    }
}