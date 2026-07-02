#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

const int N = 510;

typedef pair<int, int> PII;

int n, m, a, b;
int dist[N][N];
PII q[N * N];
int head = 0, tail = 0;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs()
{
    // 队列非空
    while (head < tail)
    {
        PII f = q[head++];

        int cur_r = f.first;
        int cur_c = f.second;

        for (int i = 0; i < 4; i++)
        {
            int ne_r = cur_r + dr[i];
            int ne_c = cur_c + dc[i];
            if (ne_r < 1 || ne_r > n || ne_c < 1 || ne_c > m)
                continue;
            if (dist[ne_r][ne_c] >= 0)
                continue;

            dist[ne_r][ne_c] = dist[cur_r][cur_c] + 1;
            q[tail++] = {ne_r, ne_c};
        }
    }
}

void print_dist()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a >> b;

    memset(dist, -1, sizeof dist);

    int r, c;
    while (a--)
    {
        cin >> r >> c;
        q[tail++] = {r, c};
        dist[r][c] = 0;
    }

    bfs();
    // print_dist();

    while (b--)
    {
        cin >> r >> c;
        cout << dist[r][c] << '\n';
    }

    return 0;
}

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// typedef pair<int, int> PII;

// int n, m, a, b;
// vector<vector<int>> gmap;
// vector<vector<int>> dist;
// queue<PII> q;
// int dr[] = {-1, 0, 1, 0};
// int dc[] = {0, 1, 0, -1};

// void bfs()
// {
//     while (!q.empty())
//     {
//         PII head = q.front();
//         q.pop();

//         int cur_r = head.first;
//         int cur_c = head.second;

//         for (int i = 0; i < 4; i++)
//         {
//             int next_r = cur_r + dr[i];
//             int next_c = cur_c + dc[i];
//             if (next_r < 1 || next_r > n || next_c < 1 || next_c > m)
//                 continue;
//             if (dist[next_r][next_c] >= 0)
//                 continue;
//             dist[next_r][next_c] = dist[cur_r][cur_c] + 1;
//             q.push({next_r, next_c});
//         }
//     }
// }

// void print_mat(vector<vector<int>> &mat)
// {
//     for (const auto &arr : mat)
//     {
//         for (const int &e : arr)
//         {
//             cout << e << ' ';
//         }
//         cout << '\n';
//     }
// }

// int main()
// {

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n >> m >> a >> b;
//     gmap.assign(n + 1, vector<int>(m + 1, 0));
//     dist.assign(n + 1, vector<int>(m + 1, -1));
//     int r, c;
//     while (a--)
//     {
//         cin >> r >> c;
//         q.push({r, c});
//         dist[r][c] = 0;
//     }

//     bfs();

//     while (b--)
//     {
//         cin >> r >> c;
//         cout << dist[r][c] << '\n';
//     }

//     // print_mat(dist);

//     return 0;
// }