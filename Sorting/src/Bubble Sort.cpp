#include<stdio.h>
void bubble_sort(int A[],int n)
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(A[j]>A[j+1])
      {
        A[j]=A[j]+A[j+1];
        A[j+1]=A[j]-A[j+1];
        A[j]=A[j]-A[j+1];
      }
    }
    printf("\n\nAfter pass %d:\n",i+1);
    printf(A,n);
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
  bubble_sort(A,n);
  printf("\n\nThe sorted array is:\n");
  print(A,n);
}

