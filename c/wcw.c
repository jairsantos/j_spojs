#include <stdio.h>
#include <stdlib.h>

// Esse é uma estrutura que será usada para guardar instâncias e
// a contagem das intâncias;
struct instance {
	// Armazena o número de operações realizadas
	int sort_count;

	// Guarda o número de elementos.
	int elements_count;

	// Ponteiro que aponta para os elementos
	int *elements;
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

int char_to_int(char chr)
{
	return ((int) chr) - 48;
}

void read_by_space(int *elements)
{
	// Esse purge limpa o stdin
	__fpurge(stdin);

	// Guarda o carcter que foi digitado
	int chr;

	// Valor do elemento lido
	int element = 0;

	// Guarda o índice onde está salvando os dados
	int index = 0;
	do
	{
		chr = fgetc(stdin);

		if (chr == 32 || chr == '\n')
		{
			elements[index++] = element;
			element = 0;
		}
		else
		{
			element = element * 10 + char_to_int(chr);
		}

	} while (chr != '\n');
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
	root.instances = (struct instance*) malloc (root.instances_count * sizeof(struct s_root) + 1);

	// Faz a interação para a leitura da quantidade de instâncias pedidas.
	for(i = 0; i < root.instances_count; i++)
	{
		// Requisita a quantidade de elementos do vetor que será
		// lido.
		scanf("%d", &root.instances[i].elements_count);

		// Aloca a quantidade de memória necessária para fazer a leitura
		// dos elementos dados pelo usuário.
		root.instances[i].elements = (int*) malloc (root.instances[i].elements_count * sizeof(int) + 1);

		// Faz leitura da sequência dada pelo usuário.
		read_by_space(root.instances[i].elements);

		root.instances[i].elements;
	}

	// Ordena os vetores e contabiliza quantas movimentações foram necessárias.
	for(i = 0; i < root.instances_count; i++)
	{
		root.instances[i].sort_count = linear_sort(root.instances[i].elements, root.instances[i].elements_count);
		for(j = 0; j < root.instances[i].elements_count; j++)
		{
			printf(" %d ", root.instances[i].elements[j]);
		}
	}

	// Exibe na tela o número de vezes de cada operação.
	for(i = 0; i < root.instances_count; i++)
	{
		printf("%d\n", root.instances[i].sort_count);
	}
}
