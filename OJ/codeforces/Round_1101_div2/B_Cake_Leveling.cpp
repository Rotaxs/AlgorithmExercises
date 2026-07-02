#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    ll sum = 0;
    int prev;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        if (i == 1)
        {
            prev = a;
            cout << prev << ' ';
            sum += prev;
            continue;
        }
        sum += a;
        if (a >= prev)
        {   
            prev = prev;
        }
        else
        {
            prev = min(sum / i, (ll)prev);
        }
        cout << prev << ' ';
    } 
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}