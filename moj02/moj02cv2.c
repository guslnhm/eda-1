#include <stdio.h>

int degree9(char a[], int sum){
    if(a[0]!='\0'){
        sum += a[0] - 48;
        printf("sum: %d\n",sum);
        for(int j=0; a[j]!='\0'; j++){
            a[j] = a[j+1];
        }
        if(a[0] !='\0') sum += degree9(a,sum);
    }
    printf("sum final: %d\n",sum);
}

int main(){
    char a[1000][1001];
    int i=0, resultado;
    while(1){
        scanf(" %[^\n]",a[i]);
        if(a[i][0]=='0' && a[i][1]=='\0') break;
        i++;
    }
    for(int k=0;k<i;k++){
        resultado = degree9(a[k], 0);
    }
}