#include <stdio.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int separa(int *v, int e, int d){
    int c = v[d];
    int j=e, k=e;
    while(k<d){
        if(v[k]<=c){
            troca(&v[k], &v[j]);
            j++;
        }
        k++;
    }
    troca(&v[j], &v[d]);
    return j;
}

void quicksort(int *v, int e, int d){
    if(e<d){
        int p = separa(v,e,d);
        quicksort(v,e,p-1);
        quicksort(v,p+1,d);
    }
}

int main(){
    int v[5] = {5,4,6,2,1};
    int n = sizeof(v)/sizeof(int);
    quicksort(v,0,n-1);
    for(int i=0; i<n; i++) printf("%d ",v[i]);
    printf("\n");
}