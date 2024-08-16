#include <stdio.h>
#include <stdlib.h>

int matriz[1000][1000];

void **ler(int N){
	int i, j;
	
	for(i = 0; i<N; i++)
		for(j = 0; j<N; j++)
			scanf("%d", &matriz[i][j]);	
}

void minimos(int N, int M){
	int i, j, k;
	int a, b, min;
	
	for(i = 0; i<M; i++)
	{
		scanf("%d %d", &a, &b);
		
		min = (2*N*N);
		for(j = a - 1; j<b; j++)
			for(k = a - 1; k<b; k++)
				if(matriz[j][k] < min)
					min = matriz[j][k];
		
		printf("%d\n", min);
	}
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	
	ler(N);
	minimos(N, M);
	
	return 0;
}
