#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��e de texto por regi�o
#include<string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios
{
	
	setlocale(LC_ALL, "Portuguese");
	
	//in�cio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cria��o das vari�veis
	
	printf("Digite apenas os n�meros do CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se � strings, para salvamento de string
	
	strcpy(arquivo, cpf); //este comando copia os valores de cpf para arquivo
	
	FILE *file; //cria o arquivo no banco de dados, FILE acessa o banco, *file abre o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo w de write
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //a de atualizar, comando para abrir e atualizar arquivo
	fprintf(file, ", "); //inclui uma v�rgula e um espa�o ap�s a var�vel salva, para melhorar visualiza��o durante consulta
	fclose(file); //fecha o arquivo ap�s atualiza��o
	
	printf("Digite o nome a ser cadastrado: "); //solicita digita��o do nome que ser� salvo na vari�vel nome
	scanf("%s",nome); //carrega o nome digitado pelo usu�rio, no formato de string (%s), na vari�vel nome
	
	file = fopen(arquivo,"a"); //abre o arquivo para ser atualizado
	fprintf(file,nome); //salva o nome digitado na vari�vel nome
	fclose(file); //fecha o arquivo ap�s altera��o
	
	file = fopen(arquivo, "a"); //a de atualizar, comando para abrir e atualizar arquivo
	fprintf(file, ", ");//inclui uma v�rgula e um espa�o ap�s a var�vel salva, para melhorar visualiza��o durante consulta
	fclose(file); //fecha o arquivo ap�s atualiza��o
	
	printf("Digite o sobrenome a ser cadastrado: "); //solicita digita��o do sobrenome para ser salvo na vari�vel sobrenome
	scanf("%s",sobrenome); //l� e carrega o sobrenome digitado na vari�vel sobrenome, no modo string (%s)
	
	file= fopen(arquivo, "a"); //abre o arquivo que est� sendo cadastrado para altera��o da vari�vel sobenome
	fprintf(file,sobrenome); //salva o sobrenome digitado na vari�vel sobrenome
	fclose(file); //fecha o arquivo atualizado
	
	file = fopen(arquivo, "a"); //a de atualizar, comando para abrir e atualizar arquivo
	fprintf(file, ", "); //inclui uma v�rgula e um espa�o ap�s a var�vel salva, para melhorar visualiza��o durante consulta
	fclose(file); //fecha o arquivo ap�s atualiza��o
	
	printf("Digite o cargo a ser cadastrado: "); //solicita digita��o do cargo da pessoa a ser cadastrada
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a"); //a de atualizar, comando para abrir e atualizar arquivo
	fprintf(file,cargo); //inclui uma v�rgula e um espa�o ap�s a var�vel salva, para melhorar visualiza��o durante consulta
	fclose(file); //fecha o arquivo ap�s atualiza��o
	
	printf("Cadastro realizado com sucesso!\n"); //mostra que a conclus�o do cadastro foi realizada com sucesso
	
	system("pause"); //pausa a execu��o do algoritmo para possibilitar visualiza��o da �ltima mensagem
	
	
}

int consulta() //cria��o da fun��o Consulta dos dados cadastrados 
{
	setlocale(LC_ALL, "Portuguese"); //permite utiliza��o do portugu�s na aplica��o
	//in�cio da inclus�o das vari�veis
	char cpf[40];
	char conteudo[200];
	// fim da declara��o das vari�veis
	
	printf("Digite apenas os n�meros do CPF a ser consultado: "); //solicita digita��o do cpf para cadastramento
	scanf("%s",cpf); //armazena o valor digitado na vari�vel cpf
	
	FILE *file; //FILE acessa o banco de dados, *file abre o arquivo
	file = fopen(cpf,"r"); // abre e l� (r de read)
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar este CPF.\n"); //comando if para validar e informar caso o cpf digitado esteja incorreto ou n�o integre o banco de dados
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas s�o as informa��es do usu�rio: "); //caso o cpf seja encontrado, os dados cadastrados ser�o impressos no prompt
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause"); //pausa o sistema para leitura dos dados pelo usu�rio
	fclose(file);
	
}

int deletar() //cria��o da fun��o para deletar dados cadastrados
{
	char cpf[40]; //declarando a vari�vel cpf, tipo char, com 40 caracteres
	printf("Digite apenas os n�meros do CPF a ser deletado: "); //solicita��o para digitar o cpf a ser deletado
	scanf("%s",cpf); //leitura do valor digitado, no formato string (s�rie de caracteres) e armazenamento na vari�vel cpf desta fun��o
			
	remove(cpf); //comando j� existente nas bibliotecas acionadas, para deletar arquivo.	
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf, "r"); //abre e l� o arquivo. Pela ordem de execu��o das linhas, provavelmente o arquivo j� ter� sido deletado e entrar� na situa��o null a seguir:
	
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado no sistema ou deletado.\n");		
		system("pause");
	}	
	
}

int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela
	
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("\t###  Cart�rio da EBAC  ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //limpeza de tela ap�s sele��o pelo usu�rio
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��o para registro de novo usu�rio
			break;
			
			case 2:
			consulta(); //chamada de fun��o para consulta de dados de usu�rio j� existente
			break;
			
			case 3: 
			deletar(); //chamada de fun��o para deletar usu�rio
			break;
			
			case 4:
			printf("Obrigado por utilizar o nosso sistema!\n");
			return 0;
			break;	
			
			
			default:
			printf("Esta op��o n�o est� dispon�vel!\n ");
			system("pause");
			break;	
			//fim da sele��o do menu
			
		}
	
		
	}
}
