#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void gauss(float matris[100][100],int n)
{
	int i,j,k;
	float carpan,tmp,toplam=0,dizi[100];
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			carpan=matris[j][i]/matris[i][i];
			for(k=0;k<n+1;k++)
			{
				matris[j][k]=matris[j][k]-carpan*matris[i][k];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		tmp=matris[i][i];
	    for(j=0;j<n+1;j++)
	    {
	    	matris[i][j]=matris[i][j]/tmp;
		}
	}
	k=0;
	int t=n-1;
	for(i=n-1;i>=0;i--)
	{
		toplam=0;
	    for(j=0;j<n;j++)
	    {
	    	if(i!=j)
	    	{
	    		toplam=toplam+(matris[i][j]*dizi[j]);
			}
			
			
	    
		}
		dizi[t]=matris[i][n]-toplam;
		t--;
		
	}
	printf("sondan basa dogru kokler\n");
	for(i=t+1;i<n;i++)
	{
		printf("%f  ",dizi[i]);
	}
	printf("\n*******\n");
	
}
int main(int argc, char *argv[]) 
{
	float matris[100][100];
	int i,j,n;
	printf("kac satir oldugunu girin:");
	scanf("%d",&n);
	printf("matrisi girin:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			printf("[%d] [%d]",i,j);
			scanf("%f",&matris[i][j]);
		}
	}
	gauss(matris,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			if(j==n)
			{
				printf("====%f",matris[i][j]);
			}
			else
			{
				printf("%f  ",matris[i][j]);
			}
			
		}
		printf("\n");
	}
	
	
	return 0;
}
