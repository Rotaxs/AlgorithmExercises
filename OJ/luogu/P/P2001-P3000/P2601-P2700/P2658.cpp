#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

int M, N;
vector<vector<int>> gmap;
// 相当于 dist 数组，但是这题不要求求最短路径，所以只需记录是否访问
vector<vector<bool>> vis;
vector<vector<int>> flag;
int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

// 传入一个海拔高度 m
// 通过 bfs 找到可行的通过所有路标且相邻海拔不超过 m 的路径
// 如果存在，返回 true，否则返回 false
bool check(int r, int c, int m, int cnt)
{
    queue<PII> q;
    vis.assign(M, vector<bool>(N, false));

    q.push({r, c});
    vis[r][c] = true;
    int cur_cnt = 1;

    while (!q.empty())
    {
        PII f = q.front();
        q.pop();

        int cur_r = f.first;
        int cur_c = f.second;

        for (int i = 0; i < 4; i++)
        {
            int ne_r = cur_r + dr[i];
            int ne_c = cur_c + dc[i];
            if (ne_r < 0 || ne_r >= M || ne_c < 0 || ne_c >= N)
                continue;
            if (vis[ne_r][ne_c])
                continue;
            if (abs(gmap[ne_r][ne_c] - gmap[cur_r][cur_c]) > m)
                continue;
            vis[ne_r][ne_c] = true;
            q.push({ne_r, ne_c});
            if (flag[ne_r][ne_c] == 1)
            {
                cur_cnt++;
                if (cur_cnt == cnt)
                    return true;
            }
        }
    }
    return false;
}

int reached_flag = 0;
void dfs(int cur_r, int cur_c, int m, int flags_total)
{
    if (reached_flag == flags_total)
        return;
    for (int i = 0; i < 4; i++)
    {
        int ne_r = cur_r + dr[i];
        int ne_c = cur_c + dc[i];
        if (ne_r < 0 || ne_r >= M || ne_c < 0 || ne_c >= N)
            continue;
        if (vis[ne_r][ne_c])
            continue;
        if (abs(gmap[ne_r][ne_c] - gmap[cur_r][cur_c]) > m)
            continue;
        if (flag[ne_r][ne_c] == 1)
            reached_flag++;
        vis[ne_r][ne_c] = true;
        dfs(ne_r, ne_c, m, flags_total);
    }
}

int main()
{
    cin >> M >> N;
    gmap.assign(M, vector<int>(N));
    vis.assign(M, vector<bool>(N, false));
    flag.assign(M, vector<int>(N, 0));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> gmap[i][j];
        }
    }

    int flags_cnt = 0;
    int start_r, start_c;
    bool found = false;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> flag[i][j];
            if (flag[i][j] == 1)
            {
                flags_cnt++;
                // 找到 搜索 的入口
                if (!found)
                {
                    start_r = i;
                    start_c = j;
                    found = true;
                }
            }
        }
    }

    // 通过二分查找符合条件的海拔高度
    int l = -1, r = 1e9, m;
    // bfs 的二分
    // while (l + 1 != r)
    // {
    //     m = (l + r) / 2;
    //     if (check(start_r, start_c, m, flags_cnt))
    //         r = m;
    //     else
    //         l = m;
    // }

    // dfs 的二分
    while (l + 1 != r)
    {
        m = (l + r) / 2;
        reached_flag = 1;
        vis.assign(M, vector<bool>(N, false));
        vis[start_r][start_c] = true;
        dfs(start_r, start_c, m, flags_cnt);
        if (reached_flag == flags_cnt)
            r = m;
        else
            l = m;
    }

    cout << r << '\n';

    return 0;
}
