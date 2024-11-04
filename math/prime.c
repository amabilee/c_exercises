#include <stdio.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int nums[15];
	int primos[15];
	
	for (int i = 0 ; i <= 15; i++){
		printf("Insira um numero: ");
		scanf("%i", &nums[i]);
		for (int j = 2; j <= 15 / 2; j++) {
    		if (nums[i] % j == 0) {
       			primos[i] == nums[i];
       			break;
    		}
 		}
	}
	
	printf("Os numeros primos sao: %i", primos);
}
