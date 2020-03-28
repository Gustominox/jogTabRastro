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
    int r = 0;
    int j = obter_jogador_atual(e);
    int fim;
    //Prompt
    printf ("\n  ABCDEFGH\n");
    printf ("# ");
    printf ("%d ", obter_numero_de_comandos(e));
    printf ("PL%d ",j);
    printf ("(%d)> ",obter_numero_de_jogadas(e));

    if(fgets(linha, BUF_SIZE, stdin) == NULL) {
        return r;
    }

    char comandos[3];
    sscanf(linha ,"%s",&comandos);

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h] %[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        coord.linha ++;
        coord.coluna ++;
        fim = jogar(e, coord);
        if (fim == 1) return fim;
        mostrar_tabuleiro(e);
        e->num_comando ++;
    } else{
        if (strcmp(comandos, "gr") == 0){
            char nome[20];
            printf("Nome do ficheiro: ");
            scanf("%s", &nome);
            comando_gr(e,nome);
            char c;
            while((c = getchar()) != '\n' && c != EOF)
                /* apagar remains no stdin */ ;
        }
        if (strcmp(comandos, "q") == 0) r = comando_q(e);
        if (strcmp(comandos, "ler") == 0) {
            char nome[20];
            printf("Nome do ficheiro: ");
            scanf("%s", &nome);
            comando_ler(e,nome);
            char c;
            while((c = getchar()) != '\n' && c != EOF)
                /* apagar remains no stdin */ ;
        }
        if (strcmp(comandos, "movs") == 0) comando_movs(e);
        }



    if(fim == 2) r = 2;

    return r;
}

int comando_q(ESTADO *e){
    return 2;
}

void comando_ler(ESTADO *e, char nome[]){
    FILE *fp;
    fp=fopen(nome, "r");
    char c[200] ;
    char temp;
    int cont = 0;
    int n_comandos = 0;
    int j = 0 , k = 7;
    for (int i = 0; i < 200; ++i) {
        temp = fgetc(fp);
        if (temp == EOF) break;
        if (i < 88) {
            int mod = i % 11;
            if (mod > 1){
                if(j == 8) {
                    j = 0;
                    k--;
                }

                //printf("%d %d -",j,k);
                if (temp == '.') e->tab[j][k] = VAZIO; //printf("%c",temp);
                if (temp == '#') e->tab[j][k] = PRETA; //printf("%c",temp);
                if (temp == '*') e->tab[j][k] = BRANCA; //printf("%c",temp);
                if (temp == '1') e->tab[j][k] = UM; //printf("%c",temp);
                if (temp == '2') e->tab[j][k] = DOIS; //printf("%c",temp);
                //putchar('\n');
                if (temp == '\n') j--;
                j++;
            }
        } else if (i > 92) {
            char temp2 = fgetc(fp);
            COORDENADA c = transforma_jogada(temp, temp2);
            e->jogadas[cont].jogador1.coluna = c.coluna;
            e->jogadas[cont].jogador1.linha = c.linha;
            e->jogador_atual = 2;
            n_comandos ++;
            e->num_comando = n_comandos;
            temp = fgetc(fp);
            if (temp == EOF) break;
            temp = fgetc(fp);
            temp2 = fgetc(fp);
            c = transforma_jogada (temp,temp2);
            e->jogadas[cont].jogador2.coluna = c.coluna;
            e->jogadas[cont].jogador2.linha = c.linha;
            e->jogador_atual = 1;
            n_comandos ++;
            cont ++;
            e->num_comando = n_comandos;
            e->num_jogadas = cont;
            temp = fgetc(fp);
            if (temp == EOF) break;
            for (int l = 0; l < 4; ++l) fgetc(fp);
        }
    }
}

COORDENADA transforma_jogada(char x, char y){
    int x1 = x - 96;
    int y1 = y - 48;
    COORDENADA c ;
    c.coluna = x1;
    c.linha = y1;
    return c;
}
void comando_gr (ESTADO *e, char nome[]) {
    FILE *fp;
    fp = fopen(nome, "w");
    //Tabuleiro
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
        fprintf(fp,"\n\n");
        // Lista dos movimentos
    int cont = 0;
    for (int i = 0 ; i < e->num_comando; ++i) {
        if (i % 2 == 0) {
            int coluna_jog1 = e->jogadas[cont].jogador1.coluna;
            int linha_jog1 = e->jogadas[cont].jogador1.linha;
            if (cont < 10)
                fprintf(fp ,"0%d: %c%d", cont+1, coluna_jog1 + 96, linha_jog1);
            else fprintf(fp ,"%d: %c%d", cont+1, coluna_jog1 + 96, linha_jog1);
        } else {
            int coluna_jog2 = e->jogadas[cont].jogador2.coluna;
            int linha_jog2 = e->jogadas[cont].jogador2.linha;
            fprintf(fp ," %c%d\n", coluna_jog2+96, linha_jog2);
            cont ++;
        }
    }
        fclose(fp);
}

void comando_movs(ESTADO *e){
    int cont = 0;
    for (int i = 0 ; i < e->num_comando; ++i) {
        if (i % 2 == 0) {
            int coluna_jog1 = e->jogadas[cont].jogador1.coluna;
            int linha_jog1 = e->jogadas[cont].jogador1.linha;
            if (cont < 10)
                printf("0%d: %c%d", cont+1, coluna_jog1 + 96, linha_jog1);
                else printf("%d: %c%d", cont+1, coluna_jog1 + 96, linha_jog1);
        } else {
            int coluna_jog2 = e->jogadas[cont].jogador2.coluna;
            int linha_jog2 = e->jogadas[cont].jogador2.linha;
            printf(" %c%d\n", coluna_jog2+96, linha_jog2);
            cont ++;
        }
    }
}