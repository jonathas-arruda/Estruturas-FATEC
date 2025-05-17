 //Código Base para o Mini-Projeto Agenda de Amigos
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
struct ficha{
	char nome[40];
	char telefone[20];
	char endereco[40];
	char email[40];
	char dataNascimento[40];	
};

int procurar(char procurado[], struct ficha vetor[], int num_fichas){
    	bool achei = false; //nao achei
			int i;
			if(num_fichas ==0) return -1;
			if(strcmp(vetor[num_fichas -1].nome, procurado) ==0){
			    return num_fichas-1;
			}else return procurar(procurado, vetor, num_fichas -1);
			
			/*for(i=0; i<num_fichas; i++)
			{
			  //Ignorando Maiusculas/Minusculas:
			  //if(strcasecmp(procurado, agenda[i].nome) == 0)
			  if(strcmp(procurado, vetor[i].nome) == 0)
			  {
			    achei = true; //achei!!
			    printf("\n\nO telefone de %s é %s\n",
			      vetor[i].nome, vetor[i].telefone);
			    //depois de achar nao preciso procurar mais
			    return i;
			  }
			}
			if(achei == false)
			{
			 return -1;
			}*/
}

int main()
{
	struct ficha agenda[100];
	int fichas_existentes = 0, proxima = 0;
	char opcao[10]="0"; 
        setlocale(LC_ALL, "Portuguese");
	while(opcao[0] != '6')
	{
		printf("\nEntre com a opção desejada:\n");
		printf("\n1) Inserir ficha:");
		printf("\n2) Procurar por nome:");
		printf("\n3) Listar toda a base:");
		printf("\n4) Excluir por nome:");
		printf("\n5) Alterar por nome:");
		printf("\n6) Sair\n\n");
		gets(opcao);
		
		if(opcao[0] == '1') //inserir
		{
			printf("\nEntre com um nome:");
			gets(agenda[proxima].nome);
			printf("\nEntre com um telefone:");
			gets(agenda[proxima].telefone);
			printf("\nEntre com um endereço:");
			gets(agenda[proxima].endereco);
			printf("\nEntre com um email:");
			gets(agenda[proxima].email);
			printf("\nEntre com uma data de nascimento:");
			gets(agenda[proxima].dataNascimento);
			fichas_existentes++;
			proxima++;
		}
		if(opcao[0] == '2') //procurar
		{
			char procurado[40];
			printf("\nEntre com o nome procurado:");
			gets(procurado);
			int resp = procurar(procurado,agenda, fichas_existentes);
			if(resp == -1){
			      printf("\n\nNome não encontrado\n");
			}else {
			       printf("\n\nO telefone de %s é %s, com endereço: %s, email: %s, data de nascimento: %s . \n",
			      agenda[resp].nome, agenda[resp].telefone, agenda[resp].endereco, agenda[resp].email, agenda[resp].dataNascimento);
			    //depois de achar nao preciso procurar mais
			}
		
		}
		if(opcao[0] == '3') //listar tudo
		{
			printf("\n\n");
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
			    printf("O telefone de %s é %s\n",
			      agenda[i].nome, agenda[i].telefone);
			}
			if(fichas_existentes == 0)
				printf("A base de dados está vazia!\n");
		}
		if(opcao[0] == '4') //excluir	
		{
			char procurado[40];
			printf("\nEntre com o nome que sera excluído:");
			gets(procurado);
			bool achei = false; //nao achei
			int i;
			int indiceEncontrado = procurar(procurado,agenda, fichas_existentes);
			if(indiceEncontrado != -1){
			achei = true; //achei!!
			agenda[indiceEncontrado] = agenda[fichas_existentes-1];
			fichas_existentes--;
			}
			if(achei == false)
			{
			  printf("\n\nNome não encontrado\n");
			}
			
			/*
			for(i=0; i<fichas_existentes; i++)
			{
			  //Ignorando Maiusculas/Minusculas:
			  //if(strcasecmp(procurado, agenda[i].nome) == 0)
			  if(strcmp(procurado, agenda[i].nome) == 0)
			  {
			    achei = true; //achei!!
			    printf("\n\nO telefone de %s, que é %s, será removido\n", agenda[i].nome, agenda[i].telefone);
			    
			    int j;
			    for(j=i+1; j<fichas_existentes; j++)
			    {
					agenda[j-1] = agenda[j];
			    }
			    fichas_existentes--;
			    proxima--;
			    break;
			  }
			}
			if(achei == false)
			{
			  printf("\n\nNome não encontrado\n");
			}*/
		}
		if(opcao[0] == '5') //Alteração
		{
		    struct ficha auxiliar;
			char procurado[40];
			printf("\nEntre com o nome procurado:");
			gets(procurado);
			int indiceEncontrado = procurar(procurado,agenda, fichas_existentes);
			if(indiceEncontrado == -1){
			      printf("\n\nNome não encontrado\n");
			}else {
		        printf("\n\nO telefone de %s é %s, com endereço: %s, email: %s, data de nascimento: %s . \n",
		        agenda[indiceEncontrado].nome, agenda[indiceEncontrado].telefone, agenda[indiceEncontrado].endereco, agenda[indiceEncontrado].email, agenda[indiceEncontrado].dataNascimento);
		    
			   	printf("\nEntre com um novo nome:");
    			gets(auxiliar.nome);
    			printf("\nEntre com um novo telefone:");
    			gets(auxiliar.telefone);
    			printf("\nEntre com um novo endereço:");
    			gets(auxiliar.endereco);
    			printf("\nEntre com um novo email:");
    			gets(auxiliar.email);
    			printf("\nEntre com uma nova data de nascimento:");
    			gets(auxiliar.dataNascimento);
    		
    		    agenda[indiceEncontrado] = auxiliar;
    		
    		    printf("\n\nO telefone de %s é %s, com endereço: %s, email: %s, data de nascimento: %s . \n",
		        agenda[indiceEncontrado].nome, agenda[indiceEncontrado].telefone, agenda[indiceEncontrado].endereco, agenda[indiceEncontrado].email, agenda[indiceEncontrado].dataNascimento);
			}
			
		}
	}
	return 0;
}
