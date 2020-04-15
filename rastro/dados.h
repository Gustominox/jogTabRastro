/**
@file dados.h
Definição do estado e das funções que o manipulam.
*/

#ifndef ___DADOS_H___//
#define  ___DADOS_H___
#define BUF_SIZE 1024

#include "dados.h"
#include "listas.h"

/**
\brief Tipo de dados para os erros
*/
typedef enum {
    OK,
    COORDENADA_INVALIDA,
    JOGADA_INVALIDA,
    ERRO_LER_TAB,
    ERRO_ABRIR_FICHEIRO,
} ERROS;

/**
\brief Tipo de dados para a casa
*/
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;

typedef enum {
    FALSE,
    TRUE
}BOOL;
BOOL caminh[8][8];
/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

typedef struct nodo * rede[8];
/**
 *
 */

typedef struct nodo{
    COORDENADA inicial;
    COORDENADA final;
    double peso;
    rede nodos;
}nodo;

/**
\brief Tipo de dados para a jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para o estado
*/
typedef struct {
    /** O tabuleiro */
    CASA tab[8][8];
    /** As jogadas */
    JOGADAS jogadas;
    /** O número das jogadas, usado no prompt */
    int num_jogadas;
    /** O jogador atual */
    int jogador_atual;
    /** O nº de comando, usado no prompt */
    int num_comando;
    /** A coordenada da última jogada */
    COORDENADA ultima_jogada;
    /** O nº de jogadas por jogador */
    int num_jogagas_por_j;
} ESTADO;

/**
\brief Muda o valor de uma celula de tab.
@param e Apontador para o estado
@param c A coordenada
@param casa O novo valor para a celula.
*/
void set_casa(ESTADO *e, COORDENADA c, CASA V);

/**
\brief Devolve o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@returns O valor da casa
*/
CASA obter_estado_casa(ESTADO *e, int i, int j);

/**
\brief Inicializa o valor do estado \n
Esta função inicializa o valor do estado.
Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.

Alocação da memória para o estado
O jogador atual a 1
O número de jogadas a 0
O número de jogadas por jogador a 0
A colocação da peça VAZIA em todas as casas
A posição da última jogada a coluna 5 e linha 5
Na casa (4,4), está uma peça BRANCA
Na casa (7,7), está uma peça DOIS
Na casa (0,0), está uma peça UM
O número de comandos a 0

@returns O novo estado
*/
ESTADO *inicializar_estado();

/**
\brief Obtem o jogador atual.
@returns 1 jogador atual, 2 jogador atual.
*/
int obter_jogador_atual(ESTADO *estado);

/**
\brief Obtem o número de jogadas.
@return um inteiro.
*/
int obter_numero_de_jogadas(ESTADO *estado);

/**
\brief Obtem o número de comandos.
@return um inteiro.
*/
int obter_numero_de_comandos(ESTADO *estado);

/**
\brief Muda o valor de uma celula de tab.
@param e Apontador para o estado
@param c A coordenada
@param casa O novo valor para a celula
*/
void set_casa (ESTADO *e, COORDENADA c, CASA casa);

/**
\brief Muda o jogador
@param e Apontador para o estado
@param n O jogador
*/
void set_jogador_atual (ESTADO *e,int n);

/**
\brief Limpa o estado
@param e Apontador para o estado
*/
void limpa_estado(ESTADO *e);



COORDENADA criar_coordenada(int col, int lin);
COORDENADA transforma_jogada(char x, char y);
nodo *init_nodo (nodo *nodol,COORDENADA final, COORDENADA inicial, double peso);
double calcular_peso_nodo(COORDENADA i, COORDENADA f);
void criar_rede (nodo *nodol,ESTADO *e);
nodo *menor_peso(nodo *rede[],int k);
//nodo *percorrer_rede(nodo *nodol,LISTA l);
void iguala_tab(ESTADO *e);

#endif //RASTRO_DADOS_H
