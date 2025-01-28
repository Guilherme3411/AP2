#include <stdio.h>
#include <stdlib.h>
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int somaArray(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += *(array + i);
    }
    return soma;
}

void alocarArray() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}

typedef struct {
    int x;
    int y;
} Ponto;

void atualizarPonto(Ponto *p, int novoX, int novoY) {
    p->x = novoX;
    p->y = novoY;
}

int contarCaracteres(char *str) {
    int contador = 0;
    while (*str != '\0') {
        contador++;
        str++;
    }
    return contador;
}

int main() {

    int a = 5, b = 10;
    printf("Antes de trocar: a = %d, b = %d\n", a, b);
    trocar(&a, &b);
    printf("Depois de trocar: a = %d, b = %d\n", a, b);
    int array[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);
    printf("Soma dos elementos do array: %d\n", somaArray(array, tamanho));
    alocarArray();
    Ponto p;
    atualizarPonto(&p, 10, 20);
    printf("Coordenadas do ponto: x = %d, y = %d\n", p.x, p.y);
    char string[100];
    printf("Digite uma string: ");
    scanf("%s", string);
    printf("Numero de caracteres na string: %d\n", contarCaracteres(string));
    return 0;
}
