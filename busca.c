#include <stdio.h>

int busca_crescente(int *vet, int in, int fin, int x){
	int mid = (in+fin)/2;

	//se encontramos x no vetor
	if(vet[in] == x)
		return in;
		
	if(vet[mid] == x)
		return mid;

	if(vet[fin] == x)
		return fin;
	
	//se chegamos ao fim do vetor, e não encontramos x
	if(in == fin)
		return -1;
	
	//do contrário, ainda estamos procurando
	
	//se o número é menor do que a posição atual
	if(x < vet[mid])
	{
		//buscamos na metade anterior do vetor
		return busca_crescente(vet, in, mid, x);;
	}
	//se o número é maior do que aposição atual
	
	//buscamos na metade posteiror do vetor
	return busca_crescente(vet, mid, fin, x);
}

int busca_decrescente(int *vet, int in, int fin, int x){
	int mid = (in+fin)/2;
	
	//se encontramos x no vetor
	if(vet[in] == x)
		return in;
		
	if(vet[mid] == x)
		return mid;

	if(vet[fin] == x)
		return fin;
	
	//se chegamos ao fim do vetor, e não encontramos x
	if(in == fin)
		return -1;

	//do contrário, ainda estamos procurando

	//se o número é menor do que a posição atual
	if(x < vet[mid])
	{
		//buscamos na metade posterior do vetor
		return busca_decrescente(vet, mid, fin, x);;
	}
	//se o número é maior do que a piosição atual
	
	//buscamos na metade anterior do vetor
	return busca_decrescente(vet, in, mid, x);
}

int main(){
	int N, M;
	int i, x, pos;
	
	scanf("%d", &N);
	int vet[N];
	
	for(i = 0; i<N; i++)
		scanf("%d", &vet[i]);
	
	scanf("%d", &M);
	
	for(i = 0; i<M; i++)
	{
		scanf("%d", &x);
		pos = busca_crescente(vet, 0, N/2, x);
		if(pos == -1)
			pos = busca_decrescente(vet, (N/2)+1, N-1, x);
		printf("%d ", pos);
	}

	return 0;
}
