/*C program to generate a spiral matrix with user entered limit*/
#include <stdio.h>
#include <math.h>
#include <conio.h>
int main()
{
	int A[10][10];
	int N,L,M,i,j,a=1,b=2,x;
	printf("\n Enter the number ");
	scanf("%d",&N);
	L=N*N;
	if (N%2==0)
	{
		M=(N/2)-1;
	}
	else
	{
		M=N/2;
	}
	i=M,j=M;
	A[M][M]=1;
	while(b<=L)
	{
		if(i==j)
		{
			for(x=1;x<=a;x++)
			{
				j=(j+pow(-1,a+1)*1);
				A[i][j]=b++;
			}
			a++;
		}
		else if(i<j)
		{
			while(i!=j)
			{
				A[++i][j]=b++;
			}
		}
		else if(i>j)
		{
			while (i!=j)
			{
				A[--i][j]=b++;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		printf("\n");
		for(j=0;j<N;j++)
		{
			printf("\t %d",A[i][j]);
		}
	}
	getch();
}
