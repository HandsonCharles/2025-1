#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cifraDeCesar(char texto[], int deslocamento) {
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            texto[i] = (c - base + deslocamento) % 26 + base;
        }
    }
}

int main() {
    char mensagem[100];
    int deslocamento;

    printf("Digite a mensagem: ");
    scanf(" %[^\n]", mensagem);

    printf("Digite o valor do deslocamento: ");
    scanf("%d", &deslocamento);

    cifraDeCesar(mensagem, deslocamento);

    printf("Mensagem criptografada: %s\n", mensagem);
    return 0;
}
