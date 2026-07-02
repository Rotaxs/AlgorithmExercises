#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<int> pqd;
priority_queue<int, vector<int>, greater<int>> pqx;

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<int> a(m + 1);
    for (int i = 0; i < m; i++) cin >> a[i];
    // 目前要维护 now 个元素，已维护的元素个数为 cnt
    int now = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> now;
        while (cnt < now)
        {
            if (pqd.empty())
            {
                pqd.push(a[cnt++]);
            }
            else
            {
                if (pqd.top() > a[cnt])
                {
                    pqd.push(a[cnt]);
                    cnt++;
                }
                else
                {
                    pqx.push(a[cnt++]);
                }
            }
        }
        while (!pqd.empty() && pqd.size() > i)
        {
            pqx.push(pqd.top());
            pqd.pop();
        }
        while (!pqx.empty() && pqd.size() < i)
        {
            pqd.push(pqx.top());
            pqx.pop();
        }
        cout << pqd.top() << '\n';
    }
    
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();
    
    return 0;
}