#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<int> pqd;
priority_queue<int, vector<int>, greater<int>> pqx;

void update(int x, int i)
{
    if (pqx.size() == i)
    {
        int top = pqx.top();
        if (x > top)
        {
            pqx.pop();
            pqx.push(x);
            pqd.push(top);
        }
        else
        {
            pqd.push(x);
        }
    }
    else
    {
        int top = pqd.top();
        if (x >= top)
        {
            pqx.push(x);
        }
        else
        {
            pqd.pop();
            pqd.push(x);
            pqx.push(top);
        }
    }
}

void solve()
{
    int x, q; cin >> x >> q;
    pqx.push(x);
    for (int i = 1; i <= q; i++)
    {
        int len = i + 1;
        int a, b; cin >> a >> b;
        update(a, i);
        update(b, i);
        cout << pqd.top() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();
    
    return 0;
}