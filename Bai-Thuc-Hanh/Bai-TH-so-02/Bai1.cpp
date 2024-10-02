#include <iostream>
#include <algorithm>

void pick(int a[], int n, int i, int s, int t)
{
    while (t + a[i] <= s)
    {
        t += a[i];
        std::cout << a[i] << " ";
    }

    i--;

    if (i < 0)
        return;

    pick(a, n, i, s, t);
}

int main()
{
    int n = 9;
    int a[] = { 1,2,3,5,7,4,9,6,2 };
    int s = 20;

    std::sort(a, a + n);

    pick(a, n, n-1, s, 0);

    return 0;
}