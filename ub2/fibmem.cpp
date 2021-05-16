#include <stdio.h>




int fibrec(int n)
{
    if (n <= 1)
        return n;
    return fibrec(n-1) + fibrec(n-2);
}
 

long fib(int n)
{
    // globale Variable, die sofort initialisiert wird
    static long *lookup = new long[93];

    if (lookup[n] > 0)
        return lookup[n];
    if (n > 1)
    {
        lookup[n] = fib(n - 1) + fib(n - 2);
        return lookup[n];
    }
    else
        return n;
}
int main()
{
    printf("%ld\n", fib(6));
}
