#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void fonksiyonal(int *derece,float katsayi[10000])
{
	int i,j;
	printf("fonksiyonun derecesini giriniz:");
	scanf("%d",derece);
	for(i=0;i<=(*derece);i++)
	{
	
		printf("%d. derecenin katsayisini giriniz:",i);
		scanf("%f",&katsayi[i]);
	
	}

	
}
float fonksiyonbul(int derece,float nokta,float katsayi[10000])
{
	int i,j;
	float x=1,toplam=0;
	for(i=0;i<=(derece);i++)
	{
		x=1;
		for(j=0;j<i;j++)
		{
			x=x*nokta;
		}
		x=x*katsayi[i];
		toplam=toplam+x;
	}
	return toplam;
}
float fonksiyonturev(float nokta,float derece,float katsayi[10000])
{
	float a,b,c,d=nokta+0.000001,e=nokta-0.000001;
	a=fonksiyonbul(derece,d,katsayi);
	b=fonksiyonbul(derece,e,katsayi);
	c=(a-b)/0.000002;
	return c;
	
	
}
int main(int argc, char *argv[]) 
{
	int derece,c=0;
	float katsayi[1000],nokta,deger,turev,prevnokta,hata;
	fonksiyonal(&derece,katsayi);
	printf("hangi noktadan baslanacagini giriniz:");
	scanf("%f",&nokta);
	printf("hata miktarini girin:");
	scanf("%f",&hata);
	
	if(fonksiyonbul(derece,nokta,katsayi)==0)
	{
		printf("kok :%f\n",nokta);
	}
	else
	{
	
	do
	{
		prevnokta=nokta;
		nokta=nokta-(fonksiyonbul(derece,nokta,katsayi)/fonksiyonturev(nokta,derece,katsayi));
		if(fabs(nokta-prevnokta)>1000)
		{c++;
		}
		
	}
	while(fabs(nokta-prevnokta)>hata&&c==0);

		if(c==0)
		{
			printf("kok: %f",nokta);
		}
		else
		{
			printf("iraksiyor yeni nokta girin");
		}
	}
	
	
	
	
	
	
	
	return 0;
}
