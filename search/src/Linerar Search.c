#include <stdio.h>
#define endl printf("\n")

int main()
{
	int f, arr[5], i;

	printf("enter array \n");

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf(" the array is ");
	endl;

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("Enter find element: ");
	scanf("%d", &f);
	endl;

	for (i = 0; i < 5; i++)
	{
		if (arr[i] == f)
		{
			printf("%d found at index %d", f, i);
			endl;
		}
	}
	if (i == n)
		printf("item not found");
	endl;
}