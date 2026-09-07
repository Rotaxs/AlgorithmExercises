#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 10;

struct { int ne, to; } edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[++cnt] = { head[u], v }; 
    head[u] = cnt;
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    int maxLen = 0;

    function<void(int, int, int, int&)> dfs = [&](int u, int fa, int len, int &a) {
        if (len > maxLen) {
            maxLen = len;
            a = u;
        }
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa) continue;
            dfs(v, u, len + 1, a);
        }
    };

    int A, B = 1;
    dfs(1, 0, 0, A);
    dfs(A, 0, 0, B);

    cout << maxLen << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}
