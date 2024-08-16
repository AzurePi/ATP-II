#include <stdio.h>
#include <stdlib.h>

int K; //quantidade de movimentos
int torre[3] = {0}; //inicializa com uma torre vazia
int *A, *B, *C; //endereço dos três pinos na torre

void hanoi(int origem, int destino, int auxilio, int n){
	int *io, *id; //endereço de origem, endereço de destino
	int i;
	
	if(K != 0) //se há movimentos a fazer
	{
		if(n == 1) //se estamos lidando com o primeiro disco
		{	
			torre[origem]--; //há um disco a menos no pino de origem
			torre[destino]++; //há um disco a mais no pino de destino
			
			
			//determinação do endereço de origem
			if(origem == 0) //se a origem for o primeiro pino
				io = A;
			else if(origem == 1) //se a origem for o segundo pino
				io = B;
			else if(origem == 2) //se a orgiem for o terceiro pino
				io = C;
			
			//deterinação do endereço de destino	
			if(destino == 0) //se o destino for o primeiro pino
				id = A;
			else if(destino == 1) //se o destino for o segundo pino
				id = B;
			else if(destino == 2) //se o destino for o terceiro pino
				id = C;
			
			
			i = 0;
			while(io[i] == 0) //enquanto não há disco
				i++; //passa para a próxima posição
			
			io[i] = 0; //no endereço de origem não há mais pino
			id[i] = 1; //no endereço de destino agora há pino
			
			K--;
		}else{
			hanoi(origem, auxilio, destino, n-1); //faça o processo
			//pensando em um disco a menos e trocando a função de cada pino
			hanoi(origem, destino, auxilio, 1); //faça o processo para 
			//mover um único pino
			hanoi(auxilio, destino, origem, n-1); //faça o processo
			//pensando em um disco a menos e trocando a função de cada pino
		}
	}
}

int main(){
	int N;
	int i, flag = 0;
	
	scanf("%d %d", &N, &K);

	//aloca dinamicamente o espaço necessário para cada pino
	A = malloc(N*sizeof(int));
	B = malloc(N*sizeof(int));
	C = malloc(N*sizeof(int));
	
	torre[0] = N; //no primeiro pino, há N discos
	
	//determina que há discos no primeiro pino, mas não há discos nos demais
	for(i = 0; i<N; i++)
	{
		A[i] = 1;
		B[i] = 0;
		C[i] = 0;
	}

	//executa movimentos na torre
	hanoi(0, 2, 1, N); 
	
	//imprimindo o pino de origem
	for(i = 0; i<N; i++)
	{
		if(A[i] == 1) //se há disco nessa posição do pino
		{
			printf("%d ", i+1);
			flag = 1;
		}
	}
	if(flag == 0) //se não houve disco em posição alguma
		printf("0");
		
	printf("\n");
	flag = 0; //zera flag para reaproveitá-la
	
	//imprimindo o pino auxiliar
	for(i = 0; i<N; i++)
	{
		if(B[i] == 1) //se há disco nessa posição do pino
		{
			printf("%d ", i+1);
			flag = 1;
		}
	}
	if(flag == 0) //se não houve disco em posição alguma
		printf("0");
		
	printf("\n");
	flag = 0; //zera flag para reaproveitá-la
	
	//imprimindo o pino de destino
	for(i = 0; i<N; i++)
	{
		if(C[i] == 1) //se há disco nessa posição do pino
		{
			printf("%d ", i+1);
			flag = 1;
		}
	}
	if(flag == 0) //se não houve disco em posição alguma
		printf("0");
	
		
	//libera o espaço alocado para a torre
	free(A);
	free(B);
	free(C);
	
	return 0;
}
