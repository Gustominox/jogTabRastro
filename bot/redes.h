/**
@file redes.h
Definição das funções que criam ,modificam e analisam a rede.
*/

#ifndef RASTRO_REDES_H
#define RASTRO_REDES_H
#include "dados.h"

/**
\brief Definição de um array de pointers de nodos com tamanho 8
*/
typedef struct nodo * rede[8];

/**
\brief Tipo de dados para o nodo
*/
typedef struct nodo{
    COORDENADA place;
    double peso;
    rede nodos;
}nodo;



/**
\brief Inicia um nodo com os valores recebidos na função e aloca o espaço de memória para os próximos nodos
@param peso_nd_ant Peso do nodo anterior
@param nodol Nodo local
@param final Coordenada do nodo atual
@param inicial Coordenada do nodo anterior
@param peso Peso do nodo atual
@param player Variável que indica se é o jogador atual a jogar ou não
@returns o nodo iniciado
*/
nodo *init_nodo (double peso_nd_ant, nodo *nodol, COORDENADA place, double peso);

/**
\brief Calcula o peso do nodo, pelo Teorema de Pitágoras
@param i Coordenada do nodo inicial
@param f Coordenada do nodo final
@param player Variável que indica se é o jogador atual a jogar ou não
@returns o peso do nodo
*/
double calcular_peso_nodo(COORDENADA i, COORDENADA f);

/**
\brief Para um dado nodo, inicia os nodos contidos no seu array "nodos"
@param nodol Nodo local
@param e Apontador para o estado
@param player Variável que indica se é o jogador atual a jogar ou não
@returns o tamanho da rede
*/
int criar_rede (nodo *nodol,ESTADO *e,BOOL caminh[8][8]);

/**
\brief Dado uma rede e o seu tamanho, retorna o nodo de menor peso
@param rede Array de pointers de nodos
@param k O tamanho do array
@returns o nodo de menor peso
*/

void iguala_tab(ESTADO *e,BOOL caminh[8][8]);

/**
\brief Mostra os valores da rede, função criada para debug
@param rede Array de pointers de nodos
@param num_nodos Tamanho da rede
*/
COORDENADA print_rede(nodo *rede[],int num_nodos,double res);

/**
\brief Calcula o valor máximo entre dois doubles
@param val1 Primeiro valor
@param val2 Segundo valor
@returns o maior valor
*/
double max(double val1,double val2);

/**
\brief Calcula o valor mínimo entre os dois doubles
@param val1 Primeiro valor
@param val2 Segundo valor
@returns o menor valor
*/
double min(double val1,double val2);

/**
\brief Objetivo minmax, todo augusto comentarios + explicaçao
@param nodol Nodo local
@param e Apontador para o estado
@param depth
@alpha
@beta
@param player Variável que indica se é o jogador atual a jogar ou não
@param arr
@returns o nodo de menor peso
*/
double minimax(nodo *nodol, ESTADO *e, int depth, double alpha, double beta, BOOL player,BOOL caminh[8][8]);
COORDENADA *coor_create(int col, int lin);
#endif //RASTRO_REDES_H