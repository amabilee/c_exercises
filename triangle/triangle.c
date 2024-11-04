#include<stdio.h>
#include<math.h>
#include<locale.h>

int square(int x);

int triangulo(int a, int b){
	int result = (a*b)/2;
	return result;
}

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int i;
	int answer;
	
	printf("Digite a opcao que deseja"
			"1 - Calcule a area de um triangulo."
				"2 -  Ordene de forma crescente 3 valores."
					"3 - Ordene de forma decrescente 3 valores ."
						"4 - Calcular as raizes de uma equacao do 2 Grau (Ax2+Bx+C)"

   );
	scanf("%i",&answer);
	
	if (answer == 1){
		
		int a;
		int b;
		printf("Insira a altura do triangulo: ");
		scanf("%i", &a);
		
		printf("Insira a base do triangulo: ");
		scanf("%i", &b);
		
		printf("\n Resultado: %i ",(a*b)/2);
	
	} else if (answer == 2){
		int a;
		int b;
		int c;
		
		int bigger;
		
		printf("Insira o primeiro valor: ");
		scanf("%i", &a);
		printf("Insira o segundo valor: ");
		scanf("%i", &b);
		printf("Insira o terceiro valor: ");
		scanf("%i", &c);
		
		if (a > b && a > c){
			bigger = a;
			if (b>c){
				printf("%i %i %i", a, b , c);
			} else {
				printf("%i %i %i", a, c , b);	
			};
		} else if (b > a && b > c){
			bigger = b;
			if(a>c){
				printf("%i %i %i", b, a , c);
			} else {
				printf("%i %i %i", b, c , a);
			};
		} else {
			bigger = c;
			if (a>b){
				printf("%i %i %i", c, a , b);
			} else {
				printf("%i %i %i", c, b , a);
			} ;
		}
		
	} else if (answer == 3){
		int a;
		int b;
		int c;
		
		int smaller;
		
		printf("Insira o primeiro valor: ");
		scanf("%i", &a);
		printf("Insira o segundo valor: ");
		scanf("%i", &b);
		printf("Insira o terceiro valor: ");
		scanf("%i", &c);
		
		if (a < b && a < c){
			smaller = a;
			if (b<c){
				printf("%i %i %i", a, b , c);
			} else {
				printf("%i %i %i", a, c , b);	
			};
		} else if (b < a && b < c){
			smaller = b;
			if(a<c){
				printf("%i %i %i", b, a , c);
			} else {
				printf("%i %i %i", b, c , a);
			};
		} else {
			smaller = c;
			if (a<b){
				printf("%i %i %i", c, a , b);
			} else {
				printf("%i %i %i", c, b , a);
			} ;
		}
	} else if (answer == 4){
		int a;
		int b;
		int c;
		
		int delta;
		
		printf("Insira o primeiro valor: ");
		scanf("%i", &a);
		printf("Insira o segundo valor: ");
		scanf("%i", &b);
		printf("Insira o terceiro valor: ");
		scanf("%i", &c);
		
		delta = (b*b)-(4*a*c);
		
		printf("%i %i", delta/(2*a), -(delta/(2*a)));
	};
	
};
