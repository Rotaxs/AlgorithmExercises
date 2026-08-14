#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n;

struct A
{
    int pos, val;
} a[N];

int bisearch(int val)
{
    int l = 0, r = n + 1;
    while ((l + 1) != r)
    {
        int m = l + ((r - l) >> 1);
        if (a[m].val < val) l = m;
        else r = m;
    }
    if (a[r].val == val) return r;
    return -1;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].val, a[i].pos = i;
    auto cmp = [&](A a, A b) { return a.val < b.val; };
    sort(a + 1, a + n + 1, cmp);
    int t; cin >> t;
    while (t--)
    {
        int cnt; cin >> cnt;
        int i = bisearch(cnt);
        if (i == -1)
            cout << 0 << '\n';
        else
            cout << a[i].pos << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}