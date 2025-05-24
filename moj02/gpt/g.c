#include <stdio.h>

void troca_x_por_y(char *s) {
    if (*s == '\0')
        return;

    if (*s == 'x')
        *s = 'y';

    troca_x_por_y(s + 1);
}

int main() {
    char s[81];
    scanf("%s", s);
    troca_x_por_y(s);
    printf("%s\n", s);
    return 0;
}
