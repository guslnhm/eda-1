#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *dados;
    int N;
    int topo;
} pilha;

pilha *cria_pilha(int N){
    pilha *p = malloc(sizeof(pilha));
    p->dados = malloc(N*sizeof(int));
    p->N = N;
    p->topo = 0;
    return p;
}

int empilha(pilha *p, int x){
    if(p->topo == p->N){
        p->dados = realloc(p->dados, 2*p->N*sizeof(int));
        if(p->dados==NULL) return 1; //estouro da pilha *?
        p->N *= 2;
    }
    p->dados[p->topo] = x;
    p->topo++;
    return 0; //inserção bem sucedida
}

int main(){
    pilha *p = cria_pilha(5);
    empilha(p, 2);
    printf("%d\n",p->dados[0]);
}