#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define el "\n"
#define Faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fors(i, a, b) for(int i = a; i < b; i++)
#define fords(i, a, b) for(int i = a; i > b; i--)
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define sz size
#define mapint map<int, int>

// luong bai lam trong time gio co <= h ?
bool check(int a[], int n, int h, int time){
    int ans = 0;
    for(int i = 0; i < n; i++){
        // ans += (a[i] + time - 1) / time;
        ans += (int)ceil(1.00*a[i] / time);
        // if(a[i] % k).. else
    }
    return ans <= h;
}
int main(){
    Faster();
    int n, h; cin >> n >> h; // so luong cuoc thi & thoi gian tong
    int a[n];
    for(int& x : a) cin >> x;

    int l = 1, r = *max_element(a, a + n);
    int min_of_k = -1; // so luong prob giai trong 1 gio
    while(l <= r){
        int m = (l + r) / 2;
        if(check(a, n, h, m)){
            min_of_k = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    } 
    cout << min_of_k << el;
    return 0;
}