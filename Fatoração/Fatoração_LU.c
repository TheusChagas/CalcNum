#include<stdio.h>
#include<stdlib.h>

void FatorLU(float **mat, int n) {
    float **inf, **sup;
    int i = 0, j = 0, k = 0;

    // Alocando memória para as matrizes lower e upper
    inf = (float **)malloc(n * sizeof(float *));
    sup = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        inf[i] = (float *)malloc(n * sizeof(float));
        sup[i] = (float *)malloc(n * sizeof(float));
    }

    // Inicializando as matrizes lower e upper
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            inf[i][j] = 0;
            sup[i][j] = 0;
        }
    }

    // Decomposição da matriz em lower e upper
    for (i = 0; i < n; i++) {
        // Upper
        for (k = i; k < n; k++) {
            float sum = 0;
            for (j = 0; j < i; j++)
                sum += (inf[i][j] * sup[j][k]);
            sup[i][k] = mat[i][k] - sum;
        }

        // Lower
        for (k = i; k < n; k++) {
            if (i == k)
                inf[i][i] = 1; // Diagonal como 1
            else {
                float sum = 0;
                for (j = 0; j < i; j++)
                sum += (inf[k][j] * sup[j][i]);
                inf[k][i] = (mat[k][i] - sum) / sup[i][i];
            }
        }
    }

    // Imprimindo as matrizes superior e Inferior
    printf("Inferior\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%.2f ", inf[i][j]);
        printf("\n");
    }

    printf("sup\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%.2f ", sup[i][j]);
        printf("\n");
    }

    // Liberando a memória alocada
    for (i = 0; i < n; i++) {
        free(inf[i]);
        free(sup[i]);
    }
    free(inf);
    free(sup);
    }

    int main() {
    int n, i, j;
    float **mat;

    printf("Insira o tamanho da matriz: ");
    scanf("%d", &n);

    // Alocando memória para a matriz
    mat = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++)
        mat[i] = (float *)malloc(n * sizeof(float));

    printf("Insira os elementos da matriz:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%f", &mat[i][j]);

    FatorLU(mat, n);

   // Liberando a memória alocada
    for (i = 0; i < n; i++)
        free(mat[i]);
    free(mat);

    return 0;
}
