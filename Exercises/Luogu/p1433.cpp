#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<double, double> PDD;
int n;
double ans = 1e18;
const int N = 16;
PDD cheeses[N];
double dists[N][N], dp[1 << N][N];

double get_d(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double dfs(int state, int cur)
{
    if (dp[state][cur] != -1)
        return dp[state][cur];
    if (state == (1 << n) - 1)
        return 0;
    double res = 1e18;
    for (int ne = 1; ne <= n; ne++)
    {
        // 已经吃过
        if (state & (1 << (ne - 1)))
            continue;
        res = min(res, dists[cur][ne] + dfs(state | (1 << (ne - 1)), ne));
    }
    return dp[state][cur] = res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%lf %lf", &cheeses[i].first, &cheeses[i].second);
    cheeses[0].first = cheeses[0].second = 0;
    fill(dp[0], dp[0] + (1 << N) * N, -1.0);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dists[i][j] = get_d(cheeses[i].first, cheeses[i].second, cheeses[j].first, cheeses[j].second);
    printf("%.2lf\n", dfs(0, 0));
    return 0;
}

// ==================== 90 分没过 ===================
// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;

// typedef pair<double, double> PDD;

// int n;
// vector<PDD> cheeses;
// vector<bool> vis;
// double dist[20][20];

// double ans = 1e18;

// double get_distance(double r1, double c1, double r2, double c2)
// {
//     double sq = (r1 - r2) * (r1 - r2) + (c1 - c2) * (c1 - c2);
//     double l = 0, r = 1e9, m;
//     for (int i = 0; i < 100; i++)
//     {
//         m = (l + r) / 2;
//         if (m * m < sq)
//             l = m;
//         else
//             r = m;
//     }
//     return m;
// }

// void dfs(int pos, int cur_i, double cur_s)
// {
//     if (cur_s >= ans)
//         return;
//     if (pos == n)
//     {
//         ans = min(ans, cur_s);
//         return;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (vis[i])
//             continue;
//         int ne_i = i;
//         vis[i] = true;
//         dfs(pos + 1, ne_i, cur_s + dist[cur_i][ne_i]);
//         vis[i] = false;
//     }
// }

// int main()
// {
//     cin >> n;
//     double r, c;
//     vis.resize(n + 1, false);
//     vis[0] = true;
//     cheeses.push_back({0, 0});
//     for (int i = 0; i < n; i++)
//     {
//         cin >> r >> c;
//         cheeses.push_back({r, c});
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             dist[i][j] = get_distance(cheeses[i].first, cheeses[i].second,
//                                       cheeses[j].first, cheeses[j].second);
//         }
//     }
//     dfs(0, 0, 0);
//     // cout << get_distance(0, 0, 1, 1) << '\n';
//     printf("%.2f", ans);
//     return 0;
// }