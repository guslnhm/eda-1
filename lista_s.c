#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

/* Implementações: criar, inserir, remover, buscar e destruir lista

criar_lista(): tipo "celula", pois retorna uma lista
insere_lista(): tipo "void"
buscar_celula(): tipo "celula", retorna uma celula
remove(): tipo "int", pois retorna o dado - vc pode querer fazer algo com esse dado
destroi(): tipo "void"
*/

celula *cria_lista(){
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    return le;
} // é um ponteiro pq retorna um endereço, aponta para o HEAD, cabeça da lista

void insere(celula *ptr, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = ptr->prox;
    ptr->prox = novo;
}

celula *busca(celula *le, int x){
    for(celula *ptr = le->prox; ptr!=NULL; ptr=ptr->prox){
        if(ptr->dado==x) return ptr;
    }
    return NULL;
}

int remove(celula *ptr){
    celula *lixo = ptr->prox;
    int x = lixo->dado;
    ptr->prox = lixo->prox;
    free(lixo);
    return x;
}

void destroi_lista(celula *le){
    while(le->prox!=NULL) remove(le);
    free(le);
}

int main(){
    celula *lista = cria_lista();
    insere(lista, 10);
    celula *y = busca(lista,10);
    if(y!=NULL) insere(y,11);
}