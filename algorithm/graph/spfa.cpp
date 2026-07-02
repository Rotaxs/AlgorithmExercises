#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int M = 2e3 + 10;
const int inf = 0x3f3f3f3f;

struct { int to, ne, w; } edge[M];
int head[N], dist[N], cnt, relax_cnt[N];
bool inq[N];

void add_edge(int u, int v, int w)
{
    edge[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

bool spfa(int n, int m, int s)
{
    for (int i = 1; i <= n; i++) dist[i] = inf;
    dist[s] = 0;
    queue<int> q;
    q.push(s); inq[s] = true;
    while (q.size())
    {
        int u = q.front(); q.pop(); inq[u] = false;
        for (int e = head[u]; e; e = edge[e].ne)
        {
            int v = edge[e].to, w = edge[e].w;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                relax_cnt[v] = relax_cnt[u] + 1;
                if (relax_cnt[v] >= n) return true;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    
    return 0;
}