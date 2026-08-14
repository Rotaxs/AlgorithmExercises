#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n;
ll s, l;
int h[N], a[N];

bool check(int x)
{
    ll xs = 0, newh = 0;
    for (int i = 1; i <= n; i++)
    {
        newh = (ll)h[i] + (ll)a[i] * x;
        // 第二个条件：每名入选的士兵的战斗力至少为 L
        if (newh >= l)
        {
            xs += newh;
        }
    }
    // 第一个条件：入选的士兵的战斗力之和至少为 S
    return xs >= s;
}

void solve()
{
    cin >> n >> s >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 二分月数
    // m 月能组建出精英部队，那么 m + 1 个月也能组建精英不对（单调性）
    ll le = -1, ri = 1e8;
    while ((le + 1) != ri)
    {
        int m = le + ((ri - le) >> 1);
        // m 个月不能组成精英部队，缩小左边界
        if (!check(m)) le = m;
        // 缩小右边界
        // 二分结束后 ri 就是能组成精英不对的最小月数
        // 因为 le 是恰好不能组建精英不对的最大月数
        else ri = m;
    }
    cout << ri << '\n';
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