#include <iostream>

/**
 * @brief  naive Search by iterating the whole array 
 * 
 * @param a a filled array
 * @param x element to look for 
 * @param n size of the array
 */
void search(int *a, int x, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            std::cout << x << " found in index : " << i;
        if (i == n - 1 && a[i] != x)
            std::cout << x << " not found ";
    }
}

//testing the search function
int main()
{

    int x = 453;
    int a[5] = {16, 2, 77, 40, 12071};
    search(a, x, 5);
}