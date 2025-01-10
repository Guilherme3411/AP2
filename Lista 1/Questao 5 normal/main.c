#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
    char email[50];
};

int main() {
    struct Contato contato;

    printf("Cadastro de Contato\n");
    printf("Nome: ");
    fgets(contato.nome, 50, stdin);
    printf("Telefone: ");
    fgets(contato.telefone, 15, stdin);
    printf("Email: ");
    fgets(contato.email, 50, stdin);

    printf("\nInformacoes do Contato:\n");
    printf("Nome: %s\n", contato.nome);
    printf("Telefone: %s\n", contato.telefone);
    printf("Email: %s\n", contato.email);

    return 0;
}
