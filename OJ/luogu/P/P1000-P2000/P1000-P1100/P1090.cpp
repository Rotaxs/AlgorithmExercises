#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<int, vector<int>, greater<int>> pq;

void solve()
{
    int n;
    cin >> n;
    int a;
    while (n--) { cin >> a; pq.push(a); }
    ll ans = 0;
    while (pq.size() != 1)
    {
        int a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        pq.push(a + b);
        ans += a + b;
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