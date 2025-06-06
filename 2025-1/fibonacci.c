#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Digite a posição n para calcular o Fibonacci: ");
    scanf("%d", &n);
    printf("Fibonacci de %d é %d\n", n, fibonacci(n));
    return 0;
}
