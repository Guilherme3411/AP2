#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include <stdio.h>
#include <string.h>

#define MAX_QUARTOS 100

typedef struct {
    int numero_quarto;
    char status[20];
} Quarto;
void menu() {
    printf("---------- Menu ----------\n");
    printf("1. Verificar disponibilidade\n");
    printf("2. Fazer reserva\n");
    printf("3. Consultar reserva\n");
    printf("4. Sair\n");
    printf("--------------------------\n");
    printf("Escolha uma opção: ");
}
void carregar_quartos(Quarto quartos[], int *quantidade_quartos) {
    FILE *arquivo = fopen("Quartos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de quartos.\n");
        return;
    }
    *quantidade_quartos = 0;
    while (fscanf(arquivo, "Quarto %d - %s\n", &quartos[*quantidade_quartos].numero_quarto, quartos[*quantidade_quartos].status) != EOF) {
        (*quantidade_quartos)++;
    }
    fclose(arquivo);
}
void salvar_quartos(Quarto quartos[], int quantidade_quartos) {
    FILE *arquivo = fopen("Quartos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de quartos.\n");
        return;
    }
    for (int i = 0; i < quantidade_quartos; i++) {
        fprintf(arquivo, "Quarto %d - %s\n", quartos[i].numero_quarto, quartos[i].status);

    fclose(arquivo);
}

void verificar_disponibilidade(Quarto quartos[], int quantidade_quartos) {
    printf("\n--- Disponibilidade de Quartos ---\n");
    for (int i = 0; i < quantidade_quartos; i++) {
        printf("Quarto %d - %s\n", quartos[i].numero_quarto, quartos[i].status);
    }
}

void fazer_reserva(Quarto quartos[], int quantidade_quartos) {
    int numero_quarto;
    printf("\nDigite o número do quarto que deseja reservar: ");
    scanf("%d", &numero_quarto);

    int encontrado = 0;
    for (int i = 0; i < quantidade_quartos; i++) {
        if (quartos[i].numero_quarto == numero_quarto) {
            encontrado = 1;
            if (strcmp(quartos[i].status, "Disponível") == 0) {
                strcpy(quartos[i].status, "Indisponível");
                printf("Reserva realizada com sucesso para o Quarto %d!\n", numero_quarto);
            } else {
                printf("O Quarto %d já está reservado!\n", numero_quarto);
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Quarto não encontrado.\n");
    }

    salvar_quartos(quartos, quantidade_quartos);  // Salva as alterações no arquivo
}

void consultar_reserva(Quarto quartos[], int quantidade_quartos) {
    int numero_quarto;
    printf("\nDigite o número do quarto para consultar a reserva: ");
    scanf("%d", &numero_quarto);

    int encontrado = 0;
    for (int i = 0; i < quantidade_quartos; i++) {
        if (quartos[i].numero_quarto == numero_quarto) {
            encontrado = 1;
            printf("O Quarto %d está %s.\n", numero_quarto, quartos[i].status);
            break;
        }
    }

    if (!encontrado) {
        printf("Quarto não encontrado.\n");
    }
}
#endif // LOGIN_H_INCLUDED
