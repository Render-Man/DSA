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

int n, k, a[100];

void inkq(){
    for(int i = 1; i <= k; i++){
        cout << a[i] << ' ';
    }
    cout << el;
}
void Try(int i){
    // miền giá trịxet nhung kha nang co the gan cho a[i]
    for(int j = a[i - 1] + 1; j <= n - k + i; j++){
        a[i] = j;
        if(i == k) inkq();
        // backtracking
        else Try(i + 1);
    } 
}

int main(){
    Faster();
    cin >> n >> k;
    Try(1);
    return 0;
}