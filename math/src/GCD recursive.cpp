#include <iostream>


//*****GCD Recursive Function*****//
  
  int GCD (int a, int b)
  {
    if (b !=0)
      GCD(b, a%b);
    else
      return a;
  }

//*****End Function*****//
  
  
int main()
{
  int a, b;
  std::cout << "Enter First Number: ";
  std::cin >> a;
  std::cout << "Enter Second Number: ";
  std::cin >> b;
  std::cout << GCD(a, b);
}