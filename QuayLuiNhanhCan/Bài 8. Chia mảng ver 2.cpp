#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define el "\n"
#define Faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORD(i, a, b) for(int i = a; i > b; i--)
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define sz size
#define mapint map<int, int>
#define vvi vector<vector<int>>
#define reset(x) memset(x, (ll)0, sizeof x)
#define pi 3,14159265358979
#define mod 1e9 + 7

vector<ll> a, d;
ll n, k, cnt = 0, sum = 0, aim;

ll Try(ll idx, ll k, ll cur_sum){
    if(k == 1) return 1;
    if(aim == cur_sum) return Try(0, k - 1, 0); 
    for(int i = idx; i <= n; i++){
        if(!d[i] && cur_sum + a[i] <= aim){
            d[1] = 1;
            if(Try(i + 1, k, cur_sum + a[i])) return 1;
            d[1] = 0;
        }
    }
    return 0;
}

int main(){
    Faster();
    cin >> n >> k;
    a.resize(n);
    d.resize(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    } 
    
    if(sum % k != 0){
        cout << 0;
        return 0;
    }
    aim = sum / k;
    sort(a.rbegin(), a.rend());
    if(Try(0, k, 0) == 1) cout << '1';
    else cout << 0;
    return 0;
}