#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int j = 1, espacos = n-j, 
        asterisco = 1,
        k=1;
    
    for(int i=0; i<n; i++){
        while(espacos>0){
            printf(" ");
            espacos--;
        }
        j++;
        espacos=n-j;
        for(int m=0; m<k; m++){
            printf("*");
        }
        k += 2;

        printf("\n");
    }
}