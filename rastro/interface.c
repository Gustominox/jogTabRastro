//
// Created by gusto on 3/10/20.
//

#include <stdio.h>
#include <string.h>
#include "interface.h"
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
    for (int i = 0; i < 8; i++) {
        if (obter_estado_casa(e,i,7) == VAZIO)
            printf(".");
        if (obter_estado_casa(e,i,7) == BRANCA)
            printf("*");
        if (obter_estado_casa(e,i,7) == PRETA)
            printf("#");
        if (obter_estado_casa(e,i,7) == DOIS)
            printf("2");
    }
    printf("\n7|");
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
    for (int i = 0; i < 8; i++) {
        if (obter_estado_casa(e,i,0) == UM)
            printf("1");
        if (obter_estado_casa(e,i,0) == VAZIO)
            printf(".");
        if (obter_estado_casa(e,i,0) == BRANCA)
            printf("*");
        if (obter_estado_casa(e,i,0) == PRETA)
            printf("#");
    }
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];

    printf ("\n  ABCDEFGH\n");
    printf ("# ");
    printf ("%d ", obter_numero_de_comandos(e));
    int j = obter_jogador_atual(e);
    printf ("PL%d ",j);
    printf ("(%d)> ",obter_numero_de_jogadas(e));

    if(fgets(linha, BUF_SIZE, stdin) == NULL) {
        return 0;
    }

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h] %[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        coord.linha ++;
        coord.coluna ++;
        int fim = jogar(e, coord);
        comando_q(e);
        mostrar_tabuleiro(e);
        if (fim == 0){
            printf("\nTerminar ");
            return 0;
        }
        e->num_comando ++;
    }
    return 1;
}

void comando_q (ESTADO *e) {
    FILE *fp;
    fp = fopen("c:\\jogo.txt", "w");
    int col = 6;
    fprintf(fp, "8|");
    for (int i = 0; i < 8; i++) {
        if (obter_estado_casa(e,i,7) == VAZIO)
            fprintf(fp, ".");
        if (obter_estado_casa(e,i,7) == BRANCA)
            fprintf(fp, "*");
        if (obter_estado_casa(e,i,7) == PRETA)
            fprintf(fp, "#");
        if (obter_estado_casa(e,i,7) == DOIS)
            fprintf(fp, "2");
    }
        fprintf(fp,"\n");
        fprintf(fp, "7|");
        for (int j = 6; j > 0; --j) {
            for (int i = 0; i < 8; ++i) {
                if (obter_estado_casa(e, i, j) == VAZIO)
                    fprintf(fp, ".");
                if (obter_estado_casa(e, i, j) == BRANCA)
                    fprintf(fp, "*");
                if (obter_estado_casa(e, i, j) == PRETA)
                    fprintf(fp, "#");
            }

            fprintf(fp, "\n");
            fprintf(fp, "%d", col--);
            fprintf(fp, "|");
        }
        for (int i = 0; i < 8; i++) {
            if (obter_estado_casa(e, i, 0) == UM)
                fprintf(fp, "1");
            if (obter_estado_casa(e, i, 0) == VAZIO)
                fprintf(fp, ".");
            if (obter_estado_casa(e, i, 0) == BRANCA)
                fprintf(fp, "*");
            if (obter_estado_casa(e, i, 0) == PRETA)
                fprintf(fp, "#");
        }
        fclose(fp);
}