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
        p->dados = realloc(p->dados, 2*p->N*sizeof(int)); // dobra a capacidade da pilha - evita ter que ficar fazendo isso toda hora, se precisar ficar realocando
        if(p->dados==NULL) return 1; // estouro da pilha *? : verifica se o realloc falhou
        // caso não tenha memória RAM suficiente disponível; pedido grnade ou exagerado, etc
        // encerra execução
        p->N *= 2; // só reajusta o valor de N, capacidade máxima da pilha
    }
    p->dados[p->topo] = x;
    p->topo++;
    return 0; //inserção bem sucedida
}

int desempilha(pilha *p, int *y){
    if(p->topo == 0) return 1;
    p->topo--;
    *y = p->dados[p->topo];
    return 0;
}

void destroi_pilha(pilha *p){
    free(p->dados);
    free(p);
}

int main(){
    pilha *p = cria_pilha(5); //cria pilha de tamanho N
    empilha(p, 2);
    printf("%d\n",p->dados[0]);

    // teste de desempilhar
    int valor;
    desempilha(p, &valor);
    printf("Valor desempilhado: %d\n", valor);

    // teste de destruição de pilha
    destroi_pilha(p);
    printf("Destruição de pilha realizada com sucesso\n");
}