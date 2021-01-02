#include <string.h>
#include <stdio.h>

int ulong_string(unsigned long x,char *alg);

int llong_string(long long x,char *alg);

int int_string(int x,char *alg);



int do_freqAUX(char *buffer_e, char *buffer_s, unsigned long block_size);

void do_freqM (char *nome_do_fich,  long long *n_blocks, unsigned long *size_of_last_block, unsigned long *block_size);
