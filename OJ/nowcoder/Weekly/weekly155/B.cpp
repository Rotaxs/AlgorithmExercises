#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 105;

int count(int i, int j, int k, int a) {
    int cnt = 0;
    if (i == j && j == k) cnt++;
    if (j == k && i + j == a) cnt++;
    if (i == k && k + j == a) cnt++;
    if (i == j && j + k == a) cnt++;
    return cnt;
}

void solve()
{
    int a; cin >> a;
    ll ans = 0;
    for (int k = 0; k < a + 1; ++k) {
        for (int i = 0; i < a + 1; ++i) {
            for (int j = 0; j < a + 1; ++j) {
                int v; cin >> v;
                ans += v * count(i, j, k, a);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}