#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerda;
    struct Aluno* direita;
} Aluno;

Aluno* criarAluno(char nome[], int matricula, float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo) {
        strcpy(novo->nome, nome);
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerda = novo->direita = NULL;
    }
    return novo;
}

Aluno* inserir(Aluno* raiz, char nome[], int matricula, float nota) {
    if (raiz == NULL)
        return criarAluno(nome, matricula, nota);

    int cmp = strcmp(nome, raiz->nome);
    if (cmp < 0)
        raiz->esquerda = inserir(raiz->esquerda, nome, matricula, nota);
    else if (cmp > 0)
        raiz->direita = inserir(raiz->direita, nome, matricula, nota);

    return raiz;
}

Aluno* buscar(Aluno* raiz, char nome[]) {
    if (raiz == NULL)
        return NULL;

    int cmp = strcmp(nome, raiz->nome);
    if (cmp == 0)
        return raiz;
    else if (cmp < 0)
        return buscar(raiz->esquerda, nome);
    else
        return buscar(raiz->direita, nome);
}

float somaNotas(Aluno* raiz, int* total) {
    if (raiz == NULL)
        return 0;

    float somaEsq = somaNotas(raiz->esquerda, total);
    float somaDir = somaNotas(raiz->direita, total);
    (*total)++;
    return somaEsq + somaDir + raiz->nota;
}

void imprimirEmOrdem(Aluno* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("Nome: %s | Matricula: %d | Nota: %.2f\n", raiz->nome, raiz->matricula, raiz->nota);
        imprimirEmOrdem(raiz->direita);
    }
}

void remover(Aluno* raiz) {
    if (raiz != NULL) {
        remover(raiz->esquerda);
        remover(raiz->direita);
        free(raiz);
    }
}

int main() {
    Aluno* raiz = NULL;
    raiz = inserir(raiz, "Vermax", 101, 8.5);
    raiz = inserir(raiz, "Carmelha", 102, 7.2);
    raiz = inserir(raiz, "Safirafulli", 103, 6.2);
    raiz = inserir(raiz, "Luseria", 104, 10.0);

    printf("\n--- Alunos em ordem alfabética ---\n");
    imprimirEmOrdem(raiz);

    char nomeBusca[50] = "Luseria";
    Aluno* a = buscar(raiz, nomeBusca);
    if (a != NULL)
        printf("\nAluno encontrado: %s, matricula: %d, nota: %.2f\n", a->nome, a->matricula, a->nota);
    else
        printf("\nAluno %s nao encontrado!\n", nomeBusca);

    int total = 0;
    float media = somaNotas(raiz, &total) / total;
    printf("\nMedia das notas: %.2f\n", media);

    remover(raiz);
    return 0;
}