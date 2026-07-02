#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 310;
typedef pair<int, int> PII;

int M;
vector<vector<int>> dist;
vector<vector<int>> gmap;
queue<PII> q;
int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

int bfs(int r, int c, int t)
{
    q.push({r, c});
    dist[r][c] = 0;

    while (!q.empty())
    {
        PII f = q.front();
        q.pop();

        int cur_r = f.first;
        int cur_c = f.second;

        if (gmap[cur_r][cur_c] == 0x3f3f3f3f)
            return dist[cur_r][cur_c];

        t = dist[cur_r][cur_c] + 1;
        for (int i = 0; i < 4; i++)
        {
            int ne_r = cur_r + dr[i];
            int ne_c = cur_c + dc[i];
            if (ne_r < 0 || ne_r > N - 1 || ne_c < 0 || ne_c > N - 1)
                continue;
            if (dist[ne_r][ne_c] >= 0 || gmap[ne_r][ne_c] <= t)
                continue;
            q.push({ne_r, ne_c});
            dist[ne_r][ne_c] = dist[cur_r][cur_c] + 1;
        }
    }
    return -1;
}

void print_mat()
{
    for (const auto &arr : dist)
    {
        for (const int &e : arr)
        {
            cout << e << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin >> M;
    dist.assign(N, vector<int>(N, -1));
    gmap.assign(N, vector<int>(N, 0x3f3f3f3f));
    int r, c, t;
    while (M--)
    {
        cin >> r >> c >> t;
        gmap[r][c] = min(gmap[r][c], t);
        for (int i = 0; i < 4; i++)
        {
            int ne_r = r + dr[i];
            int ne_c = c + dc[i];
            if (ne_r < 0 || ne_r > N - 1 || ne_c < 0 || ne_c > N - 1)
                continue;
            gmap[ne_r][ne_c] = min(gmap[ne_r][ne_c], t);
        }
    }
    if (gmap[0][0] == 0)
        cout << 0 << '\n';
    else
        cout << bfs(0, 0, 0) << '\n';
    // print_mat();
    return 0;
}
