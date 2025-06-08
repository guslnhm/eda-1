#include <stdio.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *v, int n){
    for(int i=0; i<n; i++){
        int menor = i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[menor]) menor=j;
        }
        troca(&v[i], &v[menor]);
    }
}

int main(){
    int v[5] = {5,4,6,2,1};
    int n = sizeof(v)/sizeof(int);
    selection_sort(v,n);
    for(int i=0;i<n;i++) printf("%d ", v[i]);
    printf("\n");
}