#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n, m;

// 原数组 A，一阶差分数组 B，二阶差分数组 D
// tree 是 D 的树状数组
ll tree[N], tree_help[N];

int lowbit(int x) { return x & -x; }

// 其实是 add_D，二阶差分数组 D 的单点修改
void add(int i, ll v)
{
    ll helper_v = v * (ll)(i - 1);
    while (i <= n)
    {
        tree[i] += v;
        tree_help[i] += helper_v;
        i += lowbit(i);
    }
}

// 通过 B 的差分数组 D 实现对 B 的区间修改
void range_add_B(int l, int r, ll v)
{
    add(l, v);
    add(r + 1, -v);
}

// 通过 A 的差分数组 B 实现对 A 的区间修改
void range_add_A(int l, int r, ll v)
{
    range_add_B(l, l, v);
    range_add_B(r + 1, r + 1, -v);
}

ll query(int i)
{
    int p = i;
    // sum_d 是 D 的前缀和，即 B 的单点
    ll sum_d = 0, sum_id = 0;
    while (i >= 1)
    {
        sum_d += tree[i];
        sum_id += tree_help[i];
        i -= lowbit(i);
    }
    // 返回结果是 B 的前缀和，即 A 的单点
    return p * sum_d - sum_id;
}

int main()
{
    cin >> n >> m;
    ll num;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        range_add_A(i, i, num);
    }

    int opt, l, r, k, d, e, p;
    while (m--)
    {
        cin >> opt;
        switch (opt)
        {
        case 1:
            cin >> l >> r >> k >> d;
            e = k + (r - l) * d;
            range_add_B(l, l, k);
            range_add_B(l + 1, r, d);
            range_add_B(r + 1, r + 1, -e);
            break;
        case 2:
            cin >> p;
            cout << query(p) << '\n';
            break;
        }
    }

    return 0;
}

// #include <iostream>
// #include <cstring>
// using namespace std;

// const int N = 1e5 + 10;
// int n, m;
// long long nums[N], diff[N], pre[N];

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> nums[i];
//     int opt, l, r, k, e, d, p;
//     while (m--)
//     {
//         cin >> opt;
//         switch (opt)
//         {
//         case 1:
//             cin >> l >> r >> k >> d;
//             e = k + (r - l) * d;
//             diff[l] += k;
//             diff[l + 1] += d - k;
//             diff[r + 1] -= e + d;
//             diff[r + 2] += e;
//             break;
//         case 2:
//             cin >> p;
//             memset(pre, 0, sizeof(pre));
//             for (int i = 1; i <= n; i++)
//                 pre[i] = pre[i - 1] + diff[i];
//             for (int i = 1; i <= n; i++)
//                 pre[i] += pre[i - 1];
//             cout << nums[p] + pre[p] << '\n';
//             break;
//         }
//     }
//     return 0;
// }