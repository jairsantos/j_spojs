#include <stdio.h>
#include <stdlib.h>

// Esse é uma estrutura que será usada para guardar os elementos e
// a contagem dos elementos;
struct instance {
	// Guarda o número total de elementos.
	int elements_count;

	// Guarda os elementos em si.
	int *elements;
};

// Função que realiza a troca entre os valores
void swap(int a, int b)
{
	int x = a;
	a = b;
	b = a;
}

// Essa é a função responsável por ordenar o vetor.
// Após ordenar o vetor, ele retorna o número de vezes
// em que precisou realizar uma traca
int linear_sort(int ary[], int size)
{
	int i, j, count = 0;

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if (ary[i] < ary[j])
			{
				swap(ary[i], ary[j]);
				count++;
			}
		}
	}
	return count;
}

void main()
{

	// Esses serão os ponteiros responsáveis por armazenar as
	// instâncias, e os elementos dessas instâncias.
	struct instance *instances;

	// Variáveis para fim de controle de loops no código.
	int i, j;

	// Essa variável armazenará a quantidade de instâncias que
	// será disponibilizada pelo usuário.
	int instances_quantity = 0;

	// Essa variável armazenará a quantidade de elementos na
	// estrutura de dados.
	int sequence_quantity  = 0;

	// Requisita a quantidade de instâncias para o usuário.
	scanf("%d", &instances_quantity);

	// Aloca a quantidade de memória necessária para fazer a leitura
	// das instâncias dadas pelo usuário.
	instances = (struct instance*) malloc (instances_quantity + 1);

	// Faz a interação para a leitura da quantidade de instâncias pedidas.
	for(i = 0; i < instances_quantity; i++)
	{
		// Requisita a quantidade de elementos do vetor que será
		// lido.
		scanf("%d", &sequence_quantity);

		// Aloca a quantidade de memória necessária para fazer a leitura
		// dos elementos dados pelo usuário.
		instances[i].elements = (int*) malloc (sequence_quantity + 1);

		// Faz a iteração para a leitura da sequência dada pelo usuário.
		//-------------------------------
		for(j = 0; j < sequence_quantity; j++)
		{
			// Requisita o elemento para o usuário, e armazena no espaço
			// indicado pelo ponteiro.
			scanf("%d", &instances[i].elements[j]);
		}
		//--------------------------------
	}

	for(i = 0; i < instances_quantity; i++)
	{
		linear_sort(instances[i].elements, instances[i].elements_count);
		/*
		for(j = 0; j < length(instances[i]); j++)
		{
			printf("%d", instances[i][j]);
		}
		*/
	}
}
