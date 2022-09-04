#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float fonksiyonbulma(int derece,float katsayi[10000],float nokta)
{
    
	
	float a=1,c;
	int b=0,i;
	float toplam=0;
	while(b<=derece)
	{
		a=1;
		for(i=0;i<b;i++)
		{	
				a=a*nokta;	
		}
		c=katsayi[b]*a;
		toplam=c+toplam;
		b++;
	}
	return toplam;
}
void fonksiyonalma(float *aralik1,float *aralik2,int *derece,float katsayi[10000],float *hata)
{
	
	
	printf("fonksiyonun kacinci derece oldugunu giriniz:");
	scanf("%d",derece);
	int b=0;
	while(b<=(*derece))
	{
		
		printf("%d. derecenin katsayisini girin:\n",b);
		scanf("%f",&katsayi[b]);
		b++;
	}
	printf("1. ve 2. araligi girin(kucukten buyuge):\n");
	scanf("%f %f",aralik1,aralik2);
	printf("hata miktarini girin:");
    scanf("%f",hata);
}
int main(int argc, char *argv[]) 
{
	int derece,c=0,d=0;
	float katsayi[10000];
	float aralik1,aralik2,yeninokta,yeni,hata;
	
	fonksiyonalma(&aralik1,&aralik2,&derece,katsayi,&hata);
	int s=1;
	float altaraliksonuc=fonksiyonbulma(derece,katsayi,aralik1);
	
	float ustaraliksonuc=fonksiyonbulma(derece,katsayi,aralik2);
    

	float prevaralik1=aralik1,prevaralik2=aralik2,kontrol;
	if(altaraliksonuc==0)
	{
		printf("kok %f",aralik1);
	}
	else if(ustaraliksonuc==0)
	{
		printf("kok %f",aralik2);
	}
	else if(altaraliksonuc*ustaraliksonuc<0)
	{
		printf("bu aralikta kok vardir\n");
		printf("onceki kokler:\n");
	
	do
	{
		
		yeninokta=(aralik1+aralik2)/2;
		yeni=fonksiyonbulma(derece,katsayi,yeninokta);
		if(yeni*altaraliksonuc<0)
		{
			prevaralik2=aralik2;
			ustaraliksonuc=yeni;
			aralik2=yeninokta;
			printf(" %f\n",aralik2);
			prevaralik1=aralik1;
			
		}
		else if(yeni*ustaraliksonuc<0)
		{
			prevaralik1=aralik1;
			altaraliksonuc=yeni;
			aralik1=yeninokta;
			printf(" %f\n",aralik1);
			prevaralik2=aralik2;
		
		}
    	
		s=s*2;
		kontrol=(prevaralik2-prevaralik1)/s;
	}while(kontrol>hata);
	printf("yaklasik kok: %f",yeninokta);
}


else{
	printf("bu aralikta kok yoktur");
}
	
	
		
	
	
	return 0;
}
