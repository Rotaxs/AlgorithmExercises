#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> PII;

int n, m;
vector<string> gmap;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(int r, int c)
{
    int ret = 1;
    queue<PII> q;
    vector<vector<int>> dist;
    dist.assign(n + 1, vector<int>(n + 1, -1));

    q.push({r, c});
    dist[r][c] = 0;

    while (!q.empty())
    {
        PII f = q.front();
        q.pop();

        int cur_r = f.first;
        int cur_c = f.second;
        char cur_flag = gmap[cur_r][cur_c];

        for (int i = 0; i < 4; i++)
        {
            int ne_r = cur_r + dr[i];
            int ne_c = cur_c + dc[i];
            if (ne_r < 1 || ne_r > n || ne_c < 1 || ne_c > n)
                continue;
            char ne_flag = gmap[ne_r][ne_c];
            if (cur_flag == ne_flag)
                continue;
            if (dist[ne_r][ne_c] >= 0)
                continue;

            q.push({ne_r, ne_c});
            dist[ne_r][ne_c] = dist[cur_r][cur_c] + 1;
            ret++;
        }
    }
    return ret;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    gmap.resize(n + 1);

    string temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        gmap[i] = " " + temp;
    }
    int r, c;
    for (int i = 0; i < m; i++)
    {
        cin >> r >> c;
        cout << bfs(r, c) << '\n';
    }

    return 0;
}