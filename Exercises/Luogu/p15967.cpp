#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
priority_queue<int, vector<int>, greater<int>> pq;

const int N = 1e5 + 10;

int c[N], a[N];


void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n - 1; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int sumc = 0, sumk = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {   
        if (pq.size() < k)
        {
            pq.push(a[i]);
            sumk += a[i];
        }
        else
        {
            int top = pq.top();
            pq.pop();
            sumk -= top;
            sumk += a[i];
            pq.push(a[i]);
        }
        ans = max(ans, min(m - sumc, sumk));
        sumc += c[i];
    }
    cout << ans << '\n';
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