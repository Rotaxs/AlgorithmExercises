#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    vector<vector<int>> T(m + 1), S(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= m; i++)
    {
        int len; cin >> len;
        int d = 0;
        while (len--)
        {
            int s; cin >> s;
            S[i].push_back(s);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int len; cin >> len;
        int d = 0;
        while (len--)
        {
            int t; cin >> t;
            T[i].push_back(t);
        }
    }

    for (int i = 1; i <= m; i++)
    {
        bool f1 = true, f2 = true;

        int t_len = T[i].size();
        int s_len = S[i].size();

        int xor_s = 0, xor_t = 0;
        for (int j = 0; j < s_len; j++)
            xor_s ^= a[S[i][j]];
        for (int j = 0; j < t_len; j++)
            xor_t ^= a[T[i][j]];
        if (xor_s != xor_t)
            f2 = false;

        if (t_len != s_len)
            f1 = false;
        else
        {
            for (int j = 0; j < t_len; j++)
                if (S[i][j] != T[i][j])
                    f1 = false;
        }
        
        if (f1 == f2)
            cout << "correct\n";
        else
            cout << "wrong\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}