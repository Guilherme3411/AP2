#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
} Produto;

typedef struct {
    Produto *produtos;
    int tamanho;
} Inventario;

void inicializarInventario(Inventario *inventario) {
    inventario->produtos = NULL;
    inventario->tamanho = 0;
}

void adicionarProduto(Inventario *inventario) {
    Produto novoProduto;
    printf("Digite o nome do produto: ");
    scanf(" %[^]", novoProduto.nome);
    printf("Digite o codigo do produto: ");
    scanf("%d", &novoProduto.codigo);
    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoProduto.quantidade);

    inventario->produtos = realloc(inventario->produtos, (inventario->tamanho + 1) * sizeof(Produto));
    if (inventario->produtos == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    inventario->produtos[inventario->tamanho] = novoProduto;
    inventario->tamanho++;

    printf("Produto adicionado com sucesso!\n");
}

void listarProdutos(const Inventario *inventario) {
    if (inventario->tamanho == 0) {
        printf("Nenhum produto no inventario.\n");
        return;
    }
    printf("Lista de produtos:\n");
    for (int i = 0; i < inventario->tamanho; i++) {
        printf("Nome: %s\n", inventario->produtos[i].nome);
        printf("Codigo: %d\n", inventario->produtos[i].codigo);
        printf("Preco: %.2f\n", inventario->produtos[i].preco);
        printf("Quantidade: %d\n", inventario->produtos[i].quantidade);
        printf("--------------------------\n");
    }
}

void buscarProduto(const Inventario *inventario) {
    int codigo;
    printf("Digite o codigo do produto a ser buscado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < inventario->tamanho; i++) {
        if (inventario->produtos[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", inventario->produtos[i].nome);
            printf("Preco: %.2f\n", inventario->produtos[i].preco);
            printf("Quantidade: %d\n", inventario->produtos[i].quantidade);
            return;
        }
    }
    printf("Produto com codigo %d nao encontrado.\n", codigo);
}

void salvarEmArquivo(const Inventario *inventario) {
    FILE *arquivo = fopen("inventario.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < inventario->tamanho; i++) {
        fprintf(arquivo, "%s;%d;%.2f;%d\n",
                inventario->produtos[i].nome,
                inventario->produtos[i].codigo,
                inventario->produtos[i].preco,
                inventario->produtos[i].quantidade);
    }

    fclose(arquivo);
    printf("Inventario salvo com sucesso em 'inventario.txt'.\n");
}

void carregarDeArquivo(Inventario *inventario) {
    FILE *arquivo = fopen("inventario.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura ou arquivo inexistente.\n");
        return;
    }

    inicializarInventario(inventario);
    Produto temp;
    while (fscanf(arquivo, " %49[^;];%d;%f;%d\n", temp.nome, &temp.codigo, &temp.preco, &temp.quantidade) == 4) {
        inventario->produtos = realloc(inventario->produtos, (inventario->tamanho + 1) * sizeof(Produto));
        if (inventario->produtos == NULL) {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
        inventario->produtos[inventario->tamanho] = temp;
        inventario->tamanho++;
    }

    fclose(arquivo);
    printf("Inventario carregado com sucesso.\n");
}

int main() {
    Inventario inventario;
    inicializarInventario(&inventario);

    int opcao;
    do {
        printf("\nSistema de Gerenciamento de Inventario\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Buscar Produto\n");
        printf("4. Salvar em Arquivo\n");
        printf("5. Carregar de Arquivo\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(&inventario);
                break;
            case 2:
                listarProdutos(&inventario);
                break;
            case 3:
                buscarProduto(&inventario);
                break;
            case 4:
                salvarEmArquivo(&inventario);
                break;
            case 5:
                carregarDeArquivo(&inventario);
                break;
            case 6:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    free(inventario.produtos);

    return 0;
}
