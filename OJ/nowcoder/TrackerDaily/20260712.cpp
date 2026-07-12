#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    if (n == 4 || n == 8)
    {
        cout << "YES\n";
        return;
    }
    int cnt[10] = {0};
    while (n)
    {
        cnt[n % 10]++;
        n /= 10;
    }
    for (int i = 12; i <= 96; i += 4)
    {
        int a = i / 10, b = i % 10;
        bool found = false;
        if (a == b)
        {
            if (cnt[a] >= 2) found = true;
        }
        else if (cnt[a] >= 1 && cnt[b] >= 1)
            found = true;
        if (found) 
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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