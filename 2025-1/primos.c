#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

bool ehPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
setlocale(LC_ALL,"PORTUGUESE");
    int n1,n2;

    printf("Digite o intervalo (inicio e fim): ");
    scanf("%d %d", &n1, &n2);

    printf("Números primos entre %d e %d:\n", n1, n2);
    for (int i = n1; i <= n2; i++) {
        if (ehPrimo(i))
            printf("%d ", i);
    }

    return 0;
}
