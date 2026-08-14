#include <bits/stdc++.h>
using namespace std;

void divide(int x, int &a, int &b, int &c)
{
    a = (x & (7 << 6)) >> 6;
    b = (x & (7 << 3)) >> 3;
    c = (x & 7);
}

int f(int x, int k)
{
    return (((x * x + k * k) % 8) ^ k);
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> k(m + 1), a(n + 1);
    for (int i = 1; i <= m; i++) cin >> k[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int anss[(1 << 9)];
    for (int x = 0; x < (1 << 9); x++)
    {
        int a2 = 0, b2 = 0, c2 = 0;
        divide(x, a2, b2, c2);
        for (int j = m; j >= 1; j--)
        {
            int a1, b1, c1;
            b1 = a2;
            c1 = b2 ^ f(b1, k[j]);
            a1 = c2 ^ f(c1, k[j]);
            a2 = a1; b2 = b1; c2 = c1;
        }
        int ans = 0;
        ans = (a2 << 6) | (b2 << 3) | (c2);
        anss[x] = ans;
    }
    for (int i = 1; i <= n; i++)
        cout << anss[a[i]] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}