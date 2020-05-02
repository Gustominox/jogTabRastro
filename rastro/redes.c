/**
@file redes.c
Construção do código correspondente às funções que dizem respeito à criação de uma rede neural para a implementação da AI.
*/
#include "redes.h"
#include <stdlib.h>
#include "dados.h"
#include "interface.h"
#include "listas.h"
#include <math.h>
#define nodoInv NAN

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


double minimax(nodo *nodol, ESTADO *e, int depth, double alpha, double beta, BOOL player,COORDENADA *arr) {
    //arr[2-depth]=nodol->final;
    if (depth == 0) {
        return nodol->peso;
    }

    int num_nodos_val = criar_rede(nodol, e, player);

    if (player == TRUE) {
        double mineval = nodoInv;
        for (int i = 0; i < num_nodos_val; ++i) {
            double eval = minimax(nodol->nodos[i], e, depth - 1, alpha, beta, FALSE,arr);
            printf("eval do nodo %d %d: %lf\n", nodol->nodos[i]->final.coluna, nodol->nodos[i]->final.linha, eval);
            mineval = min(mineval, eval);
            if(mineval == eval) arr[2-depth-1]=nodol->nodos[i]->final;
            alpha = min(alpha,eval);
            if (beta <= alpha) break;
        }

        if (depth == 2) printf("eval do nodo %d %d: %lf\n", nodol->final.coluna, nodol->final.linha, mineval);
        return mineval;
    } else {
        double maxeval = nodoInv;
        for (int i = 0; i < num_nodos_val; ++i) {
            double eval = minimax(nodol->nodos[i], e, depth - 1, alpha, beta, TRUE,arr);
            printf("eval do nodo %d %d: %lf\n", nodol->nodos[i]->final.coluna, nodol->nodos[i]->final.linha, eval);
            maxeval = max(maxeval, eval);
            if(maxeval == eval) arr[2-depth]=nodol->nodos[i]->final;
            beta = max(beta,eval);
            if (beta <= alpha) break;
        }
        if (depth == 2) printf("eval do nodo %d %d: %lf\n", nodol->final.coluna, nodol->final.linha, maxeval);
        return maxeval;
    }
}
//printf("new child whit alpha %lf and beta %lf\n",alpha,beta);
/*
if (depth!=3) {
    for (int j = 0; j < num_nodos_val; ++j) {
        if (maxeval == nodol->nodos[j]->peso)
            //printf("nodo escolhido: %d %d\n", nodol->nodos[j]->final.coluna,nodol->nodos[j]->final.linha);//nodol->nodos[i]->final;
    }
}
*/
//printf("minEval do nodo %d %d: %lf\n",nodol->nodos[i]->final.coluna,nodol->nodos[i]->final.linha,maxeval);
/*
*/
//printf("nodo escolhido: %d %d\n",nodoprox.coluna,nodoprox.linha);
//printf("new child whit alpha %lf and beta %lf\n",alpha,beta);
/*
if (depth!=3) {
    for (int j = 0; j < num_nodos_val; ++j) {
        if (mineval == nodol->nodos[j]->peso)
            printf("nodo escolhido: %d %d\n", nodol->nodos[j]->final.coluna,nodol->nodos[j]->final.linha);//nodol->nodos[i]->final;
    }
}
 */
//printf("maxEval do nodo %d %d: %lf\n",nodol->nodos[i]->final.coluna,nodol->nodos[i]->final.linha,mineval);
/*
*/
//printf("nodo escolhido: %d %d\n",nodoprox.coluna,nodoprox.linha);


