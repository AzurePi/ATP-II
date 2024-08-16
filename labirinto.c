//malloc() won't work in professor dearest's testing programm

#include <stdio.h>
#include <stdlib.h>

int labirinto[25][25];
int sol = 0; //assume que não há solução

void ler_labirinto(int N);
int valido(int N, int x, int y);
void caminhar(int N, int C, int x, int y, int p);

int main(){
	int N, I, C;
	
	scanf("%d %d %d", &N, &I, &C);
	
	ler_labirinto(N);
	caminhar(N, C, 0, I, 0);
	
	if(sol == 0)
		printf("-1\n");

	return 0;
}

void ler_labirinto(int N){
	int i, j;
		
	for(i = 0; i<N; i++)
	{
		for(j = 0; j<N; j++)
			scanf("%d", &labirinto[i][j]);
	}
	
	return;
}

//verifica se a posição atual é válida
int valido(int N, int x, int y){
	if(x >= 0 && y >= 0 && x < N && y < N) //extrapolamos a borda?
	{
		if(labirinto[x][y] == 0) //o caminho está livre?
			return 1;
	}
	return 0;
}

void caminhar(int N, int C, int x, int y, int p){

	//encerra a chamada se extrapolamos a borda, se o caminho está bloqueado, ou se já chegamos ao final
	if(!valido(N, x, y) || sol != 0)
		return;

	//se chegamos ao final
	if(x == N-1 && y == C)
	{
		printf("%d\n", p);
		sol = 1; //indica que encontramos uma solução
		return;
	}
	
	labirinto[x][y] = 1; //marca o caminho como já percorrido
	
	caminhar(N, C, x+1, y, p+1);
	caminhar(N, C, x, y+1, p+1);
	caminhar(N, C, x, y-1, p+1);

	return;
}
