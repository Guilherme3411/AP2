#include <stdio.h>
#include <stdlib.h>

struct
{
    char tituloliv[100];
    char autor[50];
    int anodepubli;
} Livro;

int main()
{
    printf("\n-----Cadastro Do Livro-----\n");
    printf("\n Escreva o titulo do livro: ");
    scanf("%s",Livro.tituloliv);
    printf("\n Escreva o nome do autor: ");
    scanf("%s",Livro.autor);
    printf("\n Escreva o ano de publicacao: ");
    scanf("%d",&Livro.anodepubli);
    printf("\n------Livro Cadastrado------\n");
    printf("\n O titilo do livro e: %s",Livro.tituloliv);
    printf("\n O nome do autor e: %s",Livro.autor);
    printf("\n O ano de publicacao e: %d\n",Livro.anodepubli);
}
