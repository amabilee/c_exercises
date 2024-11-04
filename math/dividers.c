#include<stdio.h>
#include<math.h>
#include<locale.h>

int somaDivisiveisPorA(int a, int b, int c) {

    int soma = 0;
    int i;

    for (i = b; i <= c; i++) {
        if (i % a == 0) {
            soma += i;
        }
    }

    return soma;
}

main(){

	setlocale(LC_ALL,"Portuguese");

	int a, b, c, result;

    printf("Digite o valor de 'A' (deve ser maior que 1): ");
    scanf("%i", &a);
    if (a <= 1) {
        printf("O valor de a deve ser maior que 1.\n");
    }

    printf("Digite o valor de 'B': ");
    scanf("%i", &b);

    printf("Digite o valor de 'C': ");
    scanf("%i", &c);

    result = somaDivisiveisPorA(a, b, c);

    printf("A soma dos numeros inteiros entre %i e %i que são divisiveis por %i é: %i \n", b, c, a, result);

}
