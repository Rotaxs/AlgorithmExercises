#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 10;

int fa[N];
int dist[N]; // 记录到达每个格子的最少跳跃次数

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), k(n + 1);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) dist[i] = -1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> k[i];
    
    queue<int> q;
    q.push(1); dist[1] = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        int limit = min(n, u + k[u]);
        int j = find(u + 1); // 找到第一个没被访问过的落脚点 j
        while (j <= limit)
        {
            int v = j - a[j];
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                if (v == n)
                {
                    cout << dist[v] << '\n';
                    return;
                }
                q.push(v);
            }
            fa[j] = j + 1;
            j = find(j + 1);
        }
    }   
    cout << "-1\n";
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// const int N = 1e5 + 10;

// vector<int> e[N];

// void solve()
// {
//     int n; cin >> n;
//     vector<int> a(n + 1), k(n + 1);
//     vector<bool> vis(n + 1, false);
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     for (int i = 1; i <= n; i++) cin >> k[i];
//     for (int u = 1; u <= n; u++)
//     {
//         vis[u] = true;
//         int limit = min(n - u, k[u]);
//         for (int step = 1; step <= limit; step++)
//         {
//             int v = u + step - a[u + step];
//             if (vis[v]) continue;
//             e[u].push_back(v);
//             vis[v] = true;
//         }
//     }
//     vis.resize(n + 1, false);
//     queue<int> q;
//     q.push(1); vis[1] = true;
//     int ans = 0;
//     while (!q.empty())
//     {
//         ans++;
//         int sz = q.size();
//         for (int i = 1; i <= sz; i++)
//         {
//             int u = q.front(); q.pop();
//             for (int v : e[u])
//             {
//                 if (v == n)
//                 {
//                     cout << ans << '\n';
//                     return;
//                 }
//                 if (vis[v]) continue;
//                 q.push(v);
//                 vis[v] = true;
//             }
//         }
//     }
//     cout << "-1\n";
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     solve();

//     return 0;
// }