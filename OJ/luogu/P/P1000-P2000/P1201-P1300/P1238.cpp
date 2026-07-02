#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int m, n, start_r, start_c, end_r, end_c;
vector<vector<int>> mat;
vector<vector<bool>> vis;
vector<pair<int, int>> path;
bool found = false;
// vector<vector<pair<int, int>>> res;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

void print_path(vector<pair<int, int>> path)
{
    int len = path.size();
    for (int i = 0; i < len; i++)
    {
        printf("(%d,%d)", path[i].first, path[i].second);
        if (i != len - 1)
            printf("->");
    }
    printf("\n");
}

void dfs(int cur_r, int cur_c)
{
    if (cur_r == end_r && cur_c == end_c)
    {
        found = true;
        print_path(path);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int next_r = cur_r + dx[i], next_c = cur_c + dy[i];
        if (!vis[next_r][next_c])
        {
            vis[next_r][next_c] = true;
            path.push_back({next_r, next_c});
            dfs(next_r, next_c);
            vis[next_r][next_c] = false;
            path.pop_back();
        }
    }
}

int main()
{
    cin >> m >> n;
    mat.assign(m + 2, vector<int>(n + 2, 0));
    vis.assign(m + 2, vector<bool>(n + 2, true));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
                vis[i][j] = false;
        }
    }
    cin >> start_r >> start_c >> end_r >> end_c;
    path.push_back({start_r, start_c});
    vis[start_r][start_c] = true;
    dfs(start_r, start_c);
    if (!found)
        printf("-1\n");
    return 0;
}