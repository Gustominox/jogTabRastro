/**
@file redes.h
Definição das funções que criam ,modificam e analisam a rede.
*/

#ifndef RASTRO_REDES_H
#define RASTRO_REDES_H
#include "dados.h"


typedef struct nodo * rede[8];
/**
\brief Tipo de dados para o nodo
*/
typedef struct nodo{
    COORDENADA inicial;
    COORDENADA final;
    double peso;
    rede nodos;
}nodo;

nodo *init_nodo (double peso_nd_ant, nodo *nodol, COORDENADA final, COORDENADA inicial, double peso,BOOL player);
double calcular_peso_nodo(COORDENADA i, COORDENADA f,BOOL player);
int criar_rede (nodo *nodol,ESTADO *e,BOOL player);
nodo *menor_peso(nodo *rede[],int k);
void iguala_tab(ESTADO *e);
void trocarNodos(nodo *nodo1, nodo *nodo2);
int organiza_rede(nodo *rede[]);
void print_rede(nodo *rede[],int num_nodos);
double max(double val1,double val2);
double min(double val1,double val2);
double minimax(nodo *nodol, ESTADO *e, int depth, double alpha, double beta, BOOL player, COORDENADA *arr);

#endif //RASTRO_REDES_H
