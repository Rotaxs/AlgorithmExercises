#include <iostream>
#include <vector>
using namespace std;

int N, M, ans = 0;
vector<vector<char>> gmap;
vector<vector<bool>> vis;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs(int cur_r, int cur_c)
{
    for (int i = 0; i < 8; i++)
    {
        int next_r = cur_r + dx[i], next_c = cur_c + dy[i];
        if (!vis[next_r][next_c])
        {
            vis[next_r][next_c] = true;
            dfs(next_r, next_c);
        }
    }
}

int main()
{
    cin >> N >> M;
    gmap.assign(N + 2, vector<char>(M + 2, '.'));
    vis.assign(N + 2, vector<bool>(M + 2, true));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> gmap[i][j];
            if (gmap[i][j] == 'W')
                vis[i][j] = false;
        }
    }
    for (int i = 1; i <= N + 1; i++)
    {
        for (int j = 1; j <= M + 1; j++)
        {
            if (!vis[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}