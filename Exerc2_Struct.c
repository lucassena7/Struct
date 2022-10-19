/*
	FAETERJ-Rio
	FPR - Professor Leonardo Vianna
	
	Lista de Exerc�cios VI (Structs)
	
	Quest�o 02:
	Determinada zona eleitoral possui N eleitores inscritos que poder�o votar, uma �nica vez, em um dos C candidatos para o �nico cargo a ser definido. 
	Pede-se:

	a. A declara��o de todo(s) o(s) tipo(s) de dados necess�rio(s) para o armazenamento dos n�meros dos candidatos, assim como a quantidade de votos 
	   brancos, nulos e votos para cada candidato;
	b. Uma fun��o que leia o voto de cada eleitor, considerando que o processo terminar� quando os N eleitores votarem ou quando o n�mero -1 for 
	   digitado como voto;
    c. Uma fun��o que exiba:
    	i.   O total de votos para cada candidato, assim com a quantidade de votos brancos (c�digo 0) e de nulos (c�digo sem candidato associado);
    	ii.	 A quantidade de absten��es (eleitores que n�o votaram);
    	iii. O n�mero do candidato vencedor (caso tenha mais de 50% dos votos v�lidos) ou dos que ir�o para o segundo turno (os dois mais votados). 
    	
    Notas: 
    a) o n�mero do candidato deve conter dois algarismos apenas;
	b) podem considerar que n�o haver� mais de um candidato com a mesma quantidade de votos.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define N 10  				//n�mero de eleitores da zona eleitoral
#define C 3					//n�mero de candidatos

//defini��o de tipos
typedef struct {
	int numero;				//n�mero do candidato
	int totalVotos;			//total de votos que o candidato recebeu
} TCandidato;				//struct que representada cada candidato

typedef struct {
	TCandidato vetCand[C];	//armazenar�, para cada candidato, o seu n�mero e a quantidade de votos recebidos
	int totalVotos;			//total de votos
	int brancos;			//total de votos brancos (informar 0 para o n�mero do candidato)
	int nulos;				//total de votos nulos (informar um valor inv�lido para o n�mero do candidato)
} TVotacao;					//struct que representar� a elei��o e os diversos votos

//prot�tipos das fun��es

  //fun��es solicitadas
  void leituraVotos (TVotacao *eleicao, int numEleitores);
  void exibirResultadoEleicao (TVotacao eleicao);
  
  //fun��es auxiliares
  void preencherVetorCandidatos (TCandidato candidatos[], int tamanho);
  void inicializarVotacao (TVotacao *eleicao);
  int buscar (TCandidato candidatos[], int tamanho, int numeroCandidato);
  void candidatosMaisVotados (TCandidato candidatos[], int tamanho, int *primeiro, int *segundo);
  
//main
void main ()
{
	//declara��o de vari�veis
	TVotacao vetEleicao;
	
	//inicializando o vetor da Elei��o, inclusive lendo os dados dos candidatos
	inicializarVotacao (&vetEleicao);
	
	//lendo os votos dos eleitores
	leituraVotos (&vetEleicao, N);
	
	//exibindo os resultados
  	exibirResultadoEleicao (vetEleicao);	
}

//implementa��o das fun��es
void preencherVetorCandidatos (TCandidato candidatos[], int tamanho)
{
	//declara��o de vari�veis
	int i, numero;
	
	//varrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//lendo o n�mero de cada candidato
		do
		{
			printf ("Entre com o numero do %do. candidato: ", i+1);
			scanf ("%d", &numero);
			
			//verificando se o n�mero digitado � inv�lido (pois deve ter dois algarismos)
			if ((numero < 10) || (numero > 99))
			{
				printf ("\n\n\tErro: o numero do candidato deve estar no intervalo de 10 a 99\nTente novamente.\n\n");
			}
			
		} while ((numero < 10) || (numero > 99));
		
		candidatos[i].numero = numero;
		candidatos[i].totalVotos = 0;
	}
}

void inicializarVotacao (TVotacao *eleicao)
{
	//inicializando os votos com zero no in�cio da vota��o
	(*eleicao).totalVotos = 0;
	(*eleicao).brancos = 0;
	(*eleicao).nulos = 0;
	
	//lendo os dados de cada candidato
	preencherVetorCandidatos ((*eleicao).vetCand, C);
}

int buscar (TCandidato candidatos[], int tamanho, int numeroCandidato)
{
	//declora��o de vari�veis
	int i;
	
	//varrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//verificando se o n�mero do candidato foi encontrado
		if (candidatos[i].numero == numeroCandidato)
		{
			return i;	//retornando a posi��o do candidato no vetor
		}
	}
	
	//retornando -1, se o n�mero do candidato n�o existir
	return -1;
}

void leituraVotos (TVotacao *eleicao, int numEleitores)
{
	//declara��o de vari�veis
	int numero, retorno;
	
	printf ("\n\n\n");
	
	do
	{
		//lendo o voto de cada eleitor
		printf ("Numero do candidato: ");
		scanf ("%d", &numero);
		
		//verificando se n�o foi o voto de sa�da do sistema
		if (numero != -1)
		{
			//atualizando o total de votos
			(*eleicao).totalVotos++;
			
			//trata-se de voto em branco?
			if (numero == 0)
			{
				(*eleicao).brancos++;
			}
			else
			{
				//buscando no vetor o candidato votado, para atualizar o seu total de votos
				retorno = buscar ((*eleicao).vetCand, C, numero);
			
				//verificando se o n�mero do candidato foi encontrado
				if (retorno >= 0)
				{
					(*eleicao).vetCand[retorno].totalVotos++;	//atualizando o n�mero de votos do candidato
				}
				else
				{
					//trata-se de voto nulo
					(*eleicao).nulos++;
				}
			}
		}
	}
	while (((*eleicao).totalVotos < numEleitores) && (numero != -1));	
}

void exibirResultadoEleicao (TVotacao eleicao)
{
	//declara��o de vari�veis
	int i, primeiro, segundo, votosValidos;
	float percentualPrimeiro;
	
	//exibindo o resultado da elei��o
	printf ("\n\n\nResultado da Eleicao:\n\n");
	
	printf ("No. Candidato\t\tTotal de votos\n");
	for (i=0;i<C;i++)
	{
		printf ("%d\t\t\t\t%d\n", eleicao.vetCand[i].numero,eleicao.vetCand[i].totalVotos);
	}
	
	printf ("\nVotos Brancos: %d\n", eleicao.brancos);
	printf ("\nVotos Nulos: %d\n", eleicao.nulos);
	printf ("\nAbstencoes: %d\n", N-eleicao.totalVotos);	
	
	//determinando os dois candidatos mais votados
	candidatosMaisVotados (eleicao.vetCand, C, &primeiro, &segundo);
	
	votosValidos = eleicao.totalVotos-eleicao.brancos-eleicao.nulos;
	percentualPrimeiro = (float)eleicao.vetCand[primeiro].totalVotos/votosValidos;
		
	//verificando se o mais votado possui mai de 50% dos votos
	if (percentualPrimeiro > 0.5)
	{
		printf ("\nVencedor da Eleicao: candidato %d!!!\n", eleicao.vetCand[primeiro].numero);
	}
	else
	{
		printf ("\nCandidatos que concorrerao no segundo turno: %d e %d.\n", eleicao.vetCand[primeiro].numero, eleicao.vetCand[segundo].numero);
	}	
}

void candidatosMaisVotados (TCandidato candidatos[], int tamanho, int *primeiro, int *segundo)
{
	//declara��o de vari�veis
	int i, maisVotos1, maisVotos2;
	
	//inicializado o candidato mais votado como o candidato da posi��o 0 do vetor
	*primeiro = 0;
	maisVotos1 = candidatos[0].totalVotos;
	
	for (i=1;i<tamanho;i++)
	{
		if (candidatos[i].totalVotos > maisVotos1)
		{
			maisVotos2 = maisVotos1;
			*segundo = *primeiro;
			
			maisVotos1 = candidatos[i].totalVotos;
			*primeiro = i;
		}
		else
		{
			if (candidatos[i].totalVotos > maisVotos2)
			{
				maisVotos2 = candidatos[i].totalVotos;
				*segundo = i;
			}
		}
	}
} 	
