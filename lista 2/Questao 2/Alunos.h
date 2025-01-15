#ifndef ALUNOS_H_INCLUDED
#define ALUNOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int code;
    float nota;
} Aluno;

void menu()
{
    printf("--------------Menu---------------\n");
    printf("1 - Adicionar Aluno\n");
    printf("2 - Adicionar Notas\n");
    printf("3 - Ver lista de alunos e notas\n");
    printf("4 - Sair\n");
    printf("Digite um valor: ");
}

void AddAl()
{
    FILE *arquivo;
    Aluno aluno;

    arquivo = fopen("alunos.txt", "a");
    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    printf("\nNome do aluno: ");
    scanf(" %[^\n]s", aluno.nome);
    printf("Codigo de matricula do aluno: ");
    scanf("%d", &aluno.code);

    fprintf(arquivo, "Nome: %s\nNumero da matricula: %d\n", aluno.nome, aluno.code);
    fclose(arquivo);

    printf("Aluno adicionado com sucesso!\n");
}

void AddNota()
{
    float nota, soma = 0;
    int contador = 0;
    FILE *arquivo;

    arquivo = fopen("notas.txt", "a");
    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    printf("Digite as notas (digite -1 para parar):\n");

    while (1)
    {
        printf("Nota %d: ", contador + 1);
        scanf("%f", &nota);

        if (nota == -1)
        {
            break;
        }

        fprintf(arquivo, "Nota %d: %.2f\n", contador + 1, nota);
        soma += nota;
        contador++;
    }
    fclose(arquivo);

    if (contador > 0)
    {
        float media = soma / contador;
        printf("A média das notas é: %.2f\n", media);
    }
    else
    {
        printf("Nenhuma nota foi inserida.\n");
    }
}

void lista()
{
    FILE *arquivo;
    char linha[100];

    printf("\n--- Lista de Alunos ---\n");
    arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de alunos!\n");
    }
    else
    {
        while (fgets(linha, sizeof(linha), arquivo))
        {
            printf("%s", linha);
        }
        fclose(arquivo);
    }

    printf("\n--- Lista de Notas ---\n");
    arquivo = fopen("notas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de notas!\n");
    }
    else
    {
        while (fgets(linha, sizeof(linha), arquivo))
        {
            printf("%s", linha);
        }
        fclose(arquivo);
    }
}
#endif // ALUNOS_H_INCLUDED
