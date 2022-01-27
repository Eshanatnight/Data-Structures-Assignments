#include<stdio.h>
#define ret return

int sum=0,rem;
reverse_function(int num)
{
   if(num)
   {
      rem=num%10;
      sum=sum*10+rem;
      reverse_function(num/10);
   }
   else
      ret sum;
   ret sum;
}


int main(){
   int num,rev;

   printf("\nEnter any number:");
   scanf("%d",&num);
   rev=reverse_function(num);
   printf("\nAfter reverse the no is :%d",rev);
   ret 0;
}
