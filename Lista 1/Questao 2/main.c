#include <stdio.h>
#include <stdlib.h>

struct
{
    int matricula;
    float nota1;
    float nota2;
    char nome[50];
} aluno;

float medianota(float nota1,float nota2)
{
    return (nota1+nota2)/2;
}

int main()
{
    printf("\n---Cadastro Do Aluno----\n");
    printf("\n Digite o nome do aluno: ");
    scanf("%s",aluno.nome);
    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&aluno.matricula);
    printf("\n Digite o nota 1 do aluno: ");
    scanf("%f",&aluno.nota1);
    printf("\n Digite o nota 2 do aluno: ");
    scanf("%f",&aluno.nota2);
    printf("\n-----Ficha Do Aluno-----\n ");
    printf("\n O nome do aluno e: %s",aluno.nome);
    printf("\n A matricula do aluno e: %d ",aluno.matricula);
    printf("\n As notas do aluno foram %f e %f",aluno.nota1,aluno.nota2);
    printf("\n A media do aluno e: %f\n",medianota(aluno.nota1,aluno.nota2));
}
