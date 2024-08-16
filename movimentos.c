#include <stdio.h>
#include <math.h>

void O1(); // distância a partir da velocidade e do tempo
void O2(); // velocidade a partir da distância e do tempo
void O3(); // tempo a partir da distância e da velocidade
void O4(); // distância a partir de velocidade inicial, aceleração e tempo
void O5(); // velocidade final a partir de velocidade inicial, aceleração e tempo
void O6(); // velocidade inicial a partir de distância, aceleração e tempo
void O7(); // tempo a partir de distância, velocidade inicial e aceleração

int main(){
	int N, O;
	int i;
	
	scanf("%d", &N);
	
	for(i = 0; i<N; i++)
	{
		scanf("%d ", &O);
		
		switch(O)
		{
			case 1: O1(); break;
			case 2: O2(); break;
			case 3: O3(); break;
			case 4: O4(); break;
			case 5: O5(); break;
			case 6: O6(); break;
			case 7: O7(); break;
		}
	}
	
	return 0;
}

//distância a partir da velocidade e do tempo
void O1(){
	double V, T, S;
	
	scanf("%lf %lf", &V, &T);
	S = V*T;
	printf("%.2lf\n", S);
}

//velocidade a partir da distância e do tempo
void O2(){
	double S, T, V;

	scanf("%lf %lf", &S, &T);
	V = S/T;
	printf("%.2lf\n", V);
}

//tempo a partir da distância e da velocidade
void O3(){
	double S, V, T;

	scanf("%lf %lf", &S, &V);
	T = S/V;
	printf("%.2lf\n", T);
}

//distância a partir de velocidade, aceleração e tempo
void O4(){
	double Vi, A, T, S;
	
	scanf("%lf %lf %lf", &Vi, &A, &T);
	S = (Vi*T) + ((A*T*T)/2);
	printf("%.2lf\n", S);
}

//velocidade final a partir de velocidade inicial, aceleração e tempo
void O5(){
	double Vi, A, T, Vf;
	
	scanf("%lf %lf %lf", &Vi, &A, &T);
	Vf = Vi + (A*T);
	printf("%.2lf\n", Vf);
}

//velocidade inicial a partir de distância, aceleração e tempo
void O6(){
	double S, A, T, Vi;
	
	scanf("%lf %lf %lf", &S, &A, &T);
	Vi = (S - ((A*T*T)/2))/T;
	printf("%.2lf\n", Vi);
}

//tempo a partir de distância, velocidade inicial e aceleração
void O7(){
	double S, Vi, A, T;

	scanf("%lf %lf %lf", &S, &Vi, &A);
	T = (sqrt((Vi*Vi) + (2*A*S)) - Vi) / A;
	printf("%.2lf\n", T);
}
