#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> a(n), b(m + 2);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin() + 1, b.begin() + 1 + m);

    b[0] = 0;
    b[m + 1] = w + 1;

    vector<int> ans;

    auto cover = [&](int l, int r) -> bool {
        int al = lower_bound(a.begin(), a.end(), l) - a.begin();
        int ar = upper_bound(a.begin(), a.end(), r) - a.begin() - 1;

        if (al > ar) return true;

        int start = ans.size();

        int p = al;
        while (p <= ar) {
            int x = a[p];
            ans.push_back(x);
            while (p <= ar && a[p] <= x + k - 1) {
                ++p;
            }
        }

        ans.back() = min(ans.back(), r - k + 1);
        for (int i = (int)ans.size() - 2; i >= start; --i) {
            ans[i] = min(ans[i], ans[i + 1] - k);
        }

        return ans[start] >= l;
    };

    for (int i = 0; i <= m; ++i) {
        int L = b[i] + 1;
        int R = b[i + 1] - 1;
        if (!cover(L, R)) {
            cout << -1 << endl;
            return;
        }
    }

    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}
