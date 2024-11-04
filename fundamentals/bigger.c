#include <stdio.h>
#include <locale.h>
#include <math.h>

void maior(int *a, int *b);

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int a,b;
	
	printf("Digite o valor da vari�vel A: ");
	scanf("%i", &a);
	printf("Digite o valor da vari�vel B: ");
	scanf("%i", &b);
	
	maior(&a, &b);
	
	
	printf("/n O Maior Valor e %i", a);
	
}

void maior(int *a, int *b){
	int temp;
	if(*a < *b){
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
