#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), dist(n + 1, -1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    queue<int> q;
    dist[1] = 0;
    q.push(1);

    // while (!q.empty())
    for (; !q.empty(); )
    {
        int u = q.front(); q.pop();
        if (u == n) break;

        // if (a[u] > 0)
        // {
        //     for (int k = 1, v; k <= a[u] && (v = u + k) <= n; k++)
        //     {
        //         if (dist[v] == -1)
        //         {
        //             q.push(v);
        //             dist[v] = dist[u] + 1;
        //         }
        //     }
        // }
        // else if (a[u] < 0)
        // {
        //     for (int v = 1; v <= max(1, u + a[u]); v++)
        //     {
        //         if (dist[v] == -1)
        //         {
        //             q.push(v);
        //             dist[v] = dist[u] + 1;
        //         }
        //     }
        // }

        for (int v = (a[u] > 0) ? u + 1 : 1; v <= ((a[u] > 0) ? min(n, u + a[u]) : max(1, u + a[u])); v++)
        {
            if (dist[v] != -1) continue;
            q.push(v);
            dist[v] = dist[u] + 1;
        }
    }

    cout << dist[n] << endl;
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
