/* Uma loja de autom�veis mant�m os carros � venda sob a forma de um vetor de structs
contendo as seguintes informa��es, para cada ve�culo: placa, modelo, marca, cor, quilometragem, ano modelo/fabrica��o
(deve ser um struct), valor e tipo (usado ou 0 km, conforme o valor do campo quilometragem). Pede-se a declara��o de 
uma vari�vel que represente o estoque de ve�culos da loja, incluindo todas as declara��es de tipos que possam ser 
necess�rias. Al�m disso, implementar as seguintes fun��es:
	i. Exibir todos os carros do modelo m, ano de fabrica��o entre a1 e a2 (inclusive), com valor n�o superior a
	   x reais;
	
	ii. Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;

	iii. Retirar do estoque um determinado ve�culo, dada a sua placa. */
	
//Importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//Defini��o de constantes
#define NUM_CARROS 5

//Defini��o de tipos
typedef enum {ZERO, USADO} TipoCarro; //definindo um tipo enumerado.
typedef enum {FALSE, TRUE} TLogico;
// typedef enum {JANEIRO=1, FEVEREIRO, ..., DEZEMBRO} TMeses;

typedef struct {
	int modelo;
	int fabricacao;
}TAno;

typedef struct { 
	char placa [10];
	char modelo[10];
	char marca[10];
	char cor [10];
	float quilometragem;
	TAno ano;
	float valor;
	TipoCarro tipo; //char tipo [10];
} TCarro;

//Prot�tipo das fun��es
void preencherVetor (TCarro ag[]);
void exibirCarrosFiltro (TCarro agencia[], int quant, char modelo[], int ano1, int ano2, float dinheiro);
void exibirDadosCarro (TCarro carro);
void reajustarValor0km (TCarro agencia[], int quant, float taxa);
int removerVeiculo (TCarro agencia[], int *quant, char placa[]);
void exibirTodosCarros (TCarro ag[], int quantidade);

//Main
void main ()
{
	//declara��o de vari�veis
	TCarro agen[NUM_CARROS];	
	int quantCarros = NUM_CARROS;
	
	//preenchendo o vetor para que as demais fun��es possam ser testadas
	preencherVetor (agen);
		
	//exibindo os carros que atenderem aos filtros definidos
	
	//Chamada 1
	printf ("Chamada 1 (exibindo carros por filtro):\n");
	exibirCarrosFiltro (agen, quantCarros, "HB20", 2016, 2020, 38000);
	
	//Chamada 2
	printf ("Chamada 2 (exibindo carros por filtro):\n");
	exibirCarrosFiltro (agen, quantCarros, "CRETA", 2016, 2020, 38000);
	
	//chamando a fun��o que reajustar� os carros 0km
	reajustarValor0km (agen, quantCarros, 2.5);  //passando a taxa de 2.5%
	
	//exibindo os carros ap�s o reajuste
	printf ("\n\nExibindo os carros apos o reajuste:\n");
	exibirTodosCarros (agen, quantCarros);

	//Chamada 1
	printf ("Chamada 1 (removendo carro do estoque):\n");
	if (removerVeiculo (agen, &quantCarros, "XYZ 1234") == TRUE)
	{
		printf ("\n\tCarro removido com sucesso!\n");
		exibirTodosCarros (agen, quantCarros);
	}
	else
	{
		printf ("\n\tPlaca n�o localizada!\n\n");
	}
	
	//Chamada 2
	printf ("Chamada 2 (removendo carro do estoque):\n");
	if (removerVeiculo (agen, &quantCarros, "CDE 3456") == TRUE)
	{
		printf ("\n\tCarro removido com sucesso!\n");
		exibirTodosCarros (agen, quantCarros);
	}
	else
	{
		printf ("\n\tPlaca n�o localizada!\n\n");
	}
}

//Implementa��o das demais fun��es

