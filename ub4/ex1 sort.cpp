#include <iostream>

void selection_sort(int *a, int n)
{
    //Falls das Array weniger als zwei Elemente enthaelt, brauchen wir nichts zu machen
    if (n > 1)
    {
        //Finde den Index des minimalen Elements
        int min_i = 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[min_i] > a[i])
                min_i = i;
        }
        //Vertausche das minimale Element mit dem ersten Element
        //Das minimale Element ist jetzt an der richtigen Stelle
        int tmp = a[0];
        a[0] = a[min_i];
        a[min_i] = tmp;
        //Fahre fort mit dem Rest des Arrays
        selection_sort(a + 1, n - 1);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = 10;

    selection_sort(A, n);

    for (int i = 0; i < 10; i++)
        std::cout<<A[i]<<", ";
    std::cout<<"\n";

    return 0;
}