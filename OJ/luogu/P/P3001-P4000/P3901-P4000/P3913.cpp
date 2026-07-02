#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
int r[N], c[N];

void solve()
{
    ll n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> r[i] >> c[i];
    ll x = 0, y = 0;
    sort(r, r + k);
    sort(c, c + k);
    // x = unique(r, r + k) - r;
    // y = unique(c, c + k) - c;
    for (int i = 0; i < k; i++)
    {
        if (r[i] != r[i + 1]) x++;
        if (c[i] != c[i + 1]) y++;
    }
    cout << (n * n - (n - x) * (n - y)) << '\n';
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