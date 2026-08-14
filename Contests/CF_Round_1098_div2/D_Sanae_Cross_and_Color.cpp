#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e6 + 10;
const int inf = 2e9;

int x[N], y[N];
int ls[N], rs[N];
int cnt[N];
vector<int> e[N];

void solve()
{
    int n; cin >> n;
    int maxy = 0, miny = inf;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        e[y[i]].push_back(x[i]);
        maxy = max(maxy, y[i]);
        miny = min(miny, y[i]);
    }

    int L = inf, R = 0;
    for (int Y = miny; Y <= maxy; Y++)
    {   
        for (int ele : e[Y]) 
        {
            L = min(L, ele);
            R = max(R, ele);
        }
        ls[Y] = L;
        rs[Y] = R;
    }
    L = inf, R = 0;
    for (int Y = maxy; Y >= miny; Y--)
    {
        // maxy ~ Y + 1（L/R）与  miny ~ Y（ls/rs） 取交集
        ls[Y] = max(ls[Y], L);
        rs[Y] = min(rs[Y], R);
        for (int ele : e[Y])
        {
            L = min(L, ele);
            R = max(R, ele);
        }
    }
    // 去重前缀和
    // cnt[i] 表示 1 ~ i 有多少个不同的 x
    for (int i = 1; i <= n; i++) cnt[x[i]] |= 1;
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    ll ans = 0;
    for (int Y = miny; Y < maxy; Y++)
    {
        if (e[Y].empty()) continue;
        if (ls[Y] < rs[Y])
            ans += cnt[rs[Y] - 1] - cnt[ls[Y] - 1];
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = ls[i] = rs[i] = 0;
        e[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}