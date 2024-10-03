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

int n, a[100], x[100];
vector<string> v;

void in(int i){
    string s = "";
    for(int j = 1; j <= i; j++){
        s += to_string(x[j]) + " ";
    }
    v.pb(s);
}

void Try(int i, int bd){
    for(int j = bd; j <= n; j++){
        if(a[j] > x[i - 1]){
            x[i] = a[j];
            if(i >= 2) in(i);
            Try(i + 1, j + 1);
        }
    }
}
 
int main(){
    Faster();
    cin >> n;
    for(int i= 1; i <= n; i++){
        cin >> a[i];
    }
    x[0] = 0;
    Try(1, 1);
    sort(v.begin(), v.end());
    for(string x : v) cout << x << el;
    return 0;
}