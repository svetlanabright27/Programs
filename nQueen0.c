#include <stdio.h>
int ROW[20];
int COLUMN[20];
int TOP=-1;
int count=0;
int total=0;
int ORDER;
void PUSH(int,int);
void POP();
void DISPLAY();
int CHECK(int,int);
int PLACE(int,int);
void EXECUTE(int,int,int);
void PUSH(int a,int b)
{
	TOP++;
	ROW[TOP]=a;
	COLUMN[TOP]=b;
}
void POP()
{
	TOP--;
	total--;
}
void DISPLAY()
{
	int i,j,k,flag=0;
	printf("\n");
	for(i=0;i<=TOP;i++)
	printf("	(%d , %d)\n",ROW[i],COLUMN[i]);
	printf("\n");
	for(i=0;i<ORDER;i++)
	{
		for(j=0;j<ORDER;j++)
		{
			for(k=0;k<=TOP;k++)
			{
				if ((ROW[k]==i)&&(COLUMN[k]==j))
				flag=1;
			}
			if (flag==1)
			printf(" o ");
			else
			printf(" * ");
			flag=0;
		}
		printf("\n");
	}
}
int CHECK(int R,int C)
{
	int c=0,i=0;
	while(i<=TOP)
	{
		if((ROW[i]==R)||(COLUMN[i]==C)||(abs(ROW[i]-R)==abs(COLUMN[i]-C)))
		c++;
		i++;
	}
	return c;
}
int PLACE(int K,int L)
{
	if((K==ROW[0])&&(L==COLUMN[0]))
	return count;
	else if (CHECK(K,L)==0)
	{
		PUSH(K,L);
		count++;
	}
	if(L==ORDER-1)
	{
		if(K==ORDER-1)
		PLACE(0,0);
		else
		PLACE(K+1,0);
	}
	else
	PLACE(K,L+1);
}
void EXECUTE(int queens, int row,int column)
{
	total=total+PLACE(row,column);
	count=0;
	if (total==queens)
	DISPLAY();
	else
	{
		if((ROW[TOP]==ORDER-1)&&(COLUMN[TOP]==ORDER-1))
		POP();
		POP();
		if(COLUMN[TOP+1]==ORDER-1)
		EXECUTE(queens,ROW[TOP+1]+1,0);
		else
		EXECUTE(queens,ROW[TOP+1],COLUMN[TOP+1]+1);
	}
}
void main()
{
	int num;
	printf("___THIS IS THE N-QUEEN PROBLEM.THE USER PROVIDES THE NUMBER OF QUEENS N AND ORDER AND IT RETURNS THE BEST POSITIONS TO PLACE N QUEENS ON A [ORDER*ORDER] BOARD SO THEY DO NOT CROSS EACH OTHER___ \n");
	printf("\nENTER ORDER AND NUMBER OF QUEENS\n");
	scanf("%d %d",&ORDER,&num);
	if(num>ORDER)
	printf("NOT POSSIBLE");
	else
	EXECUTE(num,0,0);	
}
