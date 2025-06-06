#include <stdio.h>

int main() {
    int A[5], B[5], i, j;

    printf("Digite 5 elementos do vetor A:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }

    printf("Digite 5 elementos do vetor B:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &B[i]);
    }

    printf("Elementos comuns entre A e B:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                break;
            }
        }
    }

    return 0;
}
