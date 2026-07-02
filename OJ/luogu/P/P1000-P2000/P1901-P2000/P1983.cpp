// ============= 引入虚拟结点的链式前向星建图 ==============

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2010;    // n + m 个节点
const int M = 1000005; // 边数降为 O(MN)

struct
{
    int to, ne, w;
} edge[M];

int head[N], cnt = 0;
int in_degree[N], dist[N];
bool is_stop[N];

void add_edge(int u, int v, int w)
{
    edge[++cnt] = {v, head[u], w};
    head[u] = cnt;
    in_degree[v]++;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int s_cnt;
        cin >> s_cnt;
        vector<int> stops(s_cnt);
        fill(is_stop + 1, is_stop + n + 1, false);

        for (int j = 0; j < s_cnt; j++)
        {
            cin >> stops[j];
            is_stop[stops[j]] = true;
        }

        int vir_node = n + i; // 为每趟车建立一个虚拟节点
        int start = stops[0], end = stops[s_cnt - 1];

        for (int j = start; j <= end; j++)
        {
            if (is_stop[j])
            {
                // 虚拟点 -> 停靠站，边权为 1 (等级提升)
                add_edge(vir_node, j, 1);
            }
            else
            {
                // 未停靠站 -> 虚拟点，边权为 0 (等级不变)
                add_edge(j, vir_node, 0);
            }
        }
    }

    // 拓扑排序计算最长路
    int q[N + N], l = 0, r = 0;
    for (int i = 1; i <= n + m; i++)
    {
        if (in_degree[i] == 0)
        {
            q[r++] = i;
            // 真实站等级初始为 1，虚拟点不占等级初始为 0
            if (i <= n)
                dist[i] = 1;
            else
                dist[i] = 0;
        }
    }

    int ans = 0;
    while (l < r)
    {
        int u = q[l++];
        if (u <= n)
            ans = max(ans, dist[u]); // 只有真实车站更新答案

        for (int i = head[u]; i != 0; i = edge[i].ne)
        {
            int v = edge[i].to;
            // 如果是从 虚拟点 -> 真实站，等级才真正 +1
            // 如果是从 真实站 -> 虚拟点，等级不变
            if (dist[v] < dist[u] + edge[i].w)
            {
                dist[v] = dist[u] + edge[i].w;
            }

            if (--in_degree[v] == 0)
            {
                q[r++] = v;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

// =========== 邻接矩阵建图（可去重） =============

// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// const int N = 1010;
// bool has_edge[N][N];
// int in_degree[N], level[N];
// int n, m;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> n >> m;

//     for (int i = 0; i < m; i++)
//     {
//         int s_cnt;
//         cin >> s_cnt;
//         vector<int> stops(s_cnt);
//         vector<bool> is_stop(n + 1, false);

//         for (int j = 0; j < s_cnt; j++)
//         {
//             cin >> stops[j];
//             is_stop[stops[j]] = true;
//         }

//         // 在这趟车的起点 stops[0] 到 终点 stops[s_cnt-1] 之间
//         // 没停靠的站(is_stop[k]==false) -> 停靠了的站(stops[j]) 连边
//         int start = stops[0], end = stops[s_cnt - 1];
//         for (int k = start; k <= end; k++)
//         {
//             if (!is_stop[k])
//             { // 如果区间内没停靠
//                 for (int stop_node : stops)
//                 { // 向所有停靠站连边
//                     if (!has_edge[k][stop_node])
//                     {
//                         has_edge[k][stop_node] = true;
//                         in_degree[stop_node]++;
//                     }
//                 }
//             }
//         }
//     }

//     // 拓扑排序找层数
//     queue<pair<int, int>> q;
//     for (int i = 1; i <= n; i++)
//     {
//         if (in_degree[i] == 0)
//         {
//             q.push({i, 1});
//         }
//     }

//     int max_level = 0;
//     while (!q.empty())
//     {
//         pair<int, int> cur = q.front();
//         q.pop();

//         int u = cur.first;
//         int l = cur.second;
//         max_level = max(max_level, l);

//         for (int v = 1; v <= n; v++)
//         {
//             if (has_edge[u][v])
//             {
//                 in_degree[v]--;
//                 if (in_degree[v] == 0)
//                 {
//                     q.push({v, l + 1});
//                 }
//             }
//         }
//     }

//     cout << max_level << endl;

//     return 0;
// }

// ========= 链式前向星建图（此题不推荐） ==========

// #include <iostream>
// #include <vector>
// using namespace std;

// const int N = 1010;
// int n, m;
// int g[N][N];
// struct
// {
//     int to, ne;
// } edge[N * N];
// int head[N], cnt = 0, in_degree[N];

// void add_edge(int u, int v)
// {
//     cnt++;
//     edge[cnt].to = v;
//     edge[cnt].ne = head[u];
//     head[u] = cnt;
// }

// int main()
// {
//     cin >> n >> m;

//     // 建图
//     int s_cnt; // 当前车次停靠站的数量
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> s_cnt;
//         vector<int> stops; // 记录所有的停靠站
//         vector<bool> is_stop; // 当前车站是否是停靠站
        
//         stops.resize(s_cnt + 1);
//         is_stop.resize(n + 1, false);
        
//         int st;
//         for (int i = 1; i <= s_cnt; i++)
//         {
//             cin >> st;
//             is_stop[st] = true;
//             stops[i] = st;
//         }
//         // 无站台结点要与所有有站台的结点连边
//         // 如此，只要将最前面的站台的等级设置为 1
//         // 那么最后面的无站台结点的等级就是最少要划分的级别数
//         for (int i = stops[1]; i <= stops[s_cnt]; i++)
//         {
//             if (!is_stop[i])
//             {
//                 for (int s = 1; s <= s_cnt; s++)
//                 {
//                     // 防止重复建边
//                     // 如果这样还不如直接用邻接矩阵 🤣
//                     if (!g[i][stops[s]])
//                     {
//                         g[i][stops[s]] = true;
//                         add_edge(i, stops[s]);
//                         in_degree[stops[s]]++;
//                     }
                    
//                 }
//             }
//         }
//     }

//     // 拓扑排序
//     int level = 0;
//     int q[N], l = 0, r = 0;

//     // 将入度为 0 的结点放入队列
//     for (int i = 1; i <= n; i++)
//         if (in_degree[i] == 0)
//             q[r++] = i;
    
//     while (l < r)
//     {
//         int sz = r - l;
//         level++;

//         // 将当前层（队列中入度相同的结点）对其邻接表的影响消除
//         while (sz--)
//         {
//             int cur = q[l++];
//             // 等于 0 说明当前边没有链接下一个结点
//             for (int e = head[cur]; e != 0; e = edge[e].ne)
//             {
//                 int ne = edge[e].to;
//                 if (--in_degree[ne] == 0)
//                 {
//                     q[r++] = ne;
//                 }
//             }
//         }
//     }
//     cout << level << '\n';
//     return 0;
// }