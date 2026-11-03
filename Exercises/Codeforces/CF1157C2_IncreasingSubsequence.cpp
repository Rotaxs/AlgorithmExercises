#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> behind(n, 1), before(n, 1);
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            before[i] = before[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1]) {
            behind[i] = behind[i + 1] + 1;
        }
    }

    string ans1 = "", ans2 = "";
    int last, l, r;

    auto apply = [&](int& p, string& s, char dir) {
        last = a[p];
        if (dir == 'L') {
            ++p;
        } else if (dir == 'R') {
            --p;
        }
        s += dir;
    };

    last = a[0];
    ans1 += 'L';
    l = 1, r = n - 1;
    while (l < r) {
        if (a[l] == a[r] && a[l] > last) {
            if (behind[l] >= before[r]) {
                apply(l, ans1, 'L');
            } else {
                apply(r, ans1, 'R');
            }
        } else if (a[l] > a[r]) {
            if (a[r] > last) {
                apply(r, ans1, 'R');
            } else if (a[l] > last) {
                apply(l, ans1, 'L');
            } else {
                break;
            }
        } else {
            if (a[l] > last) {
                apply(l, ans1, 'L');
            } else if (a[r] > last) {
                apply(r, ans1, 'R');
            } else {
                break;
            }
        }
    }
    if (l == r && a[l] > last) {
        apply(l, ans1, 'L');
    }

    last = a[n - 1];
    ans2 += 'R';
    l = 0, r = n - 2;
    while (l < r) {
        if (a[l] == a[r] && a[l] > last) {
            if (behind[l] >= before[r]) {
                apply(l, ans2, 'L');
            } else {
                apply(r, ans2, 'R');
            }
        } else if (a[l] > a[r]) {
            if (a[r] > last) {
                apply(r, ans2, 'R');
            } else if (a[l] > last) {
                apply(l, ans2, 'L');
            } else {
                break;
            }
        } else {
            if (a[l] > last) {
                apply(l, ans2, 'L');
            } else if (a[r] > last) {
                apply(r, ans2, 'R');
            } else {
                break;
            }
        }
    }
    if (l == r && a[l] > last) {
        apply(l, ans2, 'L');
    }

    if (ans1.size() > ans2.size()) {
        cout << ans1.size() << endl;
        cout << ans1 << endl;
    } else {
        cout << ans2.size() << endl;
        cout << ans2 << endl;
    }
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
