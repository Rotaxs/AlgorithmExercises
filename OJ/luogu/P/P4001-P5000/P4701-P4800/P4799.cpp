#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
ll m;
vector<ll> p;
vector<ll> suma, sumb;

void dfs(int l, int r, ll cur_sum, vector<ll> &sums)
{
    if (cur_sum > m) return;
    if (l > r)
    {
        sums.push_back(cur_sum);
        return;
    }
    dfs(l + 1, r, cur_sum + p[l], sums);
    dfs(l + 1, r, cur_sum, sums);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    
    int mid = n >> 1;
    dfs(1, mid, 0, suma);
    dfs(mid + 1, n, 0, sumb);

    ll ans = 0;
    // 双指针
    sort(suma.begin(), suma.end());
    sort(sumb.begin(), sumb.end());
    int i = 0, j = sumb.size() - 1;
    while (i < suma.size() && j >= 0)
    {
        if (suma[i] + sumb[j] <= m)
        {
            ans += j + 1;
            i++;
        }
        else
        {
            j--;
        }
    }

    // 二分
    // sort(sumb.begin(), sumb.end());
    // for (ll val : suma)
    // {
    //     ans += upper_bound(sumb.begin(), sumb.end(), m - val) - sumb.begin();
    // }
    cout << ans << '\n';

    return 0;
}