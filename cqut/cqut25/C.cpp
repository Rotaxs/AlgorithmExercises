#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

// 链式前向星建图
struct
{
    int to, ne;
} edge[N];
int head[N], cnt = 0;

void add_edge(int u, int v)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

void dfs(int p)
{
    if (p != 0) cout << p << ' ';
    // head[p] 表示连接 p 这个结点第一条边
    // i = edge[i].ne 保证每次搜索下一条边
    for (int i = head[p]; i != 0; i = edge[i].ne)
        // 递归搜索保证输出顺序
        dfs(edge[i].to);
}

int main()
{
    int n;
    cin >> n;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        // i 的位置是 a，那么 a 就是 i 的直接后继
        // 建立 a 指向 i 的有向边，表示 a 是 i 的直接后继
        add_edge(a, i);
        // a 是 0，表示虚拟根结点
    }
    // 从根结点开始搜索
    dfs(0);

    return 0;
}