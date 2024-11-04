#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    int matricula;
    char nome[50];
    int ano_nascimento;
};

int main() {
    int num_alunos;
    Aluno *alunos;  

    printf("Digite o número de alunos: ");
    scanf("%d", &num_alunos);

    alunos = (Aluno *) malloc(num_alunos * sizeof(Aluno));

    for (int i = 0; i < num_alunos; i++) {
        printf("\n--- Cadastro do aluno %d ---\n", i + 1);
        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Ano de nascimento: ");
        scanf("%d", &alunos[i].ano_nascimento);
    }

    printf("\n--- Dados dos alunos cadastrados ---\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Ano de nascimento: %d\n\n", alunos[i].ano_nascimento);
    }

    free(alunos);
}
