#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[32005];
int mw[65], mv[65];       // main weight, main value
int fw[65][3], fv[65][3]; // follower weight, follower value
int fcnt[65];             // 每个主件的附件数量

int main()
{
    int N, m;
    cin >> N >> m;

    for (int i = 1; i <= m; i++)
    {
        int v, p, q;
        cin >> v >> p >> q;
        if (q == 0)
        { // 主件
            mw[i] = v;
            mv[i] = v * p;
        }
        else
        { // 附件
            fcnt[q]++;
            fw[q][fcnt[q]] = v;
            fv[q][fcnt[q]] = v * p;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        if (mw[i] == 0)
            continue; // 跳过附件，只处理主件

        for (int j = N; j >= mw[i]; j--)
        {
            // 只买主件
            dp[j] = max(dp[j], dp[j - mw[i]] + mv[i]);

            // 主件 + 附件 1
            if (j >= mw[i] + fw[i][1])
                dp[j] = max(dp[j], dp[j - mw[i] - fw[i][1]] + mv[i] + fv[i][1]);

            // 主件 + 附件 2
            if (j >= mw[i] + fw[i][2])
                dp[j] = max(dp[j], dp[j - mw[i] - fw[i][2]] + mv[i] + fv[i][2]);

            // 主件 + 附件 1 + 附件 2
            if (j >= mw[i] + fw[i][1] + fw[i][2])
                dp[j] = max(dp[j], dp[j - mw[i] - fw[i][1] - fw[i][2]] + mv[i] + fv[i][1] + fv[i][2]);
        }
    }

    cout << dp[N] << endl;
    return 0;
}