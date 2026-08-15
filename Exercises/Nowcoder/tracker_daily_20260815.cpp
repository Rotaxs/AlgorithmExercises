#include <bits/stdc++.h>
#define endl '\n'
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x)  << " (Line " << __LINE__ << ")" << endl
#else
#define debug(x)
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pos = pair<int, int>;
using info = pair<int, bool>;

const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

// void solve()
// {
//     int n; cin >> n;
//     map<pos, info> mp;
//     for (int i = 0; i < n; ++i) {
//         int x, y; cin >> x >> y;
//         mp[{x, y}].second = true;
//         for (int dir = 0; dir < 8; ++dir) {
//             int nex = x + dx[dir];
//             int ney = y + dy[dir];
//             if (nex < 1 || ney < 1) continue;
//             if (mp.count({nex, ney})) {
//                 ++mp[{nex, ney}].first;
//             } else {
//                 mp[{nex, ney}].first = 1;
//                 mp[{nex, ney}].second = false;
//             }
//         }
//     }
//     int ansx, ansy, maxCnt = 0;
//     for (auto [p, i] : mp) {
//         if (i.second) continue;
//         if (i.first > maxCnt) {
//             ansx = p.first;
//             ansy = p.second;
//             maxCnt = i.first;
//         }
//     }
//     cout << ansx << ' ' << ansy << endl;
// }

void solve()
{
    int n; cin >> n;
    vector<pos> pawns(n);
    // unordered_map<pos, int> vis;
    for (int i = 0; i < n; ++i) {
        cin >> pawns[i].first >> pawns[i].second;
    }
    sort(pawns.begin(), pawns.end());

    vector<pos> cand;
    cand.reserve(8 * n);
    for (int i = 0; i < n; ++i) {
        int x = pawns[i].first;
        int y = pawns[i].second;
        for (int dir = 0; dir < 8; ++dir) {
            int nex = x + dx[dir];
            int ney = y + dy[dir];
            if (nex >= 1 && ney >= 1)
                cand.push_back({nex, ney});
        }
    }

    sort(cand.begin(), cand.end());

    int ansx, ansy, maxCnt = -1;
    int sz = cand.size();
    for (int i = 0; i < sz; ) {
        int j = i;
        while (j < sz && cand[j] == cand[i]) {
            j++;
        }
        int cnt = j - i;
        if (!binary_search(pawns.begin(), pawns.end(), cand[i])) {
            if (cnt > maxCnt) {
                maxCnt = cnt;
                ansx = cand[i].first;
                ansy = cand[i].second;
            }
        }
        i = j;
    }

    if (maxCnt == -1) {
        ansx = 1; ansy = 1;
        while (binary_search(pawns.begin(), pawns.end(), make_pair(ansx, ansy))) {
            ansx++;
        }
    }

    cout << ansx << ' ' << ansy << endl;
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