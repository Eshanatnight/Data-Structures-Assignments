#include <iostream>
#define endll std::cout << std::endl


struct Fraction
{
  public:
    int numerator;
    int denominator;
};

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
    Fraction F[3]; //stored in array pattern for easy of use
    int gcd;
    std::cout << "Enter First Fraction: \t" << std::endl;
    std::cin >> F[0].numerator >> F[0].denominator;
    
    std::cout << "Enter Second Fraction: \t" << std::endl;
    std::cin >> F[1].numerator >> F[1].denominator;
    
    gcd = GCD(F[0].denominator, F[1].denominator);
    
    if(gcd != 1)
    {
      F[0].numerator *= gcd;
      F[0].denominator *= gcd;
      F[1].numerator *= gcd;
      F[1].denominator *= gcd;
    }
    
    else
    {
      if(gcd = 1)
      {
        int ch = F[0].denominator;
        F[0].numerator *= F[1].denominator;
        F[0].denominator *= F[1].denominator;
        F[1].numerator *= ch;
        F[1].denominator *= ch;
      }
      
      else 
        std::cout << "Error Line 63/ GCD function \t" << std::endl;
    }
    
    
    F[2].numerator = F[0].numerator + F[1].numerator;
    F[2].denominator = F[0].denominator;
    
    std::cout << "The result is: \t" << F[2].numerator << "  "
              << F[2].denominator << std::endl;
}