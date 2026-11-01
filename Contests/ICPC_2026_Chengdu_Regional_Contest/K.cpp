#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Range {
    ll l, r;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), l(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        cin >> l[i];
    }

    auto check = [&](int d) -> bool {
        ll cl = a[n] - d, cr = a[n] + d;
        for (int i = n - 1; i >= 1; --i) {
            ll pl = a[i] - d, pr = a[i] + d;
            ll gap = l[i + 1];

            ll lm = min(pr, cr - gap);
            ll rm = max(pl, cl + gap);

            if (pl > lm && rm > pr) return false;

            if (pl <= lm && rm <= pr) {
                cl = pl;
                cr = pr;
                continue;
            }

            if (pl <= lm) {
                cl = pl;
                cr = lm;
            } else {
                cl = rm;
                cr = pr;
            }
        }
        return true;

        // stack<Range> ranges;
        // int i = n;
        // for (int i = 1; i <= n; ++i) {
        //     ranges.push({a[i] - d, a[i] + d});
        // }

        // queue<Range> q;
        // q.push(ranges.top());
        // ranges.pop();

        // while (!ranges.empty()) {
        //     int size = q.size();
        //     auto [pl, pr] = ranges.top();
        //     ranges.pop();
        //     ll gap = l[i];
        //     --i;
        //     while (size--) {
        //         auto [cl, cr] = q.front();
        //         q.pop();
        //         if (pl <= min(pr, cr - gap)) q.push({pl, min(pr, cr - gap)});
        //         if (max(pl, gap + cl) <= pr) q.push({max(pl, gap + cl), pr});
        //     }
        //     if (q.empty()) return false;
        // }

        // return true;
    };

    int L = -1, R = 1e9 + 1;
    while (L + 1 != R) {
        int m = L + ((R - L) >> 1);
        if (check(m)) {
            R = m;
        } else {
            L = m;
        }
    }

    cout << R << endl;
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
