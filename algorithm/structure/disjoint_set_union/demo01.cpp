/**
 * N 个计算结点和 M 个冗余链路，其中第 i 条链路连接 Ai 和 Bi
 * 链路可双向传输数据
 * 现在这 M 条链路按照 1，2，3，...，M 的顺序依次失效
 * 定义系统不便度为系统中无法通讯的有序结点数对 (u,v) (u<v) 的数量
 *
 * 输入：
 *  第一行输入 N，M
 *  接下来的 M 行，输入 Ai Bi
 *
 * 输出：
 *  M 行，输出结点失效后的系统不便度
 *
 * 2 <= N <= 1e5
 * 1 <= M <= 1e5
 * 1 <= A_i < B_i <= N
 */

// 测试用例
/*
In：
2 1
1 2
Out：
1
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    题目要求删除链路，实际上，如果反向思考，则是一个合并结点的过程
    而判断结点能否联通，则是判断它们在不在同一个集合中
    因此，此题考虑 逆向 + 并查集
*/

const int N = 1e5 + 10;

int n, m;
int fa[N];
long long sizes[N]; // 用于维护连通分量的大小
int ranks[N];

// 初始化并查集
void init()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sizes[i] = 1; // 初始时，每个集合大小为1
        ranks[i] = 1;
    }
}

// 查找根节点（带路径压缩）
int find(int x)
{
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

// 合并两个节点所在的集合，并返回减少的不便度
long long unite(int i, int j)
{
    int x = find(i);
    int y = find(j);
    if (x == y)
    {
        return 0; // 已经在同一个集合，不便度不减少
    }

    // 记录合并前的大小
    long long size_x = sizes[x];
    long long size_y = sizes[y];

    // 按秩合并优化
    if (ranks[x] < ranks[y])
    {
        swap(x, y);
    }
    fa[y] = x;
    if (ranks[x] == ranks[y])
    {
        ranks[x]++;
    }

    // 更新新集合的大小
    sizes[x] = size_x + size_y;

    // 返回减少的不便度
    return size_x * size_y;
}

int main()
{
    // 提高输入输出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    init();

    // 使用 vector 存储边，避免栈溢出
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    // 初始不便度：所有节点对都不连通
    // 注意：n * (n-1) 可能会溢出，需要强制类型转换
    long long current_inconvenience = (long long)n * (n - 1) / 2;

    vector<long long> answers;

    // 逆向处理：从最后一条边开始添加
    for (int i = m - 1; i >= 0; i--)
    {
        // 记录添加当前边之前的状态
        answers.push_back(current_inconvenience);

        // 添加边，并更新不便度
        int u = edges[i].first;
        int v = edges[i].second;
        current_inconvenience -= unite(u, v);
    }

    // answers 中是逆序的，需要反向输出
    for (auto it = answers.rbegin(); it != answers.rend(); it++)
    {
        cout << *it << "\n";
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// /*
//     题目要求删除链路，实际上，如果反向思考，则是一个合并结点的过程
//     而判断结点能否联通，则是判断它们在不在同一个集合中
//     因此，此题考虑 逆向 + 并查集
// */

// // N个结点最多有 (N-1)N/2 条链路
// const long long M = 1e10 + 1;
// const int N = 1e5 + 10;

// int n;
// long long m;

// int fa[N];
// // long long ques[M][2];
// vector<vector<int>> ques;
// int ranks[N];

// void init()
// {
//     for (int i = 0; i < n; i++)
//     {
//         fa[i] = i;
//         ranks[i] = 1;
//     }
// }

// int find(int x)
// {
//     return fa[x] == x ? x : (fa[x] = find(fa[x]));
// }

// long long unite(int i, int j)
// {
//     long long x = find(i), y = find(j);
//     if (x == y)
//         return 1;
//     if (ranks[x] < ranks[y])
//         swap(x, y);
//     fa[y] = x;
//     if (ranks[x] == ranks[y])
//         ranks[x]++;
//     return ranks[x] * ranks[y];
// }

// int main()
// {
//     cin >> n >> m;
//     init();
//     for (long long i = 0; i < m; i++)
//     {
//         scanf("%d %d", &ques[i][0], &ques[i][1]);
//     }
//     long long current_convenience = (n * (n - 1)) / 2;
//     int A, B;
//     vector<long long> answers;
//     for (long long i = m - 1; i >= 0; i--)
//     {

//         answers.push_back(current_convenience);
//         A = ques[i][0];
//         B = ques[i][1];
//         current_convenience -= unite(A, B);
//     }
//     for (auto it = answers.end() - 1; it != answers.begin(); it--)
//     {
//         cout << *it << endl;
//     }
//     return 0;
// }
