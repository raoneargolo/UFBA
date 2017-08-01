#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
 
int pontuacao_desconto(int numero_secreto, int numero_chutado)
{
	int desconto;
	 
	return desconto = (abs(numero_chutado - numero_secreto))/2;
}
 
int main()
{
 
	int numero_secreto = rand() % 100;
	 
	int numero_chutado, qt_tentativas=4, pontuacao_atual=1000;
	 
	printf("\tOi! Vamos iniciar o jogo?\n\n");
	printf("Digite o seu chute: ");
	 
	while(qt_tentativas>=1)
	{
	 
		scanf("%d", &numero_chutado);
		 
		if(numero_chutado==numero_secreto)
		{
			printf("\n\nParabens, voce acertou! Sua pontuacao final foi %d\n",pontuacao_atual);
			 
			return 0;
		}
		else
		{
			if(qt_tentativas > 1)
			{
				printf("\n\nQue pena! :/\n");
				 
				if(numero_chutado > numero_secreto)
				{
					printf("\n\n(Spoiler alert: O numero que voce chutou foi maior que o numero secreto");
				}
				else
				{
					printf("\n\n(Spoiler alert: O numero que voce chutou foi menor que o numero secreto)");
				}
				 
				pontuacao_atual = pontuacao_atual - pontuacao_desconto(numero_secreto, numero_chutado);
				 
				printf("\nVoce possui apenas mais %d tentativa(s). Pense bem antes de dar o proximo chute!\n", qt_tentativas-1);
				 
				printf("\nEntao vamos de novo. Digite seu chute: ");
			}
		}
		qt_tentativas--;
	}
	 
	printf("\n\nAcabaram as tentativas e voce nao advinhou o numero secreto... :/");
	 
	return 0;
}