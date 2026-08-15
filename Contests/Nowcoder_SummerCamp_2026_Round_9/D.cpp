#include <bits/stdc++.h>
#define endl '\n'
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x)  << " (Line " << __LINE__ << ")" << endl
#else
#define debug(x)
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 5;
int n, m, d[N], ans[N];

vector<int> e[N];
unordered_map<int, int> mp[N];
unordered_set<int> st[N];

void dfs1(int u, int fa) {
    d[u] = d[fa] + 1;
    for (int v : e[u]) {
        if (v != fa) dfs1(v, u);
    }
}

void dfs2(int u, int fa) {
    for (int v : e[u]) {
        if (v == fa) continue;
        dfs2(v, u);
        if (mp[u].size() < mp[v].size()) {
            swap(mp[u], mp[v]);
        }

        for (auto i : mp[v]) {
            if (mp[u].count(i.first)) {
                st[u].insert(i.first);
            }
            mp[u][i.first] = i.second;
        }
    }
    for (int x : st[u]) {
        mp[u].erase(x);
    }
    st[u].clear();
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs1(1, 0);

    for (int i = 1; i <= m; ++i) {
        int x, s; cin >> x >> s;
        int t = s + d[x];
        if (mp[x].count(t)) {
            st[x].insert(t);
        }
        mp[x][t] = i;
    }

    dfs2(1, 0);

    for (auto i : mp[1]) {
        if (i.second != -1) ans[i.second] = 1;
    }

    for (int i = 1; i <= m; ++i) {
        cout << ans[i];
    }
    cout << endl;
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