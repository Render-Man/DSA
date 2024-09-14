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
// n so luong thannh domino
bool check(int a, int b, int n, int m){
    int x = m/a, y = m/b;
    return x >= n/y;
}

int main(){
    Faster();
    int a, b, n; cin >> a >> b >> n;
    ll l = 0, r = max(a, b) * n;
    int ans = -1;
    while(l <= r){
        ll m = (l + r) / 2;
        if(check(a, b, n, m)){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    cout << ans;
    return 0;
}