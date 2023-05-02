#include <stdio.h>// biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca das strings

int registro () // Função responsavel por cadastrar o usuário
{  
    //início das variáveis/strings       
    char arquivo[40];
    char cpf[40]; //char é a variavel character que vai receber as informações de cadastro
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação das variáveis/string
            
    printf("Digite o cpf a ser cadastrado:"); //coletando as informações do usuário
    scanf("%s", cpf); //%s refere-se as string
            
	strcpy(arquivo, cpf); // função criada pra armazenar/copiar o numero das strings
            
    FILE *file; //dar o comando para criar o arquivo
    file = fopen(arquivo, "w");  //cria o arquivo no sistema, e o "W" significa escrever
    fprintf(file,cpf); //salvando a informação no arquivo = valor da variável
    fclose(file); //fechando o arquivo
            
    file = fopen (arquivo,"a");
    fprintf (file, ",");
    fclose(file);
            
    printf ("Digite o nome a ser cadastrado:");
    scanf ("%s", nome);
            
    file = fopen (arquivo,"a"); //abre o arquivo, e a letra A é pq nao vai criar um arquivo novo, apenas atualizar
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

int consulta() // abrir função de consulta
{ 
    setlocale(LC_ALL , "portuguese");   
	     
    char cpf [40];
    char conteudo [200];
	
	printf("Digite o cpf a ser consultado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file=fopen(cpf,"r"); //r = read vai apenas ler o que já foi salvo
	
	if (file==NULL)
	{ 
	printf ("\n Esse arquivo não foi encontrado.\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL) // enquanto o arquivo estiver lendo os arquivos existentes, até que tenha algum invalido
	{
		printf("\n Essas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar() // abrir função de apagar nomes
{    
    setlocale(LC_ALL , "portuguese"); //definindo a lingua e o uso de acentuação
      
    char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s", cpf);
	
	remove (cpf); //comando de deletar o cpf
	
	FILE *file; //mandando o FILE abrir o file
	file = fopen(cpf, "r"); //dizendo para o file abrir e ler apenas o cpf
	
	printf("CPF deletado");
	
	if (file == NULL) // se o cpf digitado não for encontrado
	{
	 printf ("\n O usuário não se encontra no sistema.\n");
	 system ("pause");
	}
    
}

int main ()
{

	int opcao=0; // Definindo as variaveis
	
	int laco=1; //definindo a quantidade de repetições
	
	char senhadigitada[10]="a"; //string para criação de senha
	
	int comparacao; //variavel para comparação do valor da senha
	
	printf("###cartório da EBAC### \n \n");
	printf("Login de Administrador/ \n \n Digite sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp (senhadigitada, "admin");
	
	if(comparacao==0)
	
		{
	
	        system("cls");
        	for(laco=1;laco=1;)  //repetir sempre
     	 {
	
          
	        system ("cls");//apagar tela
	    
	        setlocale(LC_ALL , "portuguese"); // definindo a lingua e o uso de acentuação
	 
	        printf ("###cartório da EBAC### \n \n"); // inicio do Menu
            printf ("Escolha a opção desejada do menu: \n \n");
	        printf ("\t1- Registrar nomes \n");
	        printf ("\t2- Consultar nomes \n");
	        printf ("\t3- Deletar nomes \n\n");
	        printf(" \t4- Sair do Sistema \n \n");
	        printf(" Opção:"); // Final do Menu
	 
	 
	        scanf("%d", &opcao); //esperar tomada de decisão
	 
	        system ("cls"); // limpar tela
	  
	        switch(opcao) //inicio da seleção do menu
	       {
	          	case 1:
	    		registro(); //chamar a função registro
	 	        break;
	 	        
	 	        case 2:
			     consulta(); //chamar a função consulta
	 	         break;
	 	    
			    case 3:
			 	deletar(); //chamar a função deletar
	 	        break;
	 	        
	 	         case 4:
			     printf("Obrigado por utilizar o sistema \n");
			     return 0;
			     break; 
			     
	 	        default: //quando não houver opçao disponivel
	 	     	printf ("Essa opção não está disponivel! \n");
	 	        system("pause");
	 	        
	    	}
     	}
     	
    }  
    else 
     printf("Senha incorreta!");
     
} 
