//41.
#include<stdio.h>
void input(int rw,int cl,int A[][100])
{
	for(int i=0;i<rw;i++)
	for(int j=0;j<cl;j++)
	scanf("%d",&A[i][j]);
}
void print(int rw,int cl,int A[][100])
{
	for(int i=0;i<rw;i++)
	{
		for(int j=0;j<cl;j++)
		printf("%d\t",A[i][j]);
		printf("\n");	
	}
	
}
void mult(int A[][100],int B[][100],int rw1,int cl1,int rw2,int cl2,int C[][100])
{
	for(int i=0;i<rw1;i++)
	{
		for(int j=0;j<cl2;j++)
		{
			int term=0;
			for(int k=0;k<cl1;k++)
			{
				term=term+(A[i][k]*B[k][j]);
			}
			C[i][j]=term;
		}
	}
}
void trans(int A[][100],int rw,int cl)
{
	for(int i=0;i<rw;i++)
	for(int j=0;j<cl;j++)
	{
		 if(i<j)
		 {
			A[i][j]=A[i][j]+A[j][i];
			A[j][i]=A[i][j]-A[j][i];
			A[i][j]=A[i][j]-A[j][i];	
		 }
	}
}
int main()
{
	int rw1,cl1,rw2,cl2;
	printf("Enter the no of Rows and Cols of A:\n");
	scanf("%d%d",&rw1,&cl1);
	printf("Enter the no of Rows and Cols of B:\n");
	scanf("%d%d",&rw2,&cl2);
	int A[rw1][100],B[rw2][100];
	printf("\nEnter the elements in the array A:\n");
	input(rw1,cl1,A);
	printf("\nEnter the elements in the array B:\n");
	input(rw2,cl2,B);
	printf("\nThe array A with row:%d & column:%d is:\n",rw1,cl1);
	print(rw1,cl1,A);
	printf("\nThe array B with row:%d & column:%d is:\n",rw2,cl2);
	print(rw2,cl2,B);
	if(rw1==cl2)
	{
		int C[rw1][100],D[rw1][100];
		printf("\nMatrix multiplication of A and B is possible.\n");
		mult(A,B,rw1,cl1,rw2,cl2,C);
		printf("\nThe resultant array C after matrix multiplication with row:%d & column:%d is:\n",rw1,cl2);
		print(rw1,cl2,C);
		printf("\nThe resultant array D with row:%d & column:%d after matrix transpose of C is:\n",cl2,rw1);
		trans(C,rw1,cl2);
		print(cl2,rw1,C);
	}
	else
	printf("\nMatrix multiplication of A and B is not possible.\n");
}

