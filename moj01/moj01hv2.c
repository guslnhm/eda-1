#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int D;
    scanf("%d", &D);

    int ano, semestre, m;

    while (scanf("%d %d %d", &ano, &semestre, &m) == 3) {
        int cod, mat, apr;
        int max_reprovados = -1;
        int reprovados[MAX];
        int codigos[MAX];
        int qtd_codigos = 0;

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &cod, &mat, &apr);
            int rep = mat - apr;

            if (rep > max_reprovados) {
                qtd_codigos = 0;
                codigos[qtd_codigos++] = cod;
                max_reprovados = rep;
            } else if (rep == max_reprovados) {
                codigos[qtd_codigos++] = cod;
            }
        }

        for (int i = 0; i < qtd_codigos - 1; i++) {
            for (int j = i + 1; j < qtd_codigos; j++) {
                if (codigos[i] > codigos[j]) {
                    int temp = codigos[i];
                    codigos[i] = codigos[j];
                    codigos[j] = temp;
                }
            }
        }

        printf("%d/%d\n", ano, semestre);
        for (int i = 0; i < qtd_codigos; i++) {
            printf("%d ", codigos[i]);
        }
        printf("\n\n");
    }

    return 0;
}
