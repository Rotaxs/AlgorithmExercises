#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    ll a, b, c;
    ll m;
    cin >> a >> b >> c >> m;
    ll A = m / a, B = m / b, C = m / c;
    ll AB = m / lcm(a, b), AC = m / lcm(a, c), BC = m / lcm(b, c);
    ll ABC = m / lcm(a, lcm(b, c));
    ll ansa = 0, ansb = 0, ansc = 0;
    ansa += 2 * ABC; ansb += 2 * ABC; ansc += 2 * ABC;
    ansa += 3 * (AB - ABC + AC - ABC); 
    ansb += 3 * (AB - ABC + BC - ABC);
    ansc += 3 * (AC - ABC + BC - ABC);
    ansa += 6 * (A - AB - AC + ABC);
    ansb += 6 * (B - AB - BC + ABC);
    ansc += 6 * (C - AC - BC + ABC);
    cout << ansa << ' ' << ansb << ' ' << ansc << '\n';
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