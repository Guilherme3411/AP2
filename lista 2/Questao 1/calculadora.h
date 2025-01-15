#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED

void soma()
{
    int v1,v2,result,s;
    printf("Escreva um numero inteiro:");
    scanf("%d",&v1);
    printf("\nEscreva outro numero inteiro:");
    scanf("%d",&v2);
    result=v1+v2;
    printf("\nO resultado da soma e:%d",result);

}
void subitracao()
{
    int v1,v2,result;
    printf("Escreva um numero inteiro:");
    scanf("%d",&v1);
    printf("\nEscreva outro numero inteiro:");
    scanf("%d",&v2);
    result=v1-v2;
    printf("\nO resultado da subitracao e:%d",result);

}
void multiplicacao()
{
    int v1,v2,result,m;
    printf("Escreva um numero inteiro:");
    scanf("%d",&v1);
    printf("\nEscreva outro numero inteiro:");
    scanf("%d",&v2);
    result=v1*v2;
    printf("\nO resultado da multiplicacao e:%d",result);

}
void divisao()
{
    int v1,v2;
    float result;
    printf("Escreva um numero inteiro:");
    scanf("%d",&v1);
    printf("\nEscreva outro numero inteiro:");
    scanf("%d",&v2);
    result=v1*v2;
    printf("\nO resultado da divisao e:%f",result);

}
void menu()
{

    printf("\n----------------[ Menu ]---------------\n");
    printf("Digite 1 Para Calcular Uma Soma\n");
    printf("Digite 2 Para Calcular Uma Subitracao\n");
    printf("Digite 3 Para Calcular Uma Multiplicacao\n");
    printf("Digite 4 Para Calcular Uma Divisao\n");
    printf("Digite 5 Para Sair!!!!\n");
    printf("\nEscreva um valor: ");
}




#endif // CALCULADORA_H_INCLUDED
