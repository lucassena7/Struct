/* Considere um vetor que, em cada posi��o, armazene os seguintes dados de um curso de gradua��o: nome (por exemplo, Medicina,
Engenharia, Direito, ...), �rea (Humanas, Exatas, ...), cidade na qual funciona e a quantidade de alunos matriculados no curso.

Desenvolver uma fun��o que, dado um vetor nesses moldes, um c�digo inteiro cod e uma string str, retorne a quantidade de alunos
associados aos par�metros.

Se o c�digo for igual a 1, str representar� um curso e, portanto, a fun��o dever� retornar a quantidade de alunos matriculados no curso
str, destacando que o mesmo curso pode encontrar-se em mais de uma posi��o do vetorc(em cidades diferentes, por exemplo). Por outro lado,
se o c�digo for 2, str representar� uma �rea e, portanto, dever� ser retornado o total de alunos matriculados em cursos daquela �rea. */

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de constantes
#define TAM 5

//defini��o de tipos
typedef struct {
	char nomeCurso[30];
	char area[30];
	char cidade[30];
	int quantAlunos;
} TDados;

//prot�tipos das fun��es
int quantAlunos (TDados vetor[], int quant, int codigo, char string[]);
void leituraDados (TDados vetor[], int quant);

//main
void main ()
{
	//declara��o de vari�veis
	TDados dados[TAM];
	int cod;
	char str[30];
	
	//preenchendo o vetor
	leituraDados (dados, TAM);
	
	//Lendo o c�digo fornecido pelo usu�rio
	printf ("Entre com o codigo (1 ou 2): ");
	scanf ("%d", &cod);
	
	//Lendo a string fornecida pelo usu�rio
	fflush(stdin);
	printf ("Se o codigo for (1) - digite o nome do Curso, se o codigo for (2) - digite a area do curso: ");
	gets (str);

	//Chamando a fun��o
	quantAlunos (dados, TAM, cod, str);
}

//implementa��o das demais fun��es
int quantAlunos (TDados vetor[], int quant, int codigo, char string[])
{
	//declara��o de vari�veis
	int i;
	char busca[30];
	
	switch (codigo)
	{
		case 1: strcpy (busca, string);
		//varrendo o vetor em busca do curso desejado
		for (i=0;i<quant;i++)
		{
			if (strcmp(vetor[i].nomeCurso,busca) == 0)
			{
				printf ("\nAtualmente ha %d alunos matriculados no curso de %s\n\n", vetor[i].quantAlunos, busca);
			}
		}
				break;
		
		case 2: strcpy (busca, string);
		//varrendo o vetor em busca da area desejada
		for (i=0;i<quant;i++)
		{
			if (strcmp(vetor[i].area,busca) == 0)
			{
				printf ("\nAtualmente ha %d alunos matriculados na regiao do %s\n\n", vetor[i].quantAlunos, busca);
			}
		}
				break;
	}
}

void leituraDados (TDados vetor[], int quant)
{
	//Declara��o de vari�veis
	int i;
	
	//Percorrendo o vetor
	for (i=0; i<quant; i++)
	{
		fflush (stdin);
		printf ("Entre com o Nome do curso: ");
		gets (vetor[i].nomeCurso);
		
		fflush (stdin);
		printf ("Entre com a Area do curso: ");
		gets (vetor[i].area);
		
		fflush (stdin);
		printf ("Entre com a Cidade em que o curso se encontra: ");
		gets (vetor[i].cidade);
		
		printf ("Entre com a quantidade de alunos do curso: ");
		scanf ("%d", &vetor[i].quantAlunos);	
	}
}
