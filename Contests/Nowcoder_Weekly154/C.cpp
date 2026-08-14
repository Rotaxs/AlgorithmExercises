#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt_U = 0, cnt_D = 0, cnt_L = 0, cnt_R = 0;
    for (char ch : s) {
        if (ch == 'U') cnt_U++;
        if (ch == 'D') cnt_D++;
        if (ch == 'L') cnt_L++;
        if (ch == 'R') cnt_R++;
    }
    int cnt = 0;
    char chx = 'R', chy = 'U';
    if (cnt_L > cnt_R) chx = 'L';
    if (cnt_D > cnt_U) chy = 'D';
    for (int i = 0; i < max(cnt_D, cnt_U) && cnt < n - k; i++, cnt++) {
        cout << chy;
    }
    for (int i = 0; i < max(cnt_L, cnt_R) && cnt < n - k; i++, cnt++) {
        cout << chx;
    }
    if (cnt >= n - k) return;
    chx = (chx == 'R' ? 'L' : 'R');
    chy = (chy == 'U' ? 'D' : 'U');
    for (int i = 0; i < min(cnt_D, cnt_U) && cnt < n - k; i++, cnt++) {
        cout << chy;
    }
    for (int i = 0; i < min(cnt_L, cnt_R) && cnt < n - k; i++, cnt++) {
        cout << chx;
    }
    
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