#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<int> pre_a(n + 1), b(n + 1), pre_b(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        int a; cin >> a;
        if (i == 0) { pre_a[i] = a; continue; }
        pre_a[i] = pre_a[i - 1] + a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        pre_b[i] = pre_b[i - 1] + b[i];
    }

    vector<int> premax(n + 1), sufmax(n + 1);
    premax[0] = pre_a[0];
    for (int i = 1; i <= n; i++)
        premax[i] = max(pre_a[i] - pre_b[i], premax[i - 1]);
    sufmax[n] = pre_a[n] - pre_b[n];
    for (int i = n - 1; i >= 1; i--)
        sufmax[i] = max(pre_a[i] - pre_b[i], sufmax[i + 1]);

    for (int i = 1; i <= n; i++)
    {
        int w = max(premax[i - 1], sufmax[i] + b[i]);
        cout << w << ' ';
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     int w = pre_a[0];
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (j >= i)
    //             w = max(pre_a[j] - pre_b[j] + b[i], w);
    //         else
    //             w = max(pre_a[j] - pre_b[j], w);
    //     }
    //     cout << w << ' ';
    // }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}