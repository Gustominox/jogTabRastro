
#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "logica.h"
#include "dados.h"
#include "io.h"
#define BUF_SIZE 1024

void prompt (ESTADO *e){
    printf ("\n# ");
    printf ("%d ", get_num_com(e));
    printf ("PL%d ", get_jog_atual(e));
    printf ("(%d)> ", get_num_jog(e));
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
        set_num_com(e,get_num_com(e)+1);
        //e->num_comando ++;
        set_num_jog_joga(e,get_num_jog_joga(e)+1);
        //e->num_jogagas_por_j ++;
        comando_gr(e,stdout);
    } else {
        sscanf(linha ,"%s %s",&comandos,&nome);

        if (strcmp(comandos, "gr") == 0) {
            FILE *fp = fopen(nome, "w");
            comando_gr(e, fp);
            fclose(fp);
            set_num_com(e,get_num_com(e)+1);
            //e->num_comando++;
        }
        if (strcmp(comandos, "q") == 0) {
            r = comando_q(e);
            set_num_com(e,get_num_com(e)+1);
            //e->num_comando++;
        }
        if (strcmp(comandos, "ler") == 0) {
            comando_ler(e, nome);
            set_num_com(e,get_num_com(e)+1);
            //e->num_comando++;
        }
        if (strcmp(comandos, "movs") == 0) {
            comando_movs(e, stdout);
            set_num_com(e,get_num_com(e)+1);
            //e->num_comando++;
        }
        if (strcmp(comandos, "pos") == 0) {
            int n;
            sscanf(nome,"%d",&n);
            comando_pos(e,n);
            set_num_com(e,get_num_com(e)+1);
            //e->num_comando++;
        }
    }

    return r;
}
