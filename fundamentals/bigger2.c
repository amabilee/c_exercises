#include <stdio.h>
#include <locale.h>
#include <math.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int A,B, *P1, *P2;
	
	printf("Digite o valor da variavel A: ");
	scanf("%i", &A);
	P1 = &A;
	
	printf("Digite o valor da variavel B: ");
	scanf("%i", &B);
	P2 = &B;
	
	if(P1 > P2){
		printf("%i", P1);
	} else {
		printf("%i", P2);
	}

}
