#include <stdio.h>

int buscaBinaria(int *v, int n, int x){
    int e=-1, d=n;
    while(e<d-1){
        int m = (e+d)/2;
        if(x>v[m]) e=m;
        else d=m;
    }
    return d;
}

int main(){
    int arr[5] = {1,3,5,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = buscaBinaria(arr,n,5);
    int y = buscaBinaria(arr,n,8);
    int z = buscaBinaria(arr,n,2);
    printf("%d\n",z);
    return 0;
}