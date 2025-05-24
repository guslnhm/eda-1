#include <stdio.h>

int main(){
    int n, k=1, p=0;
    scanf("%d",&n);
    const int m = n-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //outer layer
            if(i==0 || i==m || j==0 || j==m){
                printf("%d ", k);
                p++;
            }
            
            else if(j==i){
                k++;
                printf("%d ", k);
                p++;
            }

            if(p==0) printf("%d ", k);
        }
        p=0;
        k=1;
        printf("\n");
    }
}