#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int l, n, m;
int a[50010];

// bool check(int x)
// {
//     int g = 0;
//     int cur = 0;
//     int i = 1;
//     while (i < n + 1)
//     {
//         if (a[i] - a[cur] < x) g++;
//         else cur = i;
//         i++;
//     }
//     if (g <= m) return true;
//     return false;
// }

bool check(int x)
{
    int g = 0;
    int cur = 0;                     
    for (int i = 1; i <= n + 1; i++) 
    {
        if (a[i] - a[cur] < x)
        {
            g++; 
        }
        else
        {
            cur = i;
        }
    }
    return g <= m;
}

void solve()
{
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = l;
    int le = 0, ri = l + 1;
    while ((le + 1) != ri)
    {
        int mid = le + ((ri - le) >> 1);
        if (check(mid)) le = mid;
        else ri = mid;
    }
    cout << le << '\n';
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