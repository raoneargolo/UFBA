#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
 
//função que calcula o desconto na pontuação total inicial (1000 pontos) a cada tentativa errada do usuário
int pontuacao_desconto(int numero_secreto, int numero_chutado)
{
	int desconto;
	 
	return desconto = (abs(numero_chutado - numero_secreto))/2; //O desconto de pontos será a metade da diferença entre o chute do usuário e o número secreto.
}
 
int main()
{
 
	int numero_secreto = rand() % 100; //gera aleotoriamente um número para ser adivinhado
	 
	int numero_chutado; //armazena o número informado pelo usuário
	int qt_tentativas=4; //quantidade máxima de tentativas que o usuário pode fazer
	int pontuacao_atual=1000; //pontuação inicial do usuário
	 
	printf("\tOi! Vamos iniciar o jogo?\n\n");
	printf("Digite o seu chute: ");
	 
	while(qt_tentativas>=1) //a cada tentativa errada o número de tentativas restante cai
	{
	 
		scanf("%d", &numero_chutado); //lendo o número que o usuário acha ser o numero
		 
		if(numero_chutado==numero_secreto) //se o número informado pelo usuário for igual ao número secreto gerado
		{
			printf("\n\nParabens, voce acertou! Sua pontuacao final foi %d\n",pontuacao_atual);
			 
			return 0;
		}
		else //se o número informado pelo usuário pelo usuário for diferente ao número secreto gerado
		{
			if(qt_tentativas > 1) //se o usuário tiver mais de uma tentativa restante
			{
				printf("\n\nQue pena! :/\n");
				 
				if(numero_chutado > numero_secreto) //se o usuário digitou um número maior que o número secreto
				{
					printf("\n\n(Spoiler alert: O numero que voce chutou foi maior que o numero secreto");
				}
				else //se o usuário digitou um número menor que o número secreto
				{
					printf("\n\n(Spoiler alert: O numero que voce chutou foi menor que o numero secreto)");
				}
				 
				pontuacao_atual = pontuacao_atual - pontuacao_desconto(numero_secreto, numero_chutado); //calcula o desconto e o retira da pontuação atual do usuário
				 
				printf("\nVoce possui apenas mais %d tentativa(s). Pense bem antes de dar o proximo chute!\n", qt_tentativas-1);
				 
				printf("\nEntao vamos de novo. Digite seu chute: ");
			}
		}
		qt_tentativas--; //a cada erro, diminui o número de tentativas restantes
	}
	 
	printf("\n\nAcabaram as tentativas e voce nao advinhou o numero secreto... :/");
	 
	return 0;
}