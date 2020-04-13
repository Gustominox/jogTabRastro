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

void prompt (ESTADO *e){
    printf ("\n# ");
    printf ("%d ", obter_numero_de_comandos(e));
    printf ("PL%d ",obter_jogador_atual(e));
    printf ("(%d)> ",obter_numero_de_jogadas(e));
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    int r = 0;
    char nome[20];
    char comandos[4];

    prompt(e);

    if(fgets(linha, BUF_SIZE, stdin) == NULL) {
        return r;
    }

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h] %[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        coord.linha ++;
        coord.coluna ++;
        r = jogar(e, coord);
        if (r == 1) return r;
        e->num_comando ++;
        e->num_jogagas_por_j ++;
        comando_gr(e,stdout);
    } else {
        sscanf(linha ,"%s %s",&comandos,&nome);

        if (strcmp(comandos, "gr") == 0) {
            FILE *fp = fopen(nome, "w");
            comando_gr(e, fp);
            fclose(fp);
            e->num_comando++;
        }
        if (strcmp(comandos, "q") == 0) {
            r = comando_q(e);
            e->num_comando++;
        }
        if (strcmp(comandos, "ler") == 0) {
            comando_ler(e, nome);
            e->num_comando++;
        }
        if (strcmp(comandos, "movs") == 0) {
            comando_movs(e, stdout);
            e->num_comando++;
        }
        if (strcmp(comandos, "pos") == 0) {
            int n;
            sscanf(nome,"%d",&n);
            comando_pos(e,n);
            e->num_comando++;
        }
    }

    return r;
}

void comando_pos (ESTADO *e, int n){
    int k = e->num_comando;
    if (n < obter_numero_de_jogadas(e) && n > 0) {
        limpa_estado(e);
        for (int i = 0; i < n; i++){
            if (i != n-1){
                set_casa(e,e->jogadas[i].jogador1, PRETA);
                set_casa(e,e->jogadas[i].jogador2, PRETA);
            }
            else {
                set_casa(e,e->jogadas[i].jogador1, PRETA);
                set_casa(e,e->jogadas[i].jogador2, BRANCA);
                e->ultima_jogada = e->jogadas[i].jogador2;
            }
        }
        e->num_jogadas = n;
        e->num_comando = k;
        e->num_jogagas_por_j = n*2;
        COORDENADA coord;
        coord.coluna = 5;
        coord.linha = 5;
        if (n != 0)
            set_casa(e, coord, PRETA);
    } else printf("Impossível executar pos %d\n", n);
    comando_gr(e,stdout);
}

int comando_q(ESTADO *e){
    return 2;
}

void comando_ler(ESTADO *e, char nome[]){
    FILE *fp;
    fp=fopen(nome, "r");
    char temp;
    int cont = 0;
    int n_jogadas_p_jog = 0;
    int j = 0 , k = 7;
    for (int i = 0; i < BUF_SIZE; ++i) {
        temp = fgetc(fp);
        if (temp == EOF) break;
        if (i < 72) {
            if(j == 8) {
                j = 0;
                k--;
            }
            if (temp == '.') e->tab[j][k] = VAZIO;
            if (temp == '#') e->tab[j][k] = PRETA;
            if (temp == '*') e->tab[j][k] = BRANCA;
            if (temp == '1') e->tab[j][k] = UM;
            if (temp == '2') e->tab[j][k] = DOIS;
            if (temp == '\n')j--;
            j++;

        } else if (i > 72) {
            for (int l = 0; l < 3; ++l) fgetc(fp);
            char temp = fgetc(fp);
            char temp2 = fgetc(fp);

            COORDENADA c = transforma_jogada(temp, temp2);
            e->jogadas[cont].jogador1.coluna = c.coluna;
            e->jogadas[cont].jogador1.linha = c.linha;
            e->jogador_atual = 2;
            e->ultima_jogada = c;
            n_jogadas_p_jog ++;
            e->num_jogagas_por_j = n_jogadas_p_jog;
            cont ++;
            e->num_jogadas = cont;
            temp = fgetc(fp);
            if (temp == EOF) break;
            temp = fgetc(fp);
            temp2 = fgetc(fp);

            c = transforma_jogada (temp,temp2);
            e->jogadas[cont-1].jogador2.coluna = c.coluna;
            e->jogadas[cont-1].jogador2.linha = c.linha;
            e->jogador_atual = 1;
            e->ultima_jogada = c;
            n_jogadas_p_jog ++;
            e->num_jogagas_por_j = n_jogadas_p_jog;
            temp = fgetc(fp);
            if (temp == EOF) break;
        }
    }
    comando_gr(e,stdout);
}

COORDENADA transforma_jogada(char col, char lin){
    COORDENADA c = {col - 96, lin - 48};
    return c;

}

void comando_gr (ESTADO *e, FILE *fp) {
/**
Imprimir Tabuleiro

    comando_tab(e,fp);
*/
    comando_tab(e,fp);
/**
Imprimir Movimentos

    comando_movs(e,fp);
*/
    comando_movs(e,fp);

}

void comando_tab(ESTADO *e, FILE *fp){
    int col = 6;
    if(fp == stdout) printf( "8|");
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
    if(fp == stdout) printf( "7|");
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
        if(fp == stdout) printf( "%d", col--);
        if(fp == stdout) printf( "|");
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
    if(fp == stdout) printf ("  ABCDEFGH\n");
}

void comando_movs(ESTADO *e,FILE *fp){
    int cont = 0;
    for (int i = 0 ; i < e->num_jogagas_por_j; ++i) {
        if (i % 2 == 0) {
            int coluna_jog1 = e->jogadas[cont].jogador1.coluna;
            int linha_jog1 = e->jogadas[cont].jogador1.linha;
            if (cont < 9)
                fprintf(fp ,"0%d: %c%d", cont+1, coluna_jog1 + 96, linha_jog1);
            else fprintf(fp ,"%d: %c%d", cont+1, coluna_jog1 + 96, linha_jog1);
        } else {
            int coluna_jog2 = e->jogadas[cont].jogador2.coluna;
            int linha_jog2 = e->jogadas[cont].jogador2.linha;
            fprintf(fp ," %c%d\n", coluna_jog2+96, linha_jog2);
            cont ++;
        }
    }
}