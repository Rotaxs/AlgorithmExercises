#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

char a[N], b[N], c[N];

void read(char s[], int n)
{
    for (int i = 1; i <= n; i++) cin >> s[i];
}

void swap(int &a, int &b)
{
    int c = b;
    b = a;
    a = c;
}

void solve()
{
    int n; cin >> n;
    read(a, n); read(b, n); read(c, n);
    vector<int> ans(n + 1);
    int preone = 1, sufone = n;

    if (c[1] == '1' || c[n] == '1') { cout << -1 << '\n'; return; }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == '1') preone = max(preone, i);
        if (b[i] == '1') sufone = min(sufone, i);
        if ((a[i] == '1' || b[i] == '1') && c[i] == '1') { cout << -1 << '\n'; return; }
    }
    if (preone > sufone) { cout << -1 << '\n'; return; }

    int l = 1, r = n;
    ans[sufone] = r--;
    for (int i = 1; i < sufone; i++)
        ans[i] = l++;
    // for (int i = 1; i < sufone; i++)
    //     if (c[i] == '1') swap(ans[i], ans[i - 1]);
    for (int i = sufone - 1; i >= 1; i--)
        if (c[i] == '1') swap(ans[i], ans[i - 1]);
    for (int i = sufone + 1; i <= n; i++)
    {
        if (b[i] == '1') ans[i] = r--;
        else ans[i] = l++;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
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