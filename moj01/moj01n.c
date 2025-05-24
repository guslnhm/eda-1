#include <stdio.h>

int encaixa(int a, int b) {
    int m[20], p[20];
    int tam_a = 0, tam_b = 0;

    while(a > 0){
        m[tam_a++] = a % 10;
        a /= 10;
    }

    while(b > 0){
        p[tam_b++] = b % 10;
        b /= 10;
    }

    if (tam_b > tam_a) return 0;

    for(int i = 0; i < tam_b; i++){
        if(m[i] != p[i]) return 0;
    }

    return 1;
}

int segmento(int a, int b) {
    int m[20], p[20];
    int maior, menor;
    int tam_maior = 0, tam_menor = 0;

    if (a > b) {
        maior = a;
        menor = b;
    } else {
        maior = b;
        menor = a;
    }

    while(maior > 0){
        m[tam_maior++] = maior % 10;
        maior /= 10;
    }

    while(menor > 0){
        p[tam_menor++] = menor % 10;
        menor /= 10;
    }

    if (tam_menor > tam_maior) return 0;

    for (int i = 0; i <= tam_maior - tam_menor; i++) {
        int igual = 1;
        for (int j = 0; j < tam_menor; j++) {
            if (m[i + j] != p[j]) {
                igual = 0;
                break;
            }
        }
        if (igual) return 1;
    }

    return 0;
}