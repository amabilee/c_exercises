#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho, *vetor;
    int pares = 0, impares = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor para vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("Vetor atual: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
        if (vetor[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    printf("\nQuantidade de números pares: %d\n", pares);
    printf("Quantidade de números ímpares: %d\n", impares);


    free(vetor);
}
