#include <iostream>

struct Placebo
{
  int m_one, m_two;
  
  Placebo ()
  {
    m_one = 0;
    m_two = 0;
  }
};


int main()
{
    Placebo P;
    
    std::cout << "Enter First Number: ";
    std::cin >> P.m_one;
    std::cout << std::endl; 
    
    std::cout << "Enter Second Number: ";
    std::cin >> P.m_two;
    std::cout << std::endl << std::endl; 
    
    std::cout << "The Numbers before Swaping are " << P.m_one
              << " and " << P.m_two << std::endl;
              
    P.m_one = P.m_one ^ P.m_two;
    P.m_two = P.m_one ^ P.m_two;
    P.m_one = P.m_one ^ P.m_two;
    
    std::cout << "The Numbers after Swaping are " << P.m_one
              << " and " << P.m_two << std::endl;
    
}