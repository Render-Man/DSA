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

int n, k, a[100], sum;
bool used[100], ok = 0;

// s : tong cua tap con hien tai
// cnt : so tap con da dem duoc 
void Try(int s, int cnt){
    if(ok) return; // nhanh can
    if(s == sum){ // tong hien tai dat yeu cau
        cnt++;
        s = 0;
    }
    if(cnt == k){ // chia duoc k mang
        ok = 1;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!used[i] && s + a[i] <= sum){
            used[i] = 1;
            Try(s + a[i], cnt);
            used[i] = 0;
        }
    }
}


int main(){
    Faster();
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % k != 0){
        cout << 0;
        return 0;
    }
    sum /= k;
    Try(0, 0);
    cout << ok;
    return 0;
}