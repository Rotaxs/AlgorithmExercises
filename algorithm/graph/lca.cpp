#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int LOG = 20; // 2 ^ 19 > 5e5
struct { int to, ne; } edge[M];
int head[N], cnt;
int depth[N], fa[N][LOG];

void add_edge(int u, int v)
{
    edge[++cnt] = { v, head[u] };
    head[u] = cnt;
}

void dfs(int u, int p)
{
    depth[u] = depth[p] + 1;
    fa[u][0] = p;
    for (int i = 1; i < LOG; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int e = head[u]; e; e = edge[e].ne)
    {
        int v = edge[e].to;
        if (v != p) dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (depth[fa[u][i]] >= depth[v])
            u = fa[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}


// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// const int N = 1e5 + 10;
// const int M = 2e5 + 10;

// struct { int to, ne; } edge[M];
// int head[N], cnt;
// int depth[N], fa[N];

// void add_edge(int u, int v)
// {
//     edge[++cnt] = {v, head[u]};
//     head[u] = cnt;
// }

// // 求出每个节点的深度和直接父结点
// void dfs(int u, int p)
// {
//     depth[u] = depth[p] + 1;
//     fa[u] = p;
//     for (int e = head[u]; e; e = edge[e].ne)
//     {
//         int v = edge[e].to;
//         if (v != p) dfs(v, u);
//     }
// }

// int lca(int u, int v)
// {
//     if (depth[u] < depth[v]) swap(u, v);
//     while (depth[u] > depth[v])
//         u = fa[u];
//     if (u == v) return v;
//     while (u != v)
//     {
//         u = fa[u];
//         v = fa[v];
//     }
//     return u;
// }

int main()
{
    add_edge(1, 2); add_edge(2, 1);
    add_edge(1, 3); add_edge(3, 1);
    add_edge(1, 4); add_edge(4, 1);
    add_edge(2, 5); add_edge(5, 2);
    add_edge(2, 6); add_edge(6, 2);
    add_edge(3, 7); add_edge(7, 3);
    dfs(1, 0);
    cout << "lca(5, 3) = " << lca(5, 3) << '\n';
    cout << "lca(2, 2) = " << lca(2, 2) << '\n';
    cout << "lca(1, 2) = " << lca(2, 1) << '\n';
    cout << "lca(7, 4) = " << lca(7, 4) << '\n';
    cout << "lca(5, 6) = " << lca(5, 6) << '\n';
    return 0;
}