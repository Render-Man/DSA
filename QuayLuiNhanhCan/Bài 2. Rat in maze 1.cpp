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

void Try(int i, int j){
    // đến ô đích thì in ra đường đi 
    if(i == n && j == n){
        cout << s << el;
        cnt = 1;
    }
    // nếu ô tiếp theo tm thì mới đi xuông
    if(i + 1 <= n && a[i + 1][j] == 1){
        s += "D";
        a[i + 1][j] = 0;
        Try(i + 1, j);
        //backtracking 
        // gap duong cut phai xoa neu ko se bi thua
        s.pop_back();
        a[i + 1][j] = 1;
    }
    
    if(j + 1 <= n && a[i][j + 1] == 1){
        s += "R";
        a[i][j + 1] = 0;
        Try(i, j + 1);
        s.pop_back();
        a[i][j + 1] = 1;
    }
    
}
int main(){
    Faster();
    nhap();
    a[1][1] = 0;
    Try(1, 1);
    if(cnt == 0) cout << "-1\n";
    return 0;
}