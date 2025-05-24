#include <stdio.h>

int check_layer(int i, int j, int n, int k, int m[n][n], int q){
    if(i==k || i==n-q || j==k || j==n-q){
        m[i][j] = q;
        return 1;
    }
    return 0;
}

int main(){
    int n, half, k, q;
    scanf("%d",&n);
    if(n%2==0) half = n/2;
    else half = (n/2)+1;
    int m[n][n];


   for(int i=0; i<n; i++){
 
    for(int j=0; j<n; j++){
        k=0;
        q=1;

       while(k<half){
        if(check_layer(i, j, n, k, m, q)==1) break;
        k++;
        q++;
       }

    }
   }

    // printando
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        printf("%d ", m[i][j]);
    }
    printf("\n");
   }

    
}