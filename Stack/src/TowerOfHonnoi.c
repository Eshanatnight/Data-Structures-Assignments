#include <stdio.h>
#include <string.h>



//*****Tower Of Honnoi Function*****//

const char* Honnoi(int n, const char* src, const char* desti, const char* aux)
{
    if (n == 1)
        printf("Move disk 1 from %s to rod %s ", src, desti);
    else
    {
        Honnoi(n - 1, src, aux, desti);
        printf("Move disk %d from %s to rod %s ",n ,src ,desti);
        Honnoi(n - 1, aux, desti, src);
    }
}

//******End Function*****//


int main()
{
    int a;
    char A1[10], A2[10], A3[10];
    printf("Enter Number of Disks: ");
    scanf("%d", &a);
    printf("Enter Name of Source Tower: ");
    scanf("%s", &A1);
    printf("Enter Name of Destination Tower: ");
    scanf("%s", &A2);
    printf ("Enter Name of Auxiliary Tower: ");
    scanf("%s", &A3);

    Honnoi(a, A1, A2, A3);
