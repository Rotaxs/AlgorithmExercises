#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, m;
int a[N], sum[N];

bool check(int x)
{
    int sum = 0, cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (sum + a[i] <= x)
            sum += a[i];
        else
            sum = a[i], cnt++;
    }
    return cnt <= m;
}

void solve()
{
    cin >> n >> m;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int l = mx - 1, r = 1e9 + 1;
    while ((l + 1) != r)
    {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << '\n';
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