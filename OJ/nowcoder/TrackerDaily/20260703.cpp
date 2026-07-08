#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 10;
int a[N], cnt[N];

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int op; cin >> op;
        int x, y;
        switch (op)
        {
        case 1:
            cin >> x >> y;
            break;
        case 2:
            cin >> x; y = n;
            break;
        case 3:
            cin >> y; x = 1;
            break;
        }
        a[x]++; a[y + 1]--;
    }
    int minn = 1e6 + 10;
    cnt[a[1]]++;
    for (int i = 2; i <= n; i++)
    {
        a[i] += a[i - 1];
        if (a[i] != -1)
        {
            cnt[a[i]]++;
            minn = min(minn, a[i]);
        }
    }
    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (a[i] == minn)
    //         ans++;
    // }
    cout << m - minn << ' ' << cnt[minn] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}