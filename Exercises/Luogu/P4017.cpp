// ========= 纯 dp =============

#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 80112002;
const int M = 5 * 1e5 + 10;
const int N = 5 * 1e3 + 10;
int in[N], out[N];
ll dp[N];

// 链式前向星建图
struct { int to, ne; } edge[M];
int head[N], cnt = 0;

int n, m;

void add_edge(int u, int v)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].ne = head[u];
    head[u] = cnt;
    in[v]++;
    out[u]++;
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add_edge(u, v);
    }
    int l = 0, r = 0;
    int q[N];
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q[r++] = i;
            // 初始化：入度为 0 的点为起点，本身就有一条路径通向终点
            dp[i] = 1;
        }
    }

    while (l < r)
    {
        int u = q[l++];
        for (int i = head[u]; i != 0; i = edge[i].ne)
        {   
            // 遍历 u 的所有邻居（后继结点）
            int v = edge[i].to;
            // 从 u 可以走到 v，因此所有能到达 u 的路径都是到达 v 的路径
            dp[v] = (dp[v] + dp[u]) % MOD;
            if (--in[v] == 0)
                q[r++] = v;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (out[i] == 0)
            ans = (ans + dp[i]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}


// =========== 记忆化 =============

// #include <iostream>
// using namespace std;

// typedef long long ll;

// const int MOD = 80112002;
// const int M = 5 * 1e5 + 10;
// const int N = 5 * 1e3 + 10;
// struct { int to, ne; } edge[M];
// int head[N], cnt = 0;
// int in[N];
// // int max_inDegree = 0;
// ll ans = 0;
// ll dp[N];

// int n, m;

// void add_edge(int u, int v)
// {
//     cnt++;
//     edge[cnt].to = v;
//     edge[cnt].ne = head[u];
//     head[u] = cnt;
// }

// // 递归查找从 node 开始到结束的路径
// ll dfs(int node)
// {
//     if (dp[node] != 0) return dp[node];
//     // Error: 入度最大的点不一定是出度为 0 的点
//     // if (in[node] == max_inDegree)
//     if (head[node] == 0)
//     {
//         // ans = (ans + 1) % MOD;
//         return 1;
//     }
//     ll sum = 0;
//     for (int i = head[node]; i != 0; i = edge[i].ne)
//         sum = (sum + dfs(edge[i].to)) % MOD;
//     return dp[node] = sum;
// }

// int main()
// {
//     cin >> n >> m;

//     int u, v;
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> u >> v;
//         add_edge(u, v);
//         in[v]++;
//         // max_inDegree = max(in[v], max_inDegree);
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (in[i] == 0)
//             ans = (ans + dfs(i)) % MOD;
//     }
//     cout << ans << '\n';
//     return 0;
// }

// =========== 暴搜 ===========

// #include <iostream>
// using namespace std;

// typedef long long ll;

// const int MOD = 80112002;
// const int M = 5 * 1e5 + 10;
// const int N = 5 * 1e3 + 10;
// struct { int to, ne; } edge[M];
// int head[N], cnt = 0;
// int in[N];
// // int max_inDegree = 0;
// ll ans = 0;

// int n, m;

// void add_edge(int u, int v)
// {
//     cnt++;
//     edge[cnt].to = v;
//     edge[cnt].ne = head[u];
//     head[u] = cnt;
// }

// // 递归查找从 node 开始到结束的路径
// void dfs(int node)
// {
//     // Error: 入度最大的点不一定是出度为 0 的点
//     // if (in[node] == max_inDegree)
//     if (head[node] == 0)
//     {
//         ans = (ans + 1) % MOD;
//         return;
//     }
//     for (int i = head[node]; i != 0; i = edge[i].ne)
//         dfs(edge[i].to);
// }

// int main()
// {
//     cin >> n >> m;

//     int u, v;
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> u >> v;
//         add_edge(u, v);
//         in[v]++;
//         // max_inDegree = max(in[v], max_inDegree);
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (in[i] == 0)
//             dfs(i);
//     }
//     cout << ans % MOD << '\n';
//     return 0;
// }