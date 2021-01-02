
#ifndef modulo_a_h
#define modulo_a_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int do_rle_aux(char buffer_e[],char buffer_s[],size_t tmh_buf);

void escreve_rle_seq(char buffer_s[], int *i_s,int cont_seq);

void escreve_rle(int n_letras, char letra, char buffer_s[], int *i_s);

void do_rle(char *nome_do_fich,size_t inp_size,float *compressao,unsigned long long *tamanho_ficheiro, long long *n_blocks, unsigned long *size_of_last_block, unsigned long *block_size, unsigned long *block_size_rle);
#endif //modulo_a_h
