#include "blocos.h"
#include "interface.h"
#include "fsize.h"

void processamento_blocos(char nome_do_fich[],size_t inp_size,unsigned long long *tamanho_ficheiro, long long *n_blocks, unsigned long *size_of_last_block, unsigned long *block_size){

FILE *f_e;

 
f_e = fopen(nome_do_fich, "rb");

*block_size = inp_size;// "[-b K|m|M] ou null" - size_t size [65 536 bytes, 6415360 bytes]  

*n_blocks = fsize(f_e, NULL, block_size, size_of_last_block);
*tamanho_ficheiro = (*n_blocks-1) * *block_size + *size_of_last_block; 

if(*size_of_last_block < 1024) {
    *n_blocks = *n_blocks-1;
    *size_of_last_block = *block_size+*size_of_last_block;
    }
    fclose(f_e);
}