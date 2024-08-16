//this may or may not be a slight alteration of a code form a colleague...

#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
	int I;
	int T;
	struct fila *prox;
}Fila;

void insere_aux(Fila **h, Fila **t, int I, int T) {
	Fila *novo = malloc(sizeof(Fila)), *aux, *aux_anterior;
	novo->I = I;
	novo->T = T;

	if(*h == NULL) {
		*h = novo;
		*t = novo;
		(*h)->prox = NULL;
	    	return;
	}
	if(novo->T < (*h)->T || (novo->T == (*h)->T && novo->I > 59 && novo->I > (*h)->I)) {
		novo->prox = *h;
		*h = novo;
		return;
	}

	if(novo->T > (*t)->T) {
		novo->prox = NULL;
		(*t)->prox = novo;
		*t = novo;
		return;
	}

	aux = (*h)->prox;
	aux_anterior = *h;
	while(aux != NULL) {
		if(novo->T < aux->T || (novo->T == aux->T && novo->I > 59 && novo->I > aux->I)) {
			aux_anterior->prox = novo;
			novo->prox = aux;
			return;
		}
		aux_anterior = aux;
		aux = aux->prox;
	}

	if(novo->T == (*h)->T && ((*h)->prox == NULL || (*h)->prox->T != novo->T)) {
		novo->prox = (*h)->prox;
		(*h)->prox = novo;
		return;
	}

	aux = (*h)->prox;
	while(aux != NULL) {
		if(novo->T == aux->T && (aux->prox == NULL || aux->prox->T != novo->T)) {
			novo->prox = aux->prox;
			aux->prox = novo;
			if(novo->prox == NULL) 
			*t = novo;
			return;
		}
		aux = aux->prox;
	}
}

void insere(Fila **h, Fila **t, int I, int T) {
	Fila *novo = malloc(sizeof(Fila));
	novo->I = I;
	novo->T = T;
	Fila *aux, *aux_anterior;
	
	if(*h == NULL) {
		*h = novo;
		*t = novo;
		(novo)->prox = NULL;
		return;
	}
	
	if((novo)->I > 59) {
		if((novo)->I > (*h)->I) {
			(novo)->prox = *h;
			*h = novo;
			return;
		}
		aux = (*h)->prox;
		aux_anterior = (*h);
		while(aux != NULL) {
			if((novo)->I > aux->I) {
				aux_anterior->prox = novo;
				(novo)->prox = aux;
				return;
			}
			aux_anterior = aux;
			aux = aux->prox;
		}
	}
	(*t)->prox = novo;
	(novo)->prox = NULL;
	*t = novo;
}

void remover(Fila **h, Fila **t) {
	if(*h == NULL) return;
	if((*h)->prox == NULL) {
		free(*h);
		*h = NULL;
		*t = NULL;
		return;
	}
	if((*h)->prox == *t) {
		free(*h);
		*h = *t;
		return;
	}
	Fila *aux = *h;
	*h = (*h)->prox;
	free(aux);
}

void imprime(Fila *h) {
	while(h != NULL) {
		printf("%d ", h->I);
		h = h->prox;
	}
	printf("\n");
}

int main() {
	int i, N, idade, tempo, tempoTotal, tempo_atual = 3, idade_atual;
	Fila *head_aux = NULL, *tail_aux = NULL, *head = NULL, *tail = NULL;
	int inseriu;
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++) {
		scanf("%d %d", &idade, &tempo);
		insere_aux(&head_aux, &tail_aux, idade, tempo);
	}
	tempoTotal = head_aux->T;
	idade_atual = head_aux->I;
	insere(&head, &tail, head_aux->I, head_aux->T);
	remover(&head_aux, &tail_aux);
	inseriu = 1
	
	while(!(head_aux == NULL && head == NULL)) {
		if(tempo_atual >= 3) {
			tempo_atual = 0;
			if(head == NULL) {
				insere(&head, &tail, head_aux->I, head_aux->T);
				tempoTotal = head_aux->T;
				remover(&head_aux, &tail_aux);
				inseriu = 1;
			}
			idade_atual = head->I;
			remover(&head, &tail);
		}
		while(head_aux != NULL && tempoTotal >= head_aux->T) {
			insere(&head, &tail, head_aux->I, head_aux->T);
			remover(&head_aux, &tail_aux);
			inseriu = 1;
		}
		if(inseriu) {
			printf("%d ", idade_atual);
			imprime(head);
		}
		tempo_atual++;
		tempoTotal++;
		inseriu = 0;
	}

	return 0;
}
