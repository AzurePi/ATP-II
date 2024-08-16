#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int I, K, O;
	struct lista *prox;
} Lista;

Lista *l = NULL; //endereço do elemento "inicial" da lista, o de menor I
Lista *remov = NULL; //endereço da última pessoa removida

int ler(); //leitura das entradas e preenchimento da lista circular
void reinserir(); //eventual reinserção do último elemento removido
void josephus(int N, int K, Lista *start); //execução da lógica do problema

int main() {
	int N = ler();
	
	josephus(N, l->K - 1, l); //já considerando o primeiro movimento para se "entrar" na lista
	printf("%d\n", l->I);

	return 0;
}

//leitura das entradas e preenchimento da lista circular
int ler() {
	int N, i;
	Lista *new, *prev = NULL;
	
	scanf("%d", &N);
	for(i = 1; i < N+1; i++) //preenchimento da lista circular
	{
		new = malloc(sizeof(Lista)); //a cada iteração, new aponta para um endereço novo
		new->I = i;
		
		scanf("%d %d", &new->K, &new->O);
		
		if(i == 1) //se estamos no começo da lista
			l = new; //esté é o endereço da menor posição
		else 
   		{
      			prev->prox = new;
      			if(i == N) //se estamos no final da lista
      				new->prox = l; //ele aponta para o primeiro elemento
    		}  	
		prev = new;
	}
	return N;
}

//reinserção do último elemento removido
void reinserir() {
	Lista *aux = l;
	int i = 0;
	
	if(remov == NULL) //se não há valor para reinserir
		return;
	
	remov->O = 0;
	/*condições de parada: 	aux->prox é l (já analisamos todas as posições)
				remov é maior que o número atual e menor do que o próximo número (encontramos o lugar certo)
	*/
	while(aux->prox != l && (remov->I < aux->I || remov->I > (aux->prox)->I))
	{
		aux = aux->prox;
		i++;
	}
	
	//se encontramos o lugar certo
	if(remov->I > aux->I && remov->I < (aux->prox)->I) 
	{
		remov->prox = aux->prox;
		aux->prox = remov;
	
		remov = NULL; // descarta o valor reinserido
		return;
	}
	
	/*se demos uma volta completa no vetor, estamos na posição imediatamente
	  anterior a l e sabemos que remov não estava entre nenhum par de posições até
	  agora; portanto, remov deve ser ou maior ou menor do que todos os valores
	  ainda presentes na lista
	*/
	//se remov é maior do que a posição atual, então é maior do que todos e deve estar no final
	//se remov é menor do que a posição atual, então é menor do que todos e deve estar no começo
	//de qualquer forma, pela lista ser circular,
	remov->prox = aux->prox;
	aux->prox = remov;
	
	if(remov->I < aux->I)
		l = remov; //remov é o novo menor número

	remov = NULL;
	return;
}

//execução da lógica do problema
void josephus(int N, int K, Lista *start) {
	Lista *aux = start, *prev = NULL;
	
	//anda até encontrar a posição a ser eliminada
	while(K > 0)
	{
		prev = aux;
		aux = aux->prox;
		K--;
	}
	//verifica a operação que a posição a ser eliminada requer
	if(aux->O == 1) 
	{
		reinserir();
		N++; //uma pessoa a mais na lista
	}
	
	if(aux == l) //se estamos removendo o menor número da lista
		l = l->prox; //guardamos o próximo menor número
		
	prev->prox = aux->prox; //remove aux da lista
	remov = aux; //salva o elemento removido para eventual reinserção
	N--; //uma pessoa a menos na lista

	if(N > 1) //se ainda há mais de uma pessoa na lista
		josephus(N, aux->K - 1, aux->prox);
	/*executa para uma pessoa a menos, com o K do elemento que acabou de ser eliminado (já considerando o movimento preciso
	  para passar para a próxima posição), começando pelo próximo elemento
	*/	
	return;
}
