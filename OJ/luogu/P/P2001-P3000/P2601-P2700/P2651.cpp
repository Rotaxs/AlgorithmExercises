#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[2] /= gcd(a[2], a[1]);
    for (int i = 3; i <= n; i++)
    {
        a[2] /= gcd(a[2], a[i]);
        if (a[2] == 1) break;
    }
    if (a[2] == 1) cout << "Yes\n";
    else cout << "No\n";
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