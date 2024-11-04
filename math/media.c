#include<stdio.h>
#include<math.h>
#include<locale.h>

float calcularMedia(char tipo, float nota1, float nota2, float nota3) {

    float media;

    if (tipo == 'A' || tipo == 'a') {
        media = (nota1 + nota2 + nota3) / 3;
    } else if (tipo == 'P' || tipo == 'p') {
        media = (nota1 * 5 + nota2 * 3 + nota3 * 2) / 10;
    } else {
        media = -1; 
    }

    return media;
}

main(){

	setlocale(LC_ALL,"Portuguese");

 	float nota1, nota2, nota3, media;
    char tipo;

    printf("Qual a primeira nota: ");
    scanf("%f", &nota1);

    printf("Qual a segunda nota: ");
    scanf("%f", &nota2);
    
    printf("Qual a terceira nota: ");
    scanf("%f", &nota3);

    printf("Qual o tipo de média ? A = aritmetica, P = ponderada ");
    scanf("%c", &tipo);

    media = calcularMedia(tipo, nota1, nota2, nota3);

    if (media != -1) {
        printf("A media é: %.2f \n", media);
    } else {
        printf("Tipo de media errado. \n");
    }

}
