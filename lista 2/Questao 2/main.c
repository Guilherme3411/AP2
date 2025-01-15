#include <stdio.h>
#include <stdlib.h>
#include "Alunos.h"
int main()
{
   int num;
    while(menu>=3){
    menu();
    scanf("%d",&num);
    switch(num)
    {
    case 1:
    {
        AddAl();
        break;
    }
    case 2:
    {
        AddNota();
        break;
    }
    case 3:
    {
        lista();
        break;
    }
    case 4:
    {
        printf("Saindo......");
        return 0;
    }
    }

}
}


