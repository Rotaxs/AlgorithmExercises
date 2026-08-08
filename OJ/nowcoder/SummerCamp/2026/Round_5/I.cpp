#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int inf = 0x3f3f3f3f;

// int getFirstOne(const string &s) {
//     for (int i = 1; i < s.size(); ++i) {
//         if (s[i] == '1') return i;
//     }
//     return -1;
// }

// int getSecondOne(const string &s) {
//     int i = getFirstOne(s);
//     if (i == -1) return -1;
//     ++i;
//     for (; i < s.size(); ++i) {
//         if (s[i] == '1') return i;
//     }
//     return -1;
// }

// void solve()
// {
//     int n; cin >> n;
//     string s; cin >> s; s = " " + s;
//     int len = 1 << n;
//     vector<int> ans(len, 0);
//     int x, y;
//     while (((y = getFirstOne(s)) != -1) && ((x = getSecondOne(s)) != -1)) {
//         s[x] = s[x] == '0' ? '1' : '0';
//         s[y] = s[y] == '0' ? '1' : '0';
//         int z = x ^ y;
//         s[z] = s[z] == '0' ? '1' : '0';
//         ans[x] = y;
//     }
//     for (int i = 1; i < len; ++i) {
//         cout << ans[i] << ' ';
//     }
//     cout << endl;
// }

void solve()
{
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    int len = 1 << n;
    vector<int> ans(len, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < len; ++i) {
        if (s[i] == '1') pq.push(i);
    }

    int x, y;
    while (true) {
        while (!pq.empty() && s[y = pq.top()] != '1') pq.pop();
        if (pq.empty()) break;
        pq.pop(); s[y] = '0';
        while (!pq.empty() && s[x = pq.top()] != '1') pq.pop();
        if (pq.empty()) break;
        pq.pop(); s[x] = '0';
        int z = x ^ y;
        if (s[z] == '0') {
            s[z] = '1';
            pq.push(z);
        } else {
            s[z] = '0';
        }
        ans[x] = y;
    }

    for (int i = 1; i < len; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}