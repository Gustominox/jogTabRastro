/**
@file main.c
Função que controla o progama.
*/
/**
@mainpage Projeto Li2

# Introdução

    Nesta cadeira, o objetivo do projeto é implementar o jogo Rastros.
    Este jogo acontece num tabuleiro de 8 por 8, onde a casa UM é a casa final do primeiro jogador, enquanto que a casa DOIS é a casa final do segundo jogador.
    Cada um dos jogadores, alternadamente, desloca a peça BRANCA (inicialmente na casa e5) para uma casa VAZIA, podendo fazê-lo numa direção vertical, horizontal ou diagonal. À medida que se joga, as casas previamente ocupadas pela peça BRANCA, passarão a ser ocupadas por uma peça PRETA, não podendo ser mais ocupadas por uma peça BRANCA.
    Ora, o jogador ganha se deslocar uma peça BRANCA até à sua respetiva casa final ou, então, se for capaz de impedir o seu adversário de jogar, bloqueando-o.

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

#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listas.h"
#include "io.h"

int main(){
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
    if (menu == 2) printf ("\nVenceu o jogador 1.\n");
    if (menu == 3) printf ("\nVenceu o jogador 2.\n");
    if (menu == 4) printf ("\nJogo terminado pelo user.\n");
    printf("\nTerminado o progama\n");

    return 0;
}
