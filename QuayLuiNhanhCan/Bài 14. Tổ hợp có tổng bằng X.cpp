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



int n, s, a[1000], cnt = 0, flag = 0;
//mang luu cau hinh
int k, X[1000];

void nhap(){
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
}
vvi ans;
vector<int> tmp;

void inkq(int k){
    tmp.clear();
    for(int j = 1; j <= k; j++){
        tmp.pb(X[j]);
    }
    ans.pb(tmp);
    cnt++;
    flag = 1;
}

void Try(int i, int start, int tong){
    //dua a[j] vao cau hinh cuoi cung phai backtrack lai
    for(int j = start; j < n; j++){
        X[i] = a[j];
        tong += a[j];
        if(tong == s) inkq(i);
        else if(tong < s){
            Try(i + 1, j, tong);
        }
        //backtracking
        tong -= a[j];
    }
    
}
int main(){
    Faster();
    nhap();
    Try(1, 0, 0);
    if(flag == 0){ cout << "-1" << el; return 0;}
    cout << ans.sz() << el;
    for(auto x : ans){
        cout << "{";
        for(int i = 0; i < x.size(); i++){
            cout << x[i];
            if (i != x.size() - 1) cout << ' ';
        }
        cout << "}" << el;
    }

    return 0;
}