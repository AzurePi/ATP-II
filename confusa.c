#include <stdio.h>

void ordenar(double*, int, int); //ordenação através do algoritmo de inserção

int main(){
	int N, k;
	int i;
	
	scanf("%d %d", &N, &k);
	double vet[N];
	
	for(i = 0; i<N; i++)
		scanf("%lf", &vet[i]);
	
	ordenar(vet, N, k);
	
	for(i = 0; i<N; i++)
		printf("%.3lf ", vet[i]);
	
	return 0;
}

void ordenar(double *vet, int N, int k){
	int i, j;
	double x;
	
	if(k == 0)
	{	//ordena todo o vetor de forma decrescente
		
		//para cada número do vetor, a partir da segunda posição
		for(i = 1; i<N; i++)
		{
			x = vet[i]; //armazena o número a ser inserido
			j = i-1; //a análise para inserção começará por seu antecessor
			
			//encontramos a posição, dentre as anteriores a x,
			//em que x deveria estar
			while(j >= 0 && vet[j] < x)
			{
				vet[j+1] = vet[j]; //move o próximo número para essa posição
				j--; //analisa o índice anterior
			}
			vet[j+1] = x; //insere x na posição adequada
		}
		return;	
	}
	
	for(i = 0; i<N; i++) //andando pelo vetor inteiro (a partir do segundo elemento)
	{
		x = vet[i]; //armazena o número a ser inserido
		j = i-1; //a análise para inserção começará por aqui
		
		//se estamos antes de ou em k, ordenamos de forma crescente
		if(i <= k)
		{
			//encontramos a posição, dentre as anteriores a x,
			//em que x deveria estar
			while(j >= 0 && vet[j] > x)
			{
				vet[j+1] = vet[j]; //move o próximo número para essa posição
				j--; //analisa o índice anterior
			}
			vet[j+1] = x; //insere x na posição adequada
		}else //if(i > k) ordenamos de forma decrescente
		{
			//encontramos a posição, dentre as anteriores a x mas
			//posteriores a k, em que x deveria estar
			while(j > k && vet[j] < x)
			{
				vet[j+1] = vet[j]; //move o próximo número para essa posição
				j--; //analisa o índice anterior
			}
			vet[j+1] = x; //insere x na posição adequada
		}
	}
	return;
}
