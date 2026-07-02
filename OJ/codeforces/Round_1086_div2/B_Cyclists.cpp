#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void solve()
{
    long long n, k, p, m;
    cin >> n >> k >> p >> m;
    p--; // 转为 0-based 下标

    deque<long long> dq;
    for (int i = 0; i < n; i++)
    {
        long long cost;
        cin >> cost;
        dq.push_back(cost);
    }

    long long win_cost = dq[p];
    long long win_played = 0;

    // 第一阶段：让 win-condition 进入前 k (即 p < k)
    while (p >= k)
    {
        // 找到前 k 个中最小的代价
        int best_idx = 0;
        for (int i = 1; i < k; i++)
        {
            if (dq[i] < dq[best_idx])
            {
                best_idx = i;
            }
        }

        if (m < dq[best_idx])
        {
            cout << 0 << endl; // 还没摸到 win 牌就没钱了
            return;
        }

        m -= dq[best_idx];

        // 模拟移动
        long long card = dq[best_idx];
        dq.erase(dq.begin() + best_idx);
        dq.push_back(card);

        // 更新 win 牌的位置：它前面走了一个，它就往前挪一位
        p--;
    }

    // 第二阶段：win 牌已经在前 k 了
    if (m >= win_cost)
    {
        // 先玩一次
        m -= win_cost;
        win_played++;

        // 关键点：玩完之后，win 牌会去队尾。
        // 我们需要再次把它弄到前 k 才能继续玩。
        // 这其实是一个循环过程。但最简单的思考方式是：
        // 每次玩完 win 牌，重复第一阶段的操作，直到 m 耗尽。

        // 因为 n, m, k 范围不大 (5000)，可以继续模拟
        p = n - 1;
        while (true)
        {
            // 重复把 p 挪到 k 以内的过程
            while (p >= k)
            {
                int best_idx = 0;
                for (int i = 1; i < k; i++)
                {
                    if (dq[i] < dq[best_idx])
                        best_idx = i;
                }
                if (m < dq[best_idx])
                    goto end;
                m -= dq[best_idx];
                long long c = dq[best_idx];
                dq.erase(dq.begin() + best_idx);
                dq.push_back(c);
                p--;
            }
            // 终于又能玩 win 牌了
            if (m < win_cost)
                break;
            m -= win_cost;
            win_played++;
            p = n - 1; // 玩完又回队尾
        }
    }

end:
    cout << win_played << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}