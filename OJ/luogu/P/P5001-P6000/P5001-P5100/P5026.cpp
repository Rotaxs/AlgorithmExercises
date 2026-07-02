#include <iostream>
using namespace std;

typedef long long ll;

const int OFFSET = 30005;
const int N = 1e6 + OFFSET * 2;
int n, m, v, x;
ll t1[N], t2[N];

int lowbit(int x) { return x & -x; }

void add_D(int i, int x)
{
    ll tmp = (i - 1) * (ll)x;
    while (i < N)
    {
        t1[i] += x;
        t2[i] += tmp;
        i += lowbit(i);
    }
}

void range_add_B(int l, int r, int x)
{
    add_D(l, x);
    add_D(r + 1, -x);
}

ll query(int i)
{
    int p = i;
    ll sum_d = 0, sum_id = 0;
    while (i >= 1)
    {
        sum_d += t1[i];
        sum_id += t2[i];
        i -= lowbit(i);
    }
    return (ll)p * sum_d - sum_id;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (n--)
    {
        cin >> v >> x;
        x += OFFSET;
        range_add_B(x - 3 * v + 1, x - 2 * v, 1);
        range_add_B(x - 2 * v + 1, x - v, -1);
        range_add_B(x - v + 1, x, -1);
        range_add_B(x + 1, x + 2 * v, 1);
        range_add_B(x + 2 * v + 1, x + 3 * v, -1);
    }
    for (int i = 1; i <= m; i++)
        cout << query(i + OFFSET) << ' ';
    cout << '\n';
    return 0;
}