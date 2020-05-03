/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef ___DADOS_H___//
#define  ___DADOS_H___
#define BUF_SIZE 1024


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

/**
\brief Tipo de dados para BOOL e testar se o caminho é válido
*/
typedef enum {
    FALSE,
    TRUE
}BOOL;


/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

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
    CASA tab[8][8];
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
    int num_comando;
    COORDENADA ultima_jogada;
    int num_jogadas_por_j;
} ESTADO;

/**
\brief Inicializa o valor do estado \n
Esta função inicializa o valor do estado
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
\brief Obtem o jogador atual
@returns 1 jogador atual, 2 jogador atual
*/
int get_jog_atual(ESTADO *e);

/**
\brief Muda o jogador atual
@param e Apontador para o estado
@param jog O jogador
*/
void set_jog_atual (ESTADO *e,int jog);

/**
\brief Obtem a última jogada
@returns última jogada
*/
COORDENADA get_ult_jog(ESTADO *e);

/**
\brief Muda a última jogada
@param e Apontador para o estado
@param col A coluna da coordenada
@param lin A linha da coordenada
*/
void set_ult_jog (ESTADO *e,int i,int j);

/**
\brief Obtem o número de jogadas
@return um inteiro
*/
int get_num_jog(ESTADO *e);

/**
\brief Muda o número de jogadas
@param estado Apontador para o estado
@param nov_jog O novo valor da jogada
 */
void set_num_jog(ESTADO *e,int nov_jog);

/**
\brief Obtem o número de jogadas por jogador
@return um inteiro
*/
int get_num_jog_joga(ESTADO *e);

/**
\brief Muda o número de jogadas por jogador
@param e Apontador para o estado
@param nov_jog_por_j Novo número de jogadas por jogador
*/
void set_num_jog_joga(ESTADO *e, int nov_jog_por_j);

/**
\brief Obtem o número de comandos
@return um inteiro
*/
int get_num_com(ESTADO *e);

/**
\brief Muda o número de comandos
@param e Apontador para o estado
@param nov_com Novo número de comandos
*/
void set_num_com(ESTADO *e, int nov_com);

/**
\brief Devolve o valor de uma casa
@param e Apontador para o estado
@param col A coluna da coordenada
@param lin A linha da coordenada
@returns O valor da casa
*/
CASA get_casa(ESTADO *e, int col, int lin);

/**
\brief Muda o valor de uma celula de tab
@param e Apontador para o estado
@param c A coordenada
@param casa O novo valor para a celula
*/
void set_casa (ESTADO *e, int col, int lin, CASA casa);

/*brief Devolve o valor de uma coordenada do jogador 1
@param e Apontador para o estado
@param n Posição no array
@returns uma coordenada
*/
COORDENADA get_arr_jog_j1 (ESTADO *e,int n);

/**
\brief Muda o valor de uma coordenada do jogador 1
@param e Apontador para o estado
@param n Posição no array
@param c A coordenada
*/
void set_arr_jog_j1 (ESTADO *e,int n, COORDENADA c);

/**
\brief Devolve o valor de uma coordenada do jogador 2
@param e Apontador para o estado
@param n Posição no array
@returns uma coordenada
*/
COORDENADA get_arr_jog_j2 (ESTADO *e,int n);

/**
\brief Muda o valor de uma coordenada do jogador 2
@param e Apontador para o estado
@param n Posição no array
@param c A coordenada
*/
void set_arr_jog_j2 (ESTADO *e,int n, COORDENADA c);


/**
\brief Limpa o estado
@param e Apontador para o estado
*/
void limpa_estado(ESTADO *e);

/**
\brief Cria coordenadas através dos inteiros
@param col A coluna da coordenada
@param lin A linha da coordenada
@return Uma COORDENADA
*/
COORDENADA criar_coordenada(int col, int lin);

/**
\brief Cria coordenadas através dos chars
@param col Char referente à coluna
@param lin Char referente à linha
@return Uma COORDENADA
*/
COORDENADA transforma_jogada(char col, char lin);

#endif //RASTRO_DADOS_H
