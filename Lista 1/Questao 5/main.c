#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int telefone;
    char email[50];
} Cadastros;

struct ListadeContatos
{
    Cadastros cadastros[5];
    int quantidade;
};
void adicionarContato(struct ListadeContatos *lista)
{
    if(lista->quantidade < 5)
    {
        printf("\n Digite o nome: ");
        setbuf(stdin, NULL);
        gets(lista->cadastros[lista->quantidade].nome);
        setbuf(stdin, NULL);
        //lista->cadastros[lista->quantidade].nome[strcspn(lista->cadastros[lista->quantidade].nome, "\n")] =  '\0';
        printf("\n Digite o telefone: ");
        scanf("%d",&lista->cadastros[lista->quantidade].telefone);
        setbuf(stdin, NULL);
        //lista->cadastros[lista->quantidade].nome[strcspn(lista->cadastros[lista->quantidade].telefone, "\n")]=  '\0';
        printf("\n Digite o email: ");
        gets(lista->cadastros[lista->quantidade].email);
        //lista->cadastros[lista->quantidade].nome[strcspn(lista->cadastros[lista->quantidade].email, "\n")]=  '\0';
        setbuf(stdin, NULL);

        lista->quantidade++;
    }
    else
    {
        printf("Lista cheia");
    }

}


void exibirContatos(struct ListadeContatos lista)
{
    printf("Lista de contatos: \n");
    for(int i=0; i<lista.quantidade; i++)
    {
        printf("Contatos %d \n", i+1);
        printf("Nome: %s \n", lista.cadastros[i].nome);
        printf("Telefone: %d \n", lista.cadastros[i].telefone);
        printf("Email:  %s \n", lista.cadastros[i].email);
    }
}

int buscarContatos(struct ListadeContatos lista, char *nome)
{
    for(int i=0; i<lista.quantidade; i++)
    {
        if (strcmp(lista.cadastros[i].nome, nome)==0)
        {
            return i;
        }
    }
    return -1;
}



int main()
{
    char nome[100];
    struct ListadeContatos lista;
    lista.quantidade = 0;
    int op;

    do
    {
        printf("1. Adicionar contato\n");
        printf("2. Exibir Lista de Contato \n");
        printf("3. Buscar contatos\n");
        printf("0. Sair \n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            adicionarContato(&lista);
            break;
        case 2:
            exibirContatos(lista);
            break;
        case 3:
            printf("\n Digite o nome a buscar: ");
            setbuf(stdin,NULL);
            gets(nome);
            setbuf(stdin,NULL);

            int indice = buscarContatos(lista, nome);
            if(indice == -1)
            {
                printf("Contato nao encontrado!!! \n ");
            }
            else
            {
                printf("Contato encontrado %d \n", indice+1);
                printf("Nome: %s \n", lista.cadastros[indice].nome);
                printf("Telefone: %d \n", lista.cadastros[indice].telefone);
                printf("Email:  %s \n", lista.cadastros[indice].email);
            }
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
        }
    }
    while(op != 0);

}
