#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;
const int MAXN = 100005;

int val[MAXN];
int color[MAXN];
int cnt[MAXN][2];
long long sum_val[MAXN][2];
long long sum_idx[MAXN][2];
long long sum_idx_val[MAXN][2];

typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= n; i++) cin >> color[i];
    for (int i = 1; i <= n; ++i)
    {
        int c = color[i];
        int p = i % 2;

        cnt[c][p]++;
        sum_val[c][p] = (sum_val[c][p] + val[i]) % MOD;
        sum_idx[c][p] = (sum_idx[c][p] + i) % MOD;
        sum_idx_val[c][p] = (sum_idx_val[c][p] + (long long)i * val[i]) % MOD;
    }

    ll total_ans = 0;

    for (int c = 1; c <= m; ++c)
    {
        for (int p = 0; p < 2; ++p)
        {
            long long k = cnt[c][p];
            if (k < 2) continue;

            long long part1 = (k - 2) * sum_idx_val[c][p] % MOD;
            long long part2 = (sum_idx[c][p] * sum_val[c][p]) % MOD;

            long long group_ans = (part1 + part2) % MOD;
            total_ans = (total_ans + group_ans) % MOD;
        }
    }

    cout << total_ans << "\n";
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