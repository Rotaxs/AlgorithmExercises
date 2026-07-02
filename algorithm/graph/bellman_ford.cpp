#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int M = 2e3 + 10;
const int inf = 0x3f3f3f3f;

struct { int to, ne, w; } edge[M];
int head[N], cnt;
int dist[N];

void add_edge(int u, int v, int w)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

bool bellman_ford(int n, int m, int s)
{
    for (int i = 1; i <= n; i++) dist[i] = inf;
    dist[s] = 0;
    bool relax = false;
    // n - 1 次迭代 + 1 次判负环
    for (int i = 1; i <= n; i++)
    {
        relax = false;
        // 遍历所有顶点，从而遍历所有的边（实际上就是在遍历所有的边）
        for (int u = 1; u <= n; u++)
        {
            if (dist[u] == inf) continue;
            for (int e = head[u]; e; e = edge[e].ne)
            {
                int v = edge[e].to, w = edge[e].w;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    relax = true;
                    if (i == n) return true;
                }
            }
        }
        if (!relax) break;
    }
    // 如果第 n 次迭代仍有松弛操作，说明有负环
    return false;
}

int main()
{

    return 0;
}