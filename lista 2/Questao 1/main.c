#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main()
{
    int num;
    while(menu>=4){
    menu();
    scanf("%d",&num);
    switch(num)
    {
    case 1:
    {
        soma();
        break;
    }
    case 2:
    {
        subitracao();
        break;
    }
    case 3:
    {
        multiplicacao();
        break;
    }
    case 4:
    {
        divisao();
        break;
    }
    case 5:
    {
        printf("Saindo......");
        return 0;
    }
    }
}
}
