# 数据结构

## 堆

### 对顶堆

- **时间复杂度**：查询第 $k$ 大为 $O(1)$，插入、删除和调整 $k$ 为 $O(\log n)$
- **空间复杂度**：$O(n)$
- **不变量**：小根堆保存前 $k$ 大元素，其堆顶即第 $k$ 大；其余元素放入大根堆

#### 动态维护第 $k$ 大/小

第 $k$ 小的做法对称：使用大根堆保存前 $k$ 小元素。

- **时间复杂度**：查询 $O(1)$，插入与调整 $O(\log n)$
- **空间复杂度**：$O(n)$

```cpp
priority_queue<int> pqd;                            // 大根堆
priority_queue<int, vector<int>, greater<int>> pqx; // 小根堆

for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (pqx.empty() || pqx.top() <= x)
        pqx.push(x); // 插入
    else
        pqd.push(x);
    // 多的移到大根堆
    while (pqx.size() > k)
        pqd.push(pqx.top()), pqx.pop();
    // 不够从大根堆补，要求大根堆非空
    while (pqx.size() < k && !pqd.empty())
        pqx.push(pqd.top()), pqd.pop();
}
```

#### 动态维护第 $k$ 大/小（含删除操作）

##### `multiset` 实现

- **时间复杂度**：查询 $O(1)$，插入与调整 $O(\log n)$
- **空间复杂度**：$O(n)$
- **要点**：用 `multiset` 代替 `priority_queue`，通过迭代器实现删除

```cpp
struct DualMultiset {
    int k;
    multiset<ll> small;
    multiset<ll> big; // TopK
    ll sum_big = 0;

    DualMultiset(int k) : k(k) {
    }
    void balance() {
        while ((int)big.size() < k && !small.empty()) {
            auto it = prev(small.end()); // *prev(small.end()) 取到 small 中的最大值
            ll x = *it;
            small.erase(it);
            big.insert(x);
            sum_big += x;
        }
        while ((int)big.size() > k) {
            auto it = big.begin(); // *big.begin() 取到 big 中的最小值
            ll x = *it;
            big.erase(it);
            sum_big -= x;
            small.insert(x);
        }
    }
    void insert(ll x) {
        if (big.empty() || x > *big.begin()) {
            big.insert(x);
            sum_big += x;
        } else {
            small.insert(x);
        }
        balance();
    }
    bool erase(ll x) {
        auto it = big.find(x);
        if (it != big.end()) {
            sum_big -= x;
            big.erase(it);
            balance();
            return true;
        }
        it = small.find(x);
        if (it != small.end()) {
            small.erase(it);
            balance();
            return true;
        }
        return false;
    }
};
```

##### `priority_queue` + 懒标记

- **时间复杂度**：查询 $O(1)$，删除/插入/平衡 $O(\log n)$
- **空间复杂度**：$O(n)$
- **要点**：`bigDel` 和 `smallDel` 维护要删除的元素，当 `big` 或 `small` 的堆顶恰好是 `Del` 的堆顶时，说明这个元素应当跳过（删除）

