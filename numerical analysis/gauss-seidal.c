#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or adyour own getch, system("pause") or input loop */
       
int main(int argc, char *argv[]) 
{
	int d,i,j,k;
	float matris[100][100],dizi[100]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},toplam=0,prev,count=0,hata; 
	printf("kac degiskenli fonksiyon");
	scanf("%d",&d);
	for(i=0;i<d;i++)
	{
		printf("katsayilari kosegenler carpimi max olacak sekilde girin ve sonucu girin:\n");
		for(j=0;j<d+1;j++)
		{
			scanf("%f",&matris[i][j]);
		}
	}
	printf("hata miktari:");
	scanf("%f",&hata);
	i=0;
	while(count!=d)
	{
	    i=i%d;
		    toplam=0;
			for(k=0;k<d;k++)
			{
				if(i!=k)
				{
					toplam=toplam+(-matris[i][k]*dizi[k]);
				}
			}
			prev=dizi[i];
		    dizi[i]=(matris[i][d]+toplam)/matris[i][i];
		    
		    	if(fabs(prev-dizi[i])<hata)
	        	{
	         		count++;
	        	}
	        	i++;
	}
	for(i=0;i<d;i++)
	{
		printf("%f \n",dizi[i]);
	}
	
	
	
	return 0;
}
