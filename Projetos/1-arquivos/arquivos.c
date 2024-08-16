#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *codigo, *palavra; //endereços dos arquivos de entrada
	FILE *linha; //endereço do arquivo de saída
	int N; //código
	char pal[50]; //palavra lida a ser escrita
	int i, s; //contadores
	char palast[5][50] = {" "," "," "," "," "}; //vetor para armazenar as últimas cinco strings
	
	//abertura dos arquivos de entrada e saída
	codigo = fopen("codigos.dat", "r");
	palavra = fopen("palavras.dat", "r");
	linha = fopen("linhas.dat", "w");
	
	//escreve o arquivo linhas.dat até que um dos arquivos de entrada chegue ao fim
	while(!feof(codigo) && !feof(palavra))
	{	
		fscanf(codigo, "%d", &N);
		if(N<0)
		{	
			for(i = N+5; i<5; i++)
			{
				fprintf(linha, "%s ", palast[i]); //imprime em linhas.dat uma das cinco últimas palavras lidas
			}
		}else if(N>0)
		{
			for(i = 0; i<N; i++)
			{
				fscanf(palavra, " %s ", pal); //lê a palavra em palavras.dat
				fprintf(linha, "%s ", pal); //imprime a palavra em linhas.dat
			
				//armazena as última cinco palavras
				for(s = 0; s<5; s++)
				{	
					if(s != 4)
						strcpy(palast[s], palast[s+1]); //move as palavras que já estão em palast para trás
					else
						strcpy(palast[s], pal); //adiciona a palavra lida ao fim de palast
				}
			}
		}else //caso N = 0
			fprintf(linha, "%d", 0);
				
		fprintf(linha, "\n");
	}
	
	//imprime os códigos que faltam em linhas.dat
	while(!feof(codigo))
	{	
		fscanf(codigo, "%d", &N);
		fprintf(linha, "%d ", N);	
	}
	
	//imprime as palavras que faltam em linhas de 5
	i = 1;
	while(!feof(palavra))
	{	
		fscanf(palavra, " %s ", pal);
		fprintf(linha, "%s ", pal);
		if(i % 5 == 0)
			fprintf(linha, "\n");
		i++;
	}
	
	fclose(codigo);
	fclose(palavra);	
	fclose(linha);
	
	return 0;
}
