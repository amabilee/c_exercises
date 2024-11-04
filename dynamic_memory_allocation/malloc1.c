#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_alunos;
    float *notas;
    float soma = 0.0, media;

    printf("Digite a quantidade de alunos na turma: ");
    scanf("%d", &num_alunos);

    notas = (float *) malloc(num_alunos * sizeof(float));

    for (int i = 0; i < num_alunos; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }
    media = soma / num_alunos;

    printf("A média é: %.2f\n", media);

    free(notas);
}
