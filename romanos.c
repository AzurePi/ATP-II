#include <stdio.h>
#include <string.h>

void toRom(){
	int decimal;
	int vez, i;
	char romano[15] = {""};

	scanf("%d", &decimal);
	
	if(decimal >= 1000)
	{
		vez = decimal / 1000;
		for(i = 0; i<vez; i++)
			strcat(romano, "M");
		decimal -= vez*1000;
	}
	if(decimal >= 900)
	{
		vez = decimal / 900;
		strcat(romano, "CM");
		decimal -= vez*900;
	}
	if(decimal >= 500)
	{
		vez = decimal / 500;
		for(i = 0; i<vez; i++)
			strcat(romano, "D");
		decimal -= vez*500;
	}
	if(decimal >= 400)
	{
		vez = decimal / 400;
		strcat(romano, "CD");
		decimal -= vez*400;
	}
	if(decimal >= 100)
	{
		vez = decimal / 100;
		for(i = 0; i<vez; i++)
			strcat(romano, "C");
		decimal -= vez*100;
	}
	if(decimal >= 90)
	{
		vez = decimal / 90;
		strcat(romano, "XC");
		decimal -= vez*90;
	}
	if(decimal >= 50)
	{
		vez = decimal / 50;
		for(i = 0; i<vez; i++)
			strcat(romano, "L");
		decimal -= vez*50;
	}
	if(decimal >= 40)
	{
		vez = decimal / 40;
		strcat(romano, "XL");
		decimal -= vez*40;
	}
	if(decimal >= 10)
	{
		vez = decimal / 10;
		for(i = 0; i<vez; i++)
			strcat(romano, "X");
		decimal -= vez*10;
	}
	if(decimal >= 9)
	{
		vez = decimal / 9;
		strcat(romano, "IX");
		decimal -= vez*9;
	}
	if(decimal >= 5)
	{
		vez = decimal / 5;
		for(i = 0; i<vez; i++)
			strcat(romano, "V");
		decimal -= vez*5;
	}
	if(decimal >= 4)
	{
		vez = decimal / 4;
		strcat(romano, "IV");
		decimal -= vez*4;
	}
	if(decimal >= 1)
	{
		vez = decimal / 1;
		for(i = 0; i<vez; i++)
			strcat(romano, "I");
		decimal -= vez;
	}
	
	printf("%s\n", romano);
}

void toDec(int *sum){
	int decimal = 0, dig, interim[15];
	int i;
	char romano[15];
	
	scanf(" %s", romano);
	
	for(i = 0; i<strlen(romano); i++)
	{
		switch(romano[i])
		{
			case 'I': dig = 1; break;
			case 'V': dig = 5; break;
			case 'X': dig = 10; break;
			case 'L': dig = 50; break;
			case 'C': dig = 100; break;
			case 'D': dig = 500; break;
			case 'M': dig = 1000; break;
		}
		
		interim[i] = dig;
	}
	
	for(i = 0; i<strlen(romano); i++)
	{
		if(i != strlen(romano) - 1)
		{
			if(interim[i] < interim[i+1])
				decimal -= interim[i];
			else
				decimal += interim[i];
		}else
			decimal += interim[i];
	}
	
	*sum += decimal;
	
	printf("%d\n", decimal);
}



int main(){
	int N, C;
	int i;
	int sum = 0;
	
	scanf("%d", &N);
	
	for(i = 0; i<N; i++)
	{
		scanf("%d ", &C);
		if(C == 1)
			toDec(&sum);
		else
			toRom(&sum);
	}
	
	printf("%d", sum);
	
	return 0;
}
