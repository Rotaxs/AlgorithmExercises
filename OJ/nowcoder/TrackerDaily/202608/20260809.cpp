#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

vector<int> getFactors(int x) {
    vector<int> ret;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ret.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ret.push_back(x);
    return ret;
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> L(n + 1, 0), R(n + 1, inf);
    unordered_map<int, int> lastPos;

    for (int i = 1; i <= n; ++i) {
        vector<int> primes = getFactors(a[i]);
        for (int p : primes) {
            if (lastPos.count(p)) {
                L[i] = max(L[i], lastPos[p]);
            }
            lastPos[p] = i;
        }
    }
    lastPos.clear();
    for (int i = n; i >= 1; --i) {
        vector<int> primes = getFactors(a[i]);
        for (int p : primes) {
            if (lastPos.count(p)) {
                R[i] = min(R[i], lastPos[p]);
            }
            lastPos[p] = i;
        }
    }

    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        int minL = inf;
        for (int j = i; j >= 1; --j) {
            if (R[j] > i) {
                minL = min(minL, L[j]);
            }
            if (j <= i - 1 && j <= minL) {
                if (dp[j - 1] != -1) {
                    dp[i] = max(dp[i], dp[j - 1] + 1);
                }
            }
        }
    }
    cout << dp[n] << endl;
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