#include<iostream>>

void insertionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minJ = i;
        for (int j = i + 1; j<n;j++)
        {
            if(a[minJ] < a[j])
            {
                minJ = j;
            }
        }

        if(minJ == i)
            continue;
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
    int a[] = {1,2,3,5,6,67,123,1,2};
    int n = sizeof(a) / sizeof(int);
    insertionSort(a, n);
    print(a, n);
}