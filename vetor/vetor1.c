#include<stdio.h>
#include<math.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");

    int v1[10], v2[10], vetorJump[20];
    int i, j = 0;

    for(i = 0; i < 10; i++) {
        printf("Qual o elemento %i do vetor 1: ", i + 1);
        scanf("%i", &v1[i]);
    }

    for(i = 0; i < 10; i++) {
        printf("Qual o elemento %i do vetor 2: ", i + 1);
        scanf("%i", &v2[i]);
    }

    for(i = 0; i < 10; i++) {
        vetorJump[j++] = v1[i];
        vetorJump[j++] = v2[i];
    }

    printf("Vetor intercalado é : \n");
    for(i = 0; i < 20; i++) {
        printf("%i ", vetorJump[i]);
    }

}
