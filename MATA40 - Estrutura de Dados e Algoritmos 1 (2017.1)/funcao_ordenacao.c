/*Fazer uma função que receba 3 ponteiros para FLOATS como parâmetros: A, B e C.
Ordene de tal forma que, ao final da função, A contenha o menor número e C o maior e B o intermediário.
A função deve usar os ponteiros para acessar os valores dos números por referência
copiar os valores em cada endereço para o endereço ordenado.
Fazer um programa que receba 3 números do usuário, inclua e chame a função
mostre os números ordenados com duas casas decimais apenas.*/

#include <stdio.h>
#include <stdlib.h>

void ordena (float *num_1, float *num_2, float *num_3) //função para ordenar os três valores inseridos (passagem por referência)
{
	float aux;
	
	if (*num_1>*num_3)
	{   
		aux=*num_1;
		*num_1=*num_3;    
		*num_3=aux;
	}

	if (*num_1 > *num_2)
	{
		aux=*num_1;
		*num_1=*num_2;
		*num_2=aux;
	}

	if (*num_2 > *num_3)
	{
		aux=*num_2;
		*num_2=*num_3;
		*num_3=aux;
	}
}

int main(){

	float numero_1, numero_2, numero_3;

	printf("Insira o primeiro numero: ");
	scanf("%f", &numero_1);

	printf("Insira o segundo numero: ");
	scanf("%f", &numero_2);

	printf("Insira o terceiro numero: ");
	scanf("%f", &numero_3);
	
	ordena(&numero_1,&numero_2,&numero_3);
	
	printf("\n\nMenor numero: %.2f", numero_1);
	printf("\nNumero intermediario: %.2f", numero_2);
	printf("\nMaior numero: %.2f\n", numero_3);

}