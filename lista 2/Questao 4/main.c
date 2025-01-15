#include <stdio.h>
#include <stdlib.h>
#include "Hotel.h"
#define MAX_QUARTOS 10

int main() {
    Quarto quartos[MAX_QUARTOS];
    int opcao;
    inicializarQuartos(quartos, MAX_QUARTOS);

    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                exibirDisponibilidade(quartos, MAX_QUARTOS);
                break;
            case 2:
                reservarQuarto(quartos, MAX_QUARTOS);
                break;
            case 3:
                cancelarReserva(quartos, MAX_QUARTOS);
                break;
            case 4:
                printf("Saindo do sistema!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

