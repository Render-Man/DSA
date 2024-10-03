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

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int n, m, a[100][100], cnt;
bool used[100][100];

void nhap(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
}


// mien la gi
// khi nao thi dung

void Try(int i, int j, int &cnt){
    // dieu kien dung
    if(i == n && j == m){
        cnt++;
        return;
    }
    if(i > n || j > m) {
        return;
    }
    Try(i + 1, j, cnt);
    Try(i, j + 1, cnt);
}



int main(){
    Faster();
    cin >> n >> m;
    a[n][m];
    nhap();
    Try(1, 1, cnt);
    cout << cnt << el;
    return 0;
}