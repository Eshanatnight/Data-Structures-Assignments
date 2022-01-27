#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ret return


//Cap Check Function
void CheckCap(const char* str)
{
    char choice[5];
    if(isupper(str[0]) != 0)
      printf("The First Letter Of this string is capitalized");
    else if(islower(str[0]) != 0 )
        {
           printf("Do You Wish To Capitalize The first Letter?(Yes/No) \n");
           scanf("%s", &choice);
         
           if(strcmp(choice,"Yes") == 0)
           {
             ChangeCaps(str);
             printf("The new string is \" %s \"", str);
           }
              
           else if(strcmp(choice,"No") == 0)
              printf("Ok");
           else
             printf("incompatible input");
        }
}

void ChangeCaps(char* str)
{
    str[0] = toupper(str[0]);
}


//Frequency check Function

void FreChk(const char* str)
{
    int count = 0, length;
    char obj;
    printf("Enter Charecter to find: ");  
    scanf(" %c", &obj)
    length = strlen(str);
    
    for(int i = 0; i < length; i++)
      {
          if(str[i] == obj)
             count++;
      }
    printf("%c occurs in the string %d times", obj, count);
      
}

//Lexicology Check

void lexichk() 
{
   char str[5][50], temp[50];
   printf("Enter 5 words: ");

   for (int i = 0; i < 5; ++i) 
   {
      fgets(str[i], sizeof(str[i]), stdin);
   }

   for (int i = 0; i < 5; ++i) 
   {
      for (int j = i + 1; j < 5; ++j) 
      {

         if (strcmp(str[i], str[j]) > 0) {
            strcpy(temp, str[i]);
            strcpy(str[i], str[j]);
            strcpy(str[j], temp);
         }
      }
   }

   printf("\nIn the lexicographical order: \n");
   for (int i = 0; i < 5; ++i)
   {
      fputs(str[i], stdout);
   }
}


int main()
{
  char cstring[50], obj;
  int choice;
  
  
  printf("Press 1 for Caps Checking\n");
  printf("Press 2 for Frequency Checking\n");
  printf("Press 3 for Lexicological sorting\n");
  scanf("%d", &choice);
  if(choice != 3)
    {
        printf("Enter A String: ");
        scanf("%s", &cstring);
    }

  switch(choice)
  {
    case 1:
        CheckCap(&cstring);
        break;
        
    case 2:
          FreChk(&cstring);
          break;
    case 3:
          lexichk();
          break;
    default:
       printf("Unknown Input \n");
       break;
  }
  
  
  ret 0;
}