// ===== 链式前向星建图 =========

#include <iostream>
using namespace std;

const int N = 110;

struct
{
    int to, ne;
} edge[N << 1];
int head[N], cnt = 0; // cnt 记录当前存储位置
int in_degree[N];
int n;

// 添加边，u -> v
void add_edge(int u, int v)
{
    cnt++; // 新建边
    edge[cnt].to = v; // 新边指向 v
    edge[cnt].ne = head[u]; // 新边的下一条边为原来的第一条边（头插）
    head[u] = cnt; // u 指向新边
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int des;
        while (cin >> des)
        {
            if (des == 0)
                break;
            add_edge(i, des); // 添加一条从 i 指向 des 的边
            in_degree[des]++; // des 的入度增加
        }
    }

    int q[N];
    int l = 0,  r = 0;
    for (int i = 1; i <= n; ++i)
    {
        // 如果编号为 i 结点的入度为 0
        // 说明该结点的无依赖（祖先）
        if (in_degree[i] == 0) { q[r++] = i; }
    }
    while (l < r)
    {
        // 弹出队首
        int cur = q[l++];
        cout << cur << ' ';
        // 消除队首对其邻接表元素入度的影响
        int cur_edge = head[cur];
        while (cur_edge != 0)
        {
            // 如果当前边（cur_edge）的指向结点的度为 0
            // 就将其添加到队列
            if (--in_degree[edge[cur_edge].to] == 0)
                q[r++] = edge[cur_edge].to;
            // 如果下一条边不存在（cur_edge == 0）
            // 说明当前结点（队首 cur）的邻接表遍历完成，退出循环
            cur_edge = edge[cur_edge].ne;
        }
    }
    return 0;
}



// ========= 邻接表建图 ==========

// #include <iostream>
// #include <vector>
// using namespace std;

// const int N = 110;
// vector<vector<int>> pic;
// vector<int> in_degree;
// int n;

// int main()
// {
//     cin >> n;
//     in_degree.resize(n + 1, 0);
//     // 创建邻接表
//     pic.push_back(vector<int>()); // 创建编号 0 的邻接表（无用）
//     for (int i = 1; i <= n; i++)
//     {
//         int des;
//         pic.push_back(vector<int>()); // 创建编号 i 的邻接表
//         while (cin >> des)
//         {
//             if (des == 0)
//                 break;
//             pic[i].push_back(des); // 将后代加入邻接表
//             in_degree[des]++; // des 的入度加一
//         }
//     }
//     int q[N];
//     int l = 0, r = 0;
//     // 遍历所有结点
//     for (int item = 1; item <= n; item++)
//     {
//         // 如果入度为零，就将结点放入队列
//         if (in_degree[item] == 0)
//         {
//             q[r++] = item;
//         }
//     }
//     while (l < r)
//     {
//         // 弹出队首
//         int cur = q[l++];
//         cout << cur << ' ';
//         // 遍历队首的邻接表，消除队首对其他结点入度的影响
//         for (int ne : pic[cur])
//         {
//             // 消除影响后如果结点入度为 0，那么将新结点添加到队列中
//             if (--in_degree[ne] == 0)
//                 q[r++] = ne;
//         }

//     }

//     return 0;
// }