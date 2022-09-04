#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float fonksiyonbul(int derece,float katsayi[1000],float nokta)
{
	int i,j;
	float x,toplam=0;
	for(i=0;i<=derece;i++)
	{
		x=1;
		for(j=0;j<i;j++)
		{
			x=x*nokta;
		}
		toplam=toplam+x*katsayi[i];
		
	}
	return toplam;
}
void fonksiyonal(int *derece,float katsayi[1000])
{
	int i;
	printf("fonksiyonun derecesini girin:");
	scanf("%d",derece);
	for(i=0;i<=(*derece);i++)
	{
		printf("%d. derecenin katsayisi:\n",i);
		scanf("%f",&katsayi[i]);
	}
	
	
	
}
float simpson1_3(int derece,float katsayi[1000])
{
	float n,h,aralik1,aralik2,i,toplam=0;
	int count=0;
	printf("buyuk ve kucuk aralik degerlerini girin:\n");
	scanf("%f %f",&aralik1,&aralik2);
	printf("n i girin");
	scanf("%f",&n);
	
	h=(aralik1-aralik2)/n;
	for(i=aralik2;i<=aralik1;i=i+h)
	{
		if(i==aralik1 ||i==aralik2)
		{
			toplam=toplam+fonksiyonbul(derece,katsayi,i);
			count++;
		}
		else if(count%2==1)
		{
			toplam=toplam+fonksiyonbul(derece,katsayi,i)*4;
			count++;
		}
		else if(count%2==0)
		{
			toplam=toplam+fonksiyonbul(derece,katsayi,i)*2;
			count++;
		}
		
	}
	return toplam*h/3;
	
}
int main(int argc, char *argv[]) 
{
	int derece;
	float katsayi[1000];
	fonksiyonal(&derece,katsayi);
	float sonuc=simpson1_3(derece,katsayi);
	printf("sonuc=%f",sonuc);
	
	return 0;
}
