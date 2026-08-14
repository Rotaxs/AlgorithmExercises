#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3 * 1e6 + 10;
int inv[N];

void solve()
{
    int n, p;
    cin >> n >> p;
    inv[1] = 1;
    cout << 1 << '\n';
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (ll)(p - p / i) * inv[p % i] % p;
        cout << inv[i] << '\n';
    }
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