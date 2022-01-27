#include <iostream>

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
  int n, j, i, sum;
  
  std::cout << "Enter Number of terms: ";
  std::cin >> n;
  std::cout << std::endl;
  std::cout << "The series is:" << std::endl;
  std::cout << "0 ";
  for(i = 0, sum = 0 ; i < n; i++)
    {
      j=Fib(i);
      sum += j;
      std::cout << j << "  ";
    }
  std::cout << std::endl;
  std::cout << "The sum of the series is: " << sum;
  std::cin.ignore();
  std::cin.get();
}