#include <stdio.h>

int main(){
    int b, t, area_r = 160*70;
    scanf("%d%d", &b, &t);
    // área trapézio retângulo = (B+b)*h/2
    int area_t = (t+b)*70/2;
    int resto = area_r - area_t;
    if(area_t > resto) printf("1\n");
    else if(area_t < resto) printf("2\n");
    else if(area_t == resto) printf("0\n");
    return 0;
}