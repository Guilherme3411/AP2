#ifndef HOTEL_H
#define HOTEL_H
typedef struct
{
    int numero;
    int ocupado;
} Quarto;
void menu()
{
    printf("\n---- Sistema de Reservas ----\n");
    printf("1. Verificar Disponibilidade\n");
    printf("2. Reservar Quarto\n");
    printf("3. Cancelar Reserva\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}
void inicializarQuartos(Quarto quartos[], int n)
{
    for (int i = 0; i < n; i++)
    {
        quartos[i].numero = i + 1;
        quartos[i].ocupado = 0;
    }
}
void exibirDisponibilidade(Quarto quartos[], int n)
{
    printf("\n---- Status dos Quartos ----\n");
    for (int i = 0; i < n; i++)
    {
        printf("Quarto %d: %s\n", quartos[i].numero, quartos[i].ocupado ? "Ocupado" : "Disponivel");
    }
}
void reservarQuarto(Quarto quartos[], int n)
{
    int numeroQuarto;
    printf("\nDigite o numero do quarto para reservar: ");
    scanf("%d", &numeroQuarto);

    if (numeroQuarto < 1 || numeroQuarto > n)
    {
        printf("Numero de quarto invalido!\n");
        return;
    }
    if (quartos[numeroQuarto - 1].ocupado == 1)
    {
        printf("O quarto %d ja esta ocupado!\n", numeroQuarto);
    }
    else
    {
        quartos[numeroQuarto - 1].ocupado = 1;
        printf("Quarto %d reservado com sucesso!\n", numeroQuarto);
    }
}
void cancelarReserva(Quarto quartos[], int n)
{
    int numeroQuarto;
    printf("\nDigite o numero do quarto para cancelar a reserva: ");
    scanf("%d", &numeroQuarto);

    if (numeroQuarto < 1 || numeroQuarto > n)
    {
        printf("Numero de quarto invalido!\n");
        return;
    }

    if (quartos[numeroQuarto - 1].ocupado == 0)
    {
        printf("O quarto %d não esta reservado!\n", numeroQuarto);
    }
    else
    {
        quartos[numeroQuarto - 1].ocupado = 0;
        printf("Reserva do quarto %d cancelada com sucesso!\n", numeroQuarto);
    }
}
#endif  // HOTEL_H

