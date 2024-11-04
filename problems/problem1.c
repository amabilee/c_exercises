#include<stdio.h>
#include<math.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL,"Portuguese");
	
    float precoProdutos[10]; 
    int quantidadeProdutos[10]; 
    
    float valorTotalVenda; 
    float comissaoVenda; 
    float maiorVenda; 
    int posicaoVendaMaior;

    valorTotalVenda = 0;
    maiorVenda = 0;
    posicaoVendaMaior = 0;

    for( i = 0; i < 10; i++ ) {
        printf("Qual o preco do objeto %i: ", i + 1);
        scanf("%i", &precoProdutos[i]);

        printf("Qual a quantidade vendida do objeto %i: ", i + 1);
        scanf("%i", &quantidadeProdutos[i]);


        float valorObjetoEspecifco = precoProdutos[i] * quantidadeProdutos[i];
        valorTotal += valorObjetoEspecifco;
        if(quantidadeProdutos[i] > maiorVenda) {
            maiorVenda = quantidadeProdutos[i];
            posicaoVendaMaior = i;
        }
    }

    comissao = valorTotalVenda * 0.05;

    printf("\n Resumo das Vendas:");
    for( i = 0; i < 10; i++) {
        printf("Produto %i: Quantidade: %i, Preco: %.2f, Valor total: %.2f \n", 
               i + 1, quantidadeProdutos[i], precoProdutos[i], precoProdutos[i] * quantidadeProdutos[i]);
    }

    printf("\n Valor total das vendas: %.2f \n", valorTotalVenda);
    printf("Comissao: %.2f \n", comissao);

    printf("Produto mais vendido: %i (Quantidade: %.0f) \n", posicaoVendaMaior + 1, maiorVenda);

}

