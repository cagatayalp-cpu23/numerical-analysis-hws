#include<stdio.h>
#include<conio.h>
#include<math.h>




int main()
{
		 float a[100][100], bolum;
		 int i,j,k,der;
		
		 printf("Dizinin boyutunu girin");
		 scanf("%d", &der);
		 printf("Elemanlari girin:\n");
		 for(i=0;i<der;i++)
		 {
			  for(j=0;j<der;j++)
			  {
				   printf("a[%d][%d]= ",i,j);
				   scanf("%f", &a[i][j]);
			  }
		 }
		 for(i=0;i<der;i++)
		 {
			  for(j=0;j<der;j++)
			  {
				   if(i==j)
				   {
				    	a[i][j+der] = 1;
				   }
				   else
				   {
				    	a[i][j+der] = 0;
				   }
			  }
		 }
		 
		 for(i=0;i<der;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   printf("tekrar girin");
				   
			  }
			  for(j=0;j<der;j++)
			  {
				   if(i!=j)
				   {
					    bolum = a[j][i]/a[i][i];
					    for(k=0;k<2*der;k++)
					    {
					     	a[j][k]=a[j][k]-bolum*a[i][k];
					    }
				   }
			  }
		 } 
		
		 
		 for(i=0;i<der;i++)
		 {
			  for(j=der;j<2*der;j++)
			  {
			   	a[i][j]=a[i][j]/a[i][i];
			  }
		 }
		 printf("\nTers Matris :\n");
		 for(i=0;i<der;i++)
		 {
			  for(j=der;j<2*der;j++)
			  {
			   	printf("%0.3f\t",a[i][j]);
			  }
			  printf("\n");
		 }
		 
		 return 0;
}
