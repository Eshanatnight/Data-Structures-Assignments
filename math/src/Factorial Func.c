#include <stdio.h>

//******Factorial Function******//

int Factorial(int a)
{ 
 int fact = 1;
  
  while(a > 0)
  {
    fact *= a;
    a--;
  }
 return fact;
}

//******End Function*****//


int main()
{
  int n;
  printf("Enter Number of which you want to find the Factorial: ");
  scanf("%d", &n);
  printf("\nFactorial of %d is %d", n, Factorial(n));
 }