#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 10;
int cnt[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (cnt[a[i]] == 0) pos.push_back(a[i]);
        cnt[a[i]]++;
    }

    int lst = -1e9;
    for (int i = n; i >= 1; i--)
    {
        if (cnt[i] == 0) continue;

        bool win;
        if (lst != -1e9 && lst - i <= k) win = true;
        else win = (cnt[i] % 2 == 0);

        if (win)
        {
            for (int x : pos) cnt[x] = 0;
            cout << "YES\n";
            return;
        }

        lst = i;
    }

    cout << "NO\n";
    for (int x : pos) cnt[x] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}
