#include <bits/stdc++.h>
using namespace std;

void sapXepTang(int a[],int n){
	for(int i=1;i<n;i++){
		for(int j=n-1;j>=i;j--){
			if(a[j]<a[j-1]){
				int temp=a[j];
				a[j] = a[j-1];
				a[j-1]=temp;
			}
		}
	}
}
void nhap(int a[],int n){
	for(int i=0;i<n;i++){
		cout << "a["<<i<<"]=";
		cin >> a[i];
	}
}
void hienThi(int a[], int n){
	cout << "mang a vua nhap la: ";
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}
int main(){
	int n;
	cout << "nhap vao so nguyen n : ";
	cin >> n;
	int a[n];
	nhap(a,n);
	hienThi(a,n);
	sapXepTang(a,n);
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}