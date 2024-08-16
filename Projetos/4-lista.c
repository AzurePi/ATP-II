#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
	int I, O, C;
	struct fila *prox;
}Fila;

Fila *insere(Fila *new, Fila *head);
Fila *forma_fila(int N);
void atender(int N, int M, Fila *head);

int main(){
	int N, M;
	Fila *head = NULL;
	
	scanf("%d %d", &N, &M);
	head = forma_fila(N);
	
	/*
	Fila *aux = head;
	int i;
	printf("\n");
	for(i = 0; i<N; i++)
	{
		printf("%d %d %d\n", aux->I, aux->O, aux->C);
		aux = aux->prox;
	}
	*/
	
	atender(N, M, head);
	
	return 0;
}

//insere um elemento new na lista, ordenado em relação ao instante de chegada
Fila *insere(Fila *new, Fila *head){
	Fila *aux = head, *prev = NULL; //começa a busca pelo lugar certo a partir de head
	
	//se o instante de new já for menor do que o de aux
	if(new->O < aux->O)
	{
		new->prox = head;
		head = new;
		return head;
	}
	//se o instante de new é maior do que o de aux
	
	//"anda" com aux enquanto o instante de new for maior do que o de aux, e não estivermos no final da fila
	while(new->O > aux->O && aux->prox != NULL)
	{
		prev = aux;
		aux = aux->prox;
	}
	
	//o instante de new não é maior do que o de aux, ou estamos no final da fila
	
	//se encontramos o lugar certo
	if(new->O < aux->O)
	{
		new->prox = aux;
		prev->prox = new;
		return head;
	}
	
	//se os instantes coincidem, organiza em relação ao id
	if(new->O == aux->O)
	{	
		//se o id de new já é menor do que o que o de aux
		if(new->I < aux->I)
		{
			//e estamos no começo da fila
			if(aux == head)
			{
				new->prox = head;
				head = new;
				return head;
			}
			
			//e estamos no meio da fila
			prev->prox = new;
			new->prox = aux;
			return head;
		}
		//se o id de new não é menor que o de aux
		
		//"anda" com aux enquanto o id de new for maior que o de aux, ou até o final da fila
		while(new->I > aux->I && aux->prox != NULL)
		{
			prev = aux;
			aux = aux->prox;
		}
		
		//se encontramos o lugar certo
		if(new->I < aux->I)
		{
			//e é o começo da fila
			if(aux == head)
			{
				new->prox = head;
				head = new;
				return head;
			}
			
			//e estamos no meio da fila
			prev->prox = new;
			new->prox = aux;
			return head;
		}
		
		//se estamos no final da fila
		aux->prox = new;
		return head;
	}
	
	//se estamos no final da fila
	aux->prox = new;
	return head;
}

//lê N linhas de entrada e forma uma fila
Fila *forma_fila(int N){
	Fila *head = NULL, *aux, *prev = NULL;
	int i;
	
	for(i = 0; i<N; i++)
	{
		aux = malloc(sizeof(Fila)); //a cada iteração, cria um elemento novo
		scanf("%d %d %d", &aux->I, &aux->O, &aux->C);
		aux->prox = NULL; //por padrão, assumimos que ele é o final da fila
		
		if(head == NULL) //se a fila está vazia
			head = aux;	
		else
			head = insere(aux, head); //insere por ordem de chegada
	}
	
	return head; //retorna o endereço da cabeça da fila
}

void atender(int N, int M, Fila *head){
	int *t = malloc(M * sizeof(int)); //array para guardar os instante de atendimento em cada um dos M centros
	int i, j, min;
	
	//zera os instantes de cada centro
	for(i = 0; i<M; i++)
		t[i] = 0;
	
	//enquanto há pessoas na fila
	while(head != NULL)
	{	
		//encontra o centro de atendimento j com o menor t
		min = 2000001;
		for(i = 0; i<M; i++)
		{
			if(t[i] < min)
			{
				min = t[i];
				j = i;
			}
		}
		
		//o centro j atende head
		if(head->O > t[j])
			t[j] += (head->O - t[j]) + head->C;
		else //se head->O <= t[j]
			t[j] += head->C;
		
		head = head->prox; //passa para o próximo da fila
	}
	
	//imprime o instante em que o atendimento acaba em cada centro
	for(i = 0; i<M; i++)
	{
		printf("%d", t[i]);
		if(i != M-1) //não imprime espaço após o último centro
			printf(" ");
		else //imprime uma quebra de linha
			printf("\n");
	}
	
	return;
}
