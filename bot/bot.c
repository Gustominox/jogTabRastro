//
// Created by gusto on 5/2/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "bot.h"
#include "dados.h"
#include "redes.h"
#include "listas.h"
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

COORDENADA jog_random(ESTADO *e){
    srand (time (NULL));
    COORDENADA coor = e->ultima_jogada;
    LISTA lista = lista_cor_pos(e,coor);
    int n = tmh_lista(lista);
    int a = rand() % n;
    for (int i = 0; i < a; i++) {
        lista = remove_cabeca(lista);
    }
    COORDENADA *end = (COORDENADA *) devolve_cabeca(lista);
    COORDENADA r = *end;
    limpar_lista(lista);
    return r;
}

COORDENADA jog(ESTADO *e) {
    COORDENADA c = {5, 5};
    nodo *atual = (nodo *) malloc(sizeof(nodo));
    atual = init_nodo(0, atual, c, 0);
    BOOL caminh[8][8];
    iguala_tab(e,caminh);
    double minmax = minimax(atual, e, 8, NAN, NAN, TRUE,caminh);
    COORDENADA r = print_rede(atual->nodos, 100, minmax);
    printf("RESULTADO: %d %d :%lf\n", r.coluna,r.linha,minmax);
    return r;
}
