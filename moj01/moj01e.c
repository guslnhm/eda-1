#include <stdio.h>

int main(){
    unsigned long int exp;

    int a, b;
    scanf("%d%d", &a, &b);
    exp = a;
    
    if(b==0) exp = 1;
    else if(b==1) exp = a;
    else if(a==0) exp = 0;
    else{ 
        while(b>1){
            exp *= a;
            b--;
        }
    }

    int n, j;
    unsigned long int fat;
    scanf("%d", &n);
    // 6! = 6*5*4*3*2*1
    // n = 6
    // fat = 6*5
    fat = n;
    while(n>1){
        n--;
        fat*=n;
    }

    if(fat>exp) printf("Pedro\n");
    else printf("Lucas\n");
}