#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int n)
{
    ll ans = 0;
    for (int l = 1, r, k; l <= n; l = r + 1)
    {
        k = n / l;
        // 非必要但要知道
        if (k == 0) r = n;
        else r = min(n, n / k);
        ans += (r - l + 1) * k;
    }
    return ans;
}

ll solve(int n, int m)
{
    ll ans = 0;
    int limit = min(n, m);
    // 当 i 大于 R 时，其中必有一项计算结果为 0
    for (int l = 1, r; l <= limit; l = r + 1)
    {
        int k1 = n / l, k2 = m / l;
        r = min({n / k1, m / k2, limit});
        ans += (n / l) * (m / l) * (r - l + 1);
    }
    return ans;
}

ll solve(int n, int m, vector<int> &sum)
{
    ll ans = 0;
    int limit = min(n, m);
    for (int l = 1, r; l <= limit; l = r + 1)
    {
        int k1 = n / l, k2 = m / l;
        r = min({n / k1, m / k2, limit});
        ans += (n / l) * (m / l) * (sum[r] - sum[l - 1]);
    }
    return ans;
}

// 6 / 1 = 6
// 6 / 2 = 3
// 6 / 3 = 2
// 6 / 4 = 1 6 / 5 = 1 6 / 6 = 1

int main()
{
    cout << solve(6) << '\n';
    return 0;
}