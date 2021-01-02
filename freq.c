#include <string.h>
#include <stdio.h>

int ulong_string(unsigned long x,char *alg){
    char aux[21];
    int r;
    int i; 
    for (i = 0; x > 0 ; i++){
        aux[i] = x%10 + 48;
        x = x/10;
    }
    r = i;
    for(int j = 0; i >= 0; j++){
        alg[j] = aux[i-1];
        i--;
    }
    return r;
}

int llong_string(long long x,char *alg){
    char aux[21];
    int r;
    int i; 
    for (i = 0; x > 0 ; i++){
        aux[i] = x%10 + 48;
        x = x/10;
    }
    r = i;
    for(int j = 0; i >= 0; j++){
        alg[j] = aux[i-1];
        i--;
    }
    return r;
}

int int_string(int x,char *alg){
    char aux[21];
    int r;
    int i;
    if (x != 0){
        for (i = 0; x > 0 ; i++){
            aux[i] = x%10 + 48;
            x = x/10;
        }
        r = i;
        for(int j = 0; i >= 0; j++){
            alg[j] = aux[i-1];
            i--;
        }
    }
    else {
        alg[0] = '0';
        r = 1;
    }
    return r;

}



int do_freqAUX(char *buffer_e, char *buffer_s, unsigned long block_size){
    int frequencias[256];
    for(int k = 0; k < 256; k++)
        frequencias[k] = 0;
    for(int i = 0; i < block_size; i++){
        char c = buffer_e[i];
        frequencias[c]++;
    }
    char alg[21];
    int t = ulong_string(block_size, alg);
    strcpy(buffer_s, alg);
    int i_s = t;
    buffer_s[i_s] = '@';
    i_s++;
    t = int_string(frequencias[0], alg);
    int last_freq = frequencias[0];
    strcpy(buffer_s + i_s, alg);
    i_s = i_s + t;
    buffer_s[i_s] = ';';
    i_s++;
    for (int i = 1; i < 256; i++){
        if (frequencias[i] != last_freq){
            t = int_string(frequencias[i], alg);
            strcpy(buffer_s + i_s, alg);
            i_s = i_s + t;
        }
        last_freq = frequencias[i];
        if (i < 255){
            buffer_s[i_s] = ';';
        i_s++;
}
    }
    buffer_s[i_s] = '@';
    i_s++;
    return i_s;
}

void do_freqM (char *nome_do_fich, long long *n_blocks, unsigned long *size_of_last_block, unsigned long *block_size){
    
    FILE *f_e = fopen(nome_do_fich, "rb");
    char nome_do_fich_freq [100];
    strcpy(nome_do_fich_freq,nome_do_fich);
    strcat(nome_do_fich_freq,".freq");
    FILE *f_s = fopen(nome_do_fich_freq, "w+");
    int i_s;
    unsigned long tmh_buffer_e;
    char alg[21];
    int i;
    
    
    if (*block_size > *size_of_last_block) tmh_buffer_e = *block_size;
    else tmh_buffer_e = *size_of_last_block;
    
    char buffer_e[tmh_buffer_e];
    char buffer_s[128000];

    buffer_s[0] = '@';
    buffer_s[1] = 'N';
    buffer_s[2] = '@';
    int t =llong_string(*n_blocks, alg);
    strcpy(buffer_s + 3, alg);
    i_s = 3 + t;
    buffer_s[i_s]= '@';
    i_s++;
    fwrite(buffer_s, i_s, 1, f_s);


    for (int j = 0; j < *n_blocks-1; j++){
        fread(buffer_e, *block_size, 1, f_e);
        int tmh_buffer_s = do_freqAUX(buffer_e, buffer_s, *block_size);
        fwrite(buffer_s, tmh_buffer_s, 1 , f_s);
    }
    fread(buffer_e, *size_of_last_block, 1, f_e);
    int tmh_buffer_s = do_freqAUX(buffer_e, buffer_s, *size_of_last_block);
    buffer_s[tmh_buffer_s] = '0';
    tmh_buffer_s++;
    fwrite(buffer_s, tmh_buffer_s, 1 , f_s);
    strcpy(nome_do_fich,nome_do_fich_freq);
}
