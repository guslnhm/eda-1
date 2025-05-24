#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
    int mortos;
} Ponto;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int P;
    scanf("%d", &P);

    char linha[1005];
    int capacidade = 1005;
    char **mapa = malloc(capacidade * sizeof(char *));
    int M = 0, N = 0;
    int sx = -1, sy = -1;

    while (scanf("%s", linha) != EOF) {
        if (M == capacidade) {
            capacidade *= 2;
            mapa = realloc(mapa, capacidade * sizeof(char *));
        }
        N = 0;
        while (linha[N] != '\0') N++;
        mapa[M] = malloc(N + 1);
        for (int i = 0; i < N; i++) {
            mapa[M][i] = linha[i];
            if (linha[i] == 'S') {
                sx = M;
                sy = i;
            }
        }
        M++;
    }

    int **visitado = malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        visitado[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            visitado[i][j] = -1;
        }
    }

    Ponto *fila = malloc(M * N * sizeof(Ponto));
    int ini = 0, fim = 0;
    fila[fim++] = (Ponto){sx, sy, 0};
    visitado[sx][sy] = 0;

    int menorMortos = -1;

    while (ini < fim) {
        Ponto atual = fila[ini++];
        int x = atual.x, y = atual.y, mortos = atual.mortos;

        if (mapa[x][y] == 'E') {
            menorMortos = mortos;
            break;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (mapa[nx][ny] == '#') continue;

            int custo = mortos + (mapa[nx][ny] == 'o' ? 1 : 0);
            if (visitado[nx][ny] == -1 || custo < visitado[nx][ny]) {
                visitado[nx][ny] = custo;
                fila[fim++] = (Ponto){nx, ny, custo};
            }
        }
    }

    if (menorMortos == -1 || menorMortos >= P) {
        printf("Todos morreram :)\n");
    } else if (menorMortos == 0) {
        printf("Nenhum morreu :(\n");
    } else {
        printf("%d encontraram o vovo\n", P - menorMortos);
    }

    for (int i = 0; i < M; i++) {
        free(mapa[i]);
        free(visitado[i]);
    }
    free(mapa);
    free(visitado);
    free(fila);

    return 0;
}
