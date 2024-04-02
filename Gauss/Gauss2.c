#include <stdio.h>

void gauss_elimination(float a[10][10], float b[10], float x[10], int n) {
    int i, j, k;
    float ratio;

    // Fase de eliminação
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(j>i) {
                ratio = a[j][i]/a[i][i];
                for(k = 0; k < n; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
                b[j] -= ratio * b[i];
            }
        }
    }

    // Substituição retroativa
    x[n-1] = b[n-1]/a[n-1][n-1];
    for(i = n-2; i >= 0; i--) {
        x[i] = b[i];
        for(j = i+1; j < n; j++) {
            x[i] = x[i] - a[i][j]*x[j];
        }
        x[i] = x[i]/a[i][i];
    }
}

int main() {
    float a[10][10], b[10], x[10];
    int n, i, j;

    printf("Digite o número de equações: ");
    scanf("%d", &n);

    printf("Digite os coeficientes da matriz:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Digite os termos constantes:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    gauss_elimination(a, b, x, n);

    printf("A solução é:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i+1, x[i]);
    }

    return 0;
}