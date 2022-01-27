#include <iostream>

//*****Largest No. Finder Function*****//
  
  int Large(int a, int b, int c)
   {
     if (a > b && a > c)
       return a;
     else
      {
        if(b > c)
         return b;
        
        else
         return c;
      }
   }

//*****End Function*****//
  
  
 int main()
 
 {
   
   int x, y, z;
   
   std::cout << "Enter First Number: ";
   std::cin >> x;
   std::cout << std::endl;
   
   std::cout << "Enter Second Number: ";
   std::cin >> y;
   std::cout << std::endl;
   
   std::cout << "Enter Third Number: ";
   std::cin >> z;
   std::cout << std::endl;
   
   std::cout << "The Largest Number is: " 
             << Large(x, y, z) << std::endl;
   
 }