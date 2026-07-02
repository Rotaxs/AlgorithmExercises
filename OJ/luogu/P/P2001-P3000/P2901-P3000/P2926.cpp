#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000010;
int cnt[N];
int ans[N];
int a[N];

void solve()
{
    int n;
    cin >> n;
    int maxa = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        maxa = max(maxa, a[i]);
    }
    // 一次枚举所有约数，实际上是枚举每个数的倍数
    for (int i = 1; i <= maxa; i++)
    {
        if (cnt[i] == 0) continue;
        // i 的倍数都能被 i 整除
        for (int j = i; j <= maxa; j += i)
        {
            ans[j] += cnt[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (ans[a[i]] - 1) << '\n';
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