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

int n, x[100], cot[100], xuoi[100], nguoc[100], res = 0;
// x luu dong thu i chon pt tai cot thu x[i]
int a[64][64];

void init(){
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cin >> a[i][j];
        }
    }
}

void Try(int i){
    for(int j = 1; j <= 8; j++){
        if(cot[j] == 0 && xuoi[i - j + 8] == 0 && nguoc[i + j - 1] == 0){
            x[i] = j;
            cot[j] = xuoi[i - j + 8] = nguoc[i + j - 1] = 1;
            if(i == 8){
                int tmp = 0;
                for(int i = 1; i <= 8; i++){
                    tmp += a[i][x[i]];
                }
                res = max(res, tmp);
            }
            else Try(i + 1);
            cot[j] = xuoi[i - j + 8] = nguoc[i + j - 1] = 0;    
        }
    }
}

int main(){
    Faster();
    init();
    Try(1);
    cout << res;
    return 0;
}