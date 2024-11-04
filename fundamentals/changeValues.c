#include <stdio.h>
#include <locale.h>
#include <math.h>

void trocar(int *a, int *b);

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int a,b;
	
	printf("Digite o valor da variavel A: ");
	scanf("%i", &a);
	printf("Digite o valor da variavel B: ");
	scanf("%i", &b);
	
	trocar(&a, &b);
	
	printf("/n O Valor de A e %i", a);
	printf("/n O Valor de B e %i", b);
	
}

void trocar(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
