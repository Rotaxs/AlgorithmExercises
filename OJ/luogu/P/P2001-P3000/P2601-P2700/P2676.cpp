#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[20010];

void solve()
{
    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (sum >= b)
        {
            cout << i << '\n';
            break;
        }
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