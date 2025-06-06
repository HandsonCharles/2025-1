#include <stdio.h>

int main() {
    int numeros[10];
    int i, j, contagem;

    printf("Digite 10 números inteiros:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Frequência de cada número distinto:\n");

    for (i = 0; i < 10; i++) {
        contagem = 1;
        int jaContado = 0;

        
        for (j = 0; j < i; j++) {
            if (numeros[i] == numeros[j]) {
                jaContado = 1;
                break;
            }
        }

        if (!jaContado) {
            for (j = i + 1; j < 10; j++) {
                if (numeros[i] == numeros[j]) {
                    contagem++;
                }
            }
            printf("%d aparece %d vez(es)\n", numeros[i], contagem);
        }
    }

    return 0;
}