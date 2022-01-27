#include <iostream>



//*****Exponent of a Number Function*****//

long double Exponent(int x, int y)
{
  int b;
 if (y == 0)
   return 1;
 else
   {
    if (y == 1)
      return x;
    else
      b = x*(Exponent (x, (y-1)));
      return b;
  }

}
//******End Function*****//


int main()
{
    int a, b;
    std::cout << "Enter Base: ";
    std::cin >> a;
    std::cout << std::endl;
    std::cout << "Enter Index: ";
    std::cin >> b;
    std::cout << std::endl;
    std::cout << a << "^" << b <<" is equal to "
              << Exponent(a, b) << std::endl;
    std::cin.ignore();
    std::cin.get();

}