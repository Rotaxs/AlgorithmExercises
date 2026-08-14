#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> PII;

int x1, x2, y11, y2, n;
vector<string> gmap;
vector<vector<int>> dist;
queue<PII> q;
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

int bfs(int r, int c)
{
    q.push({r, c});
    dist[r][c] = 0;

    while (!q.empty())
    {
        PII head = q.front();
        q.pop();

        int cur_r = head.first, cur_c = head.second;

        for (int i = 0; i < 4; i++)
        {
            int next_r = cur_r + dr[i], next_c = cur_c + dc[i];
            if (next_r < 1 || next_r > n || next_c < 1 || next_c > n)
                continue;
            if (gmap[next_r][next_c] != '0')
                continue;
            if (dist[next_r][next_c] >= 0)
                continue;
            q.push({next_r, next_c});
            dist[next_r][next_c] = dist[cur_r][cur_c] + 1;

            if (dist[x2][y2] > 0)
                return dist[x2][y2];
        }
    }

    return -1;
}

int main()
{
    cin >> n;
    gmap.resize(n + 1);
    dist.assign(n + 1, vector<int>(n + 1, -1));
    string temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        gmap[i] = " " + temp;
    }
    cin >> x1 >> y11 >> x2 >> y2;
    cout << bfs(x1, y11) << '\n';
    return 0;
}