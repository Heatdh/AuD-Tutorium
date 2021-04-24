#include <iostream>

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int su;
    su = sum(6, 7);
    std::cout << su;
    int x = 0;
    while (x < 10)
    {
        x = x + 1;
        std::cout << x;
    }
}
