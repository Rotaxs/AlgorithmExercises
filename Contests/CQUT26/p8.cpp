#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
int pos[N];
int n, k;

// 找大于等于 x 的第一个元素
int bisearch(int x)
{
    int l = -1, r = n + 1;
    while ((l + 1) != r)
    {
        int m = l + ((r - l) >> 1);
        if (pos[m] < x) l = m;
        else r = m;
    }
    return r;
}

bool check(int x)
{
    int cnt = 1;
    int i = 1;
    while (i <= n)
    {
        i = bisearch(pos[i] + x);
        if (i <= n) cnt++;
    }
    // int now = 1;
    // for (; i <= n; i++)
    // {   
    //     if (pos[i] - pos[now] >= x)
    //     {
    //         cnt++;
    //         now = i;
    //     }
    // }
    return cnt >= k;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> pos[i];

    int l = 0, r = pos[n] + 1;
    while ((l + 1) != r)
    {
        int m = l + ((r - l) >> 1);
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
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