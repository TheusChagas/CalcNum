#include<stdio.h>
#include<math.h>

int main() {
    int i, j, n;
    float A[20][20], b[20], x[20] = {0}, e, temp, error, sum;
    printf("Informe o número de equações: ");
    scanf("%d", &n);
    printf("Informe os elementos da matriz:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }
    printf("Informe os elementos do vetor constante:\n");
    for(i = 0; i < n; i++) {
        printf("b[%d] = ", i+1);
        scanf("%f", &b[i]);
    }
    printf("Informe o erro tolerável: ");
    scanf("%f", &e);
    do {
        error = 0;
        for(i = 0; i < n; i++) {
            sum = 0;
            for(j = 0; j < n; j++) {
                if(j != i) {
                    sum = sum + A[i][j] * x[j];
                }
            }
            temp = (b[i] - sum) / A[i][i];
            error = error + fabs(x[i]-temp);
            x[i] = temp;
        }
    } while(error >= e);
    printf("A solução do sistema é:\n");
    for(i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i+1, x[i]);
    }
    return 0;
}
