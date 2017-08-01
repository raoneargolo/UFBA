/*Fazer um programa que tenha e use uma função que receba os valores FLOAT X, Y e Z a partir do usuário
Retorne 0 caso não seja possível criar um triangulo com estas medidas dos lados de um triangulo:
-1 caso as medidas formem um triangulo equilátero
-2 caso isósceles
-3 caso escaleno
O programa deve exibir a resposta específica da função e exibir um texto relativo, como "1 = equilátero".*/

#include <stdio.h>
#include <math.h>

int verifica_triangulo(float valor_1, float valor_2, float valor_3) //função para verificar se os valores inseridos formam um triângulo, e se formam, qual triângulo
{
	float modulo_1, modulo_2, modulo_3, triangulo_existe;

	triangulo_existe = 0; //se é possível formar um triângulo, a variável possuira valor 1

	modulo_1= fabs(valor_2-valor_1);
	modulo_2= fabs(valor_1-valor_3);
	modulo_3= fabs(valor_1-valor_2);

	//as três variaveis acima recebe o módulo entre a diferença de dois lados do triângulo

	if (modulo_1 < valor_1 && valor_1 < (valor_2+valor_3)) //primeira verificação de formação de um triângulo
	{
		triangulo_existe=1;
	}

	if (modulo_2 < valor_2 && valor_2 < (valor_1 + valor_3)) //segunda verificação de formação de um triângulo
	{
		triangulo_existe=1;
	}

	if (modulo_3 < valor_3 && valor_3 < (valor_1 + valor_2)) //terceira verificação de formação de um triângulo
	{
		triangulo_existe=1;
	}

	if(triangulo_existe==1) //se o triângulo existir
	{
		if(valor_1==valor_2 && valor_1==valor_3 && valor_2==valor_3) //se o triângulo for equilátero
		{
			return 1;
		}
		else if(valor_1==valor_2 || valor_1==valor_3 || valor_2==valor_3) //se o triângulo for isósceles
		{
			return 2;
		}
		else //se o triangulo não for nem equilátero nem isósceles, será escaleno
		{
			return 3;
		}
	}
	else
	{
		return 0;
	}
}

int main(){

	float valor_1, valor_2, valor_3;
	int resultado;

	printf("Entre com o primeiro valor: ");
	scanf("%f", &valor_1);

	printf("\nEntre com o segundo valor: ");
	scanf("%f", &valor_2);

	printf("\nEntre com o terceiro valor: ");
	scanf("%f", &valor_3);

	resultado=verifica_triangulo(valor_1,valor_2,valor_3);

	if (resultado==0)
	{
		printf("\n\n\nNão é possível formar um triângulo com os valores inseridos!");
	}
	
	else if	(resultado==1)
	{
		printf("\n\n\nAs medidas que você inseriu formam um triângulo equilátero!");
	}

	else if (resultado==2)
	{
		printf("\n\n\nAs medidas que você inseriu formam um triângulo isósceles!");
	}

	else if (resultado==3)
	{
		printf("\n\n\nAs medidas que você inseriu formam um triângulo escaleno!");
	}

	printf("\n\n\n\n\t\t\tFim do programa\n\n\n");

	return 0;
}