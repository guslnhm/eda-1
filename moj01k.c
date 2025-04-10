#include <stdio.h>

int main(){
    int n,media=0,k=0;
    scanf("%d",&n);
    int v[n];
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
        media+=v[i];
    }
    media/=n;
    for(int i=0; i<n; i++){
        if(v[i]>media && i!=n-1){
            printf("%d ", v[i]);
            k++;
        }
        else if(v[i]>media && i==n-1){
            printf("%d", v[i]);
            k++;
        }
    }
    if(k==0) printf("0\n");
}