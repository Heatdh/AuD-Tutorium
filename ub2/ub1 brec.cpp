#include <iostream>
float pi(int n)
{
    if (n == 0)
        return 4;
    return (4 - 8 * (n % 2)) / (2 * n + 1.0) + pi(n - 1);
}

int main () {
    float x;
    x = pi(500) ;
    std::cout << x;


}