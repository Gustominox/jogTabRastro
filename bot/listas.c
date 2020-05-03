/**
@file listas.c
Construção do código correspondente às funções que dizem respeito às listas ligadas.
*/

#include "stdlib.h"
#include "stdio.h"
#include "listas.h"
#include "dados.h"
LISTA criar_lista(){
    return NULL;
}

LISTA insere_cabeca(LISTA L, void *valor){
    LISTA aux;
    aux = (LISTA) malloc(sizeof(lista));
    aux -> cabeca = valor;
    aux -> cauda = L;
    return aux;
}

LISTA proximo(LISTA L){
    return (L -> cauda);
}

void *devolve_cabeca(LISTA L){
    void *head;
    if (L == NULL) printf("lista vazia\n");
    head = L -> cabeca;
    return head;
}

LISTA remove_cabeca(LISTA L){
    LISTA aux = L -> cauda;
    free (L);
    return aux;
}

int lista_esta_vazia(LISTA L){
    if (L == NULL)
        return 1;
    else
        return 0;
}

void limpar_lista (LISTA L){
    while (!lista_esta_vazia (L))
        L = remove_cabeca (L);
}
int tmh_lista (LISTA L){
    int n = 0;
    LISTA aux = L;
    while (aux != NULL) {
        aux = proximo(aux);
        n++;
    }
    return n;
}
