#include<bits/stdc++.h> 
#define int long long

using namespace std;

const int N = 1e3 + 10;

struct Cost
{
    int p, s;
    int total;
    bool operator<(const Cost &other) const
    {
        return total < other.total;
    }
} cost[N];

void solve()
{
    int n, b; cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i].p >> cost[i].s;
        cost[i].total = cost[i].p + cost[i].s;
    }
    sort(cost + 1, cost + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int total = cost[i].p / 2 + cost[i].s;
        int res = total <= b ? 1 : 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (total + cost[j].total > b) break;
            total += cost[j].total;
            res++;
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

signed main( )
{
    solve();
    return 0;
}