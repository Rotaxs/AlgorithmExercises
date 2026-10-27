#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 2e8;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0, maxn = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        maxn = max(maxn, a[i]);
    }

    vector<int> val;
    for (int p = 1; 1ll * p * p <= sum; ++p) {
        if (sum % p == 0) {
            if (1ll * p * p == sum) {
                if (p >= maxn) val.push_back(p);
                continue;
            }
            if (p >= maxn) val.push_back(p);
            if (sum / p >= maxn) val.push_back(sum / p);
        }
    }

    auto check = [&](int x) -> bool {
        int cnt = 0;
        for (int i = 0, j; i < n; i = j) {
            int v = a[i];
            j = i + 1;
            while (j < n && v < x) {
                v += a[j];
                ++cnt;
                if (v > x) {
                    return false;
                }
                ++j;
            }
        }
        return true;
    };

    int len = val.size();
    int ans = inf;
    for (int i = 0; i < len; ++i) {
        if (check(val[i])) {
            ans = min(ans, n - sum / val[i]);
        }
    }

    cout << (ans == inf ? n - 1 : ans) << endl;
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
