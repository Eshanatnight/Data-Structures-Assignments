#include <bits/stdc++.h>

int binarySearch(int num[], int low, int high, int find);

int main()
{
    int nums[] = {1, 2, 3, 5, 10, 20, 30, 40, 50, 60, 70};

    int find;
    std::cout << "Enter object to find: ";
    std::cin >> find;

    int NumberOfElems = sizeof(nums) / sizeof(nums[0]);

    std::cout << "Index of number: " << binarySearch(nums, 0, NumberOfElems - 1, find) + 1 << std::endl;

    return 0;
}

int binarySearch(int num[], int low, int high, int find)
{
    if (low > high)
        return -1;

    int middle = low + (high - low) / 2;

    if (num[middle] == find)
        return middle;

    if (find < num[middle])
    {
        return binarySearch(num, low, middle - 1, find);
    }

    else
    {
        return binarySearch(num, middle + 1, high, find);
    }
}
