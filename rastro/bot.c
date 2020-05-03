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

COORDENADA jog(ESTADO *e){

    LISTA lista = criar_lista();
    nodo *atual = (nodo*)malloc(sizeof(nodo));
    init_nodo(0,atual,get_ult_jog(e),get_ult_jog(e),0);
    criar_rede(atual,e,TRUE);
    iguala_tab(e);
    COORDENADA *coord = (COORDENADA*)malloc(sizeof(COORDENADA));
    //printf("MINIMAX: %lf\n",minimax(atual,e,2,NAN,NAN,TRUE,coord));

    limpar_lista(lista);
    printf("%d %d\n", coord->coluna,coord->linha);
    return *coord;
}