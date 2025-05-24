#include <stdio.h>

int degree9(char a[], int depth) {
    int sum = 0;

    for (int i = 0; a[i] != '\0'; i++) {
        sum += a[i] - '0';
    }

    if (sum == 9) return depth + 1;
    if (sum % 9 != 0) return 0;

    char soma_str[20];
    int i = 0, temp = sum;

    if (temp == 0) {
        soma_str[0] = '0';
        soma_str[1] = '\0';
    } else {
        while (temp > 0) {
            soma_str[i++] = (temp % 10) + '0';
            temp /= 10;
        }
        soma_str[i] = '\0';

        for (int j = 0; j < i / 2; j++) {
            char t = soma_str[j];
            soma_str[j] = soma_str[i - j - 1];
            soma_str[i - j - 1] = t;
        }
    }

    return degree9(soma_str, depth + 1);
}

int main() {
    char a[1000][1001];
    int i = 0;

    while (i < 1000) {
        scanf(" %[^\n]", a[i]);
        if (a[i][0] == '0' && a[i][1] == '\0') break;
        i++;
    }

    for (int k = 0; k < i; k++) {
        int grau = degree9(a[k], 0);
        if (grau > 0)
            printf("%s is a multiple of 9 and has 9-degree %d.\n", a[k], grau);
        else
            printf("%s is not a multiple of 9.\n", a[k]);
    }

    return 0;
}