```cpp
struct DualHeap {
    int k;
    priority_queue<ll> big, bigDel;
    priority_queue<ll, vector<ll>, greater<ll>> small, smallDel; // TopK
    ll bigSum = 0, smallSum = 0;
    int bigSize = 0, smallSize = 0;

    DualHeap(int k) : k(k) {
    }
    int size() {
        return bigSize + smallSize;
    }
    bool empty() {
        return size() == 0;
    }
    void pruneBig() { // 清理大根堆中已经被删除的元素
        while (!big.empty() && !bigDel.empty() && big.top() == bigDel.top()) {
            big.pop();
            bigDel.pop();
        }
    }
    void pruneSmall() { // 清理小根堆中已经被删除的元素
        while (!small.empty() && !smallDel.empty() && small.top() == smallDel.top()) {
            small.pop();
            smallDel.pop();
        }
    }
    void balance() {
        int K = min(k, size());
        while (smallSize > K) {
            pruneSmall();
            ll x = small.top();
            small.pop();
            --smallSize;
            smallSum -= x;
            big.push(x);
            ++bigSize;
            bigSum += x;
        }
        while (smallSize < K) {
            pruneBig();
            ll x = big.top();
            big.pop();
            --bigSize;
            bigSum -= x;
            small.push(x);
            ++smallSize;
            smallSum += x;
        }
    }
    void insert(ll x) {
        pruneSmall();
        if (smallSize < k || (smallSize > 0 && x > small.top())) {
            small.push(x);
            ++smallSize;
            smallSum += x;
        } else {
            big.push(x);
            ++bigSize;
            bigSum += x;
        }
        balance();
    }
    void erase(ll x) {
        pruneSmall(); // 因为下面要用到 small 的下一个 top，所以只需处理 small
        if (smallSize > 0 && x >= small.top()) { // 判断 x 在 small
            smallDel.push(x);
            --smallSize;
            smallSum -= x;
        } else {
            bigDel.push(x);
            --bigSize;
            bigSum -= x;
        }
        balance();
    }
    ll sumK() {
        return smallSum;
    }
    ll kthLargest() {
        assert(k > 0 && size() >= k);
        pruneSmall();
        return small.top();
    }
};
```

> [!warning]
> 使用 `erase` 需要保证 `x` 存在

#### 动态维护中位数与绝对距离和（含删除）

- **时间复杂度**：查询中位数和距离和 $O(1)$，插入、删除 $O(\log n)$
- **空间复杂度**：$O(n)$
- **要点**
  - 将较小的一半放在 `big`，较大的一半放在 `small`，并始终保持 `big.size() == (size() + 1) / 2`，因此奇数个元素时，`L` 的最大值就是中位数
  - 求所有数到中位数的距离的和：`mid * bigSize - bigSum + smallSum - mid * smallSize;`

```cpp
struct DualHeap {
    priority_queue<ll> big, bigDel;                              // 较小的一半，大根堆
    priority_queue<ll, vector<ll>, greater<ll>> small, smallDel; // 较大的一半，小根堆
    ll bigSum = 0, smallSum = 0;
    int bigSize = 0, smallSize = 0;

    int size() {
        return bigSize + smallSize;
    }
    bool empty() {
        return size() == 0;
    }
    void pruneBig() {
        while (!big.empty() && !bigDel.empty() && big.top() == bigDel.top()) {
            big.pop();
            bigDel.pop();
        }
    }
    void pruneSmall() {
        while (!small.empty() && !smallDel.empty() && small.top() == smallDel.top()) {
            small.pop();
            smallDel.pop();
        }
    }
    void balance() {
        int need = (size() + 1) / 2;
        while (bigSize > need) {
            pruneBig();
            ll x = big.top();
            big.pop();
            --bigSize;
            bigSum -= x;
            small.push(x);
            ++smallSize;
            smallSum += x;
        }
        while (bigSize < need) {
            pruneSmall();
            ll x = small.top();
            small.pop();
            --smallSize;
            smallSum -= x;
            big.push(x);
            ++bigSize;
            bigSum += x;
        }
    }
    void insert(ll x) {
        pruneBig();
        if (bigSize == 0 || x <= big.top()) {
            big.push(x);
            ++bigSize;
            bigSum += x;
        } else {
            small.push(x);
            ++smallSize;
            smallSum += x;
        }
        balance();
    }
    void erase(ll x) {
        pruneBig();
        if (bigSize > 0 && x <= big.top()) {
            bigDel.push(x);
            --bigSize;
            bigSum -= x;
        } else {
            smallDel.push(x);
            --smallSize;
            smallSum -= x;
        }

        balance();
    }
    ll median() {
        pruneBig();
        return big.top();
    }
    ll absSum() {
        if (empty()) return 0;
        ll mid = median();
        return mid * bigSize - bigSum + smallSum - mid * smallSize;
    }
};
```

