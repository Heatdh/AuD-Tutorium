#include <stdio.h>
// Potenzfunktion (man kann diese effizienter implementieren)
// easier for the compiler to optimize the code.
int pow(int x, int y)
{
    int res = 1;
    for (int i = 0; i < y; i++)
        res *= x;
    return res;
}
// Hilfsfunktion g endrekursiv
int g_hilf(int x, int y, int calc)
{
    if (x < 10)
        return calc + pow(x, y);
    return g_hilf(x / 10, y + 1, calc + pow(x % 10, y));
}


// Funktion g endrekursiv
int g_tailrec(int x, int y)
{
    return g_hilf(x, y,0);
}

// Funktion g iterativ
int g_iter(int x, int y)
{
    int calc = 0;
    while (x >= 10)
    {
        calc += pow(x % 10, y);
        y += 1;
        x /= 10;
    }
    calc =calc + pow(x, y);
    return calc;
}
int main()
{
    int n = 132;
    printf("f tailrec : %d\n", g_tailrec(n, 0));
    printf("f iter : %d\n", g_iter(n,0));
}