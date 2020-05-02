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
    COORDENADA inicial;
    COORDENADA final;
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
nodo *init_nodo (double peso_nd_ant, nodo *nodol, COORDENADA final, COORDENADA inicial, double peso,BOOL player);

/**
\brief Calcula o peso do nodo, pelo Teorema de Pitágoras
@param i Coordenada do nodo inicial
@param f Coordenada do nodo final
@param player Variável que indica se é o jogador atual a jogar ou não
@returns o peso do nodo
*/
double calcular_peso_nodo(COORDENADA i, COORDENADA f,BOOL player);

/**
\brief Para um dado nodo, inicia os nodos contidos no seu array "nodos"
@param nodol Nodo local
@param e Apontador para o estado
@param player Variável que indica se é o jogador atual a jogar ou não
@returns o tamanho da rede
*/
int criar_rede (nodo *nodol,ESTADO *e,BOOL player);

/**
\brief Dado uma rede e o seu tamanho, retorna o nodo de menor peso
@param rede Array de pointers de nodos
@param k O tamanho do array
@returns o nodo de menor peso
*/
nodo *menor_peso(nodo *rede[],int k);

/**
\brief Iguala os valores do tabuleiro com uma matriz de igual tamanho, em que uma peça __PRETA__ é *true* e qualquer outra
 peça é *false*.
@param e Apontador para o estado
*/
void iguala_tab(ESTADO *e);

/**
\brief Troca os nodos de posição um com o outro
@param nodo1 Primeiro nodo
@param nodo2 Segundo nodo
@returns o nodo de menor peso
*/
void trocarNodos(nodo *nodo1, nodo *nodo2);

/**
\brief Organiza a rede, segundo uma modificação do valor sort em que os nodos inválidos são postos no fim do array
@param rede Array de pointers de nodos
@returns número de nodos válidos
*/
int organiza_rede(nodo *rede[]);

/**
\brief Mostra os valores da rede, função criada para debug
@param rede Array de pointers de nodos
@param num_nodos Tamanho da rede
*/
void print_rede(nodo *rede[],int num_nodos);

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
double minimax(nodo *nodol, ESTADO *e, int depth, double alpha, double beta, BOOL player, COORDENADA *arr);

#endif //RASTRO_REDES_H