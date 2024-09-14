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

// ham check xem mid co thoa man hay khong
bool check(ll a[], ll n, ll L, ll heigh){
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > heigh){
            ans += a[i] - heigh;
        }
        if(ans >= L) return true;
    }
    return ans >= L;
}

int main(){
    Faster();
    ll n, L; cin >> n >> L;
    ll a[n];
    for(ll& x : a) cin >> x;
    ll l = 0, r = *max_element(a, a + n); // search space
    ll ans = -1;
    while(l <= r){
        ll m = (l + r) / 2;
        if(check(a, n, L, m)){
            ans = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    cout << ans;
    return 0;
}