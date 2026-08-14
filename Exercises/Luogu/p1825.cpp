#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

int N, M;
vector<string> gmap;
vector<vector<bool>> vis;
vector<PII> portals[26];
int ans = INT_MAX;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int cur_r, int cur_c, int cur_t)
{
    if (cur_t > ans)
        return;
    if (gmap[cur_r][cur_c] == '=')
    {
        ans = min(ans, cur_t);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ne_r = cur_r + dr[i];
        int ne_c = cur_c + dc[i];
        if (ne_r < 0 || ne_r >= N || ne_c < 0 || ne_c >= M)
            continue;
        char ch = gmap[ne_r][ne_c];
        if (ch == '#')
            continue;
        if (vis[ne_r][ne_c])
            continue;
        if (ch == '.' || ch == '=')
        {
            vis[ne_r][ne_c] = true;
            dfs(ne_r, ne_c, cur_t + 1);
            vis[ne_r][ne_c] = false;
        }
        else
        {
            vis[ne_r][ne_c] = true;
            for (const auto &portal : portals[ch - 'A'])
            {
                int portal_r = portal.first;
                int portal_c = portal.second;
                if (portal_r == ne_r && portal_c == ne_c)
                    continue;
                vis[portal_r][portal_c] = true;
                dfs(portal_r, portal_c, cur_t + 1);
                vis[portal_r][portal_c] = false;
            }
            vis[ne_r][ne_c] = false;
        }
    }
}

int bfs(int start_r, int start_c)
{
    queue<PII> q;
    vector<vector<int>> dist;
    dist.assign(N, vector<int>(M, -1));

    q.push({start_r, start_c});
    dist[start_r][start_c] = 0;

    while (!q.empty())
    {
        PII f = q.front();
        q.pop();

        int cur_r = f.first;
        int cur_c = f.second;

        if (gmap[cur_r][cur_c] == '=')
            return dist[cur_r][cur_c];

        for (int i = 0; i < 4; i++)
        {
            int ne_r = cur_r + dr[i];
            int ne_c = cur_c + dc[i];
            if (ne_r < 0 || ne_r >= N || ne_c < 0 || ne_c >= M)
                continue;
            char ch = gmap[ne_r][ne_c];
            if (ch == '#')
                continue;
            if (ch >= 'A' && ch <= 'Z')
            {
                for (const auto &portal : portals[ch - 'A'])
                {
                    int portal_r = portal.first;
                    int portal_c = portal.second;
                    if (portal_r == ne_r && portal_c == ne_c)
                        continue;
                    if (dist[portal_r][portal_c] >= 0)
                        continue;
                    dist[portal_r][portal_c] = dist[cur_r][cur_c] + 1;
                    q.push(portal);
                }
            }
            else
            {
                if (dist[ne_r][ne_c] >= 0)
                    continue;
                dist[ne_r][ne_c] = dist[cur_r][cur_c] + 1;
                q.push({ne_r, ne_c});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> N >> M;
    gmap.resize(N);
    vis.assign(N, vector<bool>(M, false));
    int start_r, start_c;
    for (int i = 0; i < N; i++)
    {
        cin >> gmap[i];
        for (int j = 0; j < M; j++)
        {
            if (gmap[i][j] >= 'A' && gmap[i][j] <= 'Z')
                portals[gmap[i][j] - 'A'].push_back({i, j});
            if (gmap[i][j] == '@')
            {
                start_r = i;
                start_c = j;
            }
        }
    }
    ans = bfs(start_r, start_c);
    // 用 dfs 会 TLE
    // vis[start_r][start_c] = true;
    // dfs(start_r, start_c, 0);
    cout << ans << '\n';
    return 0;
}
