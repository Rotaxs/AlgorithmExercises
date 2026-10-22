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

## 树形 DP 转非递归

树形 DP 往往需要通过子节点的信息推出父节点的信息，比如求每个节点的的子树的大小

```cpp
void dfs(int u, int fa) {
    sz[u] = 1;

    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
```

也就是说，如果按照先处理子节点的信息再处理父节点的顺序，也能够实现递推

通过一个 `order` 数组存放节点的顺序

```cpp
vector<int> fa(n + 1, -1);
vector<int> order;
// 以 1 节点为根
fa[1] = 0;
order.push_back(1);

for (int i = 0; i < (int)order.size(); ++i) {
    int u = order[i];
    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (v == fa[u]) continue;
        fa[v] = u;
        order.push_back(v);
    }
}
```

然后倒序处理 `order` 即可

```cpp
vector<int> sz(n + 1, 1);

for (int i = n - 1; i >= 0; --i) {
    int u = order[i];
    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (v == fa[u]) continue;
        sz[u] += sz[v];
    }
}
```
