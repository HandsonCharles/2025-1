#include <stdio.h>
#include <string.h>

#define MAX 100

struct Produto {
    char nome[50];
    int codigo;
    int quantidade;
    float preco;
};

int main() {
    struct Produto estoque[MAX];
    int n = 0, opcao, codigoBusca, encontrado;

    do {
        printf("\n1 - Cadastrar produto\n2 - Buscar por codigo\n3 - Listar todos\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Nome do produto: ");
            scanf(" %[^\n]", estoque[n].nome);
            printf("Codigo: ");
            scanf("%d", &estoque[n].codigo);
            printf("Quantidade: ");
            scanf("%d", &estoque[n].quantidade);
            printf("Preco: ");
            scanf("%f", &estoque[n].preco);
            n++;
            break;

        case 2:
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigoBusca);
            encontrado = 0;
            for (int i = 0; i < n; i++) {
                if (estoque[i].codigo == codigoBusca) {
                    printf("Produto: %s | Qtde: %d | Preco: %.2f\n", estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("Produto nao encontrado.\n");
            }
            break;

        case 3:
            printf("\n--- Produtos Cadastrados ---\n");
            for (int i = 0; i < n; i++) {
                printf("%s (Codigo: %d) - Qtde: %d - Preco: R$%.2f\n",
                       estoque[i].nome, estoque[i].codigo, estoque[i].quantidade, estoque[i].preco);
            }
            break;
        }
    } while (opcao != 0);

    return 0;
}
