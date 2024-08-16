#include <stdio.h>
#include <string.h>

int maior = 1; //o maior palindromeio é, por padrão, uma única letra

//verifica se pal, que começa em s e termina em e, é ou não palíndromo, de forma recursiva
int palindromo(char *pal, int s, int e){
	
	if(s == e)
		return 1; //se há um único caractere, é palíndromo
	if(pal[s] != pal[e])
		return 0; //se a primeira e a última letra da string não batem, não é palíndromo
	if(s < e + 1)
		return palindromo(pal, s+1, e-1); //se há mais de dois caracteres na string, checa se a string entre eles também é palíndromo
		
	return 1;

}

//determina o tamanho do maior palindromeio em ent de tamanho k
void palindromeio(char *ent, int k){
	int i, j;
	
	//laços aninhados que farão com que cada substring de ent seja checada
	for(i = 0; i < k; i++)
	{	for(j = k; j >= 0; j--)
		{
			if(palindromo(ent, i, j)) //se for palíndromo
				if(j - i + 1 > maior) //se o palíndromo foi maioO do que o maior que se conhece
					maior = j - i + 1;
		}
	}
}

int main(){
	char ent[2001];
	int k, i;
	int res;
	
	scanf("%s", ent); //lê a palavra na linha
	k = strlen(ent);
	
	palindromeio(ent, k);
	
	printf("%d", maior);

	return 0;
}
