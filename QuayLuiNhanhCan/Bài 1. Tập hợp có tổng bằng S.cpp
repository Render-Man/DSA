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
//số lượng phần tử bằng k và tổng của tất cả các phần tử trong tập hợp bằng s   
int n, k, s, a[100];
bool used[100];
int cnt = 0;

// miền là gì?
// khi nào thì dừng

// note: đếm tiến về mặt vị trí                                             
    
void Try(int i, int sum){
    // miền giá trị
    for(int j = a[i - 1] + 1; j <= n; j++){
        //nhánh cận -> không cần quay lui nữa
        if(sum + j <= s){ //lon hon thi khong quay lui nua
            a[i] = j; // ở vị trí hiện tại thì ptu nhận giá trị j
            if(i == k){ // thời điểm đủ k số
                if(sum + a[i] == s) cnt++;
            }
            // backtracking
            else{
                Try(i + 1, sum + a[i]);
            }
        }
    }
}

int main(){
    Faster();
    cin >> n >> k >> s;
    Try(1, 0);
    cout << cnt;
    return 0;
}