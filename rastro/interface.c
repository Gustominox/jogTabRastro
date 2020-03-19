//
// Created by gusto on 3/10/20.
//

#include <stdio.h>
#include <string.h>
#include "logica.h"
#include "dados.h"
#define BUF_SIZE 1024


/*
A impressão do tabuleiro é composta de 3 fazes.
Na primeira fase, a 1ª linha do tabuleiro é impressa através do printf de "8|" que corresponde ao número da linha
seguida de uma repetição de 7 "." usando um "for" com um printf de "2" no final para correspoder á casa-objetivo do 2º
jogador.
Na segunda fase, as próximas 6 linhas do tabuleiro são feitas, imprimindo 48 "." divididos em 6 linhas e as 8 colunas
do tabuleiro, enquanto são colocados os respetivos números dessas e da linha final linhas do lado esquerdo do tabuleiro.
Por fim a última linha é impressa, sendo iniciado pelo printf de "1" para corresponder com a casa-objetivo do 1ª jogador
seguido pela repetição de "." 7 vezes usando um "for".
Para ser colocada cada letra que por baixo da sua coluna foi usado um printf de "\n  ABCDEFGH" para que o "A" ficasse
por baixo da primeira coluna e por aí adiante.
*/
void mostrar_tabuleiro(ESTADO *e) {
    int col = 6;
    printf ("8|");
    for (int i = 0; i < 7; i++) {
        if (obter_estado_casa(e,i,7) == VAZIO)
            printf(".");
        if (obter_estado_casa(e,i,7) == BRANCA)
            printf("*");
        if (obter_estado_casa(e,i,7) == PRETA)
            printf("#");
    }
    printf("2\n");
    printf("7|");
    for (int j = 6; j > 0; --j) {
        for (int i = 0; i < 8; ++i) {
            if (obter_estado_casa(e,i,j) == VAZIO)
                printf(".");
            if (obter_estado_casa(e,i,j) == BRANCA)
                printf("*");
            if (obter_estado_casa(e,i,j) == PRETA)
                printf("#");
        }

        printf("\n");
        printf ("%d", col--);
        printf ("|");
    }
    printf("1");
    for (int i = 1; i < 8; i++) {
        if (obter_estado_casa(e,i,0) == VAZIO)
            printf(".");
        if (obter_estado_casa(e,i,0) == BRANCA)
            printf("*");
        if (obter_estado_casa(e,i,0) == PRETA)
            printf("#");
    }
    printf ("\n  ABCDEFGH");
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}
