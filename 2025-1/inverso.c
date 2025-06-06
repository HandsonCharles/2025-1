#include <stdio.h>
#include <locale.h>

int inverterNumero(int n) {
    int invertido = 0;
    while (n > 0) {
        invertido = invertido * 10 + (n % 10);
        n /= 10;
    }
    return invertido;
}

int main() {
setlocale(LC_ALL,"PORTUGUESE");
    int numero;

    printf("Digite um numero para inverter: ");
    scanf("%d", &numero);

    printf("Numero invertido: %d\n", inverterNumero(numero));

    return 0;
}
