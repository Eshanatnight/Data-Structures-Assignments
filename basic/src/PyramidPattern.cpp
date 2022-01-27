#include <iostream>
using namespace std;
int main()
{  int i, l, j, k, n; 
   cout<<"enter number of rows ";
   cin>>n;
   for(i=n;i>0;i--)
   {
     for(k=1;k<i;k++)
     {
       cout<<" ";
     }
     for(j=2*n-1;j>=2*i-1;j--)
     {
       cout<<"*";
     }
     cout<<endl;

   }
}