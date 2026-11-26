#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + (s[i] == 'A');
        b[i] = b[i - 1] + (s[i] == 'B');
        c[i] = c[i - 1] + (s[i] == 'C');
    }

    int start = 0, end = n + 1;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; ++i) {
        cnt1 += s[i] == 'A';
        cnt2 += s[i] == 'B';
        cnt3 += s[i] == 'C';
        if (cnt1 && cnt2 && cnt3) {
            start = i;
            break;
        }
    }
    cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = n; i >= 1; --i) {
        cnt1 += s[i] == 'A';
        cnt2 += s[i] == 'B';
        cnt3 += s[i] == 'C';
        if (cnt1 && cnt2 && cnt3) {
            end = i;
            break;
        }
    }
    if (start == 0 || end == n + 1 || end - start <= 3) {
        cout << 0 << endl;
        return;
    }
    ++start, --end;

    auto get = [&](const vector<int> &arr, int l, int r) -> int {
        int L = l - 1, R = r + 1;
        while (L + 1 != R) {
            int m = (L + R) / 2;
            if (arr[m] - arr[l - 1] >= 1) R = m;
            else L = m;
        }
        return R;
    };

    ll ans = 0;
    for (int L = start; L <= end; ++L) {
        int r1 = get(a, L, end);
        int r2 = get(b, L, end);
        int r3 = get(c, L, end);
        int R = max({r1, r2, r3});
        ans += end - R + 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}
