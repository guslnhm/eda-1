#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

/*
celula *cria_lista(){
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    return le; // le = cabeça da lista
}

void insere(celula *ptr, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = ptr->prox;
    ptr->prox = novo;
} // essa função só insere depois de uma célula específica

celula *busca(celula *le, int x){
    for(celula *ptr = le->prox; ptr!=NULL; ptr=ptr->prox)
        if(ptr->dado==x) return ptr;
    return NULL;
} // pesquisa desde o início da lista (le->prox) até o final, onde o elemento é NULL

int remove(celula *ptr){
    celula *lixo = ptr->prox;
    int x = lixo->dado;
    ptr->prox = lixo->prox;
} // para remover uma célula específica, tenho que passar a célula anterior a ela

void destroi_lista(celula *le){
    while(le->prox!=NULL) remove(le);
    free(le);
    // passa a cabeça *le para remove, que sempre remove a célula seguinte à que é passada como parâmetro
    // vai removendo todas, até no final só dar free na cabeça
}
*/

celula *cria_pilha(int N){
    celula *pilha = malloc(sizeof(celula));
    pilha->prox = NULL; // topo da pilha, sempre vai apontar para o topo da pilha
    return pilha; // nó cabeça
}

int empilha(celula *p, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo==NULL) return 1; // verifica erro na alocação de memória
    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;
    return 0;
    // empilha no começo - na prática, igual à inserção da lista encadeada
    // isto é, empilha no topo
}

celula *desempilha(celula *p){ // passo somente a pilha *p que criei na main como parâmetro
                               // ela já vai armazenar o topo, que é p->prox
    if(p->prox == NULL) return NULL;
    celula *ret = p->prox;
    p->prox = ret->prox;
    return ret; // retorna o nó removido, caso eu queira usar esse dado na chamadora
}

void destroi_pilha(pilha *p){
    celula *ret = desempilha(p);
    while(ret!=NULL){
        free(ret); // desempilha não libera a memória, faço aqui
        ret = desempilha(p);
    }
    free(p); // libero memória da cabeça da pilha
}

int main(){
    celula *p = cria_pilha(3); // crio a pilha *p
    empilha(p, 6);
    desempilha(p);
}