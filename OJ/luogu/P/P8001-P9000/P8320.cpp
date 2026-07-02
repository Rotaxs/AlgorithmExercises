#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int ask(int x)
{
    int ret;
    cout << "? 1 " << x << endl;
    cin >> ret;
    return ret;
}

void solve()
{
    cin >> n;
    vector<int> ans(n + 1);
    for (int i = n; i >= 1; i--)
    {
        int target = ask(n);

        int l = 1, r = n;
        int res = n;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (ask(mid) == target)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans[res] = i;
        cout << "? 2 " << res << endl;
    }

    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
        if (i != n) cout << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}