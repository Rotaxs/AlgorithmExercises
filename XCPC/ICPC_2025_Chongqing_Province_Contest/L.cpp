#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MOD = 998244353;
const int N = 2e5;
int st[N * 3];

void solve()
{
    int n; cin >> n;
    int sum = 0, temp = n;
    int l = 0, r = 0;
    while (temp--)
    {
        string s; cin >> s;
        if (s == "Push")
        {
            int num; cin >> num;
            st[r++] = num;
            sum = (sum + num) % MOD;
        }
        else if (s == "Pop")
        {
            int top = st[--r];
            sum = (sum - top + MOD) % MOD;
        }
        else if (s == "Repeat")
        {
            int R = r;
            if ((r - l) <= n)
                for (int i = l; i < R; i++)
                    st[r++] = st[i];
            sum = sum * 2 % MOD;
        }
        cout << sum << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}