#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarefa {
    int id;
    char titulo[50];
    int prioridade;
    char data_criacao[11]; 
    struct Tarefa* anterior;
    struct Tarefa* proximo;
} Tarefa;

void adicionar_tarefa(Tarefa** cabeca, int id, char* titulo, int prioridade, char* data_criacao) {
    Tarefa* nova_tarefa = (Tarefa*)malloc(sizeof(Tarefa));
    nova_tarefa->id = id;
    strcpy(nova_tarefa->titulo, titulo);
    nova_tarefa->prioridade = prioridade;
    strcpy(nova_tarefa->data_criacao, data_criacao);
    nova_tarefa->anterior = NULL;
    nova_tarefa->proximo = NULL;

    if (*cabeca == NULL) {
        *cabeca = nova_tarefa;
    } else {
        Tarefa* atual = *cabeca;
        Tarefa* anterior = NULL;

        while (atual != NULL && atual->prioridade <= prioridade) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL) {
            nova_tarefa->proximo = *cabeca;
            (*cabeca)->anterior = nova_tarefa;
            *cabeca = nova_tarefa;
        } else {
            nova_tarefa->proximo = atual;
            nova_tarefa->anterior = anterior;
            anterior->proximo = nova_tarefa;
            if (atual != NULL) {
                atual->anterior = nova_tarefa;
            }
        }
    }
}

void remover_tarefa(Tarefa** cabeca, int id) {
    Tarefa* atual = *cabeca;

    while (atual != NULL && atual->id != id) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Tarefa não encontrada!\n");
        return;
    }

    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        *cabeca = atual->proximo;
    }

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
    printf("Tarefa removida com sucesso!\n");
}

void buscar_tarefa(Tarefa* cabeca, int id) {
    Tarefa* atual = cabeca;

    while (atual != NULL && atual->id != id) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Tarefa não encontrada!\n");
        return;
    }

    printf("ID: %d\nTitulo: %s\nPrioridade: %d\nData de Criação: %s\n",
           atual->id, atual->titulo, atual->prioridade, atual->data_criacao);
}

void listar_tarefas(Tarefa* cabeca) {
    Tarefa* atual = cabeca;

    while (atual != NULL) {
        printf("ID: %d\nTitulo: %s\nPrioridade: %d\nData de Criação: %s\n\n",
               atual->id, atual->titulo, atual->prioridade, atual->data_criacao);
        atual = atual->proximo;
    }
}

void listar_tarefas_inverso(Tarefa* cabeca) {
    Tarefa* atual = cabeca;

    if (atual == NULL) {
        return;
    }

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    while (atual != NULL) {
        printf("ID: %d\nTitulo: %s\nPrioridade: %d\nData de Criação: %s\n\n",
               atual->id, atual->titulo, atual->prioridade, atual->data_criacao);
        atual = atual->anterior;
    }
}

int main() {
    Tarefa* lista = NULL;
    int opcao, id, prioridade;
    char titulo[50], data_criacao[11];

    do {
        printf("Menu:\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Remover tarefa\n");
        printf("3. Buscar tarefa\n");
        printf("4. Listar tarefas\n");
        printf("5. Listar tarefas em ordem inversa\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("ID da Tarefa: ");
                scanf("%d", &id);
                printf("Titulo: ");
                scanf(" %[^\n]%*c", titulo);
                printf("Prioridade: ");
                scanf("%d", &prioridade);
                printf("Data de Criação (dd-mm-aaaa): ");
                scanf("%s", data_criacao);
                adicionar_tarefa(&lista, id, titulo, prioridade, data_criacao);
                break;
            case 2:
                printf("ID da Tarefa a remover: ");
                scanf("%d", &id);
                remover_tarefa(&lista, id);
                break;
            case 3:
                printf("ID da Tarefa a buscar: ");
                scanf("%d", &id);
                buscar_tarefa(lista, id);
                break;
            case 4:
                listar_tarefas(lista);
                break;
            case 5:
                listar_tarefas_inverso(lista);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 6);

    return 0;
}
