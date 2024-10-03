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
#define pi 3.14159265358979
#define mod 1e9 + 7

int n;
char x[100];

int check1()
{
    stack<char> st;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            st.push(x[i]);
        }
        else
        {
            if (st.empty())
                return 0;
            else
            {
                char fii = st.top();
                st.pop();
                if (x[i] == ')' && fii == '(' || x[i] == ']' && fii == '[' || x[i] == '}' && fii == '{')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return st.empty();
}

int check2(int k)
{
    stack<char> st;
    for (int i = 1; i <= k; i++)
    {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            st.push(x[i]);
        }
        else
        {
            if (st.empty())
                return 0;
            else
            {
                char fii = st.top();
                st.pop();
                if (x[i] == ')' && fii == '(' || x[i] == ']' && fii == '[' || x[i] == '}' && fii == '{')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return 1;
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
    string str = "()[]{}";
    for (char c : str)
    {
        x[i] = c;
        if (check2(i))
        {
            if (i == n)
            {
                if (check1())
                    in();
            }
            else
            {
                ql(i + 1);
            }
        }
    }
}

int main()
{
    Faster();
    cin >> n;
    if(n % 2 == 0) cout << "NOT FOUND";
    ql(1);
    return 0;
}