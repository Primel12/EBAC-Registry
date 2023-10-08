#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings (banco de dados/armazenamento de cadastros)

int registry() //funcao fora da main para ganhar maior performance (programa +leve) ; cadastrar o usu�rio no sistema
{
	//in�cio da cria��o de vari�veis/string
	char note[100]; //numera��o 100 � aleat�rio, representa o maximo de vari�veis
	char cpf[100];
	char name[100];
	char surname[100];
	char function[100];
	//final da cria��o de vari�veis/string
	
	printf("Enter the CPF to be registered: "); //coletando o CPF do usu�rio
	scanf("%s",cpf); //%s refere-se a string (conjunto de vari�veis)
	
	strcpy(note, cpf); // Nome do arquivo.Respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo;
	file = fopen(note,"W"); //abrir o arquivo, sendo arquivo novo (write)
	fclose(file);//fecha o arquivo
	
	file = fopen(note,"a"); //abrir o arquivo para atualiza��o (a)
	fprintf(file,cpf); //incluindo o CPF do usu�rio
	fclose(file); //fecha o arquivo
		
	file = fopen(note,"a"); //abrir o arquivo para atualiza��o (a)
	fprintf(file,","); //incluindo a v�rgula (,)
	fclose(file); //fecha o arquivo
	
	printf("Enter the name to be registered: "); //coletando o nome do usu�rio
	scanf("%s",name); //%s refere-se a string (conjunto de vari�veis)
	
	file = fopen(note,"a"); //abrir o arquivo para atualiza��o (a)
	fprintf(file,name); //incluindo o nome do usu�rio
	fclose(file); //fecha o arquivo
	
	file = fopen(note,"a"); //abrir o arquivo para atualiza��o (a)
	fprintf(file,","); //incluindo a v�rgula (,)
	fclose(file); //fecha o arquivo
	
	printf("Enter the surname to be registered: "); //coletando o sobrenome do usu�rio
	scanf("%s",surname); //%s refere-se a string (conjunto de vari�veis)
	
	file = fopen(note,"a"); //abrir o arquivo para atualiza��o (a)
	fprintf(file,surname); //incluindo o sobrenome do usu�rio
	fclose(file); //fecha o arquivo
	
	file = fopen(note,"a"); //abrir o arquivo para atualiza��o (a)
	fprintf(file,","); //incluindo a v�rgula (,)
	fclose(file); //fecha o arquivo
	
	printf("Enter the function to be registry: "); //coletando a fun��o do usu�rio
	scanf("%s",function); //%s refere-se a string (conjunto de vari�veis)
	
	file = fopen(note,"a"); //abrir o arquivo para atualiza��o (a)
	fprintf(file,function); //incluindo a fun��o do usu�rio
	fclose(file);
	
	system("pause"); //o sistema pausa aguardando o pr�ximo comando
	
}

int consult() //consultar o usu�rio no sistema
{
	setlocale(LC_ALL,"English"); //Definindo a linguagem
	
	//in�cio das vari�veis/string que ser�o buscadas
	char cpf[100];
	char content[100];
	//final das vari�veis/string
	
	printf("Enter the CPF to be consulted: "); //coletando o CPF do usu�rio
	scanf("%s",cpf); //%s refere-se a string (conjunto de vari�veis)
	
	FILE *file; //busca a pasta/arquivo j� criado
	file = fopen(cpf,"r"); //abrir o arquivo para leitura r = reading
	
	if(file==NULL) //se n�o existir o arquivo procurado (nulo) == usado para compara��o
	{
		printf("Content not found.\n"); //mensagem para usu�rio
		printf("\n\n"); //espa�o
	}
	
	while(fgets(content,100,file) !=NULL) //enquanto busca o conte�do, em todos os 100 arquivos (maximo) != diferente de nulo
	{
		printf("\nThis is the information found: "); //mensagem para usu�rio
		printf("%s",content); //mostra o resultado da busca
		printf("\n\n"); //espa�o
	}  	
	
	system("pause"); //o sistema pausa aguardando o pr�ximo comando	
}

int delete() //deletar o usu�rio no sistema
{
	//in�cio das vari�veis/string que ser�o buscadas
	char cpf[100];
	//final das vari�veis/string
	
	printf("Enter the CPF to be deleted: "); //coletando o CPF do usu�rio
	scanf("%s",cpf); //varrendo/pesquisando os dados - %s refere-se a string (conjunto de vari�veis)
	
	remove(cpf); //fun��o para deletar o dado escolhido
	
	FILE *file; //busca a pasta/arquivo j� criado
	file = fopen(cpf,"r"); //abrir o arquivo para leitura r = reading
	
	if(file==NULL) //se n�o existir o arquivo procurado (nulo) == usado para compara��o
	{
		printf("The user doesn't be registered.\n"); //mensagem para o usu�rio
		printf("\n\n"); //espa�o
		system("pause"); //o sistema pausa aguardando o pr�ximo comando	
	}
	
	while(fgets(cpf,100,file) !=NULL)
	{
		printf("\nSuccessfully deleted file! "); //mensagem para o usu�rio
		printf("\n\n"); //espa�o
		system("pause"); //o sistema pausa aguardando o pr�ximo comando	
	}  	
		
}
	
int main () //fun��o principal - cria��o do menu
{
	int option=0;	//Definindo as vari�veis - atribui��o
	int repeat=1;
	
	for(repeat=1;repeat=1;) //definindo la�o
	{	
	
		system("cls"); //fun��o limpar a tela
		
		setlocale(LC_ALL,"English"); //definindo a linguagem
	
		printf("#EBAC Registry#\n\n"); //in�cio do menu
		printf("Choose the option: \n\n");
		printf("\t1 - Registration of names;\n");
		printf("\t2 - Consult names;\n");
		printf("\t3 - Delete names.\n"); 
		printf("\t4 - Exit the system.\n\n");
		printf("Choose your option:");//fim do menu
	
		scanf("%d", &option); //armazenando a escolha do usu�rio - pausa o programa
	
		system("cls"); //fun��o limpar a tela
	
	switch(option) //in�cio da sele��o do menu 
	{
		case 1: //de acordo com numera��o do menu
		registry(); //chamando a fun��o
		break; //quebra de p�gina. aguardando novo comando
		
		case 2: //de acordo com numera��o do menu
		consult(); //chamando a fun��o
		break; //quebra de p�gina. aguardando novo comando
		
		case 3: //de acordo com numera��o do menu
		delete(); //chamando a fun��o
		break; //quebra de p�gina. aguardando novo comando
		
		case 4: //de acordo com numera��o do menu
		printf("Thank you for enjoy the system!\n"); //chamando a fun��o
		return 0;
		break; //quebra de p�gina. aguardando novo comando
		
		default: //n�o tem no menu
		printf("Unavaiable choice.\n"); //mensagem para o usu�rio
		system("pause"); //pausa na escolha do usu�rio	
		break; //quebra de p�gina. aguardando novo comando
		//fim da sela��o
	}
	}
}
