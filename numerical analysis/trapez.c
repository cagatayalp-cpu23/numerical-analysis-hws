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
float trapez(int derece,float katsayi[1000])
{
	float i;
	float sonuc=0,aralik1,aralik2,n,h;
	printf("buyukten kucuge araliklari girin:\n");
	scanf("%f %f",&aralik1,&aralik2);
	printf("n i girin");
	scanf("%f",&n);
	h=(aralik1-aralik2)/n;
	for(i=aralik2;i<=aralik1;i=i+h)
	{
		if(i==aralik2||i==aralik1)
		{
			sonuc=sonuc+h*(fonksiyonbul(derece,katsayi,i)/2);
		}
		else
		{
			sonuc=sonuc+h*(fonksiyonbul(derece,katsayi,i));
		}
		
	}
	return sonuc;

}
int main(int argc, char *argv[]) 
{
	int derece;
	float katsayi[1000],sonuc;
	fonksiyonal(&derece,katsayi);
    sonuc=trapez(derece,katsayi);
    printf("%f",sonuc);
	
	
	
	
	
	return 0;
}
