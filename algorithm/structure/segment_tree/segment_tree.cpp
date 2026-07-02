#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int a[N], tree[4 * N];

void build(int s, int t, int p)
{
    if (s == t) { tree[p] = a[s]; return; }
    int m = s + ((t - s) >> 1);
    build(s, m, p << 1);
    build(m + 1, t, (p << 1) | 1);
    tree[p] = tree[p << 1] + tree[(p << 1) | 1];
}

int query(int l, int r, int p, int pl, int pr)
{
    if (l <= pl && r >= pr) return tree[p]; // 说明是组成区间 [l, r] 的一部分
    int m = pl + ((pr - pl) >> 1), res = 0; 
    if (l <= m) res += query(l, r, p << 1, pl, m);
    if (r > m) res += query(l, r, (p << 1) | 1, m + 1, pr);
    return res;
}

int main()
{
    int n = 10;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    build(1, n, 1);
    cout << query(7, 9, 1, 1, n) << endl;
    return 0;
}

