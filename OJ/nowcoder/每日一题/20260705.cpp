#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int MAXC = 1e6 + 10;
int cnt[MAXC], diff[N][N];
int maxx[MAXC], maxy[MAXC], minx[MAXC], miny[MAXC];

void solve()
{
    int n, m; cin >> n >> m;

    int maxc = 0;
    memset(minx, 0x3f, sizeof minx);
    memset(miny, 0x3f, sizeof miny);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int c; cin >> c;
            maxc = max(maxc, c);
            ++cnt[c];

            maxx[c] = max(maxx[c], j);
            maxy[c] = max(maxy[c], i);
            minx[c] = min(minx[c], j);
            miny[c] = min(miny[c], i);
        }
    }

    for (int i = 1; i <= maxc; i++)
    {
        if (cnt[i] < 2) continue;
        diff[miny[i]][minx[i]]++;
        diff[miny[i]][maxx[i] + 1]--;
        diff[maxy[i] + 1][minx[i]]--;
        diff[maxy[i] + 1][maxx[i] + 1]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            if (diff[i][j] == 0) ans++;
        }
    }
    cout << ans << endl;
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