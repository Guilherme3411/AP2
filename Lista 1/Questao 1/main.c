#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idade;
    float salario;
    char nome[50];
} Funcionario;

int main()
{
    Funcionario f1;
    printf("\n ----Cadastro De Funcionario---- \n");
    printf("\n Escreva o nome do Funcionario: ");
    scanf("%s",f1.nome);
    printf("\n Escreva a idade do funcionario: ");
    scanf("%d",&f1.idade);
    printf("\n Escreva o salario do funcionario: ");
    scanf("%f",&f1.salario);

    printf("\n ----Informacao do funcionario----\n");
    printf("\nO nome do funcionario e:  %s",f1.nome);
    printf("\nA idade do funcionario e:  %d",f1.idade);
    printf("\nO salario do funcionario e:  %f",f1.salario);
}
