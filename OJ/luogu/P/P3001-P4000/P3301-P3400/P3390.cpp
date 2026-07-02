#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 110;
const int MOD = 1e9 + 7;
struct matrix
{ 
    ll m[N][N];
    matrix() { memset(m, 0, sizeof m); }
};

int n;
ll k;

matrix operator * (const matrix &a, const matrix &b)
{
    matrix c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
    return c;
}

matrix pow_matrix(matrix a, ll p)
{
    matrix ans;
    for (int i = 1; i <= n; i++) ans.m[i][i] = 1; // 单位矩阵
    while (p)
    {
        if (p & 1)
            ans = ans * a;
        a = a * a;
        p >>= 1;
    }
    return ans;
}

void solve()
{
    matrix a;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a.m[i][j];
    matrix ans = pow_matrix(a, k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ans.m[i][j] << ' ';
        }
        cout << '\n';
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