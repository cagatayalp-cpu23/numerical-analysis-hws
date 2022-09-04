#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void fonksiyonalma(int *derece,float katsayi[10000])
{
	int i,j,toplam=0,x=1;
	printf("Kacinci derece oldugunu girin:");
	scanf("%d",derece);
	for(i=0;i<=(*derece);i++)
	{
		printf("%d. derecenin katsayisini girin\n",i);
		scanf("%f",&katsayi[i]);
		
	}
	
}
float sonuc(float nokta,int *derece,float katsayi[10000])
{
	int i,j,x=1;
	float toplam=0;
	float carpim=1;

	for(i=0;i<=(*derece);i++)
	{
		carpim=1;
		for(j=0;j<i;j++)
		{
			carpim=carpim* nokta;
		}
		carpim=carpim*katsayi[i];
		toplam=toplam+carpim;
	}
	return toplam;
}
int main(int argc, char *argv[]) 
{
	float nokta, katsayi[10000],aralik1,aralik2,sonuc1,sonuc2,deger,hata,temp[1000],temp1,temp2;
	int derece,i=0;
	fonksiyonalma(&derece,katsayi);
	printf("1. ve 2. araligi girin:(kucukten buyuge)\n");
	scanf("%f %f",&aralik1,&aralik2);
	printf("hata degerini girin:");
	scanf("%f",&hata);
	sonuc1=sonuc(aralik1,&derece,katsayi);
	sonuc2=sonuc(aralik2,&derece,katsayi);
	if(sonuc1*sonuc2<0)
	{
		printf("bu aralikta kok vardir\n");
		temp[0]=-INFINITY;
	
		do
		{
			
		temp1=sonuc(aralik2,&derece,katsayi);
		temp2=sonuc(aralik1,&derece,katsayi);
		deger=(aralik1*temp1-aralik2*temp2)/(temp1-temp2);
		if(sonuc(deger,&derece,katsayi)*sonuc1<0)
		{
			aralik2=deger;
			sonuc2=sonuc(deger,&derece,katsayi);
			i++;
			temp[i]=aralik2;
			
			
		}
		else if(sonuc(deger,&derece,katsayi)*sonuc2<0)
		{
			aralik1=deger;
			sonuc1=sonuc(deger,&derece,katsayi);
			i++;
			temp[i]=aralik1;
			
			
		}
	}while(fabs(temp[i]-temp[i-1])>hata);
	printf("kok: %f",temp[i]);
	}
	else if(sonuc1==0)
	{
		printf("kok: %f",aralik1);
	}else if(sonuc2==0)
	{
		printf("kok: %f",aralik2);
	}
	
	
	return 0;
}
