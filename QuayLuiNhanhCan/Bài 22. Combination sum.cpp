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

int s, n, x[100];
bool ok = 0;

void in(){
    ok = 1;
    for(int i = 1; i <= n; i++){
        cout << x[i];
        if(i < n) cout << " + ";
    }
    cout << el;
}

void ql(int i, int bd, int sum){
    for(int j = bd; j <= 9; j++){
        if(sum + j <= s){
            x[i] = j;
            if(i == n){
                if(sum + j == s) in();
            } else {
                ql(i + 1, j + 1, sum + j);
            }
        }
    }
}


int main(){
    Faster();
    cin  >> s >> n;
    ql(1, 1, 0);
    if(ok == 0) cout << "NOT FOUND";

    return 0;
}