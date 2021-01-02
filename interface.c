#include "interface.h"
/* colocar a data
 * excutar os modulos
 * tempo de exec
 *
*/

size_t definir_tamanho_bloco_entrada (char inp_size) {
    size_t tam = 65536;
    if (inp_size == 'K') tam = 655360;
    if (inp_size == 'm') tam = 8388608;
    if (inp_size == 'M') tam = 67108864;
    return tam;
}

void interface (){
    long long n_blocks = 3;
    unsigned long size_of_last_block = 1000;
    unsigned long block_size =1000;
    int q = 1;
    int rle = 0;
    char inp_uti [1024];
    size_t input_size;
    char nome_do_fich[100];
    char mod;
    char temp1 = '\0';//c ou b
    char temp2 = '\0';
    char temp3 = '\0';//c ou b
    char temp4 = '\0';
    unsigned long block_size_rle          = 1000;
    unsigned long block_size_rle_list [n_blocks-1];
    unsigned long size_of_last_block_rle  = 1000;
    unsigned long block_size_simb         = 1000;
    unsigned long size_of_last_block_simb = 1000;
    float t_exec;
    while (q>0) {
        fgets(inp_uti, 1024, stdin);
        q = sscanf(inp_uti,"shafa %s -m %c -%c %c -%c %c",  nome_do_fich, &mod, &temp1,&temp2,&temp3,&temp4);
        printf("%d argumentos,\n fich :%s,\n mod:%c,\n agr1:%c %c,\n agr2:%c %c\n",q,nome_do_fich, mod, temp1,temp2,temp3,temp4);

        if (q == 0) continue;
        else {
            printf("Augusto Campos, a93320, MIEI/CD\nCarlos Silva, a93199, MIEI/CD\nTiago Alexandre Silva, a93182,MIEI/CD\nTiago Pinheiro Silva, a93285\n'data'\n");
            if (mod == 'f') {
                if (temp1 == 'b') input_size = definir_tamanho_bloco_entrada(temp2);
                else input_size = definir_tamanho_bloco_entrada(temp4);
                if ((temp1 == 'c' && temp2 == 'r')||(temp3 =='c' && temp4 == 'r')) rle = 1;
                        //excuta o modulo f
                        printf("Módulo: f (cálculo das frequências dos símbolos)\n");
                        printf("Número de Blocos: %lld\n", n_blocks);
                        printf("Tamanho dos blocos analisados no ficheiro original: ");
                        for (int i = 0; i < n_blocks - 1; i++)
                            printf("%lu/", block_size);
                        printf("%lu bytes\n", size_of_last_block);
                        if (rle == 1){
                            printf("Compressão RLE:\n");
                            printf("Tamanho dos blocos analisados no ficheiro RLE: ");
                            for (int i = 0; i < n_blocks - 1; i++)
                                printf("%lu/", block_size_rle);
                            printf("%lu bytes\n", size_of_last_block_rle);
                            printf("Tempo de excução do módulo (ms): %f\n", t_exec);
                            printf("Ficheiro gerado: %s.rle.freq\n", nome_do_fich);
                        }
                printf("Tempo de excução do módulo (ms): %f\n", t_exec);
                printf("Ficheiro gerado: %s.freq\n", nome_do_fich);
                q = 0;
            }
            else if (mod == 't') {
                //excuta o modulo t
                printf("Módulo: t (cálculo dos códigos dos símbolos)\n");
                printf("Número de Blocos: %lld\n", n_blocks);
                printf("Tamanho dos blocos analisados no ficheiro de símbolos: ");
                for (int i = 0; i < n_blocks - 1; i++)
                    printf("%lu/", block_size_simb);
                printf("%lu bytes\n", size_of_last_block_simb);
                printf("Tempo de excução do módulo (ms): %f\n", t_exec);
                printf("Ficheiro gerado: %s.cod\n", nome_do_fich);
                q = 0;
            }
                else printf("Erro na introduçao de dados\n");
                q = 0;
        }
    }

}

/*
Shell> shafa exemplo.txt -m f -c r -b K
Shell> shafa exemplo.txt -m f -b K -c r

 John Doe, a12234, MIEI/CD, 1-jan-2021
Módulo: f (cálculo das frequências dos símbolos)
Número de blocos: 2
Tamanho dos blocos analisados no ficheiro original: 65536/2013 bytes
Compressão RLE: exemplo.txt.rle (13% compressão)
Tamanho dos blocos analisados no ficheiro RLE: 57444/1620 bytes
Tempo de execução do módulo (milissegundos): 12
Ficheiros gerados: exemplo.txt.freq, exemplo.txt.rle.freq
 *
 *
 John Doe, a12234, MIEI/CD, 1-jan-2021
Módulo: t (cálculo dos códigos dos símbolos)
Número de blocos: 2
Tamanho dos blocos analisados no ficheiro de símbolos: 57444/1620 bytes
Tempo de execução do módulo (milissegundos): 296
Ficheiro gerado: exemplo.txt.rle.cod
 */
