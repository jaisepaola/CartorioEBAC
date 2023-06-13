#include <stdio.h> //biblioteca de comunicação de usuário
#include <stdlib.h> //biblioteca de alocação de espaços de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro () //função responsável por cadastrar os usuários no sistema

{
	//início criação de variáveis/string
	char arquivo[40]; 
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações de usuário
	scanf("%s", cpf); //%s refere-se o a string- salvar
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //criando o arquivo e o "w" significa escrever
	fprintf (file, cpf); //salvo o valor da variavel dentro
	fclose(file); //fecho o arquivo
	
	file= fopen (arquivo, "a"); //o a significa atualizar
	fprintf(file, ", ");
	fclose (file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf ("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file= fopen (arquivo, "a");
	fprintf(file, " ");
	fclose (file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf ("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file= fopen (arquivo, "a");
	fprintf(file, ", ");
	fclose (file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf ("%s",cargo);
	
	file= fopen(arquivo, "a");
	fprintf (file,cargo);
	fclose(file);
	
	system ("pause");
}

int consulta ()
{	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL )
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	

	system ("pause");
		
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s",&cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não encontrado no sistema!\n");
		system("pause");
		fclose (file);
		
	}
	else
	{
		fclose(file);
		remove (cpf);
		printf ("Usuário deletado! \n");
		system ("pause");
		
	}
	}
	
int main ()
	{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf ("Escolha a opção desejada do menu: \n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("\t4 - Sair do sistema \n\n");
		printf ("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
		system ("cls");
	
	
		switch (opcao)
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf ("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não esta disponível!\n");
			system("pause");
			break;
			
		}
	}
}
