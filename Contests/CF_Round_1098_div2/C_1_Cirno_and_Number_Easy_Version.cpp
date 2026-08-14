
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t int128;

ll a;
int n, d[3];
ll ans;

void update_ans(int128 val)
{
    int128 diff = (val > a) ? (val - a) : (a - val);
    if (diff < ans)
        ans = (ll)diff;
}

void dfs(int i, bool is_greater, bool is_smaller, int128 current_val, int target_len, const string &ta)
{
    if (is_greater || is_smaller)
    {
        int128 val = current_val;
        int mx = max(d[1], d[2]), mi = min(d[1], d[2]);
        for (int k = i; k < target_len; k++)
        {
            val = val * 10 + (is_greater ? mi : mx);
        }
        update_ans(val);
        return;
    }
    if (i == target_len)
    {
        update_ans(current_val);
        return;
    }

    int w = ta[i] - '0';
    for (int j = 1; j <= n; j++)
    {
        // 首位不能为 0，除非目标长度就是 1
        if (i == 0 && target_len > 1 && d[j] == 0)
            continue;
        dfs(i + 1, is_greater || (d[j] > w), is_smaller || (d[j] < w), current_val * 10 + d[j], target_len, ta);
    }
}

void solve()
{
    cin >> a >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    string ta = to_string(a);
    ans = 9e18;

    // 长度减 1
    if (ta.length() > 1)
    {
        int128 val = 0;
        int mx = max(d[1], d[2]);
        for (int i = 0; i < (int)ta.length() - 1; i++)
            val = val * 10 + mx;
        update_ans(val);
    }

    // 长度相同
    dfs(0, false, false, 0, ta.length(), ta);

    // 长度加 1
    int128 val = 0;
    int mi = min(d[1], d[2]), mx = max(d[1], d[2]);
    // 构造最小值：第一位选最小的非0数，后面全选最小数
    int first = (mi == 0) ? mx : mi;
    val = first;
    for (int i = 0; i < (int)ta.length(); i++)
        val = val * 10 + mi;
    update_ans(val);

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}