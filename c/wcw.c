#include <stdio.h>
#include <stdlib.h>

// Esse é uma estrutura que será usada para guardar instâncias e
// a contagem das intâncias;
struct instance {
	// Guarda o número de elementos.
	int elements_count;

	// Ponteiro que aponta para os elementos
	int *elements;

	// Essa variável guarda o número de movimentos necessários
	// para ordenar o vetor.
	int sort_count = 0;
};

struct s_root {
	// Guarda o número de instâncias
	int instances_count;

	// Ponteiro para as intâncias
	struct instance *instances;
};

// Função que realiza a troca entre os valores
void swap(int *a, int *b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

// Essa é a função responsável por ordenar o vetor.
// Após ordenar o vetor, ele retorna o número de vezes
// em que precisou realizar uma traca
int linear_sort(int ary[], int size)
{
	int i, j, count = 0;

	for(i = 0; i < size; i++)
	{
		for(j = i; j < size; j++)
		{
			if (ary[j] < ary[i])
			{
				swap(&ary[i], &ary[j]);
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
	struct s_root root;

	// Variáveis para fim de controle de loops no código.
	int i, j;


	// Requisita a quantidade de instâncias para o usuário.
	scanf("%d", &root.instances_count);

	// Aloca a quantidade de memória necessária para fazer a leitura
	// das instâncias dadas pelo usuário.
	root.instances = (struct instance*) malloc (root.instances_count + 1);

	// Faz a interação para a leitura da quantidade de instâncias pedidas.
	for(i = 0; i < root.instances_count; i++)
	{
		// Requisita a quantidade de elementos do vetor que será
		// lido.
		scanf("%d", &root.instances[i].elements_count);

		// Aloca a quantidade de memória necessária para fazer a leitura
		// dos elementos dados pelo usuário.
		root.instances[i].elements = (int*) malloc (root.instances[i].elements_count + 1);

		// Faz a iteração para a leitura da sequência dada pelo usuário.
		//-------------------------------
		for(j = 0; j < root.instances[i].elements_count; j++)
		{
			// Requisita o elemento para o usuário, e armazena no espaço
			// indicado pelo ponteiro.
			scanf("%d", &root.instances[i].elements[j]);
		}
		//--------------------------------
	}

	// Ordena os vetores lidos e conta.
	for(i = 0; i < root.instances_count; i++)
	{
		root.instances[i].sort_count = linear_sort(root.instances[i].elements, root.instances[i].elements_count);
	}

	// Imprime aqui o número de operações de cada sort [ordenação].
	for(i = 0; i < root.instances_count; i++)
	{
		printf("%d", root.instances[i].sort_count);
	}
}
