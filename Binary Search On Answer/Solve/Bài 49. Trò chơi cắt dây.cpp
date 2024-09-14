#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//O(N)
bool check(int a[], int n, int k, double mid){
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += (int)(a[i] / mid);
		if(ans >= k) return true;
	}
	return ans >= k;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k; cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	double left = 0, right = 1e18;
	double res = -1;
	for(int i = 1; i <= 90; i++){
		double mid = (left + right) / 2;
		if(check(a, n, k, mid)){
			res = mid;
			left = mid;
		}
		else{
			right = mid;
		}
	}
	cout << fixed << setprecision(6) << res << endl;
}