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

int n, a[15];
int x[15];
bool used[15];

void in(){
    for(int k = 1; k <= n; k++){
        cout << x[k];
    }
    cout << el;
}

void Try(int i){
    for(int j = 1; j <= n; j++){
        if(!used[j] && abs(j - x[i - 1]) != 1){
            x[i] = j;
            used[j] = true;
            if(i == n){
                in();
            }
            else Try(i + 1);
            used[j] = false;
        }
        
    }
}

int main(){
    Faster();
    cin >> n;
    Try(1);
    return 0;
}