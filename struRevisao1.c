/*
	FAETERJ-Rio
	FPR - Noite		Professor Leonardo Vianna
	Data: 22/11/2021
	
	STRUCTS
	
	Exercício:
	
	Considere a existência de um vetor no qual cada posição pode armazenar o nome do 
	aluno, as notas de AV1 e AV2, sua média e a situação (aprovado, reprovado ou em AVF). 
	Pede-se:

	i.   A declaração do vetor, assim como de todos os tipos de dados necessários, 
	     caso existam;
	ii.  Uma função que leia os dados de todos os alunos da turma;
	iii. Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como 
	     a sua situação;
	iv.  Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), 
	     exiba todos os alunos que estão nesta situação.
*/

//Importação de bibliotecas
#include <stdio.h>
#include <string.h>

//Definição de constantes
#define TAM 5

//Definição de tipos
typedef struct {
	char nome [50];
	float av1, av2, media;
	char situacao[15];
} Taluno;

//Protótipo das funções
void leituraDados (Taluno vetor[], int quant);
void mediaSituacao (Taluno vetor[], int quant);
void exibirAlunosSituacao (Taluno vetor[], int quant, int situacao);

//Main
void main ()
{
	//Declaração de variáveis
	Taluno turma[TAM];
	
	//preenchendo o vetor
	leituraDados (turma, TAM);
	
	//Calculando (e armazenando) a média e a situação de todos o alunos
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

//Implementação das demais funções
void leituraDados (Taluno vetor[], int quant)
{
	//Declaração de variáveis
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
	//Declaração de variáveis
	int i;
	
	//Percorrendo o vetor
	for (i=0; i<quant; i++)
	{
		//Calculando a média do i-ésima aluno
		vetor[i].media = (vetor[i].av1 + vetor[i].av2)/2;
		
		//Calculando a situação do i-ésimo aluno
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
	//Declaração de variáveis
	int i;
	char busca [15];
	
	//mapeando o paramêtro 'situacion' para a variável 'busca'
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
	
	//varrendo o vetor em busca da situação desejada
	for (i=0;i<quant;i++)
	{
		if (strcmp(vetor[i].situacao,busca) == 0)
		{
			printf ("\nNome: %s \nAv1: %.1f - Av2: %.1f - Media: %.1f\n\n", vetor[i].nome, vetor[i].av1, vetor[i].av2, vetor[i].media);
		}
	}
}
