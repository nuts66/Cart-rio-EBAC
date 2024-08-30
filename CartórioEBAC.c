#include <stdio.h> //biblioteca de comnica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> // biblioteca de aloca��o de texto por regi�o 
#include <string.h> //faz as string (conjunto de vari�veis) funcionarem 

int registro ()
{ char arquivo [40]; //� a vari�vel "arquivo" onde iremos salvar os nomes
  char cpf [40]; //usamos vari�vel tipo char pq s�o strings (armazenamos v�rios algarismos nela)
  char nome [40]; //nesses tipos de vari�veis n�o precisamos igualar o valor a zero pq o sistema faz isso sozinho
  char sobrenome [	40];
  char cargo [40];
  
  printf("Voc� escolheu registrar nomes!!\n\n");
  
  FILE *file;//usamos "FILE" para chamar esta fun��o do sistema arquivos, e *file para criar um arquivo 
 
  printf("Digite o CPF a ser cadastrado: ");
  
  scanf("%s", cpf); //com o scanf salvamos informa��es dadas pelo usu�rio , colocamos o s pq salvamos em uma string e "cpf" pois � a vari�vel em que salvamos
  strcpy(arquivo, cpf); //uma fun��o para copiarmos o valor da vari�vel "cpf" para a "arquivo"
  file = fopen (arquivo, "w");  //aqui dizemos que ese arquivo que criamos � a nossa string arquivo (7), e o "w" pq criamos o arquivo
  fprintf(file, "CPF:");
  fprintf (file, cpf); //usamos fprintf para escrever algo no arquivo, 1� "file" para onde vai o dado, 2� "cpf" (vari�vel de onde veio o dado)
  fclose(file); //fecha o arquivo 
  
  file = fopen(arquivo, "a"); //abrir o arquivo. utilizamos o "a pois � um arquivo q j� existe e vamos atualiz�lo
  fprintf (file, "\n"); //com o fprintf conseguimos escrever algo no arquivo, neste caso foi uma v�rgula
  fclose(file);
  
  printf("Digite o nome a ser cadastrado: ");
  scanf("%s", nome);
  file = fopen (arquivo, "a");
  fprintf(file, "Nome:");
  fprintf(file, nome);
  fclose(file);
  
  file = fopen(arquivo, "a");
  fprintf(file,"\n");
  fclose(file);
  
  printf("Digite o sobrenome a ser cadastrado: ");
  scanf("%s", sobrenome);
  file = fopen(arquivo, "a");
  fprintf(file, "Sobrenome:");
  fprintf(file, sobrenome);
  fclose(file);
  
  file = fopen(arquivo, "a");
  fprintf(file, "\n");
  fclose(file);
  
  printf("Digite o cargo do nome a ser cadastrado: ");
  scanf("%s", cargo);
  file = fopen(arquivo, "a");
  fprintf(file, "Cargo:");
  fprintf(file, cargo);
  fclose(file);
  
  file = fopen(arquivo, "a");
  fprintf(file,"\n");
  fclose(file);
  
  system("pause");
  
  }

int consulta()
{ 
  char cpf[40];
  char conteudo[200];
  
  setlocale(LC_ALL, "Portuguese");
  
  printf("Digite o CPF a ser consultado: ");
  scanf("%s", cpf);
  printf("\n");
  
  FILE *file;
  file = fopen(cpf, "r");//o sistema vai abrir e ler o arquivo
  
  if (file == NULL) // colocamos dois = pois � uma compara��o
  {
  	printf("\n\nCPF n�o encontrado.\n\n");
  }
  while(fgets(conteudo, 200, file) !=NULL) //"enquanto" ele tiver buscando informa��es no arquivo e tiver ele vai trazendo, se n tiver mais =nulo
  {
	 printf("%s", conteudo);
	 printf("\n");
  }
  fclose(file);// fechar o arquivo
  
  system("pause");
}

int deletar()
{ 
  char cpf[40];
  
  setlocale(LC_ALL, "Portuguese");
  
  printf("Digite o CPF que deseja deletar:");
  scanf("%s", cpf);
  
  remove(cpf);//comando para deletar
  
  printf("Usu�rio deletado com sucesso\n\n");
  system("pause");
  
  FILE *file;//aqui pedimos para acessar o arquivo
  file = fopen(cpf,"r");//e aqui para abrir o arquivo e ler
  
  if(file == NULL) // "if" = "se", "file" = "arquivo" for igual a "NULL" ou seja inexistente. Usamos dois iguais pq � uma compara��o
  {
  	printf("Usu�rio n�o se encontra no sistema.\n\n");
  	system("pause");
  }
  
  
}
int main() // fun��o 
{ 
    int opcao =0; // temos que colocar o 0 para n�o ficar um valor vari�vel de mem�ria, definindo as vari�veis  
    
    
    int laco =1; //fun��o de repeti��o, para o sistema voltar ao menu ap�s a execu��o de umas das tr�s fun��es
    for(laco=1;laco=1;)
   { 
        system ("cls"); // comando para limpar a tela
        
        setlocale(LC_ALL, "Portuguese");//definindo a linguagem, importante para o sistema rodar acentos e cedilhas
		 
        printf("Cart�rio da EBAC\n\n");
        printf("Selecione abaixo a op��o desejada no menu:\n\n");
        printf("\t\t1 Adicionar nomes\n");
        printf("\t\t2 Consultar nomes\n");
        printf("\t\t3 Deletar nomes\n");
		printf("\t\t4 Sair do sistema\n\n\n");	   
        printf("Software pelo aluno da EBAC:\n Douglas Henning\n tenha um bom dia\n");
        printf("Op��o:");
	
        scanf("%d", &opcao); // o scanf tem como fun��o escanear o que o usu�rio digita, o %d serve para armazenarmo uma vari�vel do tipo inteira
	
        system("cls"); // comando para o sistema fechar o menu ap�s o usu�rio esoolher uma op��o
        
        switch (opcao) //substitui o if
        {
        	case 1: // basicamente ele ta falando "caso a op�ao for 1..." a� as instru��es
            registro();
        	break; //aqui ele fecha as instru��es que devem ser realizadas caso o a op�ao for 1, para isso que serve o break
        	
			case 2:
			consulta();	
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        case 4:
	        printf("Valeu por utilizar o sistema!! :)\n\n\n");
	        return 0; //retornamos o valor a zero, assim quebrando todos os la�os e fun��es e saindo do sistema
	        break;
	        
				
	        default:// "se for diferente das op��es apresentadas acima, ..."
	        printf("N�o temos essa op��o, muito burro\n");
	        system ("pause");
	        break;
		}
		
	 
    
}
	
}

