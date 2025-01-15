#include <stdio.h>
#include <stdlib.h>
#include "login.h"
int main() {
    int num = 0;
    do {
        menu();
        scanf("%d", &num);
        switch (num) {
        case 1:
            cadastro();
            break;

        case 2:
            verificacao();
            break;

        case 3:
            printf("Saindo......\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (num != 3);
    return 0;
}
