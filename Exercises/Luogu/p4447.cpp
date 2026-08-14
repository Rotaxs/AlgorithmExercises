#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
int cnt[N], a[N];
int sz;

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    vector<int> mx;
    for (int i = 1; i <= n; i++)
    {
        int k = lower_bound(mx.begin(), mx.end(), a[i]) - mx.begin() - 1;
        if (k == -1)
        {
            mx.push_back(a[i]);
            cnt[sz++]++;
        }
        else
        {
            if (mx[k] == a[i] - 1)
            {
                cnt[k]++;
                mx[k] = a[i];
            }
            else
            {
                mx.push_back(a[i]);
                cnt[sz++]++;
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < sz; i++)
    {
        ans = min(ans, cnt[i]);
    }
    cout << ans << '\n';
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