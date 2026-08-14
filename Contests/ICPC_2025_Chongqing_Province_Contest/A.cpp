#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 10;
int n;
int a[N], b[N];

bool chk()
{
    for (int i = 0; i + 1 < n; i++)
        if (a[i] != a[i + 1]) return false;
    return true;
}

void update(int t)
{
    for (int i = 0; i < n; i++) b[i] = a[i] | a[(i + t) % n];
    for (int i = 0; i < n; i++) a[i] = b[i];
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int t = 0;
    while (!chk()) update(++t);
    cout << t << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;

// const int N = 1e5 + 10;
// int a[N];
// int res = 0;
// int n;

// int tree[N << 2];

// inline int ls(int p) { return p << 1; }
// inline int rs(int p) { return p << 1 | 1; }

// void push_up(int p)
// {
//     tree[p] = tree[ls(p)] | tree[rs(p)];
// }

// void build(int p, int pl, int pr)
// {
//     if (pl == pr) { tree[p] = a[pl]; return; }
//     int mid = (pl + pr) >> 1;
//     build(ls(p), pl, mid);
//     build(rs(p), mid + 1, pr);
//     push_up(p);
// }

// int query(int L, int R, int p, int pl, int pr)
// {
//     int res = 0;
//     if (L <= pl && pr <= R) return tree[p];
//     int mid = (pl + pr) >> 1;
//     if (L <= mid) res |= query(L, R, ls(p), pl, mid);
//     if (R > mid) res |= query(L, R, rs(p), mid + 1, pr);
//     return res;
// }

// bool check(int x)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         ll limit = 1ll * (x + 1) * x / 2;
//         if (limit >= n - 1) return true;
//         if (limit + i <= n)
//         {
//             if (query(i, i + limit, 1, 1, n) != res)
//                 return false;
//         }
//         else if (limit <= n)
//         {
//             if ((query(i, n, 1, 1, n) | query(1, i + limit - n, 1, 1, n)) != res)
//                 return false;
//         }
//     }
//     return true;
// }

// void solve()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         res |= a[i];
//     }
//     build(1, 1, n);
//     int L = -1, R = N - 1;
//     while ((L + 1) != R)
//     {
//         int m = (L + R) >> 1;
//         if (check(m)) R = m;
//         else L = m;
//     }
//     cout << R << '\n';
//     res = 0;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t = 1;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }