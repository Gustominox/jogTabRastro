/**
@file listas.h
Definição das funções referentes às listas ligadas.
*/
#ifndef RASTRO_LISTAS_H
#define RASTRO_LISTAS_H

#include "dados.h"

typedef struct lista{
    void *cabeca;
    struct lista *cauda;
} *LISTA,lista;

// Cria uma lista vazia
LISTA criar_lista();

// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *valor);

// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L);

// Devolve a cauda da lista
LISTA proximo(LISTA L);

// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);

// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L);

void limpar_lista (LISTA L);
int tmh_lista (LISTA L);
LISTA lista_cor_pos(ESTADO *e, COORDENADA c);
#endif //RASTRO_LISTAS_H