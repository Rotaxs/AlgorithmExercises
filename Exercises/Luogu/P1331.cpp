#include <iostream>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 1010;
int r, c;
char mat[N][N];
bool vis[N][N];
int moves[] = {-1, 0, 1, 0, -1};

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nex = x + moves[i];
        int ney = y + moves[i + 1];

        if (nex <= 0 || nex > r || ney <= 0 || ney > c)
            continue;
        if (mat[nex][ney] == '.')
            continue;
        if (vis[nex][ney])
            continue;
        vis[nex][ney] = true;
        dfs(nex, ney);
    }
}

void bfs(int x, int y)
{
    queue<PII> q;
    q.push({x, y});
    vis[x][y] = true;
    while (q.size())
    {
        auto [curx, cury] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nex = curx + moves[i];
            int ney = cury + moves[i + 1];
            if (nex <= 0 || nex > r || ney <= 0 || ney > c)
                continue;
            if (vis[nex][ney] || mat[nex][ney] == '.')
                continue;
            vis[nex][ney] = true;
            q.push({nex, ney});
        }
    }
}

int main()
{
    int ans = 0;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> mat[i][j];
        }
    }

    // 判断一个 2 x 2 的方块
    // 当且仅当里面有三个 # 说明有船相撞
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            int cnt = 0;
            if (mat[i][j] == '#')
                cnt++;
            if (mat[i + 1][j] == '#')
                cnt++;
            if (mat[i][j + 1] == '#')
                cnt++;
            if (mat[i + 1][j + 1] == '#')
                cnt++;

            if (cnt == 3)
            {
                cout << "Bad placement.\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (mat[i][j] == '#' && !vis[i][j])
            {
                vis[i][j] = true;
                // dfs(i, j);
                bfs(i, j);
                ans++;
            }
        }
    }
    cout << "There are " << ans << " ships.\n";
    return 0;
}