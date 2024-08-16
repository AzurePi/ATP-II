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
int mediana_3(BigInt *v, int in, int mid, int fin);
void quicksort(BigInt *vet, int in, int fin);

int main(){
	BigInt vet[n];
	time_t begin, end;
	double t;
	
	ler(vet); //lê dados de bigint.dat e armazena num vetor
	
	begin = clock(); //marca o instante em que o sorting começa
	quicksort(vet, 0, n-1);
	end = clock(); //marca o instante em que o sorting termina
	
	t = (double)(end - begin) / CLOCKS_PER_SEC; //calcula o tempo transcorrido no sorting
	printf("%lf" , t); //imprime na tela o tempo tomado pela ordenação
	
	imprimir(vet); //imprime o vetor no arquivo quick.dat
	
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

//verifica se vet[i] é maior que vet[j]
//retorna 1 para ser maior, e 0 para ser menor ou igual
int maior_que(BigInt *vet, int i, int j){
	if(vet[i].high != vet[j].high)
	{
		if(vet[i].high > vet[j].high)
			return 1;

		return 0;
	}else //if vet[i].high == vet[j].high
	{
		//se ambos são positivos,
		if(vet[i].high >= 0 && vet[j].high >= 0)
		{
			//comparamos o componente low
			if(vet[i].low > vet[j].low)
				return 1;

			return 0;
		}
		//se ambos são negativos,
		//invertemos a lógica de ser maior ou menor para low
		if(vet[i].low < vet[j].low)
			return 1;

		return 0;
	}
}

//retorna o índice da mediana entre três valores nas posições in, mid e fin de um vetor v
int mediana_3(BigInt *v, int in, int mid, int fin){
	
	if(maior_que(v, in, mid))
	{
		if(maior_que(v, mid, fin))
			return mid;
		if(maior_que(v, fin, in))
			return in;
	}
	if(maior_que(v, in, fin))
	{
		if(maior_que(v, fin, mid))
			return fin;
		if(maior_que(v, mid, in))
			return in;
	}
	if(maior_que(v, mid, fin))
	{
		if(maior_que(v, fin, in))
			return fin;
		if(maior_que(v, in, mid))
			return mid;
	}
	return mid; //por default, se todos são iguais retorna a posição mid
}

//em um vetor v de BigInt, coloca v[i] na posição j, e v[j] na posição i
void troca(BigInt *v, int i, int j){
	BigInt aux;
	
	aux.high = v[j].high;
	aux.low = v[j].low;
	v[j].high = v[i].high;
	v[j].low = v[i].low;
	v[i].high = aux.high;
	v[i].low = aux.low;
}

void quicksort(BigInt *vet, int in, int fin){
	int pivot, maior; //indices do pivot e do número sendo analisado
	int i;

	//se o início ainda está antes do fim
	if(in < fin)
	{
		//determina o índice do pivot pelo método da mediana de três
		pivot = mediana_3(vet, in, (in+fin)/2, fin);
		
		//colocamos o pivot na posição fin do vetor
		troca(vet, pivot, fin);
		
		//in é a posição "maior" em que começaremos a ordenar os números
		maior = in; 
		
		//para cada elemento do vetor
		for(i = in; i < fin; i++)
		{
			//se o pivot é maior que esse número
			if(maior_que(vet, fin, i))
			{
				//colocamos esse número na posição de ordenação
				troca(vet, i, maior);
				maior++; //passamos para a próxima posição na ordenação
			}
		}
		//saindo desse laço, "maior" guarda o endereço do primeiro número no vetor que é maior que o pivot
		
	/*
		Colocamos o pivot no "meio" do vetor, de forma 
		que à sua esquerda estejam os valores menores, 
		e à direita of valores maiores
	*/
	troca(vet, fin, maior);

	//utilizamos quicksort para cada "metade" do vetor
	quicksort(vet, in, maior-1);
	quicksort(vet, maior+1, fin);
	}
}
