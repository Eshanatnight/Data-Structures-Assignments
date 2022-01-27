#include <iostream>
#define endll std::cout << std::endl



//*****Function To Find Odd Numbers Between*****//

void oddNumbers(unsigned int First_Num, unsigned int Second_Num )
{
  if(First_Num > Second_Num)
  {
    std::cout << "Error in Input" << std::endl;
    std::cout << "Please Input Correctly" << std::endl; endll;
  }
  
 else
 {
   std::cout << "The Odd Numbers between " << First_Num << " and "
           << Second_Num << " are" << std::endl;
           
  while(First_Num <= Second_Num)
    {
      if(First_Num % 2 != 0)
        std::cout << First_Num << " ";
      ++First_Num;
    }
 }
 
}

//*****End Function*****//
  
  

int main()
{
    unsigned int start, end;
    char inp;
     
    re:
       
    std::cout << "Enter The First Number: \t";
    std::cin >> start;
    endll;
    std::cout << "Enter Second Number: \t";
    std::cin >> end;
    endll;
    
    oddNumbers(start, end);
    
    std::cout << "Run Again? (Y/N) \t";
    std::cin >> inp;
    
    if(inp == 'Y')
        goto re;
    else 
        return 0;
}