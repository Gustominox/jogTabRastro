
#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <stdio.h>

int main()
{
    ESTADO *e = inicializar_estado();
    COORDENADA c;
    c.coluna = 6;
    c.linha = 6;
    jogar(e,c);
    /*
        Representaçao   Posicoes na
        Do Tabuleiro    Matriz
        8|.......2      7|.|.|.|.|.|.|.|2|
        7|........      6|.|.|.|.|.|.|.|.|
        6|.....*..      5|.|.|.|.|.|*|.|.|
        5|....#...      4|.|.|.|.|#|.|.|.|
        4|........      3|.|.|.|.|.|.|.|.|
        3|........      2|.|.|.|.|.|.|.|.|
        2|........      1|.|.|.|.|.|.|.|.|
        1|1.......      0|1|.|.|.|.|.|.|.|
          ABCDEFGH        0|1|2|3|4|5|6|7|
     */

    mostrar_tabuleiro(e);
    int menu = 1;
    while (menu == 1)
    menu = interpretador(e);
    return 0;
}
