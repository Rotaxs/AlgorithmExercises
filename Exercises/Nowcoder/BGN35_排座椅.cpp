#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e3 + 10;

struct Node
{
    int val, pos;
    bool operator<(const Node &other) const
    {
        return val > other.val;
    }
} r[N], c[N];

priority_queue<Node> a, b;

void solve()
{
    int n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;

    for (int i = 1; i <= n; i++)
        r[i].pos = i;
    for (int j = 1; j <= m; j++)
        c[j].pos = j;

    for (int i = 1; i <= d; i++)
    {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if (x == p)
            c[min(y, q)].val++;
        else if (y == q)
            r[min(x, p)].val++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a.size() < k) a.push(r[i]);
        else
        {
            if (a.top().val < r[i].val)
            {
                a.pop();
                a.push(r[i]);
            }
        }
    }
    for (int j = 1; j <= m; j++)
    {
        if (b.size() < l) b.push(c[j]);
        else
        {
            if (b.top().val < c[j].val)
            {
                b.pop();
                b.push(c[j]);
            }
        }
    }
    // while (!a.empty())
    // {
    //     cout << a.top().pos << ' ';
    //     a.pop();
    // }
    // cout << endl;
    // while (!b.empty())
    // {
    //     cout << b.top().pos << ' ';
    //     b.pop();
    // }
    vector<int> ans;
    
    while (!a.empty())
    {
        ans.push_back(a.top().pos);
        a.pop();
    }
    sort(ans.begin(), ans.end());
    for (int e : ans) cout << e << ' ';

    ans.clear();
    cout << endl;

    while (!b.empty())
    {
        ans.push_back(b.top().pos);
        b.pop();
    }
    sort(ans.begin(), ans.end());
    for (int e : ans) cout <<  e << ' ';

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