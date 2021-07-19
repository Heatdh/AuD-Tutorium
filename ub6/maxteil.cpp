#include <iostream>

int max_sequence(int *a, int n)
{
    if (n <= 0)
        return 0;
    int m = n / 2;
    int maxl = max_sequence(a, m);
    int maxr = max_sequence(a + m + 1, n - m - 1);
    int left = 0;
    int best_left = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        left += a[i];
        if (left > best_left)
            best_left = left;
    }
    int right = 0;
    int best_right = 0;
    for (int i = m + 1; i < n; ++i)
    {
        right += a[i];
        if (right > best_right)
            best_right = right;
    }
    int res = a[m] + best_left + best_right;
    if (maxl > res)
        res = maxl;
    if (maxr > res)
        res = maxr;
    return res;
}

int main()
{
    int A[] = {-11, -13, 7, 12, -16, -9, -24, 5, 10, 6};
    int n = 10;

    int res = max_sequence(A, n);

    std::cout << res;
    return 0;
}
