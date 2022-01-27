#include <iostream>
#define endll std::cout << std::endl

//*****Sum of Even Number Function*****//

  int sumEvenNumbers(unsigned int firstNum, unsigned int secondNum)
  {
    int ret = 0;
    while(firstNum <= secondNum)
    {

      if(firstNum % 2 == 0)
      {
        ret += firstNum;
      }

      ++firstNum;
    }
    return ret;
  }

//*****End Function*****//


int main()
{
    unsigned int sumEven;
    unsigned int firstNum, secondNum;

    std::cout << "Enter First Number: \t";
    std::cin >> firstNum;
    std::cout << "Enter Second Number: \t";
    std::cin >> secondNum;
    endll;

    sumEven = sumEvenNumbers(firstNum, secondNum);

    std::cout << "The Sum of all Even Numbers between "
              <<firstNum << " and "  << secondNum << " is "
              << sumEven;
}