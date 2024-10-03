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

int a[100], n;

void Try(int i){
    //xets nhung kha nang co the gan cho a[i]
    for(int j = 0; j <= 1; j++){
        a[i] = j;
        if(i == n){
            for(int k = 1; k <= n; k++){
                cout << a[k];
            }
            cout << el;
        }
        else Try(i + 1);
    }
}



int main(){
    Faster();
    cin >> n;
    Try(1);
    return 0;
}