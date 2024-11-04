#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Data {
    int dia;
    int mes;
};

struct Contato {
    char nome[40];
    char telefone[15];
    char celular[15];
    char email[40];
    struct Data aniversario;
    struct Contato* proximo;
};

struct Contato* criar_agenda() {
    return NULL;
}

void adicionar_contato(struct Contato** cabeca) {
    struct Contato* novo = (struct Contato*)malloc(sizeof(struct Contato));
    
    printf("Digite o nome: ");
    scanf("%s", novo->nome);
    printf("Digite o telefone: ");
    scanf("%s", novo->telefone);
    printf("Digite o celular: ");
    scanf("%s", novo->celular);
    printf("Digite o email: ");
    scanf("%s", novo->email);
    printf("Digite o dia do aniversario: ");
    scanf("%d", &novo->aniversario.dia);
    printf("Digite o mes do aniversario: ");
    scanf("%d", &novo->aniversario.mes);

    novo->proximo = *cabeca; 
    *cabeca = novo;
}

void listar_contatos(struct Contato* lista) {
    struct Contato* atual = lista;
    while (atual != NULL) {
        printf("Nome: %s, Telefone: %s, Celular: %s, Email: %s, Aniversario: %02d/%02d\n",
               atual->nome, atual->telefone, atual->celular, atual->email,
               atual->aniversario.dia, atual->aniversario.mes);
        atual = atual->proximo;
    }
}

struct Contato* buscar_contato(struct Contato* lista, char* nome) {
    struct Contato* atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void remover_contato(struct Contato** cabeca) {
    char nome[40];
    printf("Nome do contato a remover: ");
    scanf("%s", nome);

    struct Contato* atual = *cabeca;
    struct Contato* anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                *cabeca = atual->proximo;
            } else {
                anterior->proximo = atual->proximo; 
            }
            free(atual);
            printf("Contato removido.\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Contato nao encontrado.\n");
}

void atualizar_contato(struct Contato* lista) {
    char nome[40];
    printf("Nome do contato a atualizar: ");
    scanf("%s", nome);
    
    struct Contato* contato = buscar_contato(lista, nome);
    if (contato != NULL) {
        printf("Atualizando %s:\n", contato->nome);
        printf("Novo telefone: ");
        scanf("%s", contato->telefone);
        printf("Novo celular: ");
        scanf("%s", contato->celular);
        printf("Novo email: ");
        scanf("%s", contato->email);
        printf("Novo dia do aniversario: ");
        scanf("%d", &contato->aniversario.dia);
        printf("Novo mes do aniversario: ");
        scanf("%d", &contato->aniversario.mes);
        printf("Contato atualizado.\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
}

void liberar_agenda(struct Contato** cabeca) {
    struct Contato* atual = *cabeca;
    while (atual != NULL) {
        struct Contato* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *cabeca = NULL;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Contato* agenda = criar_agenda();
    int opcao;

    do {
        printf("Escolha uma opcao:\n");
        printf("(1) - Adicionar contato\n");
        printf("(2) - Listar contatos\n");
        printf("(3) - Buscar contato\n");
        printf("(4) - Remover contato\n");
        printf("(5) - Atualizar contato\n");
        printf("(6) - Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            adicionar_contato(&agenda);
        } else if (opcao == 2) {
            listar_contatos(agenda);
        } else if (opcao == 3) {
            char nome_busca[40];
            printf("Nome do contato a buscar: ");
            scanf("%s", nome_busca);
            struct Contato* encontrado = buscar_contato(agenda, nome_busca);
            if (encontrado) {
                printf("Contato encontrado: %s\n", encontrado->nome);
            } else {
                printf("Contato nao encontrado.\n");
            }
        } else if (opcao == 4) {
            remover_contato(&agenda);
        } else if (opcao == 5) {
            atualizar_contato(agenda);
        }
    } while (opcao != 6);

    liberar_agenda(&agenda);
    return 0;
}

