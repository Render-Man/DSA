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


int n, a[100], cot[100], xuoi[200], nguoc[200];

void in() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (a[i] == j) cout << "Q";  
            else cout << ".";
        }
        cout << el;
    }
    cout << el; 
}

void ql(int i) {
    for(int j = 1; j <= n; j++) {
        if(cot[j] == 0 && xuoi[i + j] == 0 && nguoc[i - j + n] == 0) {
            a[i] = j;
            cot[j] = xuoi[i + j] = nguoc[i - j + n] = 1;  
            if(i == n) {
                in(); 
            } else {
                ql(i + 1);  
            }
            cot[j] = xuoi[i + j] = nguoc[i - j + n] = 0; 
        }
    }
}

int main() {
    Faster();
    cin >> n;
    ql(1);  
    return 0;
}
