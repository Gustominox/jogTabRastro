
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
    // VAZIO -> 0 | BRANCA -> 1 | PRETA -> 2
    printf("%u\n%u\n%u",e->tab[3][3] ,e->tab[5][5] ,e->tab[4][4]);
    interpretador(e);
    return 0;
}
