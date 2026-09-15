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
