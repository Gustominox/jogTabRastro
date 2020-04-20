/**
@file logica.c
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
	e->jogador_atual = 2;
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
double max(double val1,double val2){
    if (val1 == NAN) return val2;
    if (val2 == NAN) return val1;
    if (val1 > val2) return val1;
	else return val2;
}

double min(double val1,double val2){
    printf("val1: %lf val2: %lf\n",val1 ,val2);
    if (val1 == NAN){
        printf("valor : %lf",val2);
    }else if (val2 == NAN) {
        printf("valor : %lf",val1);
    }
    else if (val1 < val2) return val1;
	else return val2;
}

void init_rede(nodo *rede[]){
	for (int i = 0; i < 8; ++i) {
	}
}
int num_de_cha=1;

double minimax(nodo *nodol, ESTADO *e, int depth, double alpha, double beta, BOOL player) {

    if (depth == 0) {
        return nodol->peso;
    }

    criar_rede(nodol, e, player);
    int num_nodos_val = organiza_rede(nodol->nodos);
    printf("rede organizada do nodo %d %d com %d nodos :\n", nodol->final.coluna, nodol->final.linha,num_nodos_val);
    print_rede(nodol->nodos);

    if (player == TRUE) {
        double mineval = nodoInv;
        for (int i = 0; i < num_nodos_val; ++i) {
            double eval = minimax(nodol->nodos[i], e, depth - 1, alpha, beta, FALSE);
            printf("eval do nodo %d %d: %lf\n", nodol->nodos[i]->final.coluna, nodol->nodos[i]->final.linha, eval);
            mineval = min(mineval, eval);
        }
        return mineval;
    } else {
        double maxeval = nodoInv;
        for (int i = 0; i < num_nodos_val; ++i) {
            double eval = minimax(nodol->nodos[i], e, depth - 1, alpha, beta, TRUE);
            printf("eval do nodo %d %d: %lf\n", nodol->nodos[i]->final.coluna, nodol->nodos[i]->final.linha, eval);
            maxeval = max(maxeval, eval);
        }
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
    alpha = min(alpha,eval);
    if (beta <= alpha) break;
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
    beta = max(beta,eval);
    if (beta <= alpha) break;
*/
    //printf("nodo escolhido: %d %d\n",nodoprox.coluna,nodoprox.linha);


int organiza_rede(nodo *rede[]){
	int num_nodos_pos = 0;
	for (int j = 6; j >= 0; --j)
	for (int i = 0; i < j; ++i) {
		if (rede[i]->peso  == nodoInv ) trocarNodos(rede[i],rede[i+1]);
	}
	for (int k = 0; k < 8; ++k)
		if (rede[k]->peso != nodoInv) num_nodos_pos++;

	return num_nodos_pos;
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
	if (peso_nd_ant == nodoInv || peso == nodoInv) nodol->peso = NAN;
    else nodol->peso = peso_nd_ant+peso;
	//if (player) nodol->peso = peso_nd_ant+peso;
	//else nodol->peso = -peso_nd_ant-peso;
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



void criar_rede (nodo *nodol,ESTADO *e,BOOL player) {

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
	/*
	if (player){
		if (e->jogador_atual == 1){
			coord2.coluna = 1;
			coord2.linha = 1;
		} else{
			coord2.coluna = 8;
			coord2.linha = 8;
		}
	} else {
		if (e->jogador_atual == 1){
			coord2.coluna = 8;
			coord2.linha = 8;
		} else{
			coord2.coluna = 1;
			coord2.linha = 1;
		}
	}
	 */
	if(player) printf("jogador %d na direcao: %d %d\n",e->jogador_atual, coord2.coluna,coord2.linha);
    else 	printf("jogador %d na direcao: %d %d\n",e->jogador_atual-1, coord2.coluna,coord2.linha);


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
					init_nodo(nodol->peso,nodol->nodos[k],c,coord1,nodoInv,player);
					printf("nodo invalido: de %d %d para %d %d: \n",c.coluna,c.linha, i, j);
					//printf("%lf\n",nodol->nodos[k]->peso);
					if (caminh[i-1][j-1] != TRUE)
						k++;
				}
			}
	}
	//int num_n = organiza_rede(nodol->nodos);
	//print_rede(nodol->nodos);
	//nodo *nodog = menor_peso(nodol->nodos,k);
	//if( nodog->peso != 0.0 )//{
		//criar_rede(nodog,e);
		// debug: printf("nodo escolhido: %d %d\n",nodog->final.coluna,nodog->final.linha);
	//          } else printf("fim no nodo: %d %d\n",nodog->final.coluna,nodog->final.linha);
}
void print_rede(nodo *rede[]){
	for (int i = 0; i < 8; ++i) {
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



