#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define el "\n"
#define Faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fors(i, a, b) for(int i = a; i < b; i++)
#define fords(i, a, b) for(int i = a; i > b; i--)
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define sz size
#define mapint map<int, int>

int n, a[105][105], cnt = 0;
string s;

void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

// void Try(int i, int j){
//     if(i == n && j == n){
//         cout << s << el;
//         cnt = 1;
//     }
//     if(i + 1 <= n && a[i + 1][j] == 1){
//         s += "D";
//         a[i + 1][j] = 0;
//         Try(i + 1, j);
//         s.pop_back();
//         a[i + 1][j] = 1;
//     }
//     if(j - 1 > 0 && a[i][j - 1] == 1){
//         s += "L";
//         a[i][j - 1] = 0;
//         Try(i, j - 1);
//         s.pop_back();
//         a[i][j - 1] = 1;
//     }
//     if(j + 1 <= n && a[i][j + 1] == 1){
//         s += "R";
//         a[i][j + 1] = 0;
//         Try(i, j + 1);
//         s.pop_back();
//         a[i][j + 1] = 1;
//     }
//     if(i - 1 > 0 && a[i - 1][j] == 1){
//         s += "U";
//         a[i - 1][j] = 0;
//         Try(i - 1, j);
//         s.pop_back();
//         a[i - 1][j] = 1;
//     }
// }

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string path = "DLRU";

void Try2(int i, int j){
    if(i == n && j == n){
        cout << s << el;
        cnt = 1;
    }
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k], j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1){
            s += path[i];
            a[i1][j1] = 0;
            Try2(i1, j1);
            s.pop_back();
            a[i1][j1] = 1;
        }
    }
}

int main(){
    Faster();
    nhap();
    a[1][1] = 0;
    Try2(1, 1);
    if(cnt == 0) cout << "-1\n";
    return 0;
}