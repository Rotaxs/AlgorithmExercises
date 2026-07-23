#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

ll get_floor(ll x, ll n)
{
    ll l = 0, r = n + 1;
    while ((l + 1) != r)
    {
        ll m = l + ((r - l) >> 1);
        if (x <= m * (m + 1) / 2) r = m;
        else l = m;
    }
    return r;
}

void solve()
{
    ll l, r, n; cin >> n >> l >> r;
    ll fl = get_floor(l, n), fr = get_floor(r, n);
    if (fl == fr) { cout << "Yes\n"; return; }
    if (fr - fl >= 2) { cout << "No\n"; return; }
    ll cl = l - (fl - 1) * fl / 2, cr = r - (fr - 1) * fr / 2;
    cout << (cl - 1 >= cr ? "Yes\n" : "No\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}