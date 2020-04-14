//
// Created by gusto on 4/13/20.
//

#ifndef RASTRO_LISTAS_H
#define RASTRO_LISTAS_H
typedef struct LISTA{
    void* cabeca;
    struct LISTA* prox;
}LISTA;
// Cria uma lista vazia
LISTA criar_lista();
// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *valor);
// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L);
// Devolve a cauda da lista
LISTA proximo(LISTA L);
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);
// Devolve verdareiro se a lista é vazia|| Devolve 0 se é vazia, maior que 0 se não é
int lista_esta_vazia(LISTA L);
// le os valores da lista
void ler_lista_double(LISTA L);

LISTA l;
#endif //RASTRO_LISTAS_H
