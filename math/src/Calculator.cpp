#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <conio.h>

#define endll std::cout << std::endl


const char* convert (char* arr)
{
  char c;
  for(int i = 0; i < strlen(arr); ++i)
   {
     if(isupper(arr[i]))
     {
       c = tolower(arr[i]);
       arr[i] = c;
     }
       
   }
  return arr;
}


struct calc
{
  public:
    float m_firstnum, m_secondnum;
    float m_result;
 
};


int main()
{   
    calc callo; 
    int n = 3; 
    char str[10];
    std::cout << "Calculator Online" << std::endl; endll;
    
    int ch = 0;
    
    re:
      
    std::cout << std::setw(10) << setiosflags(std::ios::right) 
              << "Menu" << std::endl; endll;
    std::cout << "Enter 1 for Addition"<< std::endl;
    std::cout << "Enter 2 for Substraction" << std::endl;
    std::cout << "Enter 3 for Multiplication" << std::endl;
    std::cout << "Enter 4 for Division" << std::endl;
    std::cout << "Enter 5 for Power of" << std::endl;
    std::cout << "Enter -1 for settings" << std::endl;
    endll;
    
    std::cout << "Enter Choice: \t";
    std::cin >> ch; endll; endll;
    
    
    if(ch != -1)
    {
      std::cout << "Enter First Number: \t";
      std::cin >> callo.m_firstnum;
      endll;
      std::cout << "Enter Second Number: \t";
      std::cin >> callo.m_secondnum;
      endll;
      endll;
    }
    
    
    switch(ch)
    {
      case 1: 
         callo.m_result = callo.m_firstnum + callo.m_secondnum;
         std::cout << "The result of addition of " 
                   << callo.m_firstnum << " and " 
                   << callo.m_secondnum << " is " 
                   << std::setprecision(n) << callo.m_result << std::endl;
         break;
         
         
      case 2:
        callo.m_result = callo.m_firstnum - callo.m_secondnum;
         std::cout << "The result of substraction of " 
                   << callo.m_firstnum << " and " 
                   << callo.m_secondnum << " is " 
                   << std::setprecision(n) << callo.m_result << std::endl;
         break;
         
         
      case 3:
         callo.m_result = callo.m_firstnum * callo.m_secondnum;
         std::cout << "The result of multiplication of " 
                   << callo.m_firstnum << " and " 
                   << callo.m_secondnum << " is " 
                   << std::setprecision(n) << callo.m_result << std::endl;
         break;
         
         
       case 4:
         callo.m_result = callo.m_firstnum / callo.m_secondnum;
         std::cout << "The result of division of " 
                   << callo.m_firstnum << " and " 
                   << callo.m_secondnum << " is " 
                   << std::setprecision(n) <<callo.m_result << std::endl;
         break;
       
       
       case 5:
         callo.m_result = pow(callo.m_firstnum, callo.m_secondnum);
         std::cout << "The result of division of " 
                   << callo.m_firstnum << " and " 
                   << callo.m_secondnum << " is " 
                   << std::setprecision(n) <<callo.m_result << std::endl;
         break;
       case -1:
         std::cout << "Change Decimal Precision?" << std::endl;
         std::cout << "(currently set to 3)" << std::endl;
         std::cin.ignore();
         std::cin.get(str, 10);
         convert(str);
         if(strcmp(str, "yes") == 0)
         {
           std::cout << "Enter Precision: ";
           std::cin >> n;
         }
            
         goto re;
    }
   endll; endll;
   std::cout << "Would You Like to Perform More Calculations?";
   endll;
   std::cin.ignore();
   std::cin.get(str, 10);
   strcpy(str, convert(str));
   if(strcmp(str, "yes") == 0)
   {
     clrscr();
     goto re;
     
   }
     
   else
     std::cin.get();
}