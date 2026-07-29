#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> cells;
    cells.reserve(n * m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int val; cin >> val;
            cells.emplace_back(val, i, j);
        }
    }
    sort(cells.begin(), cells.end());

    vector<int> diff((n + 2) * (m + 2), 0);
    auto at = [&](int r, int c) -> int& {
        return diff[r * (m + 2) + c];
    };
    auto add = [&](int r1, int c1, int r2, int c2) {
        ++at(r1, c1);
        --at(r1, c2 + 1);
        --at(r2 + 1, c1);
        ++at(r2 + 1, c2 + 1);
    };

    for (int start = 0; start < n * m; ) {
        int finish = start;
        while (finish < n * m && get<0>(cells[finish]) == get<0>(cells[start])) {
            ++finish;
        }

        vector<int> rows, rowMin, rowMax;
        for (int i = start; i < finish; ) {
            int row = get<1>(cells[i]);
            int mn = m + 1, mx = 0;
            while (i < finish && get<1>(cells[i]) == row) {
                int col = get<2>(cells[i]);
                mn = min(mn, col);
                mx = max(mx, col);
                i++;
            }
            rows.push_back(row);
            rowMin.push_back(mn);
            rowMax.push_back(mx);
        }

        int rowCnt = rows.size();
        vector<int> preMin(rowCnt), sufMax(rowCnt);
        for (int i = 0; i < rowCnt; ++i) {
            preMin[i] = rowMin[i];
            if (i > 0) {
                preMin[i] = min(preMin[i], preMin[i - 1]);
            }
        }
        for (int i = rowCnt - 1; i >= 0; --i) {
            sufMax[i] = rowMax[i];
            if (i < rowCnt - 1) {
                sufMax[i] = max(sufMax[i], sufMax[i + 1]);
            }
        }

        for (int i = 0; i + 1 < rowCnt; ++i) {
            if (preMin[i] < sufMax[i + 1]) {
                add(rows[i], preMin[i], rows[i + 1], sufMax[i + 1]);
            }
        }

        start = finish;
    }

    for (int i = 1; i <= n; ++i) {
        string rowAns(m, '0');
        for (int j = 1; j <= m; ++j) {
            at(i, j) += at(i - 1, j) + at(i, j - 1) - at(i - 1, j - 1);
            if (at(i, j) > 0) {
                rowAns[j - 1] = '1';
            }
        }
        cout << rowAns << endl;
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