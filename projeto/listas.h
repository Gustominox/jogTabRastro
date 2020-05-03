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

LISTA criar_lista();

LISTA insere_cabeca(LISTA L, void *valor);

void *devolve_cabeca(LISTA L);

LISTA proximo(LISTA L);

LISTA remove_cabeca(LISTA L);

int lista_esta_vazia(LISTA L);

void limpar_lista (LISTA L);
int tmh_lista (LISTA L);
LISTA lista_cor_pos(ESTADO *e, COORDENADA c);
#endif //RASTRO_LISTAS_H