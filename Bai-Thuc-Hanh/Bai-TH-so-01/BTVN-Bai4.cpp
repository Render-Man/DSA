#include<iostream>


int total(int a[], int left, int right)
{
    if(left == right)
        return a[left];
    int mid = (left + right) / 2;
    return total(a, left, mid) + total(a, mid + 1, right);
}

int main()
{
    int a[] = {1, 2, 5, 2, 6, 9};
    std::cout<<total(a, 0, sizeof(a) / sizeof(int) - 1);
}