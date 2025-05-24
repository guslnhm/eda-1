#include <stdio.h>

int encaixa(int a, int b){
   
    int i = 0, j = a, k=0, s=0;
    while(j>0){
        j/=10;
        i++;
    }

    int m[i-1], n=i-1;

    while(n>=0){
        m[s] = a%10;
        a/=10;
        n--;
        s++;
    }
    j=b;
    i=0;

    while(j>0){
        j/=10;
        i++;
    }

    int p[i-1];
    n=i-1;
    s=0;

    while(n>=0){
        p[s] = b%10;
        b/=10;
        n--;
        s++;
    }

    for(int q=0; q<i; q++){
        if(p[q]!=m[q]) return 0;
    }

    return 1;

}

int main(){
    int y = encaixa(457,2457);
    printf("%d\n",y);
}