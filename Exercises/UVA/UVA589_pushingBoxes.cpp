#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

typedef pair<int, int> PII;
typedef tuple<int, int, char> dir;
const int N = 25;
char maze[N][N];
queue<PII> q;
vector<PII> vis;

string solve(int r, int c,
             int sx, int sy,
             int bx, int by,
             int tx, int ty)
{
    string path = "";
    q.push({sx, sy});

    return path;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // int r, c;
    // int bx, by, sx, sy, tx, ty;
    // while (cin >> r >> c)
    // {
    //     if (r == 0 && c == 0)
    //         break;
    //     for (int i = 1; i <= r; i++)
    //     {
    //         for (int j = 1; j <= c; j++)
    //         {
    //             cin >> maze[i][j];
    //             if (maze[i][j] == 'B')
    //                 bx = i, by = j;
    //             else if (maze[i][j] == 'S')
    //                 sx = i, sy = j;
    //             else if (maze[i][j] == 'T')
    //                 tx = i, ty = j;
    //         }
    //     }
    //     solve(r, c, sx, sy, bx, by, tx, ty);
    // }
    return 0;
}