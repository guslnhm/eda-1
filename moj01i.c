#include <stdio.h>

int main(){
    int f, l;
    scanf("%d%d",&f,&l);
    int sala[f+1][l+1];
    char lugar[4];
    int j, k;

    for(int p=0; p<f+1; p++) for(int q=0; q<l+1; q++) sala[p][q] = 0;

    while(scanf(" %[^\n]", lugar)!=EOF){
        j=0;
        for(int i=65; i<85; i++, j++) if(lugar[0]==i) break;
        j = f-j;
        if(lugar[2]=='\0') k = lugar[1] - 48;
        else if(lugar[3]=='\0') k = ((lugar[1] - 48)*10) + (lugar[2] - 48);
        sala[j][k] = 1;
        lugar[0]='\0';
    }

    int max_ascii = f + 64;

    for(int p=0; p<f+1; p++){
        for(int q=0; q<l+1; q++){
            if(p==0 && q==0){
                printf("   ");
                continue;
            }
            if(p==0){
                if(q<10) printf("0%d ", q);
                else printf("%d ", q);
            }
            else if(q==0) printf("%c  ", max_ascii--);
            else if(sala[p][q]==0) printf("-- ");
            else printf("XX ");
        }
        printf("\n");
    }
    return 0;
}