#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    string color[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple"};
    string bright[] = {"Dark", "Bright"};
    string saturation[] = {"Low", "Medium", "High"};
    int a, b, c; cin >> a >> b >> c;
    --a;
    cout << saturation[c] << bright[b] << color[a] << endl;
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
