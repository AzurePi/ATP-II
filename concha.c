#include <stdio.h>
#include <string.h>
#include <math.h>

char pal[10000][20];

void shell(int N);

int main(){
	int N, i;
	
	scanf("%d", &N);
	
	for(i = 0; i<N; i++)
		scanf("%s", pal[i]);
	
	shell(N);
	
	return 0;
}

void shell(int N){
	int interval, i, j;
	int p, k = 0;
	char temp[20];
	int up = N/8, down = N/4;
	
	do{
		p = pow(2, k);
		k++;
	}while(p <= up || p > down);

	if(p <= up)
		p *= 2;
	else if(p > down)
		p /= 2;
		
	for (interval = p; interval > 0; interval /= 2)
	{
	    for (i = interval; i<N; i += 1)
		{
	      strcpy(temp, pal[i]);
	      
	      for (j = i; j >= interval && strcmp(pal[j - interval], temp) > 0; j -= interval)
	        strcpy(pal[j], pal[j - interval]);

	      strcpy(pal[j], temp);
	    }
	    
	    for(i = 0; i<N; i++)
		{
			printf("%s ", pal[i]);
			if(i != N-1)
				printf(" ");
			else
				printf("\n");
		}
	}

	return;
}
