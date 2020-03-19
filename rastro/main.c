
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
        8|.......2      7|.......2
        7|........      6|........
        6|.....*..      5|.....*..
        5|....#...      4|....#...
        4|........      3|........
        3|........      2|........
        2|........      1|........
        1|1.......      0|1.......
          ABCDEFGH        01234567

        VAZIO -> 0 | BRANCA -> 1 | PRETA -> 2
     */
    printf("%u\n%u\n%u\n",e->tab[3][4] ,e->tab[5][2] ,e->tab[4][3]);
    mostrar_tabuleiro(e);
    interpretador(e);
    return 0;
}
