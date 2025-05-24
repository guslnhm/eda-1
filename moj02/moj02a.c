#include <stdio.h>

int f91(int n){
    if(n>=101) return n-10;
    return f91(f91(n+11));
}

int main(){
    int n, m = 0;
    scanf("%d",&n);
    while(n!=0){
        m = f91(n);
        printf("f91(%d) = %d\n", n, m);
        scanf("%d",&n);
    }
}