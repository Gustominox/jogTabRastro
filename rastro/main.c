
#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listas.h"
int main(){
    /**
@mainpage Projeto Li2

# Introdução

Pequena introducao


## Representaçao Do Tabuleiro

    8|.......2
    7|........
    6|....#*..
    5|....#...
    4|........
    3|........
    2|........
    1|1.......
      ABCDEFGH
@note output da função comando_gr (ESTADO *e, FILE *stdout);
@see comando_gr (ESTADO, FILE);

## Posicoes na Matriz

    |7|.|.|.|.|.|.|.|2| // e->tab[7][7] = DOIS;
    +-+-+-+-+-+-+-+-+-+
    |6|.|.|.|.|.|.|.|.| // e->tab[5][6] = VAZIO;
    +-+-+-+-+-+-+-+-+-+
    |5|.|.|.|.|#|*|.|.| // e->tab[5][5] = BRANCA;
    +-+-+-+-+-+-+-+-+-+ // e->tab[4][5] = PRETA;
    |4|.|.|.|.|#|.|.|.| // e->tab[4][4] = PRETA;
    +-+-+-+-+-+-+-+-+-+
    |3|.|.|.|.|.|.|.|.|
    +-+-+-+-+-+-+-+-+-+
    |2|.|.|.|.|.|.|.|.|
    +-+-+-+-+-+-+-+-+-+
    |1|.|.|.|.|.|.|.|.|
    +-+-+-+-+-+-+-+-+-+
    |0|1|.|.|.|.|.|.|.| // e->tab[0][0] = UM;
    +-+-+-+-+-+-+-+-+-+
      |0|1|2|3|4|5|6|7|

     */


    ESTADO *e = inicializar_estado();
/*
    comando_gr(e,stdout);
    int menu = 0;
    while (menu == 0) {
        menu = interpretador(e);
        if (menu == 1) {
            printf("Jogada Invalida");
            menu = 0;
        }
    }
    if (menu == 2) printf ("\nVenceu o jogador 1.\n");
    if (menu == 3) printf ("\nVenceu o jogador 2.\n");
    printf("\nTerminado o progama\n");
*/

    //COORDENADA *cpnt;
    COORDENADA c = {6,6};
    //cpnt = &c;
    //l.cabeca = &c.coluna;
    //l = insere_cabeca(l,x);
    //ler_lista_double(l);
    //COORDENADA *coord = l.cabeca;
    //printf("%d\n",coord->coluna);

    nodo *atual;
    atual = init_nodo(0,atual,e->ultima_jogada,c,0,TRUE);
    printf("MINIMAX: %lf\n",minimax(atual,e,2,NAN,NAN,TRUE,coords));
    printf("%d %d",coords[2].coluna,coords[2].linha);


    //printf("%lf",min(NAN,1.0));
    //printf("%lf\n", atual->peso);
    //if (isnan(atual->peso)) printf("okay\n");
    //else printf("nao okay\n");
    //double peso = calcular_peso_nodo(c,coor);v
    //printf("%lf\n",NAN+1.00);    //atual = init_nodo(atual,e->ultima_jogada,c,-1.0);
    //iguala_tab(e);
    //criar_rede (atual,e,FALSE);
    //criar_rede (atual,e,TRUE);
    //print_rede(atual->nodos);
    //printf("nodo escolhido: %d %d",nodoprox.coluna,nodoprox.linha);
    //menor_peso(atual->nodos);
    //insere_cabeca(l,2);
    //percorrer_rede(atual,l);
    //ler_lista_double(l);

    return 0;
}

