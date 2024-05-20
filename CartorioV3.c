#include <stdio.h>//biblioteca de comunicação com o usuário.
#include <stdlib.h>//biblioteca de alocação de espaço em memória (acentos e sinais)
#include <locale.h>//biblioteca de alocação de texto por região (idioma da acentuação)
#include <string.h>//biblioteca de configuração da string


int registro()//função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis/string
	
	//início da coleta de informações do usuário
	
	printf ("Digite o CPF a ser cadastrado:"); //coletando informações do usuário
	scanf ("%s",cpf);//%s refere-se a string (Sequência de caracteres)
	
	strcpy(arquivo, cpf);//Responsável por copiar os valores das strings
	
	FILE *file;//Cria os arquivos
	file = fopen(arquivo, "w");//abre os arquivos (write)
	fprintf(file, cpf);//Salva o valor da variável
	fclose(file);//Fecha os arquivos
	
	file = fopen(arquivo, "a");//Atualiza os arquivos
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado:");//coletando informações do usuário
	scanf("%s",nome);
	
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, " ");
		fclose(file);
	
	printf("Digite o Sobrenome:");//coletando informações do usuário
	scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
	printf("Digite o Cargo:");//coletando informações do usuário
	
	scanf("%s",cargo);
	
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		printf("\nUsuário cadastrado com sucesso!!\n\n");
		system("pause");//pausa o sistema até alguma tecla ser pressionada
	
	//fim da coleta de informações
	
}

int consulta()
{
	//início da consulta de informações
	
	setlocale (LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");//verificar a informação armazenada
	scanf("%s",cpf);
	
	FILE *file;//cria os arquivos
	file = fopen (cpf,"r");//Lê os Arquivos (Read)
	
	
	if(file == NULL)//NULL = sem informação
	{
		printf ("Arquivo não encontrado.\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL)//while = enquanto/ fgets = buscar no arquivo
	{
		printf ("\nInformações do usuário:\n");
		printf ("%s", conteudo);
		printf ("\n\n");
	}
	
	system("pause");
	
	fclose(file);
	//fim da consulta de informações
}

int excluir()
{
	//início de deletar informações
	
	char cpf [40];
	
	printf("Digite o CPF que será excluido!\n");
	scanf("%s",cpf);
	
	
	
	FILE *file;//abre o arquivo
	file = fopen (cpf,"r");//lê o arquivo
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usuário não encontrado.\n");
		
	}
	else
	{
		remove(cpf);//remove o arquivo armazenado
		printf("Usuário excluído com sucesso!\n\n");
		
	}
	
	system("pause");
	
	//fim de deletar informações
}


int main () //início do programa
{
	int opcao=0; //definindo variáveis
	int laco=1; 
	
	for(laco=1;laco=1;) //laço de repetições até o fim do programa
	{
		system("cls"); //limpar informações
	
		setlocale (LC_ALL, "Portuguese"); //definindo liguagem
	
		printf("Cartório EBAC\n\n"); //início do menu
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - Registro de Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n");
		printf("\t4 - Fechar Programa\n\n"); 
		printf("Opção "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //limpar informações
		
		switch(opcao)//início da seleção de resposta de acordo com a opção escolhida 
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
			printf("Essa opção não está disponivel\n");
			system("pause");
			break;
			
			//fim da seleção de respostas
		}
	
	}
}
