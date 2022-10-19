/*
	FAETERJ-Rio
	FPR - Professor Leonardo Vianna
	
	Lista de Exerc�cios VI (Structs)
	
	Quest�o 05: 
	O hist�rico de um aluno � representado por um vetor de structs onde cada posi��o armazena o c�digo da 
	disciplina cursada, semestre e ano que a cumpriu e a m�dia final na disciplina. Implementar uma fun��o que 
	exiba o hist�rico do aluno com o seguinte formato:

							NomeDisciplina1 (c�digo1)	M�diaDisciplina1
							NomeDisciplina2 (c�digo2)	M�diaDisciplina2
												.
												.
												.
							NomeDisciplinaN (c�digoN)	M�diaDisciplinaN
							Coeficiente de rendimento: CR


	Observa��es:
		1. Para obter os dados da disciplina, um outro vetor de structs deve ser consultado. Este, por sua vez, 
		   armazena para cada disciplina do curso as seguintes informa��es: c�digo, nome e n�mero de cr�ditos;
		2. O coeficiente de rendimento consiste em uma m�dia ponderada de todos os graus atribu�dos �s 
		   disciplinas cursadas, onde os pesos s�o representados pelo n�mero de cr�ditos da disciplina;
		3. Todos os dados em negrito apresentados no formato do hist�rico devem ser obtidos a partir dos vetores.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//declara��o de constantes
#define QUANT 30			//n�mero de disciplinas no hist�rico do aluno
#define NUMDISC 50			//n�mero de disciplinas do curso

//declara��o de tipos
typedef struct {			//representando uma disciplina do curso
	char codigo[5];
	char nome[30];
	int creditos;		
} TDisciplina;

typedef struct {			//representando um semestre/ano
	int semestre,
	    ano;
} TSemestre;

typedef struct {			//representando uma disciplina cursada pelo aluno
	char codDisc[5];
	TSemestre semestre;
	float media;
} TCursou;

//Prot�tipo das fun��es
void exibirHistorico (TCursou H[], int quantH, TDisciplina D[], int quantD);
int buscarDisciplina (TDisciplina D[], int quantD, char codigo[5]);

//Main
void main ()
{
	//Declara��o de vari�veis
	TCursou His[QUANT];
	TDisciplina Dis[NUMDISC];
	
}

//Implementar uma fun��o que exiba o hist�rico do aluno com o formato especificado no cabe�alho deste arquivo
void exibirHistorico (TCursou H[], int quantH, TDisciplina D[], int quantD)
{
	int i, disciplina;
	float denominador = 0, numerador = 0, CR;
	
	//percorrendo todas as disciplinas cursadas pelo aluno
	for (i=0;i<quantH;i++)
	{
		disciplina = buscarDisciplina (D, quantD, H[i].codDisc);
		printf ("%s (%s)     %.1f\n", D[disciplina].nome, H[i].codDisc, H[i].media);
		
		//acumulando somat�rios para o c�lculo do coeficiente de rendimento
		denominador += H[i].media*D[disciplina].creditos;
		numerador += D[disciplina].creditos;
	} 
	
	//Calculando o CR do aluno
	CR = denominador/numerador;
	
	//exibindo o CR ao final do hist�rico
	printf ("\nCoeficiente de rendimento: %.1f", CR);
}

//Dado um c�digo de disciplina, determina o seu nome ap�s percorrer o vetor de disciplinas
int buscarDisciplina (TDisciplina D[], int quantD, char codigo[5])
{
	int i;
	
	//percorrendo o vetor de disciplinas
	for (i=0;i<quantD;i++)
	{
		if (strcmp (D[i].codigo, codigo) == 0)
		{
			return i;
		}
	}
	
	//caso n�o seja encontrado o c�digo
	return -1;
}
