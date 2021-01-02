#include "modulo_a.h"
#include "blocos.h"

void escreve_rle(int n_letras, char letra, char buffer_s[], int *end_i_s){
int i_s = * end_i_s;
if (n_letras<4){
    for (int i = 0; i < n_letras; i++)
        {
            buffer_s[i_s+i] = letra;
        }
    *end_i_s = *end_i_s+n_letras;
    }else{

        buffer_s[i_s]='\0';

        buffer_s[i_s+1]=letra;
        
        buffer_s[i_s+2]=n_letras;
        *end_i_s = *end_i_s+3;
        

        

        
    }

}

void escreve_rle_seq(char buffer_s[], int *end_i_s,int cont_seq){
        int i_s = * end_i_s;
    
        buffer_s[i_s]='\0';
        buffer_s[i_s+1]='\0';
        buffer_s[i_s+2]=cont_seq;

        *end_i_s = *end_i_s+3;    
        
    
}


int do_rle_aux(char buffer_e[],char buffer_s[],size_t tmh_buf){

int i_s = 0;
int cont_seq=0;
char letra_anterior='\0';
int n_letras = 0;


for (int i = 0; i < tmh_buf; i++)
    {
            for (int j = i; j < tmh_buf; j++)
                if( buffer_e[j] == '\0'){//(buffer_e[j] == '{')&&(buffer_e[j+1] == '0')&&(buffer_e[j+2] == '}')){
                    cont_seq++;
                }else {
                    break;
                }
            
            if ((cont_seq>0)){
                escreve_rle(n_letras,letra_anterior,buffer_s,&i_s);
                n_letras = 0;
                escreve_rle_seq( buffer_s,&i_s,cont_seq);
                i = i + cont_seq-1;
                cont_seq = 0;
                letra_anterior ='\0';
                continue;
            }
            
        
        if (letra_anterior == buffer_e[i])
        {
            if (n_letras==255){
                escreve_rle(n_letras,letra_anterior,buffer_s,&i_s);
                n_letras = 0;
            }
            n_letras++;

        }else{
                
                escreve_rle(n_letras,letra_anterior,buffer_s,&i_s);
                n_letras = 1;
        }
        letra_anterior = buffer_e[i];
    }
escreve_rle(n_letras,letra_anterior,buffer_s,&i_s);

//printf("buffer entrada:%d-%d-%d-%d-%d-%d-%d-%d\n",buffer_e[0],buffer_e[1],buffer_e[2],buffer_e[3],buffer_e[4],buffer_e[5],buffer_e[6],buffer_e[7]);
//printf("buffer saida:%d-%d-%d-%d-%d-%d\n",buffer_s[0],buffer_s[1],buffer_s[2],buffer_s[3],buffer_s[4],buffer_s[5]);


return i_s;

}

void do_rle(char *nome_do_fich,size_t inp_size,float *compressao,unsigned long long *end_tamanho_ficheiro, long long *end_n_blocks, unsigned long *end_size_of_last_block, unsigned long *end_block_size, unsigned long *block_size_rle){
    
    
    unsigned long long tamanho_ficheiro = * end_tamanho_ficheiro;
    unsigned long long tamanho_ficheiro_s = 0;
    long long n_blocks = * end_n_blocks;
    unsigned long size_of_last_block = * end_size_of_last_block;
    unsigned long block_size = *end_block_size;
    int tmh_buf_s;
    //processamento_blocos(nome_do_fich,inp_size,&tamanho_ficheiro, &n_blocks, &size_of_last_block, &block_size);
    FILE *f_e = fopen(nome_do_fich, "rb");
    char nome_do_fich_rle [100];
    strcpy(nome_do_fich_rle,nome_do_fich);
    strcat(nome_do_fich_rle,".rle");
    FILE *f_s = fopen(nome_do_fich_rle, "w+");
    
    printf("print:%llu\n%lu\n%lld\n%lu\n", tamanho_ficheiro,block_size,n_blocks,size_of_last_block);
    printf("aqui");
    unsigned long tmh_buf_e;
    
    if (block_size > size_of_last_block) tmh_buf_e = block_size;
    else tmh_buf_e = size_of_last_block;
    char buffer_e[tmh_buf_e];
    
    char *buffer_s= malloc(67109888);
    int i = 0;

    
    for (i = 0; i < n_blocks-1; ++i){
        
        
        fread(buffer_e, block_size,1,f_e);
        tmh_buf_s = do_rle_aux(buffer_e,buffer_s,block_size);
        
        block_size_rle[i]=tmh_buf_s;
        tamanho_ficheiro_s = tamanho_ficheiro_s + block_size_rle[i];
        if (i==0){
            float aux = (block_size-tmh_buf_s);
            //printf("%d - %d = %f\n",tmh_buf,i_s,aux);abbbabbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaa
            *compressao = (aux/block_size);
            //printf("[%d]COMPRESSAO:%f\n",i,(*compressao));
        }             
        fwrite(buffer_s,tmh_buf_s,1,f_s);       
        }
        
        /*
            FILE *f_e_copiar = fopen(nome_do_fich, "rb");
            char buffer_copiar [tamanho_ficheiro];
            fread(buffer_copiar,tamanho_ficheiro,1,f_e_copiar);
            fwrite(buffer_copiar,tamanho_ficheiro,1,f_s);
            fclose(f_e_copiar);
    */
            fread(buffer_e, size_of_last_block,1,f_e);
            tmh_buf_s = do_rle_aux(buffer_e,buffer_s,size_of_last_block);
            
                if (i==0){
                float aux = (size_of_last_block-tmh_buf_s);
                //printf("%d - %d = %f\n",tmh_buf,i_s,aux);
                *compressao = (aux/size_of_last_block);
                //printf("COMPRESSAO ultimo:%f\n",(*compressao));
            }         
            fwrite(buffer_s,tmh_buf_s,1,f_s);
        free(buffer_s);
        tamanho_ficheiro_s = tamanho_ficheiro_s + tmh_buf_s;
        
        *end_tamanho_ficheiro = tamanho_ficheiro_s; 
        strcpy(nome_do_fich,nome_do_fich_rle);
        fclose(f_e);
        fclose(f_s);
        



}