#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int p = 19260817;

void read(ll &n)
{
    string s;
    cin >> s;
    for (char c : s)
    {
        n = n * 10 + c - '0';
        n %= p;
    }
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve()
{
    ll a = 0, b = 0, x = 0, y = 0;
    read(a), read(b);
    ll d = exgcd(b, p, x, y);
    if (a % d != 0) { cout << "Angry!\n"; return; }
    cout << ((x * a / d) % p + p) % p << '\n';
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