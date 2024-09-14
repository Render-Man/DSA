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

// tong toi da la m
// so luong day con tao thanh <= k
bool check(int a[], int n, ll k, ll m){
    int cnt = 0; // so luong day con chia ra
    ll sum = 0; // tong cua moi day con
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum > m){
            cnt++;
            sum = a[i];
        }  
    }
    cnt++;
    return cnt <= k;
}

int main(){
    Faster();
    int n, k; cin >> n >> k;
    int a[n];
    for(int& x : a) cin >> x;
    // tong lon nhat va nn co 1 mang con trong mang
    ll l = *max_element(a, a + n);
    ll r = accumulate(a, a + n, 0ll);
    ll ans = -1;
    while(l <= r){
        ll m = (l + r) / 2;
        if(check(a, n, k, m)){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    cout << ans << el;
    return 0;   
}