#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;


const int N = 110;
vector<int> e[N];

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c; cin >> c;
        while (c--)
        {
            int a; cin >> a;
            e[a].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << e[i].size() << ' ';
        for (int a : e[i])
            cout << a << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}