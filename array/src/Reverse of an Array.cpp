//39.
#include<stdio.h>
void input(int A[],int n)
{
	printf("\nEnter the elements in the array:\n");
	for(int i=0;i<n;i++)
	scanf("%d",&A[i]);
}
void print(int A[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d\t",A[i]);
}
void reverse(int A[],int n)
{
	for(int i=0;i<=n/2;i++)	
	{ 
		int x;
		x=A[i];
		A[i]=A[n-i];
		A[n-i]=x;
	}
}
int main()
{
	int n;
	printf("\nEnter the no of elements in the array:\n");
	scanf("%d",&n);
	int A[n];
	input(A,n);
	printf("\nThe entered array is:\n");
	print(A,n);
	reverse(A,n-1);
	printf("\n\nThe new reversed array is:\n");
	print(A,n);
}

