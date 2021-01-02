
#include <stdio.h>
#include <stdlib.h>
#include "blocos.h"
#include "modulo_a.h"
#include "interface.h"
#include "freq.h"

//Shell> shafa exemplo.txt -m f -c r 
//gcc -o bot *.c


/*{
    unsigned long long tamanho_ficheiro;
    long long n_blocks;
    unsigned long size_of_last_block;
    unsigned long block_size;
    size_t input_size = 65536;
    char nome_do_fich[100]="aaa.txt";
    printf("%s",nome_do_fich);
    processamento_blocos(nome_do_fich,input_size,&tamanho_ficheiro, &n_blocks, &size_of_last_block, &block_size); 
    printf("print:%llu\n%lu\n%lld\n%lu\n\n", tamanho_ficheiro,block_size,n_blocks,size_of_last_block);
    modulo_a_exe(nome_do_fich,input_size,&tamanho_ficheiro, &n_blocks, &size_of_last_block, &block_size);
    printf("print:%llu\n%lu\n%lld\n%lu\n", tamanho_ficheiro,block_size,n_blocks,size_of_last_block);

}*/

int main(){
    unsigned long long tamanho_ficheiro;
    long long n_blocks;
    unsigned long size_of_last_block;
    unsigned long block_size;
    int q = 1;
    int rle = 1;
    char inp_uti [1024];
    size_t input_size;
    char nome_do_fich[100];
    char nome_do_fich_rle[100]="";
    char mod;
    char temp1 = '\0';//c ou b
    char temp2 = '\0';
    char temp3 = '\0';//c ou b
    char temp4 = '\0';
    unsigned long block_size_simb         = 1000;
    unsigned long size_of_last_block_simb = 1000;
    float t_exec;
    float compressaototal;
    float compressao;
    
    while (q>0) {
    
        fgets(inp_uti, 1024, stdin);
        q = sscanf(inp_uti,"shafa %s -m %c -%c %c -%c %c",  nome_do_fich, &mod, &temp1,&temp2,&temp3,&temp4);
        printf("DEBUG : %d argumentos\t fich :%s\t mod:%c\t agr1:%c %c\t agr2:%c %c\n",q,nome_do_fich, mod, temp1,temp2,temp3,temp4);

        if (q == 0) continue;
        else {
            
            printf("Augusto Campos, a93320, MIEI/CD\nCarlos Silva, a93199, MIEI/CD\nTiago Alexandre Silva, a93182,MIEI/CD\nTiago Pinheiro Silva, a93285\n'data'\n");
                        
            if (mod == 'f') {
                if (temp1 == 'b') input_size = definir_tamanho_bloco_entrada(temp2);
                else input_size = definir_tamanho_bloco_entrada(temp4);
                
                        //excuta o modulo f
                        
                        processamento_blocos(nome_do_fich,input_size,&tamanho_ficheiro, &n_blocks, &size_of_last_block, &block_size); 
                        printf("print:%llu\n%lu\n%lld\n%lu\n", tamanho_ficheiro,block_size,n_blocks,size_of_last_block);
                        
                        unsigned long long tamanho_ficheiro_ori = tamanho_ficheiro;


                        printf("Módulo: f (cálculo das frequências dos símbolos)\n");
                        printf("Número de Blocos: %lld\n", n_blocks);
                        printf("Tamanho dos blocos analisados no ficheiro original: ");

                        for (int i = 0; i < n_blocks - 1; i++)
                            printf("%lu/", block_size);
                        printf("%lu bytes\n", size_of_last_block);
                        
                        unsigned long block_size_rle[n_blocks];
                        do_rle(nome_do_fich,input_size,&compressao,&tamanho_ficheiro, &n_blocks, &size_of_last_block, &block_size,block_size_rle);
                        
                        
                        //printf("COMPRESSAO:%f\n",compressao);
                        if (compressao<5.0)
                            rle =0;   
            
                    
                        if ((temp1 == 'c' && temp2 == 'r')||(temp3 =='c' && temp4 == 'r')) rle = 1;
                        //printf("RLE:%d\n",rle);
                        if (rle == 1){
                            
                            unsigned long long tamanho_ficheiro_rle = tamanho_ficheiro;
                            
                            strcpy(nome_do_fich_rle,nome_do_fich);
                            float aux = (tamanho_ficheiro_ori-tamanho_ficheiro_rle);

                            printf("%d - %d = %f",tamanho_ficheiro_ori,tamanho_ficheiro_rle,aux);
                            compressaototal = (aux/tamanho_ficheiro_ori*100);

                            printf("Compressão RLE: %s (%.2f%% compressão)\n",nome_do_fich, compressaototal);//Compressão RLE: exemplo.txt.rle (13% compressão)
                            
                            printf("Tamanho dos blocos analisados no ficheiro RLE: ");
                            for (int i = 0; i < n_blocks - 1; i++)
                                printf("%lu/", block_size_rle[i]);
                            printf("%lu bytes\n", size_of_last_block);

                            processamento_blocos(nome_do_fich_rle,input_size,&tamanho_ficheiro, &n_blocks, &size_of_last_block, &block_size); 
                       
                            do_freqM(nome_do_fich_rle,  &n_blocks, &size_of_last_block, &block_size);
                            
                        
                        }else{
                            
                            
                            processamento_blocos(nome_do_fich,input_size,&tamanho_ficheiro, &n_blocks, &size_of_last_block, &block_size); 
                       
                            do_freqM(nome_do_fich,  &n_blocks, &size_of_last_block, &block_size);
                            
                        }
                        
        
                            printf("Tempo de excução do módulo (ms): %f\n", t_exec);
                            printf("Ficheiros gerados: %s %s\n", nome_do_fich, nome_do_fich_rle);    
                        
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
                printf("Tempo de execução do módulo (ms): %f\n", t_exec);
                printf("Ficheiro gerado: %s.cod\n", nome_do_fich);
                q = 0;
            }
                else printf("Erro na introduçao de dados\n");
                q = 0;
        }
    }

}




/*{
unsigned long long tamanho_ficheiro;
long long n_blocks;
unsigned long size_of_last_block, block_size;
char nome_do_fich [100] = "ddd.rle";
char inp_size = 'b';
processamento_blocos(nome_do_fich,inp_size,&tamanho_ficheiro, &n_blocks, &size_of_last_block, &block_size);

printf("print:%llu\n%lu\n%lld\n%lu\n", tamanho_ficheiro,block_size,n_blocks,size_of_last_block);
do_freqM(nome_do_fich,&tamanho_ficheiro, &n_blocks, &size_of_last_block, &block_size);
}


*/