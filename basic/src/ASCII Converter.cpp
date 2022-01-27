#include <iostream>
using namespace std;

int main()
{
 int i=1;
 while (i == 1)
 {
  char c;
  cout << "\t \t \t \t \t \t \t Enter a character: ";
  cin >> c;
  cout << "\t \t \t \t \t \t ASCII Value of " << c << " is " << int(c)<< endl;
  cout<< "\t \t \t Press 1 to Perform again or Press A" <<endl <<"\t \t \t \t \t Press Enter after the beep \a";
  cin>> i;
 }
 return 0;
}