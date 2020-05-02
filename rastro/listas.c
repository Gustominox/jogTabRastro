/**
@file listas.c
Construção do código correspondente às funções que dizem respeito às listas ligadas.
*/
#include "listas.h"
#include "stdlib.h"
#include "stdio.h"

LISTA criar_lista(){
    LISTA l;
    l.cabeca = NULL;
    l.prox = NULL;
    return l;
}

LISTA insere_cabeca(LISTA l, void *valor){
    LISTA cabeca;
    cabeca.cabeca = valor;
    cabeca.prox = malloc(sizeof(LISTA));
    *cabeca.prox = l;
    return cabeca;
}

void *devolve_cabeca(LISTA l){
    return l.cabeca;
}

LISTA proximo(LISTA l){
    LISTA lprox = *l.prox;
    return lprox;
}

LISTA remove_cabeca(LISTA l){
    LISTA prox = proximo(l);
    //free(l.cabeca);
    free(l.prox);
    return prox;
}

int lista_esta_vazia(LISTA l){
    int r = 0;
    if(l.prox == NULL) r = 0;
    else r = 1 + lista_esta_vazia(*l.prox);
    return r;
}

void ler_lista_double(LISTA l){
    if (l.prox != NULL){
        printf("%d",l.cabeca);
        ler_lista_double(*l.prox);
    }
}