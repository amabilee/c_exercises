#include <stdio.h>
#include <locale.h>
#include <math.h>

void calc(int *a, int *b);

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int a,b;
	
	printf("Digite o valor da variavel A: ");
	scanf("%i", &a);
	printf("Digite o valor da variavel B: ");
	scanf("%i", &b);
	
	calc(&a, &b);
	
	
	printf("/n O Resultado e %i", a);	
}

void calc(int *a, int *b){
	int temp;

	*a = *a + *a;
	*b = *b + *b;

	temp = *a + *b;
	*a = temp;
}
