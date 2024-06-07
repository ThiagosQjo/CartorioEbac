#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de espa�o em mem�ria (acentos e sinais)
#include <locale.h>//biblioteca de aloca��o de idioma
#include <string.h>//biblioteca de configura��o de strings

int registro()
{ //fun��o respons�vel por registrar os usu�rios no sistema

//in�cio da cria��o de vari�veis/string

	char arquivo [40];						
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];

//fim da string

//in�cio da coleca te informa��es do usu�rio

	printf("Digite o CPF a ser cadastrado:"); 
	scanf ("%s", cpf); //recebe resposta do usu�rio
	
	strcpy(arquivo, cpf); //Copia e armazena os valores da string no arquivo
	
	FILE *file; //cria um arquivo 
	file = fopen (arquivo, "w"); // escreve no arquivo
	fprintf (file, cpf); //salva o valor da vari�vel (no caso, o n�mero do cpf)
	fclose (file);//fecha o arquivo
	
	file = fopen (arquivo, "a"); //atualiza a informa��o no arquivo
	fprintf (file, ",");
	fclose (file);
	
	////////////////////////////////////////////
	
	printf("Digite o Nome a ser cadastrado:");
	scanf ("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf (file, nome);
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
	
	////////////////////////////////////////////
	
	printf ("Digite o Sobrenome:");
	scanf ("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
	
	///////////////////////////////////////////
	
	printf ("Digite o Cargo:");
	scanf ("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose (file);
	
	///////////////////////////////////////////
	
	printf ("\nUsu�rio cadastrado com sucesso!\n\n");
	system ("pause"); //Pausa o sistema (CMD) at� alguma tecla ser pressionada
	
//fim da coleta de informa��es
		
}

int consulta()// fun��o respons�vel por consultar o usu�rio cadastrado no arquivo
{
	
//in�cio da consulta das informa��es cadastradas anteriormente

	setlocale (LC_ALL, "Portuguese"); //Define a Linguagem do sistema
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r"); //l� o arquivo
	
	if (file == NULL)//NULL = sem informa��o  //if = se (no caso "se" o arquivo n�o tem informa��o
	{
		printf("\nArquivo n�o encontrado!\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL) // while = enquanto //fgets = busca o arquivo //! = for diferente
	{
		printf("\nInforma��es do usu�rio:\n\n");
		printf("%s\n\n", conteudo);
		
	}
	
	system ("pause");
	
	fclose (file);

//fim da consulta das informa��es
	
}

int excluir ()//fun��o respons�vel por excluir os usu�rios cadastrados
{

	
//in�cio da fun��o de excluir registros

	char cpf [40];
	
	printf("Digite o CPF que ser� exclu�do:\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	fclose (file);
	
	if(file == NULL)
	{
		printf("\nUsu�rio n�o encontrado!\n\n");
	}
	
	else
	{
	
		printf("\nUsu�rio exclu�do com sucesso!\n\n");	
		remove(cpf);
		
	}
	
	
	
	system ("pause");

//fim da fun��o de excluir usu�rios
}

int main() //fun��o principal, menu e login
{
	
	setlocale (LC_ALL, "Portuguese");
	
	int opcao = 0;
	int rept = 1;
	char senha [] = "a" ; 
	int compare;
	
	printf ("Cart�rio EBAC\n\n");
	printf ("Login de Administrador\n\nDigite sua senha:");
	scanf("%s", senha);
	
	compare = strcmp(senha, "admin");
	
	if (compare == 0)
	{
		for (rept=1;rept=1;) //repete o menu inicial do programa
		{
		
			system ("cls");
			setlocale (LC_ALL, "Portuguese");
			
			printf("Cart�rio EBAC\n"); //in�cio do menu
			printf("Escolha a op��o desejada:\n\n");
			printf("\t 1 - Registrar Usu�rio\n");
			printf("\t 2 - Consultar Usu�rio\n");
			printf("\t 3 - Excluir Usu�rio\n");
			printf("\t 4 - Sair do Programa\n\n");\
			
			printf("Op��o: "); //fim do menu
			scanf("%d", &opcao); //armazena a escolha do usu�rio
			
			system ("cls");//limpa o sistema para a proxima fun��o
			
			switch (opcao) //in�cio da resposta de acordo com a op��o escolhida
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
				printf("Obrigado por utilizar o programa, at� a pr�xima :)\n\n");
				return 0;
				
				default:
				printf("Essa op��o n�o est� disponivel.");
				system("pause");
				break;		
			}		// fim das respostas
			
		}//fim do la�o de repeti��o
		
		
	}
	else
	printf("\nSenha Incorreta.\n");
	
	
	
}


