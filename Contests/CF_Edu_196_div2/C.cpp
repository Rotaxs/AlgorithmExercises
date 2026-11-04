#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    int xorSum = 0;

    for (int i = 1; i <= n; ++i) {
        xorSum ^= i;
    }

    vector<int> choose(n + 1, 0);
    int h = 0;
    while ((1 << (h + 1)) <= n) {
        ++h;
    }

    for (int j = h + 1; j >= 1; --j) {
        if (!(xorSum & (1 << j))) {
            int x = 1 << (j - 1);
            choose[x] = 1;
            xorSum ^= x;
            xorSum ^= (x << 1);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << choose[i] << ' ';
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
