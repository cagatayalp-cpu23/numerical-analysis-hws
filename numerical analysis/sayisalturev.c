#include <stdio.h>
#include <stdlib.h>
float fonksiyonbul(int derece,float katsayi[1000],float eleman);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float ilerifark(float nokta,float h,int derece,float katsayi[1000])
{
	float a,b,c,d=nokta+h;
	a=fonksiyonbul(derece,katsayi,d);
	b=fonksiyonbul(derece,katsayi,nokta);
	c=(a-b)/h;
	return c;
}
float gerifark(float nokta,float h,int derece,float katsayi[1000])
{
	float a,b,c;
	a=fonksiyonbul(derece,katsayi,nokta-h);
	b=fonksiyonbul(derece,katsayi,nokta);
	c=(b-a)/h;
	return c;
}
float merkezifark(float nokta,float h,int derece,float katsayi[1000])
{
	float a,b,c;
	a=fonksiyonbul(derece,katsayi,nokta+h/2);
	b=fonksiyonbul(derece,katsayi,nokta-h/2);
	c=(a-b)/h;
	return c;
}
void fonksiyonal(int *derece,float katsayi[1000])
{
	int i;
	printf("fonksiyonun derecesini girin:");
	scanf("%d",derece);
	for(i=0;i<=(*derece);i++)
	{
		printf("%d. derecenin katsayisi:",i);
		scanf("%f",&katsayi[i]);
	}
	
}
float fonksiyonbul(int derece,float katsayi[1000],float eleman)
{
	int i,j;
	float x,toplam=0;
	for(i=0;i<=derece;i++)
	{
		x=1;
		for(j=0;j<i;j++)
		{
			x=x*eleman;
		}
		toplam=toplam+x*katsayi[i];
	
	}
	return toplam;
	
}
int main(int argc, char *argv[]) 
{
	
	int derece;
	char ch[10];
	printf("hangi yontemi istediginizi girin(gerifark --g)(ileri fark --i)(merkezifark --m):");
	scanf(" %c",ch);
	float h,nokta,sonuc;
	float katsayi[1000];
	fonksiyonal(&derece,katsayi);
	printf("hangi noktanin turevi:");
	scanf("%f",&nokta);	
	printf("h degerini girin:");
	scanf("%f",&h);
	
	
	if(ch[0]=='i')
	{
		sonuc=ilerifark(nokta,h,derece,katsayi);
	}
	else if(ch[0]=='g')
	{
		sonuc=gerifark(nokta,h,derece,katsayi);
	}
	else if(ch[0]=='m')
	{		
	    sonuc=merkezifark(nokta,h,derece,katsayi);
	}
	printf("%f",sonuc);
	
	

	return 0;
}
