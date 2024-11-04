#include<stdio.h>
#include<math.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	char lojas[8][50]
    char produtos[4][50];
    float precos[8][4];
    int i, j;

    for(i = 0; i < 8; i++) {
        printf("Digite o nome da loja %i: ", i + 1);
        scanf("%s", lojas[i]);
    }

    for(i = 0; i < 4; i++) {
        printf("Digite o nome do produto %i: ", i + 1);
        scanf("%s", produtos[i]);
    }

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 4; j++) {
            printf("Qual o preco do produto %s na loja %s: ", produtos[j], lojas[i]);
            scanf("%f", &precos[i][j]);
        }
    }

}