//preenche o vetor de carros com dados pr�-definidos, auxiliando o processo de teste das fun��es solicitadas
void preencherVetor (TCarro ag[])
{
	//1� carro
	strcpy (ag[0].placa, "ABC 1234");
	strcpy (ag[0].modelo, "HB20");
	strcpy (ag[0].marca, "HYUNDAI");
	strcpy (ag[0].cor, "PRATA");
	ag[0].quilometragem = 20000;
	ag[0].ano.modelo = 2016;
	ag[0].ano.fabricacao = 2015;
	ag[0].valor = 25000;
	ag[0].tipo = USADO;	
	
	//2� carro
	strcpy (ag[1].placa, "BCD 2345");
	strcpy (ag[1].modelo, "CIVIC");
	strcpy (ag[1].marca, "HONDA");
	strcpy (ag[1].cor, "BRANCA");
	ag[1].quilometragem = 0;
	ag[1].ano.modelo = 2022;
	ag[1].ano.fabricacao = 2022;
	ag[1].valor = 90000;
	ag[1].tipo = ZERO;	
	
	//3� carro
	strcpy (ag[2].placa, "CDE 3456");
	strcpy (ag[2].modelo, "HB20");
	strcpy (ag[2].marca, "HYUNDAI");
	strcpy (ag[2].cor, "PRETA");
	ag[2].quilometragem = 45000;
	ag[2].ano.modelo = 2017;
	ag[2].ano.fabricacao = 2017;
	ag[2].valor = 35000;
	ag[2].tipo = USADO;	
	
	//4� carro
	strcpy (ag[3].placa, "EFG 4567");
	strcpy (ag[3].modelo, "HB20");
	strcpy (ag[3].marca, "HYUNDAI");
	strcpy (ag[3].cor, "AZUL");
	ag[3].quilometragem = 58000;
	ag[3].ano.modelo = 2019;
	ag[3].ano.fabricacao = 2018;
	ag[3].valor = 40000;
	ag[3].tipo = USADO;	
	
	//5� carro
	strcpy (ag[4].placa, "FGH 5678");
	strcpy (ag[4].modelo, "ECOSPORT");
	strcpy (ag[4].marca, "FORD");
	strcpy (ag[4].cor, "VERDE");
	ag[4].quilometragem = 0;
	ag[4].ano.modelo = 2022;
	ag[4].ano.fabricacao = 2022;
	ag[4].valor = 85000;
	ag[4].tipo = ZERO;
}

void exibirDadosCarro (TCarro carro)
{
	printf ("\nPlaca: %s\n", carro.placa);
	printf ("Modelo/Marca: %s/%s\n", carro.modelo, carro.marca);
	printf ("Cor: %s\n", carro.cor);
	printf ("km: %.2f\n", carro.quilometragem);
	printf ("Ano: %d/%d\n", carro.ano.fabricacao, carro.ano.modelo);
	printf ("Valor: R$ %.2f\n", carro.valor);
	printf ("Tipo: ");
	printf (carro.tipo==USADO?"Usado\n\n":"Zero\n\n"); //Se o carro for do tipo 'USADO' escreva 'Usado' sen�o, escreva 'Zero'
}

//Exibir todos os carros do modelo m, ano de fabrica��o entre a1 e a2 (inclusive), com valor n�o superior a x reais;
void exibirCarrosFiltro (TCarro agencia[], int quant, char modelo[], int ano1, int ano2, float dinheiro)
{
	//Declara��o de vari�veis
	int i, cont=0;
	
	//Percorrendo o vetor
	for (i=0; i<quant; i++)
	{
		if ((strcmp(agencia[i].modelo, modelo) == 0) && (agencia[i].ano.fabricacao >= ano1) && (agencia[i].ano.fabricacao <= ano2)
		   && (agencia[i].valor <= dinheiro))
		   {
		   		exibirDadosCarro;
		   		cont++;
		   }
	}
	
	if (cont == 0)
	{
		printf ("Nenhum carro atendeu aos filtros definidos !! \n\n");
	}
}

//Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
void reajustarValor0km (TCarro agencia[], int quant, float taxa)
{
	//Declara��o de vari�veis
	int i;
	
	for (i=0; i<quant; i++)
	{
		if (agencia[i].tipo == ZERO) //se o carro 'i' for '0km'
			//reajustar valor
		{
			agencia[i].valor = agencia[i].valor + (agencia[i].valor*taxa/100);
		}
	}
}

//Retirar do estoque um determinado ve�culo, dada a sua placa.
int removerVeiculo (TCarro agencia[], int *quant, char placa[])
{
	//Declara��o de vari�veis
	int i, j;
	
	for (i=0; i<*quant; i++)
	{
		if (strcmp(agencia[i].placa, placa) == 0)
		{
			for (j=i;j<*quant-1;j++)
			{
				//Removendo o carro movendo os demais � esquerda 
				agencia[j] = agencia[j+1]; 
			}
			
			//atualizando a quantidade
			(*quant)--;
			
			//Retornando TRUE se o carro foi encontrado;
			return TRUE;
		}
	}
	
	//Se chegou aqui � porque n�o foi encontrado um carro com essa placa
	return FALSE;
}

void exibirTodosCarros (TCarro ag[], int quantidade)
{
	//declara��o de vari�veis
	int i, cont=0;
	
	//percorrendo o vetor que representa a ag�ncia de carros
	for (i=0;i<quantidade;i++)
	{
		exibirDadosCarro (ag[i]);
	}
}
