#include<iostream>

void merge(int a[], int left, int right, int mid)
{
     if(a[mid] <= a[mid+1])
     {
         return;
     }
     
     int* copyarr = new int[right-left];
     
     for(int i = 0; i< right - left+1;i++)
     {
         *(copyarr+i) = a[i+left];
     }
     std::cout<<std::endl;
     
     int i1 = 0;
     int i2 = mid + 1 - left;
     int i = left;

     while(i1<=mid-left && i2<=right-left)
     {
        if(copyarr[i1] < copyarr[i2])
        {
            a[i] = copyarr[i1];
            i1++;
        }
        else
        {
            a[i] = copyarr[i2];
            i2++;
        }
        
        i++;
     }
     
     while(i1<=mid-left)
     {
         a[i] = copyarr[i1];
         i1++;
         i++;
     }
     
     while(i2<=right-left)
     {
         a[i] = copyarr[i2];
         i2++;
         i++;
     }
     
     delete[] copyarr;
}

void divide(int a[], int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    divide(a, left, mid);
    divide(a, mid+ 1, right);
    merge(a, left, right, mid);
}

void mergeSort(int a[], int n)
{
    divide(a, 0, n-1);
}

int main()
{
    int a[] = {2, 5, 7, 9, 1, 4, 15, 8};
    
    int n = sizeof(a) / sizeof(int);
    mergeSort(a, n);
    
    std::cout<<std::endl;
    for(int i = 0; i<n;i++)
    {
        std::cout<<a[i]<<" ";
    }
}