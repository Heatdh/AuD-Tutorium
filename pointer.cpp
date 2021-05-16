#include <iostream>
#include <memory>

int main()
{
    int *p;
    int a = 4;
    p = &a;
    std::cout << "the address of the pointer is: " << p << "\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << i;
    }
}