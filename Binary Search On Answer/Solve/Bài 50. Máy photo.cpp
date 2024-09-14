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

bool check(ll x, ll y, ll n, ll m){
    m -= min(x, y); // tao them 1 ban sao
    ll ans = m/x + m/y; // m is thoi gian
    return ans >= n - 1;
}

int main(){
    Faster();
    ll n, x, y; // so ban photo can
    cin >> n >> x >> y;

    ll l = 0, r = min(x, y) * n;
    ll ans = -1;
    while(l <= r){
        ll m = (l + r) / 2;
        if(check(x, y, n, m)){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    cout << ans ;
    return 0;
}