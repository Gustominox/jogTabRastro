/**
@file listas.c
Construção do código correspondente às funções que dizem respeito às listas ligadas.
*/

#include "stdlib.h"
#include "stdio.h"
#include "listas.h"
#include "dados.h"
#include "redes.h"
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
LISTA lista_cor_pos(ESTADO *e, COORDENADA c){
    LISTA lista = criar_lista();

     for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (c.coluna + i > 0 && c.coluna + i < 9 && c.linha + j > 0 && c.linha + j < 9) {
                CASA h = get_casa(e, c.coluna + i, c.linha + j);
                if (h == VAZIO || h == UM || h == DOIS) {
                    COORDENADA *p = coor_create(c.coluna + i, c.linha + j);
                    lista = insere_cabeca(lista, p);
                }
            }
     return lista;
}