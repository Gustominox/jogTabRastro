#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listas.h"
#include "io.h"
#include "bot.h"

int main(int argc, char *argv[ ]){
    if(argc<2) exit(0);
    ESTADO *e = inicializar_estado();
    comando_ler(e,argv[1]);
    jogar(e,jog(e));
    set_num_com(e,get_num_com(e)+1);
    set_num_jog_joga(e,get_num_jog_joga(e)+1);
    FILE *fp = fopen(argv[2], "w");
    comando_gr(e, fp);
    fclose(fp);
}
