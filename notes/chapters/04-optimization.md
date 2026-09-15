# 优化技巧

## 离散化处理

- **时间复杂度**：预处理 $O(n\log n)$，单次映射 $O(\log n)$
- **空间复杂度**：$O(n)$
- **适用**：值域大但元素少，且只关心大小关系时，将排序去重后的下标作为新值

```cpp
sort(nums.begin(), nums.end());
nums.erase(unique(nums.begin(), nums.end()), nums.end());
auto get_id = [&](int n) { return lower_bound(nums.begin(), nums.end(), n) - nums.begin() + 1; };
```

## 单峰函数二分

**CF Round 1010 C2 Seating Arrangement**

- **时间复杂度**：$O(n\log n)$
- **空间复杂度**：$O(n)$，用于存储输入序列
- **要点**：令前 $i$ 个 `A` 按 `I` 处理，`check(i)` 关于 $i$ 单峰；比较 `check(m)` 与 `check(m + 1)` 确定峰值方向

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int n, s, x;
string u;

int check(int i) {
    int ans = 0;
    int rem = x;
    ll seats = 0;
    int a = 0;
    for (char c : u) {
        if (c == 'I') {
            if (rem > 0) {
                ans++;
                rem--;
                seats += s - 1;
            }
        } else if (c == 'A') {
            a++;
            if (a <= i) {
                if (rem > 0) {
                    ans++;
                    rem--;
                    seats += s - 1;
                }
            } else {
                if (seats > 0) {
                    seats--;
                    ans++;
                }
            }
        } else if (c == 'E') {
            if (seats > 0) {
                seats--;
                ans++;
            }
        }
    }
    return ans;
}

void solve() {
    cin >> n >> x >> s;
    cin >> u;
    int ans = 0;
    int cnt_A = 0;
    for (char c : u)
        if (c == 'A') cnt_A++;
    int l = -1, r = cnt_A + 1;
    while ((l + 1) != r) {
        int m = l + ((r - l) >> 1);
        if (check(m) >= check(m + 1))
            r = m;
        else
            l = m;
    }
    cout << check(r) << '\n';
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
