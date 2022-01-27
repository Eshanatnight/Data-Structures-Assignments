#include <iostream>
#include <cmath>
#include <iomanip>
#define endll std::cout << std::endl


//******Print Function*****//
  
  void displaySquareNumbers(short int start, short int end)
  {
    int sq;
    std::cout << std::setw(14) << "Number" << std::setw(14) << "Squares" << std::endl;
    while(start <= end)
     {
       sq = pow(start, 2);
       std::cout << std::setw(14) << start << std::setw(14) << sq << std::endl;
       ++start;
     }
  }


int main()
{
    short int s = 1, e = 10;
    
    displaySquareNumbers(s, e);
    
    
}