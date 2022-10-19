/*
	FPR - Professor Leonardo Vianna
	Turma: Manh�
	Data: 20/04/2022
	
	Lista de Exerc�cios	VI
	
	Quest�o 04: 
	Suponha a exist�ncia de um vetor de tamanho TAM, cada posi��o armazenando o nome da pessoa 
	e a sua data de anivers�rio (representada por um struct do tipo TData, contendo os campos 
	dia e mes). Pede-se o desenvolvimento das seguintes fun��es:
 	
	 i. Determinar a quantidade de pessoas que fazem anivers�rio no m�s M;
	 ii. Exibir os nomes de todas pessoas que fazem anivers�rio entre as datas d1 e d2, 
	     ambas do tipo TData.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de constantes
#define TAM 10

//defini��o de tipos
typedef enum {FALSE, TRUE} TLogico;

typedef struct {
	int dia, mes;
} TData;

typedef struct {
	char nome[20];
	TData aniversario;
} TPessoa;

//prot�tipos das fun��es
int aniversariantes (TPessoa vetPessoas[], int quantidade, int mes);
void exibirAniversariantes (TPessoa vetPessoas[], int quantidade, TData d1, TData d2);

void preencher (TPessoa vetor[]);
TLogico verificarIntervaloDatas (TData data, TData data1, TData data2);

//main
void main ()
{
	//declara��o de vari�veis
	TPessoa pessoas[TAM];
	int quant;
	TData data1, data2;
	
	//preenchendo o vetor com valores pr�-definidos
	preencher (pessoas);
	
	//chamando as fun��es
	quant = aniversariantes (pessoas, TAM, 7);
	
	printf ("%d pessoas fazem aniversario no mes 7\n\n\n", quant);
	
	data1.dia = 3;
	data1.mes = 5;
	
	data2.dia = 8;
	data2.mes = 7;
	
	exibirAniversariantes (pessoas, TAM, data1, data2);
}

//implementa��o das fun��es

//Determinar a quantidade de pessoas que fazem anivers�rio no m�s M.
int aniversariantes (TPessoa vetPessoas[], int quantidade, int mes)
{
	//declara��o de vari�veis
	int i, cont = 0;
	
	//varrendo o vetor
	for (i=0;i<quantidade;i++)
	{
		//verificando se a pessoa da posi��o 'i' faz anivers�rio no m�s 'mes'
		if (vetPessoas[i].aniversario.mes == mes)
		{
			//atualizando o total de aniversariantes do m�s 'mes'
			cont++;
		}
	}
	
	//retornando o total de aniversariantes do m�s 'mes'
	return cont;	
}

//Exibir os nomes de todas pessoas que fazem anivers�rio entre as datas d1 e d2, ambas do tipo TData
void exibirAniversariantes (TPessoa vetPessoas[], int quantidade, TData d1, TData d2)
{
	//declara��o de vari�veis
	int i;
	
	//varrendo o vetor
	for (i=0;i<quantidade;i++)
	{
		//verificando se a pessoa da posi��o 'i' faz anivers�rio entre as datas 'd1' e 'd2'
		if (verificarIntervaloDatas (vetPessoas[i].aniversario, d1, d2) == TRUE)
		{
			printf ("Nome: %s (%d/%d)\n", vetPessoas[i].nome, vetPessoas[i].aniversario.dia, vetPessoas[i].aniversario.mes);
		}		
	}	
}

//verificar se 'data' encontra-se entre 'data1' e 'data2'
TLogico verificarIntervaloDatas (TData data, TData data1, TData data2)
{
	//verificando se 'data' pertence a algum m�s interno entre 'data1' e 'data2'
	if ((data.mes > data1.mes) && (data.mes < data2.mes))
	{
		return TRUE;
	}
	
	//verificando se 'data' pertence ao mesmo m�s de 'data1', por�m com dia maior ou igual
	if ((data.mes == data1.mes) && (data.dia >= data1.dia))
	{
		return TRUE;
	}

	//verificando se 'data' pertence ao mesmo m�s de 'data2', por�m com dia menor ou igual
	if ((data.mes == data2.mes) && (data.dia <= data2.dia))
	{
		return TRUE;
	}

	//retornando FALSE, caso a data n�o atenda a nenhum crit�rio anterior
	return FALSE;
}

void preencher (TPessoa vetor[])
{
	//Pessoa 1
	strcpy (vetor[0].nome, "JOAO");
	vetor[0].aniversario.dia = 11;
	vetor[0].aniversario.mes = 4;
	
	//Pessoa 2
	strcpy (vetor[1].nome, "MARIA");
	vetor[1].aniversario.dia = 25;
	vetor[1].aniversario.mes = 7;
	
	//Pessoa 3
	strcpy (vetor[2].nome, "ANA");
	vetor[2].aniversario.dia = 1;
	vetor[2].aniversario.mes = 7;
	
	//Pessoa 4
	strcpy (vetor[3].nome, "PEDRO");
	vetor[3].aniversario.dia = 4;
	vetor[3].aniversario.mes = 5;
	
	//Pessoa 5
	strcpy (vetor[4].nome, "CLARA");
	vetor[4].aniversario.dia = 17;
	vetor[4].aniversario.mes = 6;	
}
