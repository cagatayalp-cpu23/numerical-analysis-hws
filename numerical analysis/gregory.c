#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void gergory(float *x)
{
	int N,i,l;
	float matris[100][100],dizi[1000],dizi1[1000],count[1000]={0},matris1[100][100],fact=1,carpim=1,toplam=0,h;
	printf("kac tane deger gireceksiniz:");
	scanf("%d",&N);
	printf("h i girin:");
	scanf("%f",&h);
	for(i=0;i<N;i++)
	{
		printf("x[%d] ve f[%d] girin;\n",i,i);
		scanf("%f %f",&matris[i][0],&matris[i][1]);
	}
	printf("hesaplanmasi istenen noktayi girin");
	scanf("%f",x);
	 i=1;
	 int j=0,k,n,c=0,t=0,u=0,a;
	n=N;
	while(!c)
	{
		
		j=t;
		while(j<n-1)
    	{
	    	matris[j+1][i+1]=matris[j+1][i]-matris[j][i];
	    	
	    	
	    	j++;
	    	
     	}
		 t++; 
     	a=t;
    	while(matris[a][a+1]==matris[a+1][a+1]&&a<n-1)
     	{
     		a++;
		 }
		 if(a==n-1)
		 {
		 	c++;
		 }
		 i++;
		
		
     	
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<t+2;j++)
   {
	    
		printf("%f\t   ",matris[i][j]);
	}
    	printf("\n");
    	
	}
	
	for(i=0;i<t+1;i++)
	{
		fact=1;
		carpim=1;
		for(j=0;j<i;j++)
		{
			carpim=carpim*((*x)-matris[j][0]);
			
			fact=fact*(j+1);
			
		}
		toplam=toplam+matris[i][i+1]*carpim/(pow(h,i)*fact);
		
	}
	printf("\n**********************\n");
	printf("%f",toplam);
	
	
	
	
}
int main(int argc, char *argv[]) 
{
	float nokta;
	gergory(&nokta);
	return 0;
}