## 并查集

- **时间复杂度**：路径压缩与按秩合并后，单次查询/合并均摊 $O(\alpha(n))$
- **空间复杂度**：$O(n)$

```cpp
const int N = 1e5;
int fa[N], ranks[N];

void init(int n) {
    for (int i = 1; i <= n; i++)
        fa[i] = i, ranks[i] = 1;
}

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    int rootx = find(x), rooty = find(y);
    if (rootx == rooty) return;
    // 确保 rootx 的秩更大
    if (ranks[rootx] < ranks[rooty]) swap(rootx, rooty);
    fa[rooty] = rootx; // 矮树并入大树
    if (ranks[rootx] == ranks[rooty]) ranks[rootx]++;
}
```

也可令根节点的 `fa` 存储集合大小的负值，省去 `ranks`。

### 节点不是连续整数

- **时间复杂度**：哈希映射期望 $O(1)$，最坏 $O(n)$
- **空间复杂度**：$O(n)$

将字符串等非连续节点映射到连续整数 ID。

```cpp
const int N = 1e5 + 10;
unordered_map<string, int> string_to_id;
string id_to_string[N];
int cnt = 0;

int get_id(string s) {
    if (string_to_id.find(s) == string_to_id.end()) {
        string_to_id[s] = cnt;
        fa[cnt] = cnt;
        id_to_string[cnt] = s;
        cnt++;
    }
    return string_to_id[s];
}
```

### 扩展域并查集

