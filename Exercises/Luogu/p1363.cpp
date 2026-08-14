#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

const int N = 1510;
char maze[N][N];
bool vis[N][N];
pair<int, int> last[N][N]; // 记录第一次到达 x，y 逻辑点的实际坐标
int n, m;
int moves[] = {-1, 0, 1, 0, -1};
bool ac = false;

void dfs(int rx, int ry)
{
    if (ac) return;
    int lx = (rx % n + n) % n;
    int ly = (ry % m + m) % m;
    if (vis[lx][ly])
    {
        if (last[lx][ly].first != rx || last[lx][ly].second != ry)
            ac = true;
        return;
    }

    vis[lx][ly] = true;
    last[lx][ly] = {rx, ry};

    for (int i = 0; i < 4; i++)
    {
        int nrx = rx + moves[i];
        int nry = ry + moves[i + 1];
        // 将实际坐标映射到逻辑坐标
        int nlx = (nrx % n + n) % n;
        int nly = (nry % m + m) % m;
        if (maze[nlx][nly] == '#')
            continue;
        // 搜索实际迷宫，传实际坐标
        dfs(nrx, nry);
        if (ac)  return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        int sx, sy;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'S') { sx = i; sy = j; }
            }
        }

        ac = false;
        memset(vis, 0, sizeof vis);
        dfs(sx, sy);
        if (ac)  { cout << "Yes\n"; } 
        else { cout << "No\n"; }
    }

    return 0;
}