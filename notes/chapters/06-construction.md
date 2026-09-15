# 构造

[**2025 ICPC Chongqing Province Contest C 区域划分**](https://codeforces.com/gym/105887/attachments)

**题意**：将 $n\times n$ 网格分成 $n$ 个区域，使相邻区域异色且所需颜色数最大。

- **时间复杂度**：$O(n^2)$，与输出规模同阶
- **空间复杂度**：$O(n)$
- **构造**：首行左右交替取数，使相邻差覆盖 $1\sim n-1$；其余各行对首行循环平移

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int step = n - 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i & 1)
            a[i] = a[i - 1] - step;
        else
            a[i] = a[i - 1] + step;
        step--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int res = a[j] + i - 1;
            if (res <= n)
                cout << res << ' ';
            else
                cout << res % n << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
```


