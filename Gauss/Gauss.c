#include <stdio.h>

#define N 3

void imprimir_matriz(float mat[N][N+1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}

void retrosubstituicao(float mat[N][N+1]) {
    float x[N];
    for (int i = N-1; i >= 0; i--) {
        x[i] = mat[i][N];
        for (int j = i+1; j < N; j++) {
            x[i] = x[i] - mat[i][j]*x[j];
        }
        x[i] = x[i]/mat[i][i];
    }

    printf("\nA solução é: \n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %f\n", i, x[i]);
    }
}

void gauss(float mat[N][N+1]) {
    int i, j, k;
    for (i = 0; i < N; i++) { //Percorre as linhas
        for (j = i+1; j < N; j++) {
            float f = mat[j][i] / mat[i][i]; //Acha um fator de eliminação entre as linhas
            for (k = 0; k <= N; k++) {
                mat[j][k] -= mat[i][k]*f; // Elimina a variavel dessa linha
            }
        }
    }
    printf("\nMatriz após a eliminação de Gauss:\n");
    imprimir_matriz(mat);
    retrosubstituicao(mat);
}

int main() {
    float mat[N][N+1] = {
        {3.0, 2.0, 4.0, 1.0},
        {1.0, 1.0, 2.0, 2.0},
        {4.0, 3.0, -2.0, 3.0}
        };

    printf("Matriz inicial:\n");
    imprimir_matriz(mat);
    gauss(mat);
    return 0;
}