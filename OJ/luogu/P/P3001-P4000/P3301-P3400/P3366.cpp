#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5010; 
const int M = 2e5 + 10;
struct Edge { int u, v, w; } edge[M];

int f[N];

int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}

void solve()
{   
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        edge[i] = {u, v, w};
    }
    sort(edge + 1, edge + 1 + m, [](Edge &a, Edge &b){
        return a.w < b.w;
    });
    int cnt = 0;
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        auto [u, v, w] = edge[i];
        int ru = find(u), rv = find(v);
        if (ru == rv) continue;
        f[ru] = rv;
        cnt++; ans += w;
    }
    if (cnt == n - 1) cout << ans << '\n';
    else cout << "orz\n";
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