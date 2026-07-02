#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

void solve()
{
    cin >> n;
    vector<int> h(n + 1);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    stack<int> st;
    
    for (int i = n; i >= 1; i--)
    {
        while (st.size() && h[st.top()] <= h[i]) st.pop();
        if (st.size()) ans[i] = st.top();
        else ans[i] = 0;
        st.push(i);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
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