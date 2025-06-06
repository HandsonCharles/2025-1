#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ehPalindromo(char str[]) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        if (tolower(str[inicio]) != tolower(str[fim]))
            return 0;
        inicio++;
        fim--;
    }
    return 1;
}

int main() {
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf(" %[^\n]", palavra);

    if (ehPalindromo(palavra))
        printf("E palindromo.\n");
    else
        printf("Nao e palindromo.\n");

    return 0;
}
