#include <stdio.h>

//*****Fibonacci Function*****//
  
  int Fib(int i)
  {
    if (i == 0 || i == 1)
      return 1;
    else
      return (Fib(i-1) + Fib(i-2));
  }

//*****End Function****//
  

int main()
{
  
  int n;
  
  printf("Enter Number of terms: ");
  scanf("%d",&n);
  printf("%dth Term of The Fibonacci Sequence is %d",n, Fib(n));
}