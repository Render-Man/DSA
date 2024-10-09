#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int a[], int n, bool kt) 
{
    int k = (kt) ? 1 : -1;
    for (int i = 1;i < n;i++) 
	{
        for (int j = n - 1;j >= i;j--) 
		{
            if (a[j]*k < a[j - 1]*k) 
			{
                int tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}
int dem(int *a, int n, int p) 
{
    bubbleSort(a, n, false);
    int d = 0;
    int t = 0;
    for (int i = 0; i < n; i++) 
	{
        t = t + a[i];
        d++;
        if (t > p) 
            return d;
        
    }
    return -1;
}
int main(int argc, char** argv) 
{
	cout << "Nhap n = ";
    int n;
    cin >> n;
    int a[100000];
    for (int i = 0; i < n; i++) 
	{
        cin >> a[i];
    }
    cout << "Nhap tong s : ";
    int s;
    cin >> s;
    int d = dem(a, n, s);
    if (d > 0 ) 
        cout << "Can it nhat " << d << " so nguyen trong day a de dc tong lon hon "<<s;
    else 
        cout << "Kut";
	return 0;
}

