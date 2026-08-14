#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 5;
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }

vector<int> h[N];
int n, a[N], sum[N];

void dfs(int u, int fa)
{
    if (h[u].size() == 1 && u)
    {
        sum[u] = a[u];
        return;
    }
    for (auto &p : h[u])
    {
        if (p == fa)
            continue;
        dfs(p, u);
        sum[u] += sum[p];
    }
}

void solve()
{
    cin >> n;
    a[0] = 2200;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p >> a[i];
        h[p].push_back(i);
        h[i].push_back(p);
    }
    dfs(0, 0);
    if (sum[0] > 2200)
    {
        cout << "NO" << endl;
        return;
    }
    vector<int> b, c;
    for (int i = 1; i <= n; i++)
    {
        if (h[i].size() > 1)
        {
            b.push_back(a[i]);
            c.push_back(sum[i]);
        }
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] < c[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}