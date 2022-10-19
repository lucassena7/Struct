/*
	FPR - Fundamentos de Programa��o
	Professor: Leonardo Vianna
	Aluno: Lucas Sena
	
	Atividade 4 - Structs 
	
	Um grupo de pessoas foi entrevistado e cada uma informou o seu nome e o nome de sua m�e.
	Estes dados foram armazenados em um vetor do qual cada posi��o consiste em um struct.
	
	Desenvolver uma fun��o que receba um vetor como o descrito acima e retorne outro
	contendo, para cada m�e, o n�mero de filhos entrevistados (portanto, um outro vetor de
	structs).
	
	Nota: considerar que n�o existem duas ou mais m�es com o mesmo nome.

*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de constantes
#define TAM 5

//defini��o de tipos
typedef struct {
	char nomeMae[30];
	int filhosEntrevistados;
} TDadosMae;

typedef struct {
	char nomePessoa[30];
	TDadosMae inforMae;
} TEntrevista;

//prot�tipos das fun��es
void receberDadosPessoa (TEntrevista vetor[], int *quant, TDadosMae infoMaes[], int *quantMaes);
void exibirDados (TDadosMae vetor[], int quant);
int buscarMae (TDadosMae vetor[], int quant, char nomeMaeBusca[]);

//main
void main ()
{
//declara��o de vari�veis
TEntrevista pessoasEntrevistadas[TAM];
TDadosMae totalMaes[TAM];
int quantPessoasEntrevistadas = 0, quantTotalMaes = 0;

receberDadosPessoa (pessoasEntrevistadas, &quantPessoasEntrevistadas, totalMaes, &quantTotalMaes);

exibirDados (totalMaes, quantTotalMaes);
}

//implementa��o das demais fun��es
void receberDadosPessoa (TEntrevista vetor[], int *quant, TDadosMae infoMaes[], int *quantMaes)
{
	//declara��o de vari�veis
	int i, resposta;
	
	//percorrendo o vetor
	for (i=0; i<TAM; i++)
	{
		fflush (stdin);
		printf ("\nEntre com o seu nome: ");
		gets (vetor[i].nomePessoa);
		
		printf ("Entre com o nome de sua mae: ");
		gets (vetor[i].inforMae.nomeMae);
		
		(*quant)++;
		
		resposta = buscarMae (infoMaes, *quantMaes, vetor[i].inforMae.nomeMae);
		
		//o nome a ser buscado est� no vetor inforMae
		if (resposta >= 0)
		{
			(infoMaes[(resposta)].filhosEntrevistados)++;
		}
		else
		{
			strcpy (infoMaes[(*quantMaes)].nomeMae, vetor[i].inforMae.nomeMae);
			
			infoMaes[(*quantMaes)].filhosEntrevistados = 1;
			
			(*quantMaes)++;
		}
	}
}

void exibirDados (TDadosMae vetor[], int quant)
{
	//declara��o de vari�veis
	int i;	
	//exibindo o nome de todas as maes e a quantidade de filhos
	for (i=0;i<quant;i++)
	{
        printf("\nNome Mae: %s\n", vetor[i].nomeMae);
		printf("Qtde filhos: %d\n", vetor[i].filhosEntrevistados);
	}
}

int buscarMae (TDadosMae vetor[], int quant, char nomeMaeBusca[])
{
	//declara��o de vari�veis
	int i;
	
	for(i=0; i<quant; i++)
	{
		if (strcmp(vetor[i].nomeMae, nomeMaeBusca) == 0)
		{
			return i;
		}
	}
	//se percorrer o vetor inteiro e n�o achou o nome, retorna -1.
	return -1; //analogia ao false
}

/* O struct 'TEntrevista' deveria ter os seguintes campos, como especificado no enunciado: o nome da pessoa e o nome de sua m�e;
	- Na fun��o desenvolvida, 'quant' ser� sempre TAM. Por refer�ncia?
	- O enunciado solicita uma fun��o que, dado um vetor, gere outro. E a sua fun��o preenche o primeiro vetor e, logo em seguida, gera o outro. */
