#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
int n, k;

ll qpow(ll a, ll n)
{
    int ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ret;
}

void solve()
{
    cin >> n >> k;
    // 对于每门课程，在某一个学期都可以选或不选
    // 那么这门课程在 k 个学期的情况数就是 2 ^ k
    // 其中有一种不合法：k 个学期都没选这门课，因此合法情况数为 2 ^ k - 1
    // 那么 n 门课程的合法情况数就是 (2 ^ k - 1) ^ n
    cout << qpow(qpow(2, k) - 1, n) << '\n';

    // 如果考虑 n 门课程选或不选
    // 那么某个学期就有 2 ^ n 种可能
    // k 个学期就有 2 ^ {nk} 种可能
    // 然后减去选择以下情况
    // 有一门课程没选、有两门课程没选、...、有 n 门课程没选
    // 定义 A_i 表示第 i 门课程没选
    // 那么需要求 A_i 的并集
    // 所有情况就可以用容斥原理来算
    // |并 A_i| = sum(|A_i|) - sum(|A_i ∩ A_j|) + sum(|A_i ∩ A_j ∩ A_k|) - ...
    // 如求 sum(|A_i ∩ A_j|)，可以先选两门课程不学 C(n, 2)，那么剩下的 n - 2 门课可学可不学，即 2 ^ {n - 2}，因此有
    // sum((-1) ^ {i + 1} C(n, i) (2 ^ {n - i}) ^ {k}) (1 <= i <= n)
    // 利用二项式定理化简得 -(2 ^ k - 1) ^ n + 2^{kn}
    // 因此结果为 2 ^{kn} - (-(2 ^ k - 1) ^ n + 2^{kn}) = (2 ^ k - 1) ^ n
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