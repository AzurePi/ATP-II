#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista{
	char palavra[50];
	struct lista *prox;
}Lista;

Lista *h = NULL; //endereço do começo da lista

void inserir(); //insere a palavra lida em ordem alfabética
void remover(); //remove a palavra lida

int main(){
	int N, M;
	int i, op;
	
	scanf("%d %d", &N, &M);
	
	for (i = 0; i<N; i++)
		inserir();
	
	for(i = 0; i<M; i++)
	{
		scanf("%d", &op);
		
		if(op == 0)
			remover();
		else
			inserir();
	}

	return 0;
}

//insere a palavra lida em ordem alfabética
void inserir(){
	Lista *novo, *aux = h, *prev = NULL;
	novo = malloc(sizeof(Lista));
	
	scanf(" %s", novo->palavra);
	
	if(h == NULL) //se a lista está vazia
	{
		novo->prox = NULL;
		h = novo;	
		return;
	}
	//lista não vazia
	
	
	while(aux->prox != NULL && strcmp(aux->palavra, novo->palavra) < 0)
	{
		if(strcmp(novo->palavra, aux->palavra) == 0)
			return;
		prev = aux;
		aux = aux->prox;
	}
	
	//se novo está depois de aux
	if(strcmp(novo->palavra, aux->palavra) > 0)
	{
		if(aux->prox == NULL) //e estamos no final da lista
		{
			aux->prox = novo;
			novo->prox = NULL;
			return;
		}
		//mas não estamos no final da lista
		
		novo->prox = aux->prox;
		aux->prox = novo;
		return;
	}
	
	//se novo está antes de aux
	if(strcmp(novo->palavra, aux->palavra) < 0)
	{
		if(aux == h) //e estamos no começo da lista
		{
			novo->prox = h;
			h = novo;
			return;
		}
		// mas não estamos no começo da lista
		
		prev->prox = novo;
		novo->prox = aux;
		return;
	}
}

//remove a palavra lida
void remover(){
	Lista *aux = h, *prev = NULL;
	char pal[50];
	
	if(h == NULL) //se a lista está vazia
	{
		printf("NULL\n");
		return;
	}
	//do contrário
	scanf(" %s", pal);
	
	//procura a palavra na lista
	while(strcmp(aux->palavra, pal) != 0 && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;
	}

	if(strcmp(aux->palavra, pal) == 0) //se achou a palavra
	{
		if(aux == h) //se estamos no começo da lista
		{
			if(aux->prox == NULL) //e no fim da lista
				h = NULL; //a lista agora está vazia
			else //mas há elementos depois
				h = aux->prox;
		}else //se não está no começo
		{
			if(aux->prox == NULL) //e está no final
				prev->prox = NULL;
			else //estamos no meio da lista
				prev->prox = aux->prox;
		}		
	}

	if(h != NULL) //se a lista não está vazia
	{
		aux = h; //volta ao começo
		do //imprime as palavras
		{
			printf("%s ", aux->palavra);
			aux = aux->prox;
		}while(aux != NULL);
		printf("\n");
	}else //se h == NULL
		printf("NULL\n");	

	return;
}
