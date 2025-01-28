#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED
#define MAX_LIVROS 100
#define MAX_USUARIOS 50
typedef struct
{
    char titulo[100];
    char autor[50];
    int ano;
} Livro;

typedef struct
{
    char nome[50];
    int id;
    char email[50];
} Usuario;

typedef struct
{
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    int qtdLivros;
    int qtdUsuarios;
} Biblioteca;

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void adicionarLivro(Biblioteca *biblio)
{
    if (biblio->qtdLivros >= MAX_LIVROS)
    {
        printf("A biblioteca esta cheia!\n");
        return;
    }

    Livro livro;
    printf("Digite o titulo do livro: ");
    fgets(livro.titulo, sizeof(livro.titulo), stdin);
    livro.titulo[strcspn(livro.titulo, "\n")] = '\0';

    printf("Digite o autor do livro: ");
    fgets(livro.autor, sizeof(livro.autor), stdin);
    livro.autor[strcspn(livro.autor, "\n")] = '\0';

    printf("Digite o ano do livro: ");
    scanf("%d", &livro.ano);
    limparBuffer();

    biblio->livros[biblio->qtdLivros++] = livro;
    printf("Livro adicionado com sucesso!\n");
}

void adicionarUsuario(Biblioteca *biblio)
{
    if (biblio->qtdUsuarios >= MAX_USUARIOS)
    {
        printf("A biblioteca esta cheia de usuarios!\n");
        return;
    }

    Usuario usuario;
    printf("Digite o nome do usuario: ");
    fgets(usuario.nome, sizeof(usuario.nome), stdin);
    usuario.nome[strcspn(usuario.nome, "\n")] = '\0';

    printf("Digite o ID do usuario: ");
    scanf("%d", &usuario.id);
    limparBuffer();

    printf("Digite o email do usuario: ");
    fgets(usuario.email, sizeof(usuario.email), stdin);
    usuario.email[strcspn(usuario.email, "\n")] = '\0';

    biblio->usuarios[biblio->qtdUsuarios++] = usuario;
    printf("Usuario adicionado com sucesso!\n");
}

void listarLivros(const Biblioteca *biblio)
{
    printf("Lista de Livros:\n");
    for (int i = 0; i < biblio->qtdLivros; i++)
    {
        printf("Titulo: %s, Autor: %s, Ano: %d\n",
               biblio->livros[i].titulo,
               biblio->livros[i].autor,
               biblio->livros[i].ano);
    }
}

void listarUsuarios(const Biblioteca *biblio)
{
    printf("Lista de Usuarios:\n");
    for (int i = 0; i < biblio->qtdUsuarios; i++)
    {
        printf("Nome: %s, ID: %d, Email: %s\n",
               biblio->usuarios[i].nome,
               biblio->usuarios[i].id,
               biblio->usuarios[i].email);
    }
}

int buscarLivroRec(const Livro livros[], int n, const char *titulo)
{
    if (n == 0) return -1;
    if (strcmp(livros[n - 1].titulo, titulo) == 0) return n - 1;
    return buscarLivroRec(livros, n - 1, titulo);
}

void buscarLivro(const Biblioteca *biblio)
{
    char titulo[100];
    printf("Digite o titulo do livro para buscar: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    int indice = buscarLivroRec(biblio->livros, biblio->qtdLivros, titulo);
    if (indice != -1)
    {
        printf("Livro encontrado: Titulo: %s, Autor: %s, Ano: %d\n",
               biblio->livros[indice].titulo,
               biblio->livros[indice].autor,
               biblio->livros[indice].ano);
    }
    else
    {
        printf("Livro nao encontrado.\n");
    }
}

void menu()
{
    Biblioteca biblio = { .qtdLivros = 0, .qtdUsuarios = 0 };
    int opcao;

    do
    {
        printf("\nMenu:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Adicionar Usuario\n");
        printf("3. Listar Livros\n");
        printf("4. Listar Usuarios\n");
        printf("5. Buscar Livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            adicionarLivro(&biblio);
            break;
        case 2:
            adicionarUsuario(&biblio);
            break;
        case 3:
            listarLivros(&biblio);
            break;
        case 4:
            listarUsuarios(&biblio);
            break;
        case 5:
            buscarLivro(&biblio);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção invalida!\n");
        }
    }
    while (opcao != 0);
}

#endif // FUNCAO_H_INCLUDED
