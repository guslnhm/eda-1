#include <stdio.h>

typedef struct {
    int valor;
    const char *romano;
} Romano;

Romano tabela[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

void converter_para_romano(int n) {
    for (int i = 0; i < 13; i++) {
        while (n >= tabela[i].valor) {
            printf("%s", tabela[i].romano);
            n -= tabela[i].valor;
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int v;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        converter_para_romano(v);
    }
    return 0;
}
