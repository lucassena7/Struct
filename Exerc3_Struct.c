/*
	FAETERJ-Rio
	FPR - Professor Leonardo Vianna
	
	Lista de Exerc�cios VI (Structs)
	
	Quest�o 03: 
	Determinada institui��o de ensino armazena, sob a forma de vetores (de structs), as seguintes informa��es:
 		- Alunos: nome, matr�cula;
 		- Disciplinas do curso: nome, c�digo;
 		- Inscri��es realizadas: matr�cula do aluno, c�digo da disciplina, semestre da inscri��o (semestre/ano).
 		
 	Pede-se o desenvolvimento de fun��es que realizem as seguintes opera��es:
 		i.  Exibir, para cada aluno, o total de inscri��es j� realizadas;
 		ii.	Dado um semestre, informar para cada disciplina o n�mero de alunos inscritos.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de constantes
#define NUM_ALUNOS 5
#define NUM_DISCIPLINAS 4
#define NUM_INSCRICOES 10

//defini��o de tipos

typedef struct {			//representando um semestre de ingresso, contendo o semestre (1 ou 2) e o ano (exemplo: 1 2021)
	int semestre, ano;
} TSemestre;

typedef struct {			//representando um aluno
	char nome[30];
	int matricula;
} TAluno;

typedef struct {			//representando uma disciplina
	char nome[40];
	char codigo[5];
} TDisciplina;

typedef struct {			//representando uma inscri��o (de um aluno em determinada disciplina)
	int matricula;
	char codigo[5];
	TSemestre semestre;
} TInscricao;

//prot�tipos das fun��es

//-----fun��es solicitadas
void exibirInscricoesPorAluno (TAluno alunos[], int quantAlunos, TInscricao inscricoes[], int quantInscricoes);
void exibirInscritosPorDisciplinaSemestre (TDisciplina disciplinas[], int quantDisciplinas, TInscricao inscricoes[], int quantInscricoes, TSemestre semestre);

//-----fun��es auxiliares
void preencherAlunos (TAluno alunos[]);
void preencherDisciplinas (TDisciplina disciplinas[]);
void preencherInscricoes (TInscricao inscricoes[]);

//main
void main ()
{
	//declara��o de vari�veis
	TAluno vetAlunos[NUM_ALUNOS];
	TDisciplina vetDisciplinas[NUM_DISCIPLINAS];
	TInscricao vetInscricoes[NUM_INSCRICOES];
	
	TSemestre semestre;
	
	//inicializando os vetores com valores pr�-definidos
	preencherAlunos (vetAlunos);
	preencherDisciplinas (vetDisciplinas);
	preencherInscricoes (vetInscricoes);
	
	//Exibir, para cada aluno, o total de inscri��es j� realizadas
	exibirInscricoesPorAluno (vetAlunos, NUM_ALUNOS, vetInscricoes, NUM_INSCRICOES);
	
	//Dado um semestre, informar para cada disciplina o n�mero de alunos inscritos
	semestre.semestre = 1;		semestre.ano = 2022;
	exibirInscritosPorDisciplinaSemestre (vetDisciplinas, NUM_DISCIPLINAS, vetInscricoes, NUM_INSCRICOES, semestre);
}

//Exibir, para cada aluno, o total de inscri��es j� realizadas.
void exibirInscricoesPorAluno (TAluno alunos[], int quantAlunos, TInscricao inscricoes[], int quantInscricoes)
{
	//declara��o de vari�veis
	int i, j, cont;
	
	//cabe�alho
	printf ("\n\n\nNumero de inscricoes por aluno:\n\n");
	printf ("Aluno\t\tInscricoes\n");
	
	//percorrendo o vetor de alunos
	for (i=0;i<quantAlunos;i++)
	{
		//inicializando com 0 o total de inscri��es do aluno atual
		cont = 0;
		
		//percorrendo o vetor de inscri��es para saber quantas foram feitas em nome do aluno atual (da posi��o i)
		for (j=0;j<quantInscricoes;j++)
		{
			//verificando se a matr�cula do aluno foi encontrada no vetor de inscri��es
			if (alunos[i].matricula == inscricoes[j].matricula)
			{
				//atualizando o n�mero de inscri��es
				cont++;
			}
		}
		
		//exibindo o total de inscri��es do aluno atual
		printf ("%s\t\t%d\n", alunos[i].nome, cont);		
	}	
}

//Dado um semestre, informar para cada disciplina o n�mero de alunos inscritos.
void exibirInscritosPorDisciplinaSemestre (TDisciplina disciplinas[], int quantDisciplinas, TInscricao inscricoes[], int quantInscricoes, TSemestre semestre)
{
	//declara��o de vari�veis
	int i, j, cont;
	
	//cabe�alho
	printf ("\n\n\nNumero de inscricoes por disciplina no semestre %d/%d:\n\n", semestre.semestre, semestre.ano);
	printf ("Disciplina\t\t\t\t\tInscricoes\n");
	
	//percorrendo o vetor de disciplinas
	for (i=0;i<quantDisciplinas;i++)
	{
		//inicializando com 0 o total de inscri��es na disciplina atual
		cont = 0;
		
		//percorrendo o vetor de inscri��es para saber quantas foram feitas na disciplina atual (da posi��o i)
		for (j=0;j<quantInscricoes;j++)
		{
			//verificando se a inscri��o foi feita no semestre e na disciplina desejados
			if ((strcmp(disciplinas[i].codigo,inscricoes[j].codigo)==0) && 
			    (inscricoes[j].semestre.semestre == semestre.semestre) && (inscricoes[j].semestre.ano == semestre.ano))
			{
				//atualizando o n�mero de inscri��es
				cont++;
			}
		}
		
		//exibindo o total de inscri��es na disciplina
		printf ("%s\t\t\t%d\n", disciplinas[i].nome, cont);
	}	
}

void preencherAlunos (TAluno alunos[])
{
	//aluno 1
	strcpy (alunos[0].nome, "JOAO");
	alunos[0].matricula = 12345;
	
	//aluno 2
	strcpy (alunos[1].nome, "MARIA");
	alunos[1].matricula = 23456;
	
	//aluno 3
	strcpy (alunos[2].nome, "ANA");
	alunos[2].matricula = 34567;
	
	//aluno 4
	strcpy (alunos[3].nome, "PEDRO");
	alunos[3].matricula = 45678;
	
	//aluno 5
	strcpy (alunos[4].nome, "CLARA");
	alunos[4].matricula = 56789;
}

void preencherDisciplinas (TDisciplina disciplinas[])
{
	//disciplina 1
	strcpy (disciplinas[0].nome, "ORGANIZACAO DE COMPUTADORES");
	strcpy (disciplinas[0].codigo, "1ORG");

	//disciplina 2
	strcpy (disciplinas[1].nome, "FUNDAMENTOS DE ALGORITMOS DE COMPUTACAO");
	strcpy (disciplinas[1].codigo, "1FAC");

	//disciplina 3
	strcpy (disciplinas[2].nome, "FUNDAMENTOS DE PROGRAMACAO");
	strcpy (disciplinas[2].codigo, "2FPR");

	//disciplina 4
	strcpy (disciplinas[3].nome, "ESTRUTURAS DE DADOS");
	strcpy (disciplinas[3].codigo, "3ESD");
}

void preencherInscricoes (TInscricao inscricoes[])
{
	//inscri��o 1
	inscricoes[0].matricula = 12345;
	strcpy (inscricoes[0].codigo, "1FAC");
	inscricoes[0].semestre.semestre = 1;
	inscricoes[0].semestre.ano = 2021;
	
	//inscri��o 2
	inscricoes[1].matricula = 12345;
	strcpy (inscricoes[1].codigo, "1ORG");
	inscricoes[1].semestre.semestre = 1;
	inscricoes[1].semestre.ano = 2021;
	
	//inscri��o 3
	inscricoes[2].matricula = 12345;
	strcpy (inscricoes[2].codigo, "2FPR");
	inscricoes[2].semestre.semestre = 2;
	inscricoes[2].semestre.ano = 2021;
	
	//inscri��o 4
	inscricoes[3].matricula = 12345;
	strcpy (inscricoes[3].codigo, "3ESD");
	inscricoes[3].semestre.semestre = 1;
	inscricoes[3].semestre.ano = 2022;
	
	//inscri��o 5
	inscricoes[4].matricula = 23456;
	strcpy (inscricoes[4].codigo, "1FAC");
	inscricoes[4].semestre.semestre = 2;
	inscricoes[4].semestre.ano = 2021;
	
	//inscri��o 6
	inscricoes[5].matricula = 23456;
	strcpy (inscricoes[5].codigo, "1ORG");
	inscricoes[5].semestre.semestre = 2;
	inscricoes[5].semestre.ano = 2021;
	
	//inscri��o 7
	inscricoes[6].matricula = 23456;
	strcpy (inscricoes[6].codigo, "2FPR");
	inscricoes[6].semestre.semestre = 1;
	inscricoes[6].semestre.ano = 2022;
	
	//inscri��o 8
	inscricoes[7].matricula = 34567;
	strcpy (inscricoes[7].codigo, "1FAC");
	inscricoes[7].semestre.semestre = 2;
	inscricoes[7].semestre.ano = 2021;
	
	//inscri��o 9
	inscricoes[8].matricula = 45678;
	strcpy (inscricoes[8].codigo, "1ORG");
	inscricoes[8].semestre.semestre = 1;
	inscricoes[8].semestre.ano = 2022;
	
	//inscri��o 10
	inscricoes[9].matricula = 56789;
	strcpy (inscricoes[9].codigo, "2FPR");
	inscricoes[9].semestre.semestre = 1;
	inscricoes[9].semestre.ano = 2022;
}
