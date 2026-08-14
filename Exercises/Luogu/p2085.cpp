#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
priority_queue<ll> pq;

void solve()
{
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    int k = (m + n - 1) / n;
    bool ok = false;
    for (int d = 1; d <= n; d++)
    {
        for (int x = (d - 1) * k + 1; x <= min(d * k, m); x++)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)   
            {
                ll f = a[i] * x * x + b[i] * x + c[i];
                if (pq.size() < m) pq.push(f);
                else if (f < pq.top()) { pq.push(f); pq.pop(); }
                else cnt++;
            }
            if (cnt == n) { ok = true; break; }
        }
        if (ok) break;
    }
    vector<int> ans;
    while (pq.size())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << ' ';
    cout << '\n';

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