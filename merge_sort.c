#include <stdio.h>
#include <stdlib.h>

void intercala(int *v, int e, int m, int d){
    int i=e, j=m, k=0;
    int *aux = malloc((d-e+1)*sizeof(int));
    while(i<m && j<=d){
        if(v[i]<v[j]){
            aux[k] = v[i];
            k++;
            i++;
        }
        else{
            aux[k] = v[j];
            k++;
            j++;
        }
    }
    while(i<m) aux[k++] = v[i++];
    while(j<=d) aux[k++] = v[j++];
    for(k=0, i=e; i<=d; k++, i++){
        v[i] = aux[k];
    }
    free(aux);
}

void merge_sort(int *v, int e, int d){
    if(e<d){
        int m = (e+d)/2;
        merge_sort(v,e,m);
        merge_sort(v,m+1,d);
        intercala(v,e,m+1,d);
    }
}

int main(){
    int v[6] = {5,4,6,7,1,2};
    int n = sizeof(v)/sizeof(int);
    merge_sort(v,0,n-1);
    for(int i=0; i<n; i++) printf("%d ", v[i]);
    printf("\n");
}