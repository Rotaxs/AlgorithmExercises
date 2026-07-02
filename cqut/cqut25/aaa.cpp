#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

// 定义最大点数
const int MAXN = 2005;

// S[i][j] 表示能与 i, j 构成活跃三元组的点的集合
// 注意：为了省空间，我们只存储 i < j 的情况
// 如果内存限制是 512MB 以上，可以直接开 S[MAXN][MAXN]
// 如果限制是 256MB，建议只对部分点对进行 bitset 优化，或者使用更高级的数据结构
bitset<MAXN> S[MAXN][MAXN];

struct Triple
{
    int u, v, w;
};

int main()
{
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<Triple> triples;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // 保证 u < v < w，方便后续处理
        int nodes[3] = {u, v, w};
        sort(nodes, nodes + 3);
        u = nodes[0];
        v = nodes[1];
        w = nodes[2];

        triples.push_back({u, v, w});

        // 记录 bitset 关系
        // 对于三元组 (u, v, w)，任意两点组合都能带上第三个点
        S[u][v].set(w);
        S[u][w].set(v);
        S[v][w].set(u);
    }

    long long total_count = 0;

    // 核心逻辑：遍历每一个已知的三元组 (a, b, c)
    for (const auto &t : triples)
    {
        int a = t.u;
        int b = t.v;
        int c = t.w;

        // 我们要找一个 d，使得 d > c
        // 且 (a, b, d), (a, c, d), (b, c, d) 全是活跃的
        // 这意味着 d 必须同时在 S[a][b], S[a][c], S[b][c] 这三个 bitset 中

        bitset<MAXN> valid_d = S[a][b] & S[a][c] & S[b][c];

        // 统计有多少个满足条件的 d 且 d > c
        // 这里有一个小技巧：我们可以先将 valid_d 右移 c+1 位，再 count
        // 或者直接遍历 bitset 中在 c 之后的 1
        // 为了代码简洁，我们使用掩码或者简单的位操作

        // 创建一个掩码，只保留比 c 大的位
        // 如果你的 bitset 支持，可以用更高效的写法，
        // 这里我们采用最稳妥的：从 c+1 开始遍历（或者手动清空前 c 位）

        // 简单的做法：手动清除 <= c 的位
        // 注意：bitset 的操作比较死板，我们可以写一个循环统计
        // 或者用一种更巧妙的方法：在外面预处理一个后缀掩码
        for (int d = c + 1; d <= n; ++d)
        {
            if (valid_d.test(d))
            {
                total_count++;
            }
        }
    }

    cout << total_count << endl;

    return 0;
}