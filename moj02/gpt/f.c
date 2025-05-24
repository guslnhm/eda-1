#include <stdio.h>

long long soma_digitos(long long n) {
    if (n < 10)
        return n;
    return (n % 10) + soma_digitos(n / 10);
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", soma_digitos(n));
    return 0;
}
