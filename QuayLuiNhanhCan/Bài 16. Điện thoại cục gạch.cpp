#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define el "\n"
#define Faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i > b; i--)
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define sz size
#define mapint map<int, int>
#define vvi vector<vector<int>>
#define reset(x) memset(x, (ll)0, sizeof x)
#define pi 3, 14159265358979
#define mod 1e9 + 7

// mien : neu la so 2 -> abc.. phu thuoc s[i]
// ket thuc : duyet het

int n, a[200];
char x[200];
string s;
string d[15];
string xuly(char c)
{
    int num = c - '0';
    d[2] = "abc";
    d[3] = "def";
    d[4] = "ghi";
    d[5] = "jkl";
    d[6] = "mno";
    d[7] = "pqrs";
    d[8] = "tuv";
    d[9] = "wxyz";
    return d[num];
}

void in()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i];
    }
    cout << ' ';
}
void ql(int i)
{
    string str = xuly(s[i]);
    for (char c : str)
    {
        x[i] = c;
        if (i == n)
            in();
        else
            ql(i + 1);
    }
}

int main()
{
    Faster();
    cin >> s;
    n = s.length();
    s = "0" + s;
    ql(1);
    return 0;
}