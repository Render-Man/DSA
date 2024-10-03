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

ll n, s, a[100], x[100], cnt = 0;
ll ans = LLONG_MAX;
vector<ll> v1;

// void Try(ll i, ll cur, ll sum){
//     for(int j = cur; j <= n; j++){
//         // if(sum + a[j] > s) return;
//         if(sum + a[j] <= s){
//             x[i] = j;
//             if(sum + a[j] == s){
//                 ans = min(ans, i);
//                 return;
//             }
//             else{
//                 Try(i + 1, j + 1, sum + a[j]);
//             }
//         }
//     }
// }

void Try(ll idx, ll cur_sum, ll cnt){
    if(cur_sum > s || cnt >= ans) return;
    if(cur_sum == s){
        ans = min(ans, cnt);
        return;
    }
    for(ll i = idx; i < n; i++){
        Try(i + 1, cur_sum + a[i], cnt + 1);
    }
}

int main(){
    Faster();
    cin >> n >> s;
    v1.resize(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(v1.rbegin(), v1.rend());
    Try(0, 0, 0);
    if(ans == LLONG_MAX || ans == 0) cout << "-1";
    else cout << ans;
    return 0;
}