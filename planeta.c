#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int N, M;
	int op;
	double dist;
	int i, j;
	char nom[21], p1[21], p2[21];
	double x1, x2, y1, y2, z1, z2;

	scanf("%d %d", &N, &M); //ler quantas linhas de informação e quantas linhas de operação

	struct p{
		char nome[21];
		double peso;
		double x, y, z;
	}planetas[N]; //vetor para armazenar os dados dos planetas

	//ler as informações dos planetas em cada linha e armazená-las no vetor de structs
	for(i=0; i<N; i++)
  	{	scanf("%s %lf %lf %lf %lf", planetas[i].nome, &planetas[i].peso, &planetas[i].x, &planetas[i].y, &planetas[i].z);
  	}

	//realizar as operações
	for(i=0; i<M; i++)
	{	scanf("%d", &op); //ler a operação que será realizada
	
		switch(op)
		{	//op = 1: calcular a distância entre dois planetas
		        case 1: scanf(" %s", p1);
		        	scanf(" %s", p2); //ler os nomes dos planetas
		        
	                	j = -1; //resetar o contador que irá procurar o planeta no vetor
				do //procurar o planeta 1
        	        	{	j++;
        	        		if(strcmp(planetas[j].nome, p1) == 0) //se o nome corresponder, pegar as coordenadas 1
					{	x1 = planetas[j].x;
						y1 = planetas[j].y;
						z1 = planetas[j].z;
					}
				}while(strcmp(planetas[j].nome, p1) != 0); //até encontrar o planeta certo
        			
				j = -1; //resetar o contador que irá procurar o planeta no vetor
				do //procurar o planeta 2
        	        	{	j++;
        	        		if(strcmp(planetas[j].nome, p2) == 0) //se o nome corresponder, pegar as coordenadas 2
				        {	x2 = planetas[j].x;
						y2 = planetas[j].y;
						z2 = planetas[j].z;
					}
				}while(strcmp(planetas[j].nome, p2) != 0); //até encontrar o planeta certo
        			
				dist = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1)); //calcular a distância entre os planetas
				printf("%.2lf\n", dist); //imprimir a distância
				break; //encerrar o switch case
        	
		        //op = 2: listar as coordenadas do planeta
			case 2:	scanf(" %s", nom); //ler o nome do planeta
			
				j = -1; //resetar o contador que irá procurar o planeta
				do //procurar o planeta
				{	j++;
					if(strcmp(planetas[j].nome, nom) == 0) //se o nome corresponder, imprimir as coordenadas
					{	printf("%.0lf %.0lf %.0lf\n", planetas[j].x, planetas[j].y, planetas[j].z);
					}
				}while(strcmp(planetas[j].nome, nom) != 0); //até encontrar o planeta
				break; //encerrar o switch case
				
		        //op = 3: listar o peso do planeta
			case 3:	scanf(" %s", nom); //ler o nome do planeta
          			
		                j = -1; //resetar o contador que irá procurar o planeta
				do //procurar o planeta
                 		{	j++;
                 			if(strcmp(planetas[j].nome, nom) == 0) //se o nome corresponder, imprimir o peso
	                 		{	printf("%.2lf\n", planetas[j].peso);
	                 		}
				}while(strcmp(planetas[j].nome, nom) != 0); //até encontrar o planeta
                 		break; //encerrar o switch case
		}
    		//seguir para a próxima linha de operação
	}
	
	//nas três operações de procura de planeta, se j++ fosse feito após o if, há o risco de o laço while não fechar

	return 0;
}
