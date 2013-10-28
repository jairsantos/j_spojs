#include <stdio.h>
#include <stdarg.h>

// Struct do C. Usado para facilitar a estruturação dos dados.
// No presente caso, usei-o para criar um nó que servirá para
// armazenar a cadeia de valores que será digitada pelo usuário.
struct node
{
	int value, *next;
};


void main()
{

	// Variáveis para fim de controle de loops no código.
	int i, j;

	// Declara que a variável 'root' será o "nó raiz" da
	// estrutura de dados.
	struct node	root;

	// Essa variável armazenará a quantidade de instâncias que
	// será disponibilizada pelo usuário.
	unsigned int instances_quantity = 0;

	// Essa variável armazenará a quantidade de elementos na
	// estrutura de dados.
	unsigned int sequence_quantity  = 0;

	// Requisita a quantidade de instâncias para o usuário.
	scanf("%d", &instances_quantity);

	// Faz a interação para a leitura da quantidade de instâncias pedidas.
	for(i = 0; i < instances_quantity; i++)
	{
		// Requisita a quantidade de elementos do vetor que será
		// lido.
		scanf("%d", &sequence_quantity);

	}
}
