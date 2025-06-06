#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 100

int main() {
    char palavraSecreta[] = "computador";
    char display[TAM_MAX];
    int tamanho = strlen(palavraSecreta);
    int tentativas = 6;
    char letra;
    int acertou, letrasRestantes = tamanho;

    for (int i = 0; i < tamanho; i++) {
        display[i] = '_';
    }
    display[tamanho] = '\0';

    printf("=== Jogo da Forca ===\n");

    while (tentativas > 0 && letrasRestantes > 0) {
        printf("\nPalavra: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%c ", display[i]);
        }

        printf("\nTentativas restantes: %d", tentativas);
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);

        acertou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavraSecreta[i] == letra && display[i] == '_') {
                display[i] = letra;
                letrasRestantes--;
                acertou = 1;
            }
        }

        if (!acertou) {
            tentativas--;
            printf("Letra incorreta!\n");
        }
    }

    if (letrasRestantes == 0) {
        printf("\nParabéns! Você acertou: %s\n", palavraSecreta);
    } else {
        printf("\nGame Over! A palavra era: %s\n", palavraSecreta);
    }

    return 0;
}
