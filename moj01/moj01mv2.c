#include <stdio.h>

int encaixa(int a, int b){
    int m[20], p[20];
    int tam_a = 0, tam_b = 0;

    // Armazena os dígitos de a ao contrário
    while(a > 0){
        m[tam_a++] = a % 10;
        a /= 10;
    }

    // Armazena os dígitos de b ao contrário
    while(b > 0){
        p[tam_b++] = b % 10;
        b /= 10;
    }

    if (tam_b > tam_a) return 0;

    // Compara os últimos dígitos (início do array, pois estão invertidos)
    for(int i = 0; i < tam_b; i++){
        if(m[i] != p[i]) return 0;
    }

    return 1;
}
