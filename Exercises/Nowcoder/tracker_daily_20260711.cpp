#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 1010;
const int M = 1e5 + 10;

int mat[N][N];
int mv[] = {1, 0, 1, 1, -1};

int count(int t, int x, int y, int dx, int dy)
{
    int res = 0;
    for (int i = 0; i <= 4; i++)
    {
        int nex = x + i * dx;
        int ney = y + i * dy;
        if (mat[nex][ney] == t) res++;
        else break;
    }
    for (int i = -1; i >= -4; i--)
    {
        int nex = x + i * dx;
        int ney = y + i * dy;
        if (mat[nex][ney] == t) res++;
        else break;
    }
    return res;
}

void solve()
{
    int n, m; cin >> n >> m;
    bool gameover = false, over = false;
    string s;
    int num;
    for (int i = 1; i <= m; i++)
    {
        int x, y, t; cin >> x >> y;
        if (i & 1) t = 1;
        else t = 2;
        mat[x][y] = t;
        
        // if (count(t, x, y, 1, 0) >= 5) gameover = true;
        // if (count(t, x, y, 0, 1) >= 5) gameover = true;
        // if (count(t, x, y, 1, 1) >= 5) gameover = true;
        // if (count(t, x, y, -1, 1) >= 5) gameover = true;

        for (int i = 0; i < 4; i++)
            if (count(t, x, y, mv[i], mv[i + 1]) >= 5) 
                gameover = true;

        if (gameover && !over)
        {
            if (t == 1) s = "HtBest";
            if (t == 2) s = "WHZ";
            num = i;
            over = true;
        } 
    }
    if (!gameover) 
    {
        num = m;
        s = "UNK";
    }

    cout << s << " " << num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}