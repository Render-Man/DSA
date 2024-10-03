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

ll n, k, a[1005], x[1005], cnt = 0;
// mang x luu vi tri để đặt phần tử vào để cho thõa mãn điều kiện
// mang a luu gia tri ban đầu
void nhap(){
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}
void in(int i){
    cout << "[";
    for(int u = 1; u <= i; u++){
        cout << a[x[u]];
        if(u != i) cout << ' ';
    }
    cout << "]" << el;
}

void Try (int i, ll sum) {
    for (int j = x[i - 1] + 1; j <= n; j++) { // miền xét vị trí
        if (sum + a[j] <= k) {
            x[i] = j; // thằng thứ i chọn vị trí j
            if (sum + a[j] == k) {
                in(i);
            } else {
                Try(i + 1, sum + a[j]);
            }
        }
    }
}

int main(){
    Faster();
    cin >> n >> k;
    nhap();
    Try(1, 0);
    return 0;
}

