#include<stdio.h>
#include<math.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int matriz[10][20]
    int sumRows[10];
    int i, j;

    for(i = 0; i < 10; i++) {
        sumRows[i] = 0;
        for(j = 0; j < 20; j++) {
            printf("Qual o elemento da matriz[%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
            sumRows[i] += matriz[i][j];
        }
    }

    for(i = 0; i < 10; i++) {
        for(j = 0; j < 20; j++) {
            matriz[i][j] *= sumRows[i];
        }
    }

    printf("Matriz final: \n");
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 20; j++) {
            printf("%i ", matriz[i][j]);
        }

        printf("\n");
    }

}
