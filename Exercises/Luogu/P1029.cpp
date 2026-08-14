#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b)
{
    return (!b ? a : gcd(b, a % b));
}

void solve()
{
    int x, y;
    cin >> x >> y;
    if (y % x != 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        int quotient = y / x;
        int n = 0;
        // 分解质因数
        int cur_factor = 2;
        while (quotient > 1)
        {
            if (quotient % cur_factor == 0)
            {
                n++;
                // 消除当前因数
                while (quotient % cur_factor == 0)
                    quotient /= cur_factor;
            }
            cur_factor++;
        }
        cout << (1 << n) << '\n';
    }
}

void solve2()
{
    int x, y;
    cin >> x >> y;
    ll mult = x * y;
    int ans = 0;
    for (int i = x; i <= y; i++) 
    {
        if (mult % i == 0 && gcd(i, mult / i) == x) 
        {
            // cout << i << ' ' << mult / i << '\n';
            ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve2();
    
    return 0;
}