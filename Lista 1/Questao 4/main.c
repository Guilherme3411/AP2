#include <stdio.h>
#include <stdlib.h>

struct
{
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
} Produto;
float somaprodutos(int preco, int quantidade)
{
    return quantidade*preco;
}

int main()
{
    printf("\n-------Cadastro De Produto-------\n");
    printf("\n Escreva o nome do produto: ");
    scanf("%s",Produto.nome);
    printf("\n Escreva o codigo do produto: ");
    scanf("%d",&Produto.codigo);
    printf("\n Escreva o preco do produto: ");
    scanf("%f",&Produto.preco);
    printf("\n Escreva a quantidade de produto: ");
    scanf("%d",&Produto.quantidade);

    printf("\n--------Tabela do produto--------\n");
    printf("\n O nome do produto e: %s",Produto.nome);
    printf("\n O codigo do produto e: %d",Produto.codigo);
    printf("\n O  preco do produto e: %f\n",Produto.preco);
    printf("\n A quantidade do produto e: %d",Produto.quantidade);
    printf("\n A soma dos produtos e: %f\n",somaprodutos(Produto.preco,Produto.quantidade));
}
