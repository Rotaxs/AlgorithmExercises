# 杂板

## 无重复元素的子数组/子串

- **时间复杂度**：$O(n)$ 期望时间
- **空间复杂度**：$O(\min(n, |\Sigma|))$
- **不变量**：窗口 $[l,r]$ 内无重复元素；用 `lastSeen` 将左端点跳到重复元素上次位置之后

```cpp
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_map<int, int> lastSeen;
    int ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
        if (lastSeen.count(s[r])) {
            l = max(l, lastSeen[s[r]] + 1);
        }
        lastSeen[s[r]] = r;
        ans = max(ans, r - l + 1);
    }
    return ans;
}
```

字符集较小时用数组代替哈希表，时间 $O(n)$，空间 $O(|\Sigma|)$。

```cpp
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    vector<int> lastSeen(128, -1); // 128 改成数据最大值 + 1
    int ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
        if (lastSeen[s[r]] != -1) {
            l = max(l, lastSeen[s[r]] + 1);
        }
        lastSeen[s[r]] = r;
        ans = max(ans, r - l + 1);
    }
    return ans;
}
```

## 置换环判断逆序数奇偶性

- **时间复杂度**：$O(n)$
- **空间复杂度**：$O(n)$

**置换环**：对一个**排列**，建立 $i \to a[i]$ 的边，会得到若干个环，这若干个环就是置换环
- 交换排列中的两个元素，环的数量变化 1
- 把环数从 $c$ 增加到 $n$（有序序列），至少需要 $n - c$ 次交换，且 $n - c$ 次交换一定能做到

因此，交换序列中的两个数，逆序对数增加 1，置换环数**变化** 1，从而有 $I \equiv n - c \pmod 2$

```cpp
int getParityOfInversion(const vector<int>& a) {
    int n = (int)a.size() - 1;
    vector<bool> vis(n + 1, false);

    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (vis[u]) continue;
        ++cnt;
        int v = u;
        while (!vis[v]) {
            vis[v] = true;
            v = a[v];
        }
    }
    return (n - cnt) & 1;
}
```

需要注意的是，当原序列不是一个排列时，需要通过离散化等方式将序列先转化为一个排列再使用置换环求解

```cpp
int getParityOfInversion(const vector<int>& a) {
    int n = a.size() - 1;

    vector<int> id(n);
    iota(id.begin(), id.end(), 1);

    sort(id.begin(), id.end(), [&](int i, int j) {
        if (a[i] != a[j]) return a[i] < a[j];
        return i < j;
    });

    // 稳定离散化
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) {
        p[id[i]] = i + 1;
    }

    // 计算置换环数量
    vector<bool> vis(n + 1, false);
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;

        ++cnt;
        int u = i;

        while (!vis[u]) {
            vis[u] = true;
            u = p[u];
        }
    }

    return (n - cnt) & 1;
}
```