#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, p;
int a[N], b[N];

bool check(double x)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x * a[i] > b[i])
            sum += x * a[i] - b[i];
        if (sum > p * x) return false;
    }
    return sum <= p * x;
}

void solve()
{
    cin >> n >> p;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if (sum <= p)
    {
        cout << -1 << '\n';
        return;
    }
    double l = 0, r = 2e10;
    while (r - l > 1e-6)
    {
        double m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << fixed << setprecision(10) << l << '\n';
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