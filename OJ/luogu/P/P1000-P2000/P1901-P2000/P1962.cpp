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

// a 是 n x k 矩阵，b 是 k x m 矩阵，得到 n x m 矩阵
matrix multiply(const matrix &a, const matrix &b, int n, int k, int m)
{
    matrix c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int r = 1; r <= k; r++)
                c.m[i][j] = (c.m[i][j] + a.m[i][r] * b.m[r][j]) % MOD;
    return c;
}

// 返回 a^p，n 表示 a 的阶数
matrix pow_matrix(matrix a, ll p, int n)
{
    matrix ans;
    for (int i = 1; i <= n; i++)
        ans.m[i][i] = 1; // 单位矩阵
    while (p)
    {
        if (p & 1)
            ans = multiply(ans, a, n, n, n);
        a = multiply(a, a, n, n, n);
        p >>= 1;
    }
    return ans;
}

void print(matrix a, int r, int c)
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cout << a.m[i][j] << ' ';
        }
        cout << '\n';
    }
}

void solve()
{
    ll n;
    cin >> n;
    matrix A;
    matrix s;
    A.m[1][1] = 1; A.m[1][2] = 1; A.m[2][1] = 1; A.m[2][2] = 0;
    s.m[1][1] = 1; s.m[1][2] = 0;
    matrix a = pow_matrix(A, n - 1, 2);
    matrix ans = multiply(s, a, 1, 2, 2);
    cout << ans.m[1][1] << '\n';
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