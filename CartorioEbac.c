#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocaçõe de texto por região
#include<string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários
{
	
	setlocale(LC_ALL, "Portuguese");
	
	//início da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de criação das variáveis
	
	printf("Digite apenas os números do CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se à strings, para salvamento de string
	
	strcpy(arquivo, cpf); //este comando copia os valores de cpf para arquivo
	
	FILE *file; //cria o arquivo no banco de dados, FILE acessa o banco, *file abre o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo w de write
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //a de atualizar, comando para abrir e atualizar arquivo
	fprintf(file, ", "); //inclui uma vírgula e um espaço após a varável salva, para melhorar visualização durante consulta
	fclose(file); //fecha o arquivo após atualização
	
	printf("Digite o nome a ser cadastrado: "); //solicita digitação do nome que será salvo na variável nome
	scanf("%s",nome); //carrega o nome digitado pelo usuário, no formato de string (%s), na variável nome
	
	file = fopen(arquivo,"a"); //abre o arquivo para ser atualizado
	fprintf(file,nome); //salva o nome digitado na variável nome
	fclose(file); //fecha o arquivo após alteração
	
	file = fopen(arquivo, "a"); //a de atualizar, comando para abrir e atualizar arquivo
	fprintf(file, ", ");//inclui uma vírgula e um espaço após a varável salva, para melhorar visualização durante consulta
	fclose(file); //fecha o arquivo após atualização
	
	printf("Digite o sobrenome a ser cadastrado: "); //solicita digitação do sobrenome para ser salvo na variável sobrenome
	scanf("%s",sobrenome); //lê e carrega o sobrenome digitado na variável sobrenome, no modo string (%s)
	
	file= fopen(arquivo, "a"); //abre o arquivo que está sendo cadastrado para alteração da variável sobenome
	fprintf(file,sobrenome); //salva o sobrenome digitado na variável sobrenome
	fclose(file); //fecha o arquivo atualizado
	
	file = fopen(arquivo, "a"); //a de atualizar, comando para abrir e atualizar arquivo
	fprintf(file, ", "); //inclui uma vírgula e um espaço após a varável salva, para melhorar visualização durante consulta
	fclose(file); //fecha o arquivo após atualização
	
	printf("Digite o cargo a ser cadastrado: "); //solicita digitação do cargo da pessoa a ser cadastrada
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a"); //a de atualizar, comando para abrir e atualizar arquivo
	fprintf(file,cargo); //inclui uma vírgula e um espaço após a varável salva, para melhorar visualização durante consulta
	fclose(file); //fecha o arquivo após atualização
	
	printf("Cadastro realizado com sucesso!\n"); //mostra que a conclusão do cadastro foi realizada com sucesso
	
	system("pause"); //pausa a execução do algoritmo para possibilitar visualização da última mensagem
	
	
}

int consulta() //criação da função Consulta dos dados cadastrados 
{
	setlocale(LC_ALL, "Portuguese"); //permite utilização do português na aplicação
	//início da inclusão das variáveis
	char cpf[40];
	char conteudo[200];
	// fim da declaração das variáveis
	
	printf("Digite apenas os números do CPF a ser consultado: "); //solicita digitação do cpf para cadastramento
	scanf("%s",cpf); //armazena o valor digitado na variável cpf
	
	FILE *file; //FILE acessa o banco de dados, *file abre o arquivo
	file = fopen(cpf,"r"); // abre e lê (r de read)
	
	if(file == NULL)
	{
		printf("Não foi possível localizar este CPF.\n"); //comando if para validar e informar caso o cpf digitado esteja incorreto ou não integre o banco de dados
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas são as informações do usuário: "); //caso o cpf seja encontrado, os dados cadastrados serão impressos no prompt
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause"); //pausa o sistema para leitura dos dados pelo usuário
	fclose(file);
	
}

int deletar() //criação da função para deletar dados cadastrados
{
	char cpf[40]; //declarando a variável cpf, tipo char, com 40 caracteres
	printf("Digite apenas os números do CPF a ser deletado: "); //solicitação para digitar o cpf a ser deletado
	scanf("%s",cpf); //leitura do valor digitado, no formato string (série de caracteres) e armazenamento na variável cpf desta função
			
	remove(cpf); //comando já existente nas bibliotecas acionadas, para deletar arquivo.	
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf, "r"); //abre e lê o arquivo. Pela ordem de execução das linhas, provavelmente o arquivo já terá sido deletado e entrará na situação null a seguir:
	
	
	if(file == NULL)
	{
		printf("Usuário não encontrado no sistema ou deletado.\n");		
		system("pause");
	}	
	
}

int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
	
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("\t###  Cartório da EBAC  ###\n\n"); //início do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //limpeza de tela após seleção pelo usuário
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada de função para registro de novo usuário
			break;
			
			case 2:
			consulta(); //chamada de função para consulta de dados de usuário já existente
			break;
			
			case 3: 
			deletar(); //chamada de função para deletar usuário
			break;
			
			case 4:
			printf("Obrigado por utilizar o nosso sistema!\n");
			return 0;
			break;	
			
			
			default:
			printf("Esta opção não está disponível!\n ");
			system("pause");
			break;	
			//fim da seleção do menu
			
		}
	
		
	}
}
