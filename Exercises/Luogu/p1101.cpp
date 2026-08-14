#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> PII;

int n;
string target = "yizhong";
vector<string> mat;
vector<vector<bool>> vis;
vector<PII> path;
vector<vector<PII>> words_pos;
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int cur_r, int cur_c, string cur_s, int d)
{
    if (cur_s.length() > 7)
        return;
    if (cur_s == target)
    {
        words_pos.push_back(path);
        return;
    }

    int ne_r = cur_r + dr[d];
    int ne_c = cur_c + dc[d];
    if (ne_r < 0 || ne_r >= n || ne_c < 0 || ne_c >= n)
        return;
    if (!vis[ne_r][ne_c])
    {
        vis[ne_r][ne_c] = true;
        path.push_back({ne_r, ne_c});
        string ne_s = cur_s + mat[ne_r][ne_c];
        dfs(ne_r, ne_c, ne_s, d);
        path.pop_back();
        vis[ne_r][ne_c] = false;
    }
}

int main()
{
    cin >> n;
    mat.resize(n);
    vis.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 'y')
            {
                vis[i][j] = true;
                path.push_back({i, j});
                for (int d = 0; d < 8; d++)
                    dfs(i, j, "y", d);
                vis.assign(n, vector<bool>(n, false));
                path.clear();
            }
        }
    }
    // for (auto &arr : words_pos)
    // {
    //     for (auto &pos : arr)
    //     {
    //         printf("(%d, %d) -> ", pos.first, pos.second);
    //     }
    //     printf("\n");
    // }

    vector<string> ans(n, "");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i].push_back('*');
        }
    }
    for (auto &arr : words_pos)
    {
        for (int i = 0; i < 7; i++)
        {
            int r = arr[i].first;
            int c = arr[i].second;
            ans[r][c] = target[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}