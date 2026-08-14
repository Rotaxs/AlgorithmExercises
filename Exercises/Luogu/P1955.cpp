#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int f[N << 1];

struct Edge
{
    int i, j, e;
} edge[N];

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

void unite(int x, int y)
{
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    f[ry] = rx;
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= N * 2; i++) f[i] = i;
    int mx = 0;
    vector<int> nums;
    for (int k = 1; k <= n; k++)
    {
        cin >> edge[k].i >> edge[k].j >> edge[k].e;
        nums.push_back(edge[k].i);
        nums.push_back(edge[k].j);
    }

    // 离散化去重
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    auto get_id = [&](int n)
    {
        return lower_bound(nums.begin(), nums.end(), n) - nums.begin() + 1;
    };

    sort(edge + 1, edge + n + 1, [](const Edge &a, const Edge &b) { return a.e > b.e; });

    for (int k = 1; k <= n; k++)
    {
        int i = get_id(edge[k].i);
        int j = get_id(edge[k].j);
        int e = edge[k].e;
        if (e == 1)
        {
            unite(i, j);
        }
        else
        {
            if (find(i) == find(j))
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();

    
    return 0;
}