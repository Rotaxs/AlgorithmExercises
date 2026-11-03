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

    string ans1 = "", ans2 = "";
    int last;

    last = a[0];
    ans1 += 'L';
    for (int l = 1, r = n - 1; l <= r;) {
        if (a[l] >= a[r]) {
            if (a[r] > last) {
                last = a[r];
                --r;
                ans1 += 'R';
            } else if (a[l] > last) {
                last = a[l];
                ++l;
                ans1 += 'L';
            } else {
                break;
            }
        } else {
            if (a[l] > last) {
                last = a[l];
                ++l;
                ans1 += 'L';
            } else if (a[r] > last) {
                last = a[r];
                --r;
                ans1 += 'R';
            } else {
                break;
            }
        }
    }

    last = a[n - 1];
    ans2 += 'R';
    for (int l = 0, r = n - 2; l <= r;) {
        if (a[l] >= a[r]) {
            if (a[r] > last) {
                last = a[r];
                --r;
                ans2 += 'R';
            } else if (a[l] > last) {
                last = a[l];
                ++l;
                ans2 += 'L';
            } else {
                break;
            }
        } else {
            if (a[l] > last) {
                last = a[l];
                ++l;
                ans2 += 'L';
            } else if (a[r] > last) {
                last = a[r];
                --r;
                ans2 += 'R';
            } else {
                break;
            }
        }
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
