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
    for (int j = 0; j < 8; j++)
        for (int i = 0; i < 8 ; i++)
            e->tab [i][j] = VAZIO;
    e-> ultima_jogada.coluna = 5;
    e-> ultima_jogada.linha = 5;
    e->tab[4][4] = PRETA;
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
    //if (peso != -1) {
    nodol->peso = peso;
    for (int i = 0; i < 8 ; i++)
        nodol->nodos[i] = malloc(sizeof(nodo));
    //}//else {
     //   nodol->peso = -1;
     //   for (int i = 0; i < 8 ; i++)
      //      nodol->nodos[i] = NULL;
    //}
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



void criar_rede (nodo *nodol,ESTADO *e) {

    COORDENADA c = nodol->final;
    caminh [c.coluna-1][c.linha-1] = TRUE;
    //printf("%d\n",caminh [c.coluna-1][c.linha-1]);

    int k = 0;
    for (int i = c.coluna - 1; i < c.coluna + 2; i++) {
            for (int j = c.linha - 1; j < c.linha + 2; ++j) {
                COORDENADA coord1 = {i,j};
                if ((j > 0 && j < 9) && (i > 0 && i < 9) && (caminh[i-1][j-1] == FALSE) && (i != c.coluna || j != c.linha)) {
                    COORDENADA coord2 = {8,8};
                    //if(i == c.coluna && j == c.linha)
                    //printf("%d\n",caminh [c.coluna-1][c.linha-1]);
                    printf("%d: de %d %d para %d %d: ",k,c.coluna,c.linha, i, j);
                    init_nodo(nodol->nodos[k],c,coord1,calcular_peso_nodo(coord1,coord2));
                    printf("%lf\n",nodol->nodos[k]->peso);
                    k++;
                } else{
                    init_nodo(nodol->nodos[k],c,coord1,-1.0);
                    printf("%d: de %d %d para %d %d: ",k,c.coluna,c.linha, i, j);
                    printf("%lf\n",nodol->nodos[k]->peso);

                    //printf("estou vivo\n");
                    k++;
                    if (caminh[i-1][j-1] == TRUE)
                        k--;
                }
            }
    }
    nodo *nodog = menor_peso(nodol->nodos,k);
    //k = 0;
    if( nodog->peso != 0.0 ){
        printf("nodo escolhido: %d %d\n",nodog->final.coluna,nodog->final.linha);
        criar_rede(nodog,e);
    } else printf("fim\n");
}

nodo *menor_peso(nodo *rede[],int k) {
    int nodo = 0;
    while(rede[nodo]->peso == -1.0) {
            nodo += 1;
    }

    //printf("%d %lf",nodo ,rede[nodo]->peso);
    for (int i = 1; i < k; i++) {
        if (rede[i]->peso != -1.0) {//rede[i]!=NULL &&
            if (rede[nodo]->peso > rede[i]->peso) nodo = i;
            //printf("%d\n",nodo);
            //printf("%d: %lf\n",nodo,rede[nodo]->peso);
        }
    }
    /*
    if (rede[nodo]->peso == 0){

        return NULL;
    }else{
        //printf("%lf\n",rede[nodo]->peso);
*/
    return rede[nodo];
   // }
}

nodo *percorrer_rede(nodo *nodol,LISTA l){
    //if (.prox != NULL){
    //printf("%d",l.cabeca);
    //insere_cabeca(l,&nodol->peso);
    nodo *proxNodo  = menor_peso(nodol->nodos,0);
    if (proxNodo == NULL){
        printf("%f\n",0);//proxNodo->peso);
        return proxNodo;
    }else {
        printf("%d %d :%f\n",proxNodo->final.coluna,proxNodo->final.linha,proxNodo->peso);
        return percorrer_rede(proxNodo,l);
    }
}// else printf("%d",l.cabeca);

void iguala_tab(ESTADO *e){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(e->tab[i][j] == PRETA)
                caminh[i][j] = TRUE;
        }
    }
}