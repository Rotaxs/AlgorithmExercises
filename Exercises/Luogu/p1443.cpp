#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

int n, m, x, y;
vector<vector<int>> dist;
queue<PII> q;
int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(int r, int c)
{
    q.push({r, c});
    dist[r][c] = 0;

    while (!q.empty())
    {
        PII f = q.front();
        q.pop();

        int cur_r = f.first;
        int cur_c = f.second;

        for (int i = 0; i < 8; i++)
        {
            int ne_r = cur_r + dr[i];
            int ne_c = cur_c + dc[i];

            if (ne_r < 1 || ne_r > n || ne_c < 1 || ne_c > m)
                continue;
            if (dist[ne_r][ne_c] >= 0)
                continue;

            dist[ne_r][ne_c] = dist[cur_r][cur_c] + 1;
            q.push({ne_r, ne_c});
        }
    }
}

int main()
{
    cin >> n >> m >> x >> y;
    dist.assign(n + 1, vector<int>(m + 1, -1));

    bfs(x, y);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}