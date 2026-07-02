#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

/*
设 x_i 为依次倒果汁到第 i 个水杯后，第 i 个水杯中果汁的体积，那么

x_1 = min(v + b_1, a_1)
x_2 = min(x_1 + b_2, a_2)
    = min(min(v + b_1, a_1) + b_2, a_2)
    = min(min(v + b_1 + b_2, a_1 + b_2), a_2) //取小后再加等于加后取小
    = min(v + b_1 + b_2, a_1 + b_2, a_2) // 也就相当于三数取最小值
x_3 = min(x_2 + b_3, a_3)
    = min(v + b_1 + b_2 + b_3, a_1 + b_2 + b_3, a_2 + b_3, a_3)
由此可归纳得出，若记 s_i = b_1 + b_2 + ... + b_i，那么
x_i = min(v + s_i, min(a_1 + s_i - s_1, a_2 + s_i - s_2 + ... + a_i + s_i - s_i))
    = min(v + s_i, min(a_1 - s_1, a_2 - s_2, ..., a_i - s_i) + s_i)
再记 t_i = min(a_1 - s_1, ... a_i - s_i)
那么  x_i = min(v + s_i, t_i + s_i) = min(v, t_i) + s_i
    （x_p = min(v, t_p) + s_p）
用前缀和数组构造 s_i，前缀 min 数组构造 t_i 即可
*/

typedef long long ll;
const int N = 2 * 1e5 + 10;
ll sum_b[N], min_t[N];

void solve()
{
    int n, q;
    cin >> n >> q;
    sum_b[0] = 0, min_t[0] = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        sum_b[i] = sum_b[i - 1] + b;
        min_t[i] = min(min_t[i - 1], a - sum_b[i]);
    }
    while (q--)
    {
        int v, p;
        cin >> v >> p;
        cout << min((ll)v, min_t[p]) + sum_b[p] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) solve();
    return 0;
}