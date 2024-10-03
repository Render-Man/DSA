// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// int n, X[100], cot[100], xuoi[100], nguoc[100], dem = 0;
// // thu theo hang
// void Try(int i){
//     for(int j = 1; j <= n; j++){
//         //Đặt con hậu ở hàng i vào cột j : X[i] = j
//         if(cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0){
//             X[i] = j;
//             cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
//             if(i == n) ++dem;
//             else Try(i + 1);
//                 //backtracking
//             cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
//         }
//     }
// }

// int main(){
//     cin >> n;
//     Try(1);
//     cout << dem << endl;
// }



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

int n, x[100], cot[100], xuoi[100], nguoc[100], cnt = 0;
// x luu cac hang

void Try(int i){
    for(int j = 1; j <= n; j++){
        if(cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0){
            x[i] = j;
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
            if(i == n){
                cnt++;
            } 
            else Try(i + 1);
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
        }
    }
    
}

int main(){
    Faster();
    cin >> n;
    Try(1);
    cout << cnt << el;
    return 0;
}