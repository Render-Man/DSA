#include <bits/stdc++.h>
using namespace std;

void nhapday(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<"a[" << i << "]=";
		cin >> a[i];
	}
}
void hienthi(int a[],int n){
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}
int sequence(int a[], int n, int kh){
	int i=0;
	while(i<n && a[i]!=kh){
		i++;
	}
	if(i<n) return i;
	else return -1;
}

int main(){
	int n,k;
	cout << "nhap so nguyen n: "; cin >> n;
	int a[n];
	cout << "nhap day so : " << endl;
	nhapday(a,n);
	cout << "day vua nhap: ";
	hienthi(a,n);
	cout << "\nnhap vao so can tim: "; cin >> k;
	int v=sequence(a,n,k);
	if(v==-1){
		cout << "khong tim thay" << endl;
		
	}
	else cout << "tim thay " << k << " o vi tri " <<v; 
}