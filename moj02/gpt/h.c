#include <stdio.h>

void desenha_tracos(int n) {
    if (n == 0) return;
    printf("-");
    desenha_tracos(n - 1);
}

void regua_inglesa(int n) {
    if (n == 0) return;

    regua_inglesa(n - 1);

    printf(".");
    desenha_tracos(n);
    printf("\n");

    regua_inglesa(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    regua_inglesa(n);
    return 0;
}
