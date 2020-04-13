//
// Created by gusto on 4/13/20.
//
#include "listas.h"
#include "stdlib.h"
LISTA criar_lista(){
    LISTA l;
    l.cabeca = NULL;
    l.prox = NULL;
    return l;
}

LISTA insere_cabeca(LISTA l, void *valor){
    LISTA cabeca;
    //cabeca.cabeca = malloc(sizeof(valor));
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