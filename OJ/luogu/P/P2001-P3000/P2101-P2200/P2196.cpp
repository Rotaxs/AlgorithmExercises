#include <iostream>
#include <vector>
using namespace std;

const int N = 25;
vector<vector<int>> pic;
int n;
int landmine[N];
int ans = 0;
vector<int> best;
// dp[p] 表示从 p 出发能找到的最大地雷和
// dp[p] = max(dp[q]) + landmine[p] q 是 p 的所有后继结点
int dp[N] = {0};
bool vis[N];
int nxt[N];

int dfs(int p)
{
    if (vis[p]) return dp[p];
    vis[p] = true;
    dp[p] = landmine[p]; // 如果 p 不再有后继结点，说明 landmine[p] 就是从 p 出发能找到的最大地雷数
    nxt[p] = -1; // 如果后面 nxt[p] 没有被覆盖（p 没有后继结点），说明结果中 p 也没有后继结点，即路径到 p 停止
    for (int q : pic[p])
    {
        int val = dfs(q) + landmine[p];
        if (val > dp[p])
        {
            dp[p] = val;
            nxt[p] = q; // p 的后继为 q
        }
    }
    return dp[p];
}

int main()
{
    cin >> n;
    pic.resize(n + 1);
    pic.push_back(vector<int>());
    for (int i = 1; i <= n; i++)
    {
        cin >> landmine[i];
        pic[0].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        pic.push_back(vector<int>());
        for (int j = i + 1; j <= n; j++)
        {
            cin >> tmp;
            if (tmp) pic[i].push_back(j);
        }
    }
    dfs(0);

    int cur = nxt[0];
    while (cur != -1)
    {
        cout << cur << ' ';
        cur = nxt[cur];
    }
    cout << '\n';
    cout << dp[0] << '\n';
    return 0;
}

// ========== 暴搜 ============

// #include <iostream>
// #include <vector>
// using namespace std;

// const int N = 25;
// vector<vector<int>> pic;
// int n;
// int landmine[N];
// int ans = 0;
// vector<int> best;

// void dfs(int p, vector<int> path, int sum)
// {
//     if (pic[p].empty())
//     {
//         if (sum > ans)
//         {
//             ans = sum;
//             best = path;
//         }
//     }
//     for (int node : pic[p])
//     {
//         path.push_back(node);
//         dfs(node, path, sum + landmine[node]);
//         path.pop_back();
//     }
// }

// int main()
// {
//     cin >> n;
//     pic.resize(n + 1);
//     pic.push_back(vector<int>());
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> landmine[i];
//         pic[0].push_back(i);
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         int tmp;
//         pic.push_back(vector<int>());
//         for (int j = i + 1; j <= n; j++)
//         {
//             cin >> tmp;
//             if (tmp) pic[i].push_back(j);
//         }
//     }
//     vector<int> path;
//     dfs(0, path, 0);

//     for (int node : best)
//         cout << node << ' ';
//     cout << '\n';
//     cout << ans << '\n';
//     return 0;
// }
