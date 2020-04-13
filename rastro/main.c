
#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
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
    if (menu == 2) printf("\nTerminado o progama\n");
*/
    /*nodo *atual;
    COORDENADA c = {3,2};
    atual = init_nodo(atual,e->ultima_jogada,c,5.0);
    criar_rede (atual);*/
    LISTA l = criar_lista();
    LISTA l2;
    l = insere_cabeca(l,1);
    l = insere_cabeca(l,2);
    l2 = proximo(l);
    //l2 = insere_cabeca(proximo(l),2);
    l = remove_cabeca(l);
    l = remove_cabeca(l);
    int r = lista_esta_vazia(l);
    if (r == 0 ) printf("lista vazia\n");
    else printf("lista nao vazia\n");
    //printf("%d\n",r);
    return 0;
}

