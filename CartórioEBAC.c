#include <stdio.h> //biblioteca de comnicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> // biblioteca de alocação de texto por região 
#include <string.h> //faz as string (conjunto de variáveis) funcionarem 

int registro ()
{ char arquivo [40]; //é a variável "arquivo" onde iremos salvar os nomes
  char cpf [40]; //usamos variável tipo char pq são strings (armazenamos vários algarismos nela)
  char nome [40]; //nesses tipos de variáveis não precisamos igualar o valor a zero pq o sistema faz isso sozinho
  char sobrenome [	40];
  char cargo [40];
  
  printf("Você escolheu registrar nomes!!\n\n");
  
  FILE *file;//usamos "FILE" para chamar esta função do sistema arquivos, e *file para criar um arquivo 
 
  printf("Digite o CPF a ser cadastrado: ");
  
  scanf("%s", cpf); //com o scanf salvamos informações dadas pelo usuário , colocamos o s pq salvamos em uma string e "cpf" pois é a variável em que salvamos
  strcpy(arquivo, cpf); //uma função para copiarmos o valor da variável "cpf" para a "arquivo"
  file = fopen (arquivo, "w");  //aqui dizemos que ese arquivo que criamos é a nossa string arquivo (7), e o "w" pq criamos o arquivo
  fprintf(file, "CPF:");
  fprintf (file, cpf); //usamos fprintf para escrever algo no arquivo, 1° "file" para onde vai o dado, 2° "cpf" (variável de onde veio o dado)
  fclose(file); //fecha o arquivo 
  
  file = fopen(arquivo, "a"); //abrir o arquivo. utilizamos o "a pois é um arquivo q já existe e vamos atualizálo
  fprintf (file, "\n"); //com o fprintf conseguimos escrever algo no arquivo, neste caso foi uma vírgula
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
  
  if (file == NULL) // colocamos dois = pois é uma comparação
  {
  	printf("\n\nCPF não encontrado.\n\n");
  }
  while(fgets(conteudo, 200, file) !=NULL) //"enquanto" ele tiver buscando informações no arquivo e tiver ele vai trazendo, se n tiver mais =nulo
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
  
  printf("Usuário deletado com sucesso\n\n");
  system("pause");
  
  FILE *file;//aqui pedimos para acessar o arquivo
  file = fopen(cpf,"r");//e aqui para abrir o arquivo e ler
  
  if(file == NULL) // "if" = "se", "file" = "arquivo" for igual a "NULL" ou seja inexistente. Usamos dois iguais pq é uma comparação
  {
  	printf("Usuário não se encontra no sistema.\n\n");
  	system("pause");
  }
  
  
}
int main() // função 
{ 
    int opcao =0; // temos que colocar o 0 para não ficar um valor variável de memória, definindo as variáveis  
    
    
    int laco =1; //função de repetição, para o sistema voltar ao menu após a execução de umas das três funções
    for(laco=1;laco=1;)
   { 
        system ("cls"); // comando para limpar a tela
        
        setlocale(LC_ALL, "Portuguese");//definindo a linguagem, importante para o sistema rodar acentos e cedilhas
		 
        printf("Cartório da EBAC\n\n");
        printf("Selecione abaixo a opção desejada no menu:\n\n");
        printf("\t\t1 Adicionar nomes\n");
        printf("\t\t2 Consultar nomes\n");
        printf("\t\t3 Deletar nomes\n");
		printf("\t\t4 Sair do sistema\n\n\n");	   
        printf("Software pelo aluno da EBAC:\n Douglas Henning\n tenha um bom dia\n");
        printf("Opção:");
	
        scanf("%d", &opcao); // o scanf tem como função escanear o que o usuário digita, o %d serve para armazenarmo uma variável do tipo inteira
	
        system("cls"); // comando para o sistema fechar o menu após o usuário esoolher uma opção
        
        switch (opcao) //substitui o if
        {
        	case 1: // basicamente ele ta falando "caso a opçao for 1..." aí as instruções
            registro();
        	break; //aqui ele fecha as instruções que devem ser realizadas caso o a opçao for 1, para isso que serve o break
        	
			case 2:
			consulta();	
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        case 4:
	        printf("Valeu por utilizar o sistema!! :)\n\n\n");
	        return 0; //retornamos o valor a zero, assim quebrando todos os laços e funções e saindo do sistema
	        break;
	        
				
	        default:// "se for diferente das opções apresentadas acima, ..."
	        printf("Não temos essa opção, muito burro\n");
	        system ("pause");
	        break;
		}
		
	 
    
}
	
}

