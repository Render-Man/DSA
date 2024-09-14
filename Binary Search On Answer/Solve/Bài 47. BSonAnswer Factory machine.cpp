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

bool check(int a[], int n, int t, ll time){
    ll ans = 0; // so sp
    for(int i = 0; i < n; i++){
        ans += time / a[i];
        if(ans >= t) return true;
    }return ans >= t;
}


int main(){
    Faster();
    int n, t; cin >> n >> t;
    int a[n];
    for(int& x : a) cin >> x;

    ll l = 0, r = 1e18;
    ll ans = -1;

    while(l <= r){
        ll m = (l + r) / 2;
        if(check(a, n, t, m)){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    cout << ans;
    return 0;
}