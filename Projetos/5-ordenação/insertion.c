#include <stdio.h>
#include <time.h>

#define n 200000

typedef struct biggo {
	int high;
	int low;
} BigInt;

void ler(BigInt *vet);
void imprimir(BigInt *vet);
int maior_que(BigInt *vet, int i, int j);
void insertion(BigInt *vet);

int main(){
	BigInt vet[n];
	time_t begin, end;
	double t;
	
	ler(vet); //lê dados de bigint.dat e armazena num vetor
	
	begin = clock(); //marca o instante em que o sorting começa
	insertion(vet);
	end = clock(); //marca o instante em que o sorting termina
	
	t = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%lf", t); //imprime na tela o tempo tomado pela ordenação
	
	imprimir(vet); //imprime o vetor ordenado no arquivo quick.dat
	
	return 0;
}

void ler(BigInt *vet){
	FILE *big;
	int i;
	
	big = fopen("bigint.dat", "r");
	
	for(i = 0; i < n; i++)
		fscanf(big, "%d %d", &vet[i].high, &vet[i].low);
	
	fclose(big);
}

void imprimir(BigInt *vet){
	FILE *quick;
	int i;
	
	quick = fopen("quick.dat", "w");
	
	for(i = 0; i < n; i++)
		fprintf(quick, "%d %d\n", vet[i].high, vet[i].low);
	
	fclose(quick);
}

//ordenação crescente de vet pelo método da inserção
void insertion(BigInt *vet){
	int i, j;
	BigInt x;
	
	//começando a partir do segundo elemento do vetor, e passando por todos
	for(i = 1; i<n; i++)
	{
		//armazena o número sendo inserido
		x.high = vet[i].high;
		x.low = vet[i].low;
		
		//começa a análise pela posição imediatamente anterior
		j = i - 1;
		

		//procura, nas posições anteriores, onde inserir x
		
		/*
			Se x.high e vet[j].high são diferentes, ordenamos com base neles
			Do contrário, se são iguais, ordenamos com base em low
			
			Se x.high e vet[j].high são negativos, a comparação se inverte para os componentes low
			Se x.hig e vet[j].high são positivos, a comparação ocorre normalmente
		*/
		while(((x.high != vet[j].high && x.high < vet[j].high) || (x.high == vet[j].high && ((x.high < 0 && x.low > vet[j].low) || (x.high > 0 && x.low < vet[j].low)))) && j >= 0)
		{
			vet[j+1].high = vet[j].high;
			vet[j+1].low = vet[j].low;
			vet[j].high = x.high;
			vet[j].low = x.low;
			j--; //vai para a posição anterior
		}
	}
}
