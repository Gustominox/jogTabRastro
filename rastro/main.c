
#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <stdio.h>

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

    return 0;
}
