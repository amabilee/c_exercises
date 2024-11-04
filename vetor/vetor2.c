#include<stdio.h>
#include<math.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int vetores[8], vPositivos[8], vNegativos[8];
    int i, posIndex = 0, negIndex = 0;

    for(i = 0; i < 8; i++) {
        printf("Digite um número: ");
        scanf("%i", &vetores[i]);

        if(vetores[i] >= 0) {
            vPositivos[posIndex++] = vetores[i];
        } else {
            vNegativos[negIndex++] = vetores[i];
        }
    }

    printf("Vetor com valores positivos: \n");
    for(i = 0; i < posIndex; i++) {
        printf("%i ", positivos[i]);
    }

    printf("\nVetor com valores negativos: \n");
    for(i = 0; i < negIndex; i++) {
        printf("%i ", vNegativos[i]);
    }

    return 0;

}
