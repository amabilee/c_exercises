#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct no {
    char nome[10]; 
    struct no* prox;
    struct no* ant;
} No;

No* criar_no(const char* valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (!novo_no) {
        printf("ERRO ao alocar a memoria.\n");
        exit(1);
    }
    strcpy(novo_no->nome, valor);
    novo_no->prox = novo_no->ant = NULL;
    return novo_no;
}

void inserir_ordenado(No** cabeca, const char* valor) {
    No* novo_no = criar_no(valor);
    if (*cabeca == NULL) {
        *cabeca = novo_no;
        novo_no->prox = novo_no->ant = novo_no;
    } else {
        No* atual = *cabeca;
        do {
            if (strcmp(valor, atual->nome) < 0) { 
                novo_no->prox = atual;
                novo_no->ant = atual->ant;
                atual->ant->prox = novo_no;
                atual->ant = novo_no;
                if (atual == *cabeca) {
                    *cabeca = novo_no; 
                }
                return;
            }
            atual = atual->prox;
        } while (atual != *cabeca);
        
        No* ultimo = (*cabeca)->ant;
        novo_no->prox = *cabeca;
        novo_no->ant = ultimo;
        ultimo->prox = novo_no;
        (*cabeca)->ant = novo_no;
    }
}

void imprimir_lista(No* cabeca) {
    if (cabeca == NULL) {
        printf("A lista esta vazia\n");
        return;
    }
    No* atual = cabeca;
    do {
        printf("[%s] <-> ", atual->nome);
        atual = atual->prox;
    } while (atual != cabeca);
    printf("\n\n");
}

void liberar_lista(No** cabeca) {
    if (*cabeca == NULL)
        return;

    No* atual = *cabeca;
    No* prox_no;
    do {
        prox_no = atual->prox;
        free(atual);
        atual = prox_no;
    } while (atual != *cabeca);
    *cabeca = NULL;
}

const char* numero_para_nome(int numero) {
    const char* nomes[] = {
        "zero", "um", "dois", "tres", "quatro",
        "cinco", "seis", "sete", "oito", "nove", "dez"
    };
    if (numero >= 0 && numero <= 10) {
        return nomes[numero];
    } else {
        return "";
    }
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    No* cabeca = NULL;
    int numeroValores;
    
    printf("Quantos valores voce deseja inserir? 0 - 10: ");
    scanf("%d", &numeroValores);

    if (numeroValores < 0 || numeroValores > 10) {
        printf("Item que ser entre 0 e 10");
        return 1;
    }

    for (int i = 0; i < numeroValores; i++) {
        int valor;
        printf("Digite o valor %d entre 0 - 10: ", i+1);
        scanf("%d", &valor);

        if (valor < 0 || valor > 10) {
            printf("Tem que ser entre 0 - 10");
            i--; 
            continue;
        }

        const char* nome = numero_para_nome(valor);
        inserir_ordenado(&cabeca, nome);
    }

    
    printf("Lista:\n");
    imprimir_lista(cabeca);
    
    liberar_lista(&cabeca);

    return 0; 
}

