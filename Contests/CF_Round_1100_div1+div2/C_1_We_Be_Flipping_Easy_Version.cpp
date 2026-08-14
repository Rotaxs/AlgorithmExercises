#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), ans;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool ok = false;
    int k = 0, minus_one_power = 1;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] * minus_one_power > 0)
        {
            ok = true; k++;
            minus_one_power *= -1;
            ans.push_back(i);
        }
    }
    cout << k << '\n';
    if (ok) 
    {
        for (int d : ans) cout << d << ' ';
    }
    cout << '\n';
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