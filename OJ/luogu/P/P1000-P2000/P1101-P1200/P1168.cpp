#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<int> pqd;
priority_queue<int, vector<int>, greater<int>> pqx;

void solve()
{
    int n;
    cin >> n;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (pqd.empty() || a <= pqd.top()) pqd.push(a);
        else pqx.push(a);
        
        if (i & 1 == 1)
        {
            while (pqd.size() > ((i + 1) >> 1)) pqx.push(pqd.top()), pqd.pop();
            while (!pqx.empty() && pqd.size() < ((i + 1) >> 1)) pqd.push(pqx.top()), pqx.pop();
            cout << pqd.top() << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();
    
    return 0;
}