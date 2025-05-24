#include <stdio.h>

int main(){
    int n, j=1;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        
        for(int k=0; k<j; k++){
            if(j<10) printf("0%d ", j);
            else printf("%d ", j);
        }
        printf("\n");
        j++;

    }

    printf("\n");
    j=1;
    int m=j;

    for(int i=0; i<n; i++){

        for(int k=0; k<j; k++){
            if(m<10) printf("0%d ", m++);
            else printf("%d ", m++);
        }
        j++;
        m=1;
        printf("\n");
    }
}