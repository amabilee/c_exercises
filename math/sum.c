#include<stdio.h>
#include<math.h>
#include<locale.h>

int somaEntreNumeros(int a, int b) {

    int soma = 0;
    int i;

    if (a < b) {
        for (i = a + 1; i < b; i++) {
            soma += i;
        }
    } else {
        for (i = b + 1; i < a; i++) {
            soma += i;
        }
    }

    return soma;
}

main(){
	setlocale(LC_ALL,"Portuguese");

	int n1, n2, result;

    printf("Digite o Primeiro numero positivo: ");
    scanf("%i", &n1);
    printf("Digite o Segundo numero positivo: ");
    scanf("%i", &n2);

    if (n1 < 0 || n2 < 0) {
        printf("Os numeros escolhidos devem ser positivos. \n");
    }

    result = somaEntreNumeros(n1, n2);

    printf("A soma dos numeros inteiros entre %i e %i é: %i \n", n1, n2, result);

}
