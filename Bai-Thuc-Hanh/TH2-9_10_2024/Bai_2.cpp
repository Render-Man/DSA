#include <iostream>
#include <bits/stdc++.h>
struct DoVat 
{
    float trongLuong, giaTri, donGia;
};

void bubbleSort_2(DoVat a[], int n) 
{
    for (int i = 1;i < n;i++) 
	{
        for (int j = n - 1;j >= i;j--) 
		{
            if (a[j].donGia > a[j - 1].donGia ) 
			{
                DoVat tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void xepBalo(DoVat a[], int n, int w) {
    bubbleSort_2(a, n);
    cout << "Cac do vat cho vao balo la :" << endl;
    for (int i = 0; i < n; i++) {
        if (w >= a[i].trongLuong) {
            w -= a[i].trongLuong;
            cout << a[i].giaTri << " " << a[i].trongLuong << endl;
        }
        else {
            continue;
        }
    }
}
int main(int argc, char** argv) 
{
	DoVat a[1000];
	cout << "Nhap so luong do vat : ";
	int n;
	cin >> n;
	cout << "Nhap trong luong toi da : ";
	int w;
	cin >> w;
	for (int i = 0; i < n; i++) 
	{
    	cout << "Nhap thong tin do vat thu " << i + 1<<endl;
    	cout << "Trong luong : ";
    	cin >> a[i].trongLuong;
    	cout << "Gia tri : ";
    	cin >> a[i].giaTri;
    	a[i].donGia = a[i].giaTri / a[i].trongLuong;
	}
	xepBalo(a, n, w);

	return 0;
}
