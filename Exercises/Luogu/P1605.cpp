#include <iostream>
#include <vector>
using namespace std;

int N, M, T, SX, SY, FX, FY;
vector<vector<bool>> vis;
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
int ans = 0;

void dfs(int cur_r, int cur_c)
{
    if (cur_r == FY && cur_c == FX)
    {
        ans++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int next_r = cur_r + dr[i], next_c = cur_c + dc[i];
        if (!vis[next_r][next_c])
        {
            vis[next_r][next_c] = true;
            dfs(next_r, next_c);
            vis[next_r][next_c] = false;
        }
    }
}

void print()
{
    for (const auto &arr : vis)
    {
        for (const bool &e : arr)
        {
            cout << e << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin >> N >> M >> T;
    cin >> SX >> SY >> FX >> FY;
    vis.assign(M + 2, vector<bool>(N + 2, false));
    int t_x, t_y;
    for (int i = 0; i < T; i++)
    {
        cin >> t_x >> t_y;
        vis[t_y][t_x] = true;
    }
    for (int i = 0; i <= M + 1; i++)
    {
        vis[i][0] = true;
        vis[i][N + 1] = true;
    }
    for (int j = 0; j <= N + 1; j++)
    {
        vis[0][j] = true;
        vis[M + 1][j] = true;
    }

    vis[SY][SX] = true;
    dfs(SY, SX);
    cout << ans << '\n';
    return 0;
}