#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 100

struct Aluno {
    char nome[50];
    int matricula;
    float media;
};

int main() {
setlocale(LC_ALL,"PORTUGUESE");
    struct Aluno alunos[MAX];
    int n;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Media: ");
        scanf("%f", &alunos[i].media);
    }

    printf("\n--- Alunos Aprovados (media >= 6.0) ---\n");
    for (int i = 0; i < n; i++) {
        if (alunos[i].media >= 6.0) {
            printf("%s (Matricula: %d) - Media: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
        }
    }

    return 0;
}
