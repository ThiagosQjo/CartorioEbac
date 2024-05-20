#include <stdio.h>//biblioteca de comunica��o com o usu�rio.
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria (acentos e sinais)
#include <locale.h>//biblioteca de aloca��o de texto por regi�o (idioma da acentua��o)
#include <string.h>//biblioteca de configura��o da string


int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	//in�cio da coleta de informa��es do usu�rio
	
	printf ("Digite o CPF a ser cadastrado:"); //coletando informa��es do usu�rio
	scanf ("%s",cpf);//%s refere-se a string (Sequ�ncia de caracteres)
	
	strcpy(arquivo, cpf);//Respons�vel por copiar os valores das strings
	
	FILE *file;//Cria os arquivos
	file = fopen(arquivo, "w");//abre os arquivos (write)
	fprintf(file, cpf);//Salva o valor da vari�vel
	fclose(file);//Fecha os arquivos
	
	file = fopen(arquivo, "a");//Atualiza os arquivos
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado:");//coletando informa��es do usu�rio
	scanf("%s",nome);
	
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, " ");
		fclose(file);
	
	printf("Digite o Sobrenome:");//coletando informa��es do usu�rio
	scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
	printf("Digite o Cargo:");//coletando informa��es do usu�rio
	
	scanf("%s",cargo);
	
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		printf("\nUsu�rio cadastrado com sucesso!!\n\n");
		system("pause");//pausa o sistema at� alguma tecla ser pressionada
	
	//fim da coleta de informa��es
	
}

int consulta()
{
	//in�cio da consulta de informa��es
	
	setlocale (LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");//verificar a informa��o armazenada
	scanf("%s",cpf);
	
	FILE *file;//cria os arquivos
	file = fopen (cpf,"r");//L� os Arquivos (Read)
	
	
	if(file == NULL)//NULL = sem informa��o
	{
		printf ("Arquivo n�o encontrado.\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL)//while = enquanto/ fgets = buscar no arquivo
	{
		printf ("\nInforma��es do usu�rio:\n");
		printf ("%s", conteudo);
		printf ("\n\n");
	}
	
	system("pause");
	
	fclose(file);
	//fim da consulta de informa��es
}

int excluir()
{
	//in�cio de deletar informa��es
	
	char cpf [40];
	
	printf("Digite o CPF que ser� excluido!\n");
	scanf("%s",cpf);
	
	
	
	FILE *file;//abre o arquivo
	file = fopen (cpf,"r");//l� o arquivo
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado.\n");
		
	}
	else
	{
		remove(cpf);//remove o arquivo armazenado
		printf("Usu�rio exclu�do com sucesso!\n\n");
		
	}
	
	system("pause");
	
	//fim de deletar informa��es
}


int main () //in�cio do programa
{
	int opcao=0; //definindo vari�veis
	int laco=1; 
	
	for(laco=1;laco=1;) //la�o de repeti��es at� o fim do programa
	{
		system("cls"); //limpar informa��es
	
		setlocale (LC_ALL, "Portuguese"); //definindo liguagem
	
		printf("Cart�rio EBAC\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 - Registro de Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n");
		printf("\t4 - Fechar Programa\n\n"); 
		printf("Op��o "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //limpar informa��es
		
		switch(opcao)//in�cio da sele��o de resposta de acordo com a op��o escolhida 
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			excluir();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema :)\n");
			return 0;
			
			default:
			printf("Essa op��o n�o est� disponivel\n");
			system("pause");
			break;
			
			//fim da sele��o de respostas
		}
	
	}
}
