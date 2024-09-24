#include<iostream>

int length(int value)
{
    if(value < 0)
        value *=-1;
    if(value < 10)
        return 1;
    return 1 + length(value / 10);
}

int main()
{
    int n = -90;

    int n_length = length(n);
    std::cout<<n_length;
}