[CF776D The Door Problem](https://codeforces.com/contest/776/problem/D)

- **时间复杂度**：$O((n+m)\alpha(m))$
- **空间复杂度**：$O(n+m)$
- **建模**：$i$ 与 $i+m$ 分别表示开关 $i$ 的两种状态；相同约束合并同侧，相反约束交叉合并
- **矛盾**：若 `find(i) == find(i + m)`，则无解

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e5 + 10;

int fa[M << 1];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    fa[ry] = rx;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n + 1);
    vector<pair<int, int>> e(n + 1, {-1, -1});
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    // 题目给的是每个开关对应的门，这里用 e 存每个门对应的开关（2个）
    for (int i = 1; i <= m; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++) {
            int d;
            cin >> d;
            if (e[d].first == -1)
                e[d].first = i;
            else
                e[d].second = i;
        }
    }
    for (int i = 1; i <= 2 * m; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++) {
        int x = e[i].first, y = e[i].second;
        // 要求开关状态相同
        if (r[i] == 1) {
            unite(x, y);
            unite(x + m, y + m);
        } else // 开关状态不同
        {
            unite(x, y + m);
            unite(y, x + m);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (find(i) == find(i + m)) // 矛盾
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
```



## 树状数组

### 单点修改 + 区间查询

- **时间复杂度**：单次修改/查询 $O(\log n)$，建树 $O(n\log n)$
- **空间复杂度**：$O(n)$

```cpp
int tree[N], n;

inline int lowbit(int x) {
    return x & -x;
}

// 修改原数组 a[i] 位置的值为 a[i] + v
void update(int i, int v) {
    while (i <= n) {
        tree[i] += v;
        i += lowbit(i);
    }
}

// 返回 1 ~ i 范围的累加和
int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}
```

### 区间修改 + 单点查询

- **时间复杂度**：单次修改/查询 $O(\log n)$
- **空间复杂度**：$O(n)$
- **要点**：维护差分数组；区间 $[l,r]$ 加 $v$ 转为 `update(l, v)` 与 `update(r + 1, -v)`

```cpp
int tree[N], n;

inline int lowbit(int x) {
    return x & -x;
}

void update(int i, int v) {
    while (i <= n) {
        tree[i] += v;
        i += lowbit(i);
    }
}

// 查询原数组索引为 i 位置的值
int query(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}
```

### 区间修改 + 区间查询

维护差分数组 $d_i$ 的两个树状数组。由于
$\sum_{i=1}^{x}a_i=(x+1)\sum_{i=1}^{x}d_i-\sum_{i=1}^{x}i d_i$，
可以同时支持区间加与区间求和。

- **时间复杂度**：单次修改/查询 $O(\log n)$
- **空间复杂度**：$O(n)$

```cpp
struct BIT {
    int n;
    vector<ll> t1, t2;

    explicit BIT(int n) : n(n), t1(n + 1), t2(n + 1) {}

    static int lowbit(int x) {
        return x & -x;
    }

    void addTree(vector<ll>& tree, int x, ll v) {
        while (x <= n) {
            tree[x] += v;
            x += lowbit(x);
        }
    }

    // 原数组 [l, r] 同时加 v
    void add(int l, int r, ll v) {
        addTree(t1, l, v);
        addTree(t2, l, 1LL * l * v);
        if (r + 1 <= n) {
            addTree(t1, r + 1, -v);
            addTree(t2, r + 1, -1LL * (r + 1) * v);
        }
    }

    void add(int x, ll v) {
        add(x, x, v);
    }

    ll sumTree(const vector<ll>& tree, int x) const {
        ll ans = 0;
        while (x > 0) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }

    // 原数组 [1, x] 的前缀和
    ll query(int x) const {
        return 1LL * (x + 1) * sumTree(t1, x) - sumTree(t2, x);
    }

    ll query(int l, int r) const {
        return query(r) - query(l - 1);
    }
};
```

## 线段树

### 维护区间和

#### 区间 add

- **时间复杂度**：建树 $O(n)$，区间修改/查询 $O(\log n)$
- **空间复杂度**：$O(n)$
- **要点**：`sum[p]` 存节点区间和，`addVal[p]` 存尚未下传的整段增量

```cpp
struct SegTree {
    int n;
    vector<int> arr;
    vector<ll> sum, addVal;
    SegTree(int n) : n(n), arr(n + 1, 0), sum((n + 1) << 2, 0), addVal((n + 1) << 2, 0) {
    }
    void pushUp(int p) {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    void pushDown(int p, int l, int r) {
        if (addVal[p]) {
            int m = (l + r) >> 1;
            addVal[p << 1] += addVal[p];
            sum[p << 1] += (m - l + 1) * addVal[p];
            addVal[p << 1 | 1] += addVal[p];
            sum[p << 1 | 1] += (r - m) * addVal[p];
            addVal[p] = 0;
        }
    }
    void build(int p, int l, int r) {
        if (l == r) {
            sum[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    void add(int ql, int qr, ll v, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            sum[p] += (r - l + 1) * v;
            addVal[p] += v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) add(ql, qr, v, p << 1, l, m);
        if (qr > m) add(ql, qr, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    ll query(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            return sum[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll res = 0;
        if (ql <= m) res += query(ql, qr, p << 1, l, m);
        if (qr > m) res += query(ql, qr, p << 1 | 1, m + 1, r);
        return res;
    }
    void build() {
        build(1, 1, n);
    }
    void add(int l, int r, ll v) {
        add(l, r, v, 1, 1, n);
    }
    ll query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
};
```

#### 区间 set

只需要区间赋值时，可去掉加法标记。必须额外维护 `hasSet`，不能用
`setVal == 0` 判断标记是否存在，因为赋值为 $0$ 也是合法操作。

- **时间复杂度**：建树 $O(n)$，区间修改/查询 $O(\log n)$
- **空间复杂度**：$O(n)$

```cpp
struct SegTree {
    int n;
    vector<int> arr;
    vector<ll> sum, setVal;
    vector<bool> hasSet;
    SegTree(int n)
        : n(n), arr(n + 1, 0), sum((n + 1) << 2, 0), setVal((n + 1) << 2, 0),
          hasSet((n + 1) << 2, 0) {
    }
    void pushUp(int p) {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    void pushDown(int p, int l, int r) {
        if (hasSet[p]) {
            int m = (l + r) >> 1;
            setVal[p << 1] = setVal[p];
            sum[p << 1] = (m - l + 1) * setVal[p];
            hasSet[p << 1] = true;
            setVal[p << 1 | 1] = setVal[p];
            sum[p << 1 | 1] = (r - m) * setVal[p];
            hasSet[p << 1 | 1] = true;
            hasSet[p] = false;
        }
    }
    void build(int p, int l, int r) {
        if (l == r) {
            sum[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    void rangeSet(int ql, int qr, ll v, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            setVal[p] = v;
            sum[p] = (r - l + 1) * v;
            hasSet[p] = true;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeSet(ql, qr, v, p << 1, l, m);
        if (qr > m) rangeSet(ql, qr, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    ll query(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            return sum[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll res = 0;
        if (ql <= m) res += query(ql, qr, p << 1, l, m);
        if (qr > m) res += query(ql, qr, p << 1 | 1, m + 1, r);
        return res;
    }
    void build() {
        build(1, 1, n);
    }
    void rangeSet(int l, int r, ll v) {
        rangeSet(l, r, v, 1, 1, n);
    }
    ll query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
};
```

#### 区间 add + 区间 set

- **时间复杂度**：建树 $O(n)$，区间修改/查询 $O(\log n)$
- **空间复杂度**：$O(n)$
- **标记复合**：`set` 覆盖旧 `set` 并清空 `add`；下传时先 `set` 后 `add`

```cpp
struct SegTree {
    int n;
    vector<int> arr;
    vector<ll> sum, addVal, setVal;
    vector<bool> hasSet;
    SegTree(int n)
        : n(n), arr(n + 1, 0), sum((n + 1) << 2, 0), addVal((n + 1) << 2, 0),
          setVal((n + 1) << 2, 0), hasSet((n + 1) << 2, 0) {
    }
    void applySet(int p, int l, int r, ll v) {
        sum[p] = (r - l + 1) * v;
        setVal[p] = v;
        hasSet[p] = true;
        addVal[p] = 0;
    }
    void applyAdd(int p, int l, int r, ll v) {
        sum[p] += (r - l + 1) * v;
        addVal[p] += v;
    }
    void pushUp(int p) {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    void pushDown(int p, int l, int r) {
        int m = (l + r) >> 1;
        if (hasSet[p]) {
            applySet(p << 1, l, m, setVal[p]);
            applySet(p << 1 | 1, m + 1, r, setVal[p]);
            hasSet[p] = false;
        }
        if (addVal[p]) {
            applyAdd(p << 1, l, m, addVal[p]);
            applyAdd(p << 1 | 1, m + 1, r, addVal[p]);
            addVal[p] = 0;
        }
    }
    void build(int p, int l, int r) {
        if (l == r) {
            sum[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    void rangeAdd(int ql, int qr, ll v, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            applyAdd(p, l, r, v);
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeAdd(ql, qr, v, p << 1, l, m);
        if (qr > m) rangeAdd(ql, qr, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    void rangeSet(int ql, int qr, ll v, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            applySet(p, l, r, v);
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeSet(ql, qr, v, p << 1, l, m);
        if (qr > m) rangeSet(ql, qr, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    ll query(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            return sum[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll res = 0;
        if (ql <= m) res += query(ql, qr, p << 1, l, m);
        if (qr > m) res += query(ql, qr, p << 1 | 1, m + 1, r);
        return res;
    }
    void build() {
        build(1, 1, n);
    }
    void rangeAdd(int l, int r, ll v) {
        rangeAdd(l, r, v, 1, 1, n);
    }
    void rangeSet(int l, int r, ll v) {
        rangeSet(l, r, v, 1, 1, n);
    }
    ll query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
};
```

### 维护区间最大值/最小值

以下代码维护最大值。若要维护最小值，把 `max` 换成 `min`，并把查询的
幺元 `LLONG_MIN` 换成 `LLONG_MAX`。

#### 区间 add

- **时间复杂度**：建树 $O(n)$，区间修改/查询 $O(\log n)$
- **空间复杂度**：$O(n)$
- **要点**：整段加同一个数时，区间最大值也只需加这个数，不乘区间长度

```cpp
struct SegTree {
    int n;
    vector<ll> arr, mx, addVal;
    SegTree(int n) : n(n), arr(n + 1, 0), mx((n + 1) << 2, 0), addVal((n + 1) << 2, 0) {
    }
    void applyAdd(int p, ll v) {
        mx[p] += v;
        addVal[p] += v;
    }
    void pushUp(int p) {
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
    }
    void pushDown(int p) {
        if (addVal[p] == 0) return;
        applyAdd(p << 1, addVal[p]);
        applyAdd(p << 1 | 1, addVal[p]);
        addVal[p] = 0;
    }
    void build(int p, int l, int r) {
        if (l == r) {
            mx[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    void rangeAdd(int ql, int qr, ll v, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            applyAdd(p, v);
            return;
        }
        pushDown(p);
        int m = (l + r) >> 1;
        if (ql <= m) rangeAdd(ql, qr, v, p << 1, l, m);
        if (qr > m) rangeAdd(ql, qr, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    ll query(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) return mx[p];
        pushDown(p);
        int m = (l + r) >> 1;
        ll res = numeric_limits<ll>::lowest();
        if (ql <= m) res = max(res, query(ql, qr, p << 1, l, m));
        if (qr > m) res = max(res, query(ql, qr, p << 1 | 1, m + 1, r));
        return res;
    }
    void build() {
        build(1, 1, n);
    }
    void rangeAdd(int l, int r, ll v) {
        rangeAdd(l, r, v, 1, 1, n);
    }
    ll query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
};
```

#### 区间 set

```cpp
struct SegTree {
    int n;
    vector<ll> arr, mx, setVal;
    vector<bool> hasSet;
    SegTree(int n)
        : n(n), arr(n + 1, 0), mx((n + 1) << 2, 0), setVal((n + 1) << 2, 0),
          hasSet((n + 1) << 2, false) {
    }
    void applySet(int p, ll v) {
        mx[p] = v;
        setVal[p] = v;
        hasSet[p] = true;
    }
    void pushUp(int p) {
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
    }
    void pushDown(int p) {
        if (!hasSet[p]) return;
        applySet(p << 1, setVal[p]);
        applySet(p << 1 | 1, setVal[p]);
        hasSet[p] = false;
    }
    void build(int p, int l, int r) {
        if (l == r) {
            mx[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    void rangeSet(int ql, int qr, ll v, int p, int l, int r) {
        if (ql <= l && r <= qr) {
            applySet(p, v);
            return;
        }
        pushDown(p);
        int m = (l + r) >> 1;
        if (ql <= m) rangeSet(ql, qr, v, p << 1, l, m);
        if (qr > m) rangeSet(ql, qr, v, p << 1 | 1, m + 1, r);
        pushUp(p);
    }
    ll query(int ql, int qr, int p, int l, int r) {
        if (ql <= l && r <= qr) return mx[p];
        pushDown(p);
        int m = (l + r) >> 1;
        ll res = numeric_limits<ll>::lowest();
        if (ql <= m) res = max(res, query(ql, qr, p << 1, l, m));
        if (qr > m) res = max(res, query(ql, qr, p << 1 | 1, m + 1, r));
        return res;
    }
    void build() {
        build(1, 1, n);
    }
    void rangeSet(int l, int r, ll v) {
        rangeSet(l, r, v, 1, 1, n);
    }
    ll query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
};
```
