#include<stdio.h>
int main()
{
  int n,a[20],max,min,i;
  printf("Enter the limit");
  scanf("%d",&n);
  printf("Enter the numbers");
  for(i=0;i<n;i++)
  {
    scanf("%d",a[i]);
  }
  max=a[0];
  min=a[0];
  for(i=0;i<n;i++)
  {
    if(a[i]>max)
    {
      max=a[i];
    }
    else if(a[i]<min)
    { 
      min=a[i];
    }
  }
  printf("The maximum number of the array is %d",max);
  printf("The minimum number of the array is %d",min);
}

