/*
	FAETERJ-Rio
	FPR - Noite		Professor Leonardo Vianna
	Data: 22/11/2021
	
	STRUCTS
	
	Exerc�cio:
	
	Considere a exist�ncia de um vetor no qual cada posi��o pode armazenar o nome do 
	aluno, as notas de AV1 e AV2, sua m�dia e a situa��o (aprovado, reprovado ou em AVF). 
	Pede-se:

	i.   A declara��o do vetor, assim como de todos os tipos de dados necess�rios, 
	     caso existam;
	ii.  Uma fun��o que leia os dados de todos os alunos da turma;
	iii. Uma fun��o que calcule a m�dia de cada aluno (e a armazene no vetor), assim como 
	     a sua situa��o;
	iv.  Uma fun��o que, dado um n�mero inteiro (1-aprovado;2-reprovado;3-em AVF), 
	     exiba todos os alunos que est�o nesta situa��o.
*/

//Importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//Defini��o de constantes
#define TAM 5

//Defini��o de tipos
typedef struct {
	char nome [50];
	float av1, av2, media;
	char situacao[15];
} Taluno;

//Prot�tipo das fun��es
void leituraDados (Taluno vetor[], int quant);
void mediaSituacao (Taluno vetor[], int quant);
void exibirAlunosSituacao (Taluno vetor[], int quant, int situacao);

//Main
void main ()
{
	//Declara��o de vari�veis
	Taluno turma[TAM];
	
	//preenchendo o vetor
	leituraDados (turma, TAM);
	
	//Calculando (e armazenando) a m�dia e a situa��o de todos o alunos
	mediaSituacao (turma, TAM);	
	
	//exibindo os alunos aprovados
	printf ("\nAlunos aprovados: \n");
	exibirAlunosSituacao (turma, TAM, 1);
	
	//exibindo os alunos reprovados
	printf ("\nAlunos reprovados: \n\n");
	exibirAlunosSituacao (turma, TAM, 2);
	
	//exibindo os alunos em Avf
	printf ("\nAlunos em AVF: \n\n");
	exibirAlunosSituacao (turma, TAM, 3);
}

//Implementa��o das demais fun��es
void leituraDados (Taluno vetor[], int quant)
{
	//Declara��o de vari�veis
	int i;
	
	//Percorrendo o vetor
	for (i=0; i<quant; i++)
	{
		fflush (stdin);
		printf ("Entre com o nome do Aluno: ");
		gets (vetor[i].nome);
		
		printf ("Entre com a AV1 do Aluno: ");
		scanf ("%f", &vetor[i].av1);
		
		printf ("Entre com a AV2 do Aluno: ");
		scanf ("%f", &vetor[i].av2);		
	}
}

void mediaSituacao (Taluno vetor[], int quant)
{
	//Declara��o de vari�veis
	int i;
	
	//Percorrendo o vetor
	for (i=0; i<quant; i++)
	{
		//Calculando a m�dia do i-�sima aluno
		vetor[i].media = (vetor[i].av1 + vetor[i].av2)/2;
		
		//Calculando a situa��o do i-�simo aluno
		if (vetor[i].media >= 6)
		{
			strcpy (vetor[i].situacao, "APROVADO");
		}
		else
		{
			if (vetor[i].media < 4)
			{
				strcpy (vetor[i].situacao, "REPROVADO");
			}
			else
			{
				strcpy (vetor[i].situacao, "AVF");
			}
		}		
	}
}

void exibirAlunosSituacao (Taluno vetor[], int quant, int situacion)
{
	//Declara��o de vari�veis
	int i;
	char busca [15];
	
	//mapeando o param�tro 'situacion' para a vari�vel 'busca'
	//Tenho que transformar o 'situacion' em 'aprovado, reprovado ou avf'
	switch (situacion)
	{
		case 1: strcpy (busca, "APROVADO");
				break;
		
		case 2: strcpy (busca, "REPROVADO");
				break;
				
		case 3: strcpy (busca, "AVF");
				break;
	}
	
	//varrendo o vetor em busca da situa��o desejada
	for (i=0;i<quant;i++)
	{
		if (strcmp(vetor[i].situacao,busca) == 0)
		{
			printf ("\nNome: %s \nAv1: %.1f - Av2: %.1f - Media: %.1f\n\n", vetor[i].nome, vetor[i].av1, vetor[i].av2, vetor[i].media);
		}
	}
}
