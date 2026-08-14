#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), pre(n + 5, 0), suf(n + 5, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + abs(a[i]);
    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + a[i];
    ll best = suf[1];
    int last_id = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
        {
            ll tmp = pre[i - 1] + suf[i + 1] - a[i];
            if (tmp > best)
            {
                best = tmp;
                last_id = i;
            }
        }
    }
    if (last_id == 0)
    {
        cout << 0 << "\n\n";
        return;
    }
    vector<int> ans;
    int ms_one_pow = 1;
    for (int i = last_id - 1; i >= 1; i--)
    {
        if (a[i] * ms_one_pow > 0)
        {
            ms_one_pow *= -1;
            ans.push_back(i);
        }
    }
    ans.push_back(last_id);
    cout << ans.size() << '\n';
    for (int d : ans)
        cout << d << ' ';
    cout << '\n';
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