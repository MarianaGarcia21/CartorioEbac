#include <stdio.h>// biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca das strings

int registro () // Fun��o responsavel por cadastrar o usu�rio
{  
    //in�cio das vari�veis/strings       
    char arquivo[40];
    char cpf[40]; //char � a variavel character que vai receber as informa��es de cadastro
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o das vari�veis/string
            
    printf("Digite o cpf a ser cadastrado:"); //coletando as informa��es do usu�rio
    scanf("%s", cpf); //%s refere-se as string
            
	strcpy(arquivo, cpf); // fun��o criada pra armazenar/copiar o numero das strings
            
    FILE *file; //dar o comando para criar o arquivo
    file = fopen(arquivo, "w");  //cria o arquivo no sistema, e o "W" significa escrever
    fprintf(file,cpf); //salvando a informa��o no arquivo = valor da vari�vel
    fclose(file); //fechando o arquivo
            
    file = fopen (arquivo,"a");
    fprintf (file, ",");
    fclose(file);
            
    printf ("Digite o nome a ser cadastrado:");
    scanf ("%s", nome);
            
    file = fopen (arquivo,"a"); //abre o arquivo, e a letra A � pq nao vai criar um arquivo novo, apenas atualizar
    fprintf (file, nome);
    fclose(file);
            
    file = fopen (arquivo,"a");
    fprintf (file, ",");
    fclose(file);
            
    printf("Digite o sobrenome a ser cadastrado:");
    scanf ("%s", sobrenome);
            
    file = fopen (arquivo,"a");
    fprintf (file, sobrenome);
    fclose(file);
            
    file = fopen (arquivo,"a");
    fprintf (file, ",");
    fclose(file);
            
    printf("Digite o cargo a ser cadastrado:");
    scanf ("%s", cargo);
            
    file = fopen (arquivo,"a");
    fprintf (file, cargo);
    fclose(file);
            
    system ("pause");
                       
}

int consulta() // abrir fun��o de consulta
{ 
    setlocale(LC_ALL , "portuguese");   
	     
    char cpf [40];
    char conteudo [200];
	
	printf("Digite o cpf a ser consultado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file=fopen(cpf,"r"); //r = read vai apenas ler o que j� foi salvo
	
	if (file==NULL)
	{ 
	printf ("\n Esse arquivo n�o foi encontrado.\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL) // enquanto o arquivo estiver lendo os arquivos existentes, at� que tenha algum invalido
	{
		printf("\n Essas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar() // abrir fun��o de apagar nomes
{    
    setlocale(LC_ALL , "portuguese"); //definindo a lingua e o uso de acentua��o
      
    char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s", cpf);
	
	remove (cpf); //comando de deletar o cpf
	
	FILE *file; //mandando o FILE abrir o file
	file = fopen(cpf, "r"); //dizendo para o file abrir e ler apenas o cpf
	
	printf("CPF deletado");
	
	if (file == NULL) // se o cpf digitado n�o for encontrado
	{
	 printf ("\n O usu�rio n�o se encontra no sistema.\n");
	 system ("pause");
	}
    
}

int main ()
{

	int opcao=0; // Definindo as variaveis
	
	int laco=1; //definindo a quantidade de repeti��es
	
	char senhadigitada[10]="a"; //string para cria��o de senha
	
	int comparacao; //variavel para compara��o do valor da senha
	
	printf("###cart�rio da EBAC### \n \n");
	printf("Login de Administrador/ \n \n Digite sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp (senhadigitada, "admin");
	
	if(comparacao==0)
	
		{
	
	        system("cls");
        	for(laco=1;laco=1;)  //repetir sempre
     	 {
	
          
	        system ("cls");//apagar tela
	    
	        setlocale(LC_ALL , "portuguese"); // definindo a lingua e o uso de acentua��o
	 
	        printf ("###cart�rio da EBAC### \n \n"); // inicio do Menu
            printf ("Escolha a op��o desejada do menu: \n \n");
	        printf ("\t1- Registrar nomes \n");
	        printf ("\t2- Consultar nomes \n");
	        printf ("\t3- Deletar nomes \n\n");
	        printf(" \t4- Sair do Sistema \n \n");
	        printf(" Op��o:"); // Final do Menu
	 
	 
	        scanf("%d", &opcao); //esperar tomada de decis�o
	 
	        system ("cls"); // limpar tela
	  
	        switch(opcao) //inicio da sele��o do menu
	       {
	          	case 1:
	    		registro(); //chamar a fun��o registro
	 	        break;
	 	        
	 	        case 2:
			     consulta(); //chamar a fun��o consulta
	 	         break;
	 	    
			    case 3:
			 	deletar(); //chamar a fun��o deletar
	 	        break;
	 	        
	 	         case 4:
			     printf("Obrigado por utilizar o sistema \n");
			     return 0;
			     break; 
			     
	 	        default: //quando n�o houver op�ao disponivel
	 	     	printf ("Essa op��o n�o est� disponivel! \n");
	 	        system("pause");
	 	        
	    	}
     	}
     	
    }  
    else 
     printf("Senha incorreta!");
     
} 
