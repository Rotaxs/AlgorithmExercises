#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> PII;

const int N = 2 * 1e5 + 10;
const int MAXW = 1e6 + 10;
// le, ri 是 w 的二分区间
int n, m, le = 0, ri = 0;
// cnt[i] 表示前 i 个矿石 w 大于等于 W 的个数
// sum[i] 表示前 i 个矿石满足 w >= W 的矿石的价值和
int cnt[N] = {0};
long long s, y, ans = 1e18, sum[N] = {0};
PII ranges[N];

struct Stone
{
    int w;
    int v;
} stones[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> stones[i].w >> stones[i].v;
        ri = max(ri, stones[i].w);
    }
    for (int i = 1; i <= m; i++)
        cin >> ranges[i].first >> ranges[i].second;

    ri++;
    while ((le + 1) != ri)
    {
        int W = le + ((ri - le) >> 1);
        y = 0;

        for (int i = 1; i <= n; i++)
        {
            if (stones[i].w >= W)
            {
                cnt[i] = cnt[i - 1] + 1;
                sum[i] = sum[i - 1] + stones[i].v;
            }
            else
            {
                cnt[i] = cnt[i - 1];
                sum[i] = sum[i - 1];
            }
        }

        for (int i = 1; i <= m; i++)
        {
            int l = ranges[i].first, r = ranges[i].second;
            y += (cnt[r] - cnt[l - 1]) * (sum[r] - sum[l - 1]);
        }

        // y 偏小，W 就要偏大
        if (y <= s)
            ri = W;
        else
            le = W;

        ans = min(ans, abs(y - s));
    }

    cout << ans << '\n';
    return 0;
}