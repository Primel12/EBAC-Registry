#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings (banco de dados/armazenamento de cadastros)

int registry() //funcao fora da main para ganhar maior performance (programa +leve) ; cadastrar o usuário no sistema
{
	//início da criação de variáveis/string
	char note[100]; //numeração 100 é aleatório, representa o maximo de variáveis
	char cpf[100];
	char name[100];
	char surname[100];
	char function[100];
	//final da criação de variáveis/string
	
	printf("Enter the CPF to be registered: "); //coletando o CPF do usuário
	scanf("%s",cpf); //%s refere-se a string (conjunto de variáveis)
	
	strcpy(note, cpf); // Nome do arquivo.Responsável por copiar os valores da string
	
	FILE *file; //cria o arquivo;
	file = fopen(note,"W"); //abrir o arquivo, sendo arquivo novo (write)
	fclose(file);//fecha o arquivo
	
	file = fopen(note,"a"); //abrir o arquivo para atualização (a)
	fprintf(file,cpf); //incluindo o CPF do usuário
	fclose(file); //fecha o arquivo
		
	file = fopen(note,"a"); //abrir o arquivo para atualização (a)
	fprintf(file,","); //incluindo a vírgula (,)
	fclose(file); //fecha o arquivo
	
	printf("Enter the name to be registered: "); //coletando o nome do usuário
	scanf("%s",name); //%s refere-se a string (conjunto de variáveis)
	
	file = fopen(note,"a"); //abrir o arquivo para atualização (a)
	fprintf(file,name); //incluindo o nome do usuário
	fclose(file); //fecha o arquivo
	
	file = fopen(note,"a"); //abrir o arquivo para atualização (a)
	fprintf(file,","); //incluindo a vírgula (,)
	fclose(file); //fecha o arquivo
	
	printf("Enter the surname to be registered: "); //coletando o sobrenome do usuário
	scanf("%s",surname); //%s refere-se a string (conjunto de variáveis)
	
	file = fopen(note,"a"); //abrir o arquivo para atualização (a)
	fprintf(file,surname); //incluindo o sobrenome do usuário
	fclose(file); //fecha o arquivo
	
	file = fopen(note,"a"); //abrir o arquivo para atualização (a)
	fprintf(file,","); //incluindo a vírgula (,)
	fclose(file); //fecha o arquivo
	
	printf("Enter the function to be registry: "); //coletando a função do usuário
	scanf("%s",function); //%s refere-se a string (conjunto de variáveis)
	
	file = fopen(note,"a"); //abrir o arquivo para atualização (a)
	fprintf(file,function); //incluindo a função do usuário
	fclose(file);
	
	system("pause"); //o sistema pausa aguardando o próximo comando
	
}

int consult() //consultar o usuário no sistema
{
	setlocale(LC_ALL,"English"); //Definindo a linguagem
	
	//início das variáveis/string que serão buscadas
	char cpf[100];
	char content[100];
	//final das variáveis/string
	
	printf("Enter the CPF to be consulted: "); //coletando o CPF do usuário
	scanf("%s",cpf); //%s refere-se a string (conjunto de variáveis)
	
	FILE *file; //busca a pasta/arquivo já criado
	file = fopen(cpf,"r"); //abrir o arquivo para leitura r = reading
	
	if(file==NULL) //se não existir o arquivo procurado (nulo) == usado para comparação
	{
		printf("Content not found.\n"); //mensagem para usuário
		printf("\n\n"); //espaço
	}
	
	while(fgets(content,100,file) !=NULL) //enquanto busca o conteúdo, em todos os 100 arquivos (maximo) != diferente de nulo
	{
		printf("\nThis is the information found: "); //mensagem para usuário
		printf("%s",content); //mostra o resultado da busca
		printf("\n\n"); //espaço
	}  	
	
	system("pause"); //o sistema pausa aguardando o próximo comando	
}

int delete() //deletar o usuário no sistema
{
	//início das variáveis/string que serão buscadas
	char cpf[100];
	//final das variáveis/string
	
	printf("Enter the CPF to be deleted: "); //coletando o CPF do usuário
	scanf("%s",cpf); //varrendo/pesquisando os dados - %s refere-se a string (conjunto de variáveis)
	
	remove(cpf); //função para deletar o dado escolhido
	
	FILE *file; //busca a pasta/arquivo já criado
	file = fopen(cpf,"r"); //abrir o arquivo para leitura r = reading
	
	if(file==NULL) //se não existir o arquivo procurado (nulo) == usado para comparação
	{
		printf("The user doesn't be registered.\n"); //mensagem para o usuário
		printf("\n\n"); //espaço
		system("pause"); //o sistema pausa aguardando o próximo comando	
	}
	
	while(fgets(cpf,100,file) !=NULL)
	{
		printf("\nSuccessfully deleted file! "); //mensagem para o usuário
		printf("\n\n"); //espaço
		system("pause"); //o sistema pausa aguardando o próximo comando	
	}  	
		
}
	
int main () //função principal - criação do menu
{
	int option=0;	//Definindo as variáveis - atribuição
	int repeat=1;
	
	for(repeat=1;repeat=1;) //definindo laço
	{	
	
		system("cls"); //função limpar a tela
		
		setlocale(LC_ALL,"English"); //definindo a linguagem
	
		printf("#EBAC Registry#\n\n"); //início do menu
		printf("Choose the option: \n\n");
		printf("\t1 - Registration of names;\n");
		printf("\t2 - Consult names;\n");
		printf("\t3 - Delete names.\n"); 
		printf("\t4 - Exit the system.\n\n");
		printf("Choose your option:");//fim do menu
	
		scanf("%d", &option); //armazenando a escolha do usuário - pausa o programa
	
		system("cls"); //função limpar a tela
	
	switch(option) //início da seleção do menu 
	{
		case 1: //de acordo com numeração do menu
		registry(); //chamando a função
		break; //quebra de página. aguardando novo comando
		
		case 2: //de acordo com numeração do menu
		consult(); //chamando a função
		break; //quebra de página. aguardando novo comando
		
		case 3: //de acordo com numeração do menu
		delete(); //chamando a função
		break; //quebra de página. aguardando novo comando
		
		case 4: //de acordo com numeração do menu
		printf("Thank you for enjoy the system!\n"); //chamando a função
		return 0;
		break; //quebra de página. aguardando novo comando
		
		default: //não tem no menu
		printf("Unavaiable choice.\n"); //mensagem para o usuário
		system("pause"); //pausa na escolha do usuário	
		break; //quebra de página. aguardando novo comando
		//fim da selação
	}
	}
}
