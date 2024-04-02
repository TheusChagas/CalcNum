#include <stdio.h>

void print_matriz(float a[10][10], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
}

void gauss(float a[10][10], float b[10], float x[10], int n) {
    int i, j, k;
    float fator;

    // Fase de eliminação
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j>i) {
                // Calcula o fator
                fator = a[j][i]/a[i][i];
                for(k = 0; k < n; k++){
                    // Atualiza a matriz 'a'
                    a[j][k] -= fator * a[i][k];
                }
                // Atualiza o vetor 'b'
                b[j] -= fator * b[i];
            }
        }
        printf("Matriz após a %dª iteração:\n", i+1);
        print_matriz(a, n);
    }

    // Substituição retroativa
    x[n-1] = b[n-1]/a[n-1][n-1]; // Resolve a última equação
    for(i = n-2; i >= 0; i--){
        x[i] = b[i];
        for(j = i+1; j < n; j++){
            // Subtrai o produto dos elementos já calculados do vetor 'x' e os respectivos elementos da matriz 'a'
            x[i] = x[i] - a[i][j]*x[j];
        }
        // Divide pelo elemento da diagonal principal da matriz 'a'
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

    printf("Matriz informada:\n");
    print_matriz(a, n);

    printf("Digite os termos constantes:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    gauss(a, b, x, n);

    printf("A solução é:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i+1, x[i]);
    }

    return 0;
}
