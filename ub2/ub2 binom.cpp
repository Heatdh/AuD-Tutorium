#include <stdio.h>
#include <iostream>


const int N = 1000;
long long lookup[N][N] = {0};
long long binom(int n, int k)
{
    
    if (lookup[n][k] == 0)
    {
        if (k == 0 || k == n)
            lookup[n][k] = 1;
        else
            lookup[n][k] = binom(n-1, k-1) + binom(n-1,k);
    }
    //std::cout<< lookup[1][1];
    return lookup[n][k];
}
int main()
{
    //Test
    int n = 8;
    int k = 4;
    printf("binom : %lld\n", binom(n, k));
}