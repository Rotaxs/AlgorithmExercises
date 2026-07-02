/**
 * 洛谷 P1683
 *  https://www.luogu.com.cn/problem/P1683
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int W, H;
vector<vector<char>> gmap;
vector<vector<bool>> vis;
int ans = 1;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void print_map()
{
    for (const auto &arr : gmap)
    {
        for (const auto &e : arr)
        {
            cout << e << " ";
        }
        cout << '\n';
    }
}

bool check(int cur_r, int cur_c)
{
    for (int i = 0; i < 4; i++)
    {
        if (!vis[cur_r + dx[i]][cur_c + dy[i]])
            return true;
    }
    return false;
}

void dfs(int cur_r, int cur_c)
{
    if (!check(cur_r, cur_c))
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int next_r = cur_r + dx[i], next_c = cur_c + dy[i];
        if (!vis[next_r][next_c])
        {
            vis[next_r][next_c] = true;
            ans++;
            dfs(next_r, next_c);
            // 关键：不回溯
        }
    }
}

int main()
{
    cin >> W >> H;
    gmap.assign(H + 2, vector<char>(W + 2, '#'));
    vis.assign(H + 2, vector<bool>(W + 2, true));

    char ch;
    int entry_r, entry_c;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> gmap[i][j];
            if (gmap[i][j] == '#')
                vis[i][j] = true;
            else if (gmap[i][j] == '@')
            {
                vis[i][j] = true;
                entry_r = i;
                entry_c = j;
            }
            else
                vis[i][j] = false;
        }
    }

    // print_map();
    dfs(entry_r, entry_c);
    cout << ans << '\n';

    return 0;
}