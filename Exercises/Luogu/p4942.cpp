#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll l, r;
    cin >> l >> r;
    l %= 9;
    r %= 9;
    if (r < l) r += 9;
    cout << (l + r) * (r - l + 1) / 2 % 9 << '\n';
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