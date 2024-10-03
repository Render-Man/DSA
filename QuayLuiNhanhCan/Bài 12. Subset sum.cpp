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

int n, s, a[100], sum = 0;
bool ok, used[100];

void init(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void Try(int tong, int bd){
    if(ok) return;
    for(int i = bd; i <= n; i++){
        if(!used[i] && tong + a[i] <= sum){
            used[i] = true;
            if(tong + a[i] == sum){
                ok = true; return;
            }
            else Try( tong + a[i], i + 1);
            used[i] = false;
        }
    }
}
int main(){
    Faster();
    init();
    if(sum % 2 == 1){
        cout << "0";
        return 0;
    }
    sum /= 2;
    Try(0, 1);
    cout << ok << el;
    
    return 0;
}