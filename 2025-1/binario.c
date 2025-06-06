#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1, meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor)
            return meio; 
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1; 
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor, pos;

    printf("Digite o valor a buscar: ");
    scanf("%d", &valor);

    pos = buscaBinaria(vetor, tamanho, valor);

    if (pos != -1)
        printf("Valor encontrado na posição %d.\n", pos);
    else
        printf("Valor não encontrado.\n");

    return 0;
}
