#include<iostream>

void insertionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int temp = a[i + 1];
        for (int j = i; j > 0; j--)
        {
            if(a[j] > temp)
            {
                a[j+1] = a[j];
                continue;
            }
            
            a[j+1] = temp;
            break;
        }   
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout<<a[i] <<" ";
    }
    
}

int main()
{
    int a[] = {1,2,31,5,6,67,123,1,2};
    int n = sizeof(a) / sizeof(int);
    insertionSort(a, n);
    print(a, n);
}