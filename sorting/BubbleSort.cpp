#include<iostream>>

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if(a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[i] = temp;
            }
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
    int a[] = {1,2,3,5,6,67,123,1,2};
    int n = sizeof(a) / sizeof(int);
    bubbleSort(a, n);
    print(a, n);
}