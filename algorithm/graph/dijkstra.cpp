#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int inf = 1e9;

struct { int to, ne, w; } edge[M];
int head[N], cnt;

int dist[N];
bool vis[N];

void add_edge(int u, int v, int w)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

// void dijkstra(int s, int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         dist[i] = inf;
//         vis[i] = false;
//     }
//     dist[s] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int min_d = inf, min_id = 0;
//         for (int j = 1; j <= n; j++)
//         {
//             if (vis[i]) continue;
//             if (dist[i] < min_d)
//             {
//                 min_d = dist[i];
//                 min_id = i;
//             }
//         }
//         vis[min_id] = true;
//         int u = min_id;
//         for (int e = head[u]; e; e = edge[e].ne)
//         {
//             int v = edge[e].to;
//             int w = edge[e].w;
//             if (dist[v] > dist[u] + w)
//                 dist[v] = dist[u] + w;
//         }
//     }
// }

void dijkstra(int s, int n)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = inf;
        vis[i] = false;
    }
    dist[s] = 0;
    // {距离, 编号}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (pq.size())
    {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int e = head[u]; e; e = edge[e].ne)
        {
            int v = edge[e].to, w = edge[e].w;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{

    return 0;
}