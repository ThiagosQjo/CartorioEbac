#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de espaço em memória (acentos e sinais)
#include <locale.h>//biblioteca de alocação de idioma
#include <string.h>//biblioteca de configuração de strings

int registro()
{ //função responsável por registrar os usuários no sistema

//início da criação de variáveis/string

	char arquivo [40];						
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];

//fim da string

//início da coleca te informações do usuário

	printf("Digite o CPF a ser cadastrado:"); 
	scanf ("%s", cpf); //recebe resposta do usuário
	
	strcpy(arquivo, cpf); //Copia e armazena os valores da string no arquivo
	
	FILE *file; //cria um arquivo 
	file = fopen (arquivo, "w"); // escreve no arquivo
	fprintf (file, cpf); //salva o valor da variável (no caso, o número do cpf)
	fclose (file);//fecha o arquivo
	
	file = fopen (arquivo, "a"); //atualiza a informação no arquivo
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
	
	printf ("\nUsuário cadastrado com sucesso!\n\n");
	system ("pause"); //Pausa o sistema (CMD) até alguma tecla ser pressionada
	
//fim da coleta de informações
		
}

int consulta()// função responsável por consultar o usuário cadastrado no arquivo
{
	
//início da consulta das informações cadastradas anteriormente

	setlocale (LC_ALL, "Portuguese"); //Define a Linguagem do sistema
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r"); //lê o arquivo
	
	if (file == NULL)//NULL = sem informação  //if = se (no caso "se" o arquivo não tem informação
	{
		printf("\nArquivo não encontrado!\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL) // while = enquanto //fgets = busca o arquivo //! = for diferente
	{
		printf("\nInformações do usuário:\n\n");
		printf("%s\n\n", conteudo);
		
	}
	
	system ("pause");
	
	fclose (file);

//fim da consulta das informações
	
}

int excluir ()//função responsável por excluir os usuários cadastrados
{

	
//início da função de excluir registros

	char cpf [40];
	
	printf("Digite o CPF que será excluído:\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	fclose (file);
	
	if(file == NULL)
	{
		printf("\nUsuário não encontrado!\n\n");
	}
	
	else
	{
	
		printf("\nUsuário excluído com sucesso!\n\n");	
		remove(cpf);
		
	}
	
	
	
	system ("pause");

//fim da função de excluir usuários
}

int main() //função principal, menu e login
{
	
	setlocale (LC_ALL, "Portuguese");
	
	int opcao = 0;
	int rept = 1;
	char senha [] = "a" ; 
	int compare;
	
	printf ("Cartório EBAC\n\n");
	printf ("Login de Administrador\n\nDigite sua senha:");
	scanf("%s", senha);
	
	compare = strcmp(senha, "admin");
	
	if (compare == 0)
	{
		for (rept=1;rept=1;) //repete o menu inicial do programa
		{
		
			system ("cls");
			setlocale (LC_ALL, "Portuguese");
			
			printf("Cartório EBAC\n"); //início do menu
			printf("Escolha a opção desejada:\n\n");
			printf("\t 1 - Registrar Usuário\n");
			printf("\t 2 - Consultar Usuário\n");
			printf("\t 3 - Excluir Usuário\n");
			printf("\t 4 - Sair do Programa\n\n");\
			
			printf("Opção: "); //fim do menu
			scanf("%d", &opcao); //armazena a escolha do usuário
			
			system ("cls");//limpa o sistema para a proxima função
			
			switch (opcao) //início da resposta de acordo com a opção escolhida
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
				printf("Obrigado por utilizar o programa, até a próxima :)\n\n");
				return 0;
				
				default:
				printf("Essa opção não está disponivel.");
				system("pause");
				break;		
			}		// fim das respostas
			
		}//fim do laço de repetição
		
		
	}
	else
	printf("\nSenha Incorreta.\n");
	
	
	
}