int organiza_rede(nodo *rede[]){
    int num_nodos_val = 0;
    for (int j = 7; j >= 0; --j)
    for (int i = 0; i < j; ++i) {
    	if (isnan(rede[i]->peso) ) trocarNodos(rede[i],rede[i+1]);
    }
    for (int k = 0; k < 8; ++k)
        if (isnan(rede[k]->peso) != TRUE) num_nodos_val++;

    return num_nodos_val;
}
void trocarNodos(nodo *nodo1, nodo *nodo2){

    double auxPeso;
    COORDENADA auxInicial;
    COORDENADA auxFinal;

    auxPeso = nodo1->peso;
    nodo1->peso = nodo2->peso;
    nodo2->peso = auxPeso;

    auxInicial = nodo1->inicial;
    nodo1->inicial = nodo2->inicial;
    nodo2->inicial = auxInicial;

    auxFinal = nodo1->final;
    nodo1->final = nodo2->final;
    nodo2->final = auxFinal;
}
nodo *init_nodo (double peso_nd_ant,nodo *nodol,COORDENADA inicial, COORDENADA final, double peso,BOOL player){
    nodol->final = final;
    nodol->inicial = inicial;
    if (isnan(peso_nd_ant) || isnan(peso)) nodol->peso = NAN;
    else nodol->peso = peso_nd_ant+peso;
    for (int i = 0; i < 8 ; i++)
        nodol->nodos[i] = malloc(sizeof(nodo));
}

double calcular_peso_nodo(COORDENADA i, COORDENADA f,BOOL player){
    float distx = abs(i.coluna - f.coluna);
    float disty = abs(i.linha - f.linha);
    float distinit = distx*distx + disty*disty;
    if (player) return sqrt(distinit);
    else return sqrt(distinit);
}



int criar_rede (nodo *nodol,ESTADO *e,BOOL player) {

    COORDENADA c = nodol->final;
    caminh [c.coluna-1][c.linha-1] = TRUE;
    COORDENADA coord2;
    if (e->jogador_atual == 1){
        coord2.coluna = 1;
        coord2.linha = 1;
    } else{
        coord2.coluna = 8;
        coord2.linha = 8;
    }

    //if(player) printf("jogador %d na direcao: %d %d\n",e->jogador_atual, coord2.coluna,coord2.linha);
    //else 	printf("jogador %d na direcao: %d %d\n",e->jogador_atual-1, coord2.coluna,coord2.linha);


    int k = 0;
    for (int i = c.coluna - 1; i < c.coluna + 2; i++) {
        for (int j = c.linha - 1; j < c.linha + 2; ++j) {
            COORDENADA coord1 = {i,j};
            if ((j > 0 && j < 9) && (i > 0 && i < 9) && (caminh[i-1][j-1] == FALSE) && (i != c.coluna || j != c.linha)) {
                init_nodo(nodol->peso,nodol->nodos[k],c,coord1,calcular_peso_nodo(coord1,coord2,player),player);
                //printf("%d: de %d %d para %d %d: ",k,c.coluna,c.linha, i, j);
                //printf("%lf\n",nodol->nodos[k]->peso);
                k++;
            } else{
                //init_nodo(nodol->peso,nodol->nodos[k],c,coord1,nodoInv,player);
                //printf("nodo invalido: de %d %d para %d %d: \n",c.coluna,c.linha, i, j);
                //printf("%lf\n",nodol->nodos[k]->peso);
                //if (caminh[i-1][j-1] != TRUE)
                //	k++;
            }
        }
    }
    return k;
    //int num_n = organiza_rede(nodol->nodos);
    //print_rede(nodol->nodos);
    //nodo *nodog = menor_peso(nodol->nodos,k);
    //if( nodog->peso != 0.0 )//{
    //criar_rede(nodog,e);
    // debug: printf("nodo escolhido: %d %d\n",nodog->final.coluna,nodog->final.linha);
    //          } else printf("fim no nodo: %d %d\n",nodog->final.coluna,nodog->final.linha);
}
void print_rede(nodo *rede[],int num_nodos){
    for (int i = 0; i < num_nodos; ++i) {
        printf(" de %d %d para %d %d: ",rede[i]->inicial.coluna,rede[i]->inicial.linha,rede[i]->final.coluna, rede[i]->final.linha);
        printf("%lf\n",rede[i]->peso);
    }
}
nodo *menor_peso(nodo *rede[],int k) {
    int nodo = 0;
    while(rede[nodo]->peso == nodoInv) nodo += 1;

    for (int i = 1; i < k; i++){
        if (rede[i]->peso != nodoInv)
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


