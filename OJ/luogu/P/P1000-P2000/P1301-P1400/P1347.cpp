#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 27, M = 610;

struct { int to, ne; } edge[M];
int head[N], cnt, in[N];

void add_edge(int u, int v)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].ne = head[u];
    in[v]++;
    head[u] = cnt;
}

int topo(int n, string &order)
{
    queue<int> q;
    int deg[N];
    for (int i = 0; i < n; i++) deg[i] = in[i];
    for (int i = 0; i < n; i++)
        if (deg[i] == 0) q.push(i);
    bool determined = true;
    while (q.size())
    {
        if (q.size() > 1) determined = false;
        int u = q.front(); q.pop();
        order += (char)(u + 'A');
        for (int e = head[u]; e != 0; e = edge[e].ne)
        {
            int v = edge[e].to;
            if (--deg[v] == 0) q.push(v);
        }
    }
    if (order.size() < n) return -1;
    if (!determined) return 0;
    return 1;
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        char u, op, v;
        cin >> u >> op >> v; 
        u = (int)(u - 'A');  v = (int)(v - 'A');
        add_edge(u, v);
        string order; order = "";
        int res = topo(n, order);
        if (res == -1)
        {
            cout << "Inconsistency found after " << i << " relations.\n";
            return;
        }
        else if (res == 1)
        {
            cout << "Sorted sequence determined after " << i << " relations: " << order << ".\n";
            return;
        }
    }
    cout << "Sorted sequence cannot be determined.\n";
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