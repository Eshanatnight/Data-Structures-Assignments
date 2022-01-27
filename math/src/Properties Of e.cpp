
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
  double n;
  double i=1, t=1, s=1;
  cout<<"Enter n"<<endl << endl;
  cin>> n; cout<<endl;
  cout << "Series For e till " << n << "th term is" << endl << endl;
  while (i<=n)
  {
    
    t/=i;
    cout << (float)t;
    if(i != n) { cout << " + "; }
    s+=t;
    //cout << "Iteration  " << i << endl;
    i++;
    
    } 
    cout<< endl << endl;
  cout<<"The Value of e for n= "<<n<<" is "<<s<<endl;

}  