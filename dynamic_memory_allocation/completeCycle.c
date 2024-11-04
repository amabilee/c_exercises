#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

struct No{
	int codigo;
	char nome[50];
	int quantidade;
	float valor;
	struct No* next;
};

void inser_inicio(struct No** head_ref, int codigo, char* nome, int quantidade , float valor){
	struct No* novo_no = (struct No*)malloc(sizeof(struct No));
	
	strcpy(novo_no->nome, nome);
	novo_no->codigo = codigo;
	novo_no->quantidade = quantidade;
	novo_no->valor = valor;
	
	novo_no->next = (*head_ref);
	(*head_ref) = novo_no;
}

void imprimir(struct No* n){
	while(n != NULL){
		printf("C�digo do item> %d - Nome: %s - Valor: %f - Quantidade: %d", n->codigo, n->nome, n->valor, n->quantidade);
		n = n->next;
	};
}

main(){
	setlocale(LC_ALL, "Portuguese");
	struct No* head = NULL;
	int n, i;
	
	int codigo;
	char nome[50];
	int quantidade;
	float valor;

	printf("Quantos Itens deseja inserir na lista? ");
	scanf("%d", &n);
	
	getchar();
	
	for (i=0; i<n; i++){
		printf("Digite o nome do %d� Item.", i+1);
		fgets(nome, sizeof(nome), stdin);
		nome[strcspn(nome, "/n")] = '/0';
		
		printf("Digite o codigo do %d� Item.", i+1);
		scanf("%d", &codigo);
		
		printf("Digite a quantidade do %d� Item.", i+1);
		scanf("%d", &quantidade);
		
		printf("Digite o valor do %d� Item.", i+1);
		scanf("%f", &valor);
		getchar();
		
		inser_inicio(&head, codigo, nome, quantidade, valor);
	}

	printf("/n *** Lista de Aluno e Notas *** /n");
	imprimir(head);
}

