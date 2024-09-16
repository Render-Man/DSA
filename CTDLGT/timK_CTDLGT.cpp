#include <bits/stdc++.h>
using namespace std;

void nhapVaInDayA(int a[],int n){
	 cout << "nhap vao day so a: " << endl;
	 for(int i=0;i<n;i++){
	 	cout <<"a[" << i << "]=";
	 	cin >> a[i];	
	 }
	 cout << "mang a vua nhap la: ";
	 for(int i=0;i<n;i++){
	 	cout << a[i] << " ";
	 }
}

void sapXepTang(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int timK(int a[],int n,int k){
	int i=0;
	while(i<n && a[i]!=k){
		i++;
	}
	if(i<n) return i;
	else return -1;
}
int main(){
	int n,k;
	cout << "nhap vao so nguyen n(0<n<100):";
	cin >> n;
	int a[100];
	nhapVaInDayA(a,n);
	sapXepTang(a,n);
	cout << "\nday so a sau khi sap xep tang: ";
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << "\nnhap so can tim k : ";
	cin >> k;
	int v=timK(a,n,k);
	if(v==-1){
		cout << "khong tim thay so " << k << endl; 
	}
	else{
		cout << "so k o vi tri " << v << endl;
	}
	return 0;
}