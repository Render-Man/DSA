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

int n, a[100][100], res = INT_MAX, cmin = INT_MAX;

int X[100], visited[100], s = 0;

void init(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] != 0) cmin = min(cmin, a[i][j]);
        }
    }
}

void Try(int i){
    //X[i] : luot i di qua tp X[i]
    for(int j = 1; j <= n; j++){
        if(visited[j] == 0){
            X[i] = j;
            visited[j] = 1;
            //X[i - 1] _> X[i] 
            s += a[X[i - 1]][X[i]];
            if(i == n){
                res = min(res, s + a[X[n]][1]);
            }
            else if(s + (n - i + 1) * cmin < res){
                Try(i + 1);
            }
            visited[j] = 0;
            s -= a[X[i - 1]][X[i]];
        }
    }
    
}

int main(){
    Faster();
    init();
    X[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << res;
    return 0;
}