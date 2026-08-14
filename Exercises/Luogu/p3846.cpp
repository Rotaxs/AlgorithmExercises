#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll qpow(ll a, ll n, ll p)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = ret * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ret;
}

int bsgs(int a, int b, int p)
{
    a %= p; b %= p;
    // 特判 A = 0 的情况
    if (b % p == 1 % p) return 0; // 1 % p 防止 p == 1
    unordered_map<int, int> ha;
    int k = ceil(sqrt(p)); // 防止精度丢失
    for (int B = 0, val = b % p; B < k; B++)
    {
        ha[val] = B;
        val = 1LL * val * a % p;
    }
    ll ak = qpow(a, k, p);
    // 
    for (int A = 1, val = ak; A <= k; A++)
    {
        if (ha.count(val)) return 1LL * A * k - ha[val];
        val = 1LL * val * ak % p;
    }
    return -1;
}

void solve()
{
    int p, b, n;
    cin >> p >> b >> n;
    int ans = bsgs(b, n, p);
    if (ans == -1) cout << "no solution\n";
    else cout << ans << '\n';
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