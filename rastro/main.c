
#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <stdio.h>

int main()
{
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

    ESTADO *e = inicializar_estado();


    mostrar_tabuleiro(e);
    int menu = 0;
    while (menu == 0) {
        menu = interpretador(e);
        if (menu == 1) {
            printf("Jogada Invalida");
            menu = 0;
        }
    }
    if (menu == 2) printf("\nTerminado o progama\n");
    lista_movs(e);
    return 0;
}
