/**
@file io.c
Construção do código correspondente às funções que dizem respeito à interação do utilizador com o jogo.
*/

#include "io.h"
#include "dados.h"


void comando_pos (ESTADO *e, int n){
    int k = get_num_com(e);
    if (n < get_num_jog(e) && n > 0){
        limpa_estado(e);
        for (int i = 0; i < n; i++){
            if (i != n-1){
                set_casa(e,get_arr_jog_j1(e,i).coluna-1,get_arr_jog_j1(e,i).linha-1, PRETA);
                set_casa(e,get_arr_jog_j2(e,i).coluna-1,get_arr_jog_j2(e,i).linha-1, PRETA);
            }
            else {
                set_casa(e,get_arr_jog_j1(e,i).coluna-1,get_arr_jog_j1(e,i).linha-1, PRETA);
                set_casa(e,get_arr_jog_j2(e,i).coluna-1,get_arr_jog_j2(e,i).linha-1, BRANCA);
                set_ult_jog(e,get_arr_jog_j2(e,i).coluna,get_arr_jog_j2(e,i).linha);
            }
        }
        set_num_jog(e,n);
        set_num_com(e,k);
        set_num_jog_joga(e,n*2);

        if (n != 0)
            set_casa(e, 4, 4, PRETA);
    } else printf("Impossível executar pos %d\n", n);
    comando_gr(e,stdout);
}

int comando_q(){
    return 4;
}

void comando_ler(ESTADO *e, char nome[]){
    FILE *fp;
    fp=fopen(nome, "r");
    char temp;
    int cont = 0;

    limpa_estado(e);
    int j = 0 , k = 7;
    for (int i = 0; i < BUF_SIZE; ++i) {
        temp = fgetc(fp);
        if (temp == EOF) break;
        if (i < 72) {
            if(j == 8) {
                j = 0;
                k--;
            }
            if (temp == '.') set_casa(e,j,k,VAZIO);
            if (temp == '#'){
                set_casa(e,j,k,PRETA);
                set_num_jog_joga(e,get_num_jog_joga(e)+1);
            }
            if (temp == '*'){
                set_casa(e,j,k,BRANCA);
                set_ult_jog(e,j+1,k+1);
            }
            if (temp == '1') set_casa(e,j,k,UM);
            if (temp == '2') set_casa(e,j,k,DOIS);
            if (temp == '\n') j--;
            j++;

        } else if (i > 72) {
            for (int l = 0; l < 3; ++l) fgetc(fp);
            char temp = fgetc(fp);
            char temp2 = fgetc(fp);

            COORDENADA c = transforma_jogada(temp, temp2);
            set_arr_jog_j1(e,cont,c);
            cont ++;

            temp = fgetc(fp);
            if (temp == EOF) break;
            temp = fgetc(fp);
            temp2 = fgetc(fp);

            c = transforma_jogada (temp,temp2);
            set_arr_jog_j2(e,cont-1,c);
            temp = fgetc(fp);
            if (temp == EOF) break;
        }
        //set_num_jog_joga(e,n_jogadas_p_jog);
        if (get_num_jog_joga(e) % 2 == 1){
            set_jog_atual(e,2);
            set_num_jog(e, (get_num_jog_joga(e)+1)/2);
        }
        else{
            set_jog_atual(e,1);
            set_num_jog(e, get_num_jog_joga(e)/2);
        }
    }
    comando_gr(e,stdout);
}


void comando_gr (ESTADO *e, FILE *fp) {
    comando_tab(e,fp);
    comando_movs(e,fp);
}

void comando_tab(ESTADO *e, FILE *fp){
    int col = 6;
    if(fp == stdout) printf( "8|");
    for (int i = 0; i < 8; i++) {
        if (get_casa(e,i,7) == VAZIO)
            fprintf(fp, ".");
        if (get_casa(e,i,7) == BRANCA)
            fprintf(fp, "*");
        if (get_casa(e,i,7) == PRETA)
            fprintf(fp, "#");
        if (get_casa(e,i,7) == DOIS)
            fprintf(fp, "2");
    }
    fprintf(fp,"\n");
    if(fp == stdout) printf( "7|");
    for (int j = 6; j > 0; --j) {
        for (int i = 0; i < 8; ++i) {
            if (get_casa(e, i, j) == VAZIO)
                fprintf(fp, ".");
            if (get_casa(e, i, j) == BRANCA)
                fprintf(fp, "*");
            if (get_casa(e, i, j) == PRETA)
                fprintf(fp, "#");
        }

        fprintf(fp, "\n");
        if(fp == stdout) printf( "%d", col--);
        if(fp == stdout) printf( "|");
    }
    for (int i = 0; i < 8; i++) {
        if (get_casa(e, i, 0) == UM)
            fprintf(fp, "1");
        if (get_casa(e, i, 0) == VAZIO)
            fprintf(fp, ".");
        if (get_casa(e, i, 0) == BRANCA)
            fprintf(fp, "*");
        if (get_casa(e, i, 0) == PRETA)
            fprintf(fp, "#");
    }
    if(fp == stdout) printf("\n");
    else fprintf(fp,"\n\n");

    if(fp == stdout) printf ("  ABCDEFGH\n");
}

void comando_movs(ESTADO *e,FILE *fp){
    int cont = 0;
    for (int i = 0 ; i < get_num_jog_joga(e); ++i) {
        if (i % 2 == 0) {
            int coluna_jog1 = get_arr_jog_j1(e,cont).coluna;
            int linha_jog1 = get_arr_jog_j1(e,cont).linha;
            if (cont < 9)
                fprintf(fp ,"0%d: %c%d", cont+1, coluna_jog1 + 96, linha_jog1);
            else fprintf(fp ,"%d: %c%d", cont+1, coluna_jog1 + 96, linha_jog1);
        } else {
            int coluna_jog2 = get_arr_jog_j2(e,cont).coluna;
            int linha_jog2 = get_arr_jog_j2(e,cont).linha;
            fprintf(fp ," %c%d\n", coluna_jog2+96, linha_jog2);
            cont ++;
        }
    }
}