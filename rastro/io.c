/**
@file io.c
Construção do código correspondente às funções que dizem respeito à interação do utilizador com o jogo.
*/

#include "io.h"
#include "dados.h"


void comando_pos (ESTADO *e, int n){
    int k = get_num_comandos(e);
    if (n < get_num_jog(e) && n > 0){
        limpa_estado(e);
        for (int i = 0; i < n; i++){
            if (i != n-1){
                set_casa(e,get_arr_jog_j1(e,i), PRETA);
                set_casa(e,get_arr_jog_j2(e,i), PRETA);
            }
            else {
                set_casa(e,get_arr_jog_j1(e,i), PRETA);
                set_casa(e,get_arr_jog_j2(e,i), BRANCA);
                set_ult_jog(e,get_arr_jog_j2(e,i).coluna,get_arr_jog_j2(e,i).linha);
                //e->ultima_jogada = e->jogadas[i].jogador2;
            }
        }
        set_num_jog(e,n);
        //e->num_jogadas = n;
        set_num_comandos(e,k);
        //e->num_comando = k;
        set_num_jog_joga(e,n*2);
        //e->num_jogagas_por_j = n*2;
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
            if (temp == '.') set_casa(e,j,k,VAZIO);//e->tab[j][k] = VAZIO
            if (temp == '#'){
                set_casa(e,j,k,PRETA);//e->tab[j][k] = PRETA
                set_num_jog_joga(e,get_num_jog_joga(e)+1);//n_jogadas_p_jog++
            }
            if (temp == '*'){
                set_casa(e,j,k,BRANCA);//e->tab[j][k] = BRANCA
                set_ult_jog(e,j+1,k+1);
                //e->ultima_jogada.coluna = j+1
                //e->ultima_jogada.linha = k+1
            }
            if (temp == '1') set_casa(e,j,k,UM);//e->tab[j][k] = UM
            if (temp == '2') set_casa(e,j,k,DOIS);//e->tab[j][k] = DOIS
            if (temp == '\n') j--;
            j++;

        } else if (i > 72) {
            for (int l = 0; l < 3; ++l) fgetc(fp);
            char temp = fgetc(fp);
            char temp2 = fgetc(fp);

            COORDENADA c = transforma_jogada(temp, temp2);
            set_arr_jog_j1(e,cont,c);
            //e->jogadas[cont].jogador1.coluna = c.coluna
            //e->jogadas[cont].jogador1.linha = c.linha
            cont ++;

            temp = fgetc(fp);
            if (temp == EOF) break;
            temp = fgetc(fp);
            temp2 = fgetc(fp);

            c = transforma_jogada (temp,temp2);
            set_arr_jog_j2(e,cont-1,c);
            //e->jogadas[cont-1].jogador2.coluna = c.coluna
            //e->jogadas[cont-1].jogador2.linha = c.linha
            temp = fgetc(fp);
            if (temp == EOF) break;
        }
        set_num_jog_joga(e,n_jogadas_p_jog);
        //e->num_jogagas_por_j = n_jogadas_p_jog
        if (get_num_jog_joga(e) % 2 == 1){
            set_jog_atual(e,2);
            //e->jogador_atual = 2
            set_num_jog(e, (get_num_jog_joga(e)+1)/2);
            //e->num_jogadas = (e->num_jogagas_por_j+1)/2
        }
        else{
            set_jog_atual(e,1);
            //e->jogador_atual = 1
            set_num_jog(e, get_num_jog_joga(e)/2);
            //e->num_jogadas = (e->num_jogagas_por_j / 2)
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
    printf("\n%d %d %d %d\n",e->num_jogagas_por_j,e->jogador_atual,e->num_comando,e->num_jogadas);
    printf("\nultima jogada:%d %d\n",e->ultima_jogada.coluna,e->ultima_jogada.linha);
}