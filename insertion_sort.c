#include <stdio.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insercao(int *v, int n){
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0 && v[j]>v[j+1]; j--){
            troca(&v[j], &v[j+1]);
        }
    }
}

int main(){
    int v[5] = {5, 2, 4, 6, 1};
    int n = sizeof(v)/sizeof(v[0]);
    for(int i=0; i<n; i++) printf("%d ", v[i]);
    printf("\n");
    insercao(v,n);
    for(int i=0; i<n; i++) printf("%d ", v[i]);
    printf("\n");
}