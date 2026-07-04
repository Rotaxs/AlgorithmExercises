#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;


void solve()
{
    int n; cin >> n;
    // if (n == 1)
    // {
    //     cout << "NO\n";
    //     return;
    // }
    // stack<int> st;
    vector<int> st(n + 1);
    int l = 0, r = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        if (r == l)
        {
            st[++r] = a;
            continue;
        }
        if ((st[r] + a) % 9 == 0)
        {
            r--;
            cnt++;
        }
        else st[++r] = a;
    }
    if (cnt & 1) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}