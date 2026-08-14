## 数据结构

### 对顶堆求中位数

```cpp
template <typename T, typename Compare = less<T>>
struct DualMultiset {
    multiset<T, Compare> L;
    multiset<T, Compare> R;
    Compare cmp;
    
    long long sum_L = 0;
    long long sum_R = 0;

    DualMultiset(Compare c = Compare()) : cmp(c), L(c), R(c) {}
    size_t size() const { return L.size() + R.size(); }
    bool empty() const { return size() == 0; }
    const T& median() const { return median_left(); } // 针对元素个数为奇数的中位数的情况
    
    void balance() {
        size_t tot = size();
        while (L.size() > ((tot + 1) >> 1)) {
            auto it = prev(L.end());
            sum_L -= *it;
            sum_R += *it;
            R.insert(L.extract(it));
        }
        while (L.size() < ((tot + 1) >> 1) && !R.empty()) {
            auto it = R.begin();
            sum_R -= *it;
            sum_L += *it;
            L.insert(R.extract(it));
        }
    }
    
    const T& median_left() const {
        assert(!L.empty());
        return *prev(L.end());
    }
    
    const T& median_right() const {
        assert(!R.empty());
        return *R.begin();
    }
    
    void insert(const T& x) {
        if (L.empty() || !cmp(median_left(), x)) {
            L.insert(x);
            sum_L += x;
        } else {
            R.insert(x);
            sum_R += x;
        }
        balance();
    }
    
    void erase(const T& x) {
        auto it = L.find(x);
        if (it != L.end()) {
            sum_L -= *it;
            L.erase(it);
        } else {
            auto it2 = R.find(x);
            if (it2 != R.end()) {
                sum_R -= *it2;
                R.erase(it2);
            }
        }
        balance();
    }

    // 计算当前集合所有元素到中位数的距离之和: 
    // (右半部分和 - 右半部分个数 * 中位数) + (左半部分个数 * 中位数 - 左半部分和)
    long long get_abs_diff_sum() const {
        if (empty()) return 0;
        long long mid = median();
        long long right_part = sum_R - 1LL * R.size() * mid;
        long long left_part = 1LL * L.size() * mid - sum_L;
        return right_part + left_part;
    }
};
```

上面使用的 `multiset` 基于红黑树，时间常数较大，必要时可改用下面的 `priority_queue` + 懒标记实现

```cpp
template <typename T>
struct DualPriorityQueue {
    priority_queue<T> L, L_del; // 维护较小的一半，用大根堆
    priority_queue<T, vector<T>, greater<T>> R, R_del; // 维护较大的一半，用小根堆
    long long sum_L = 0;
    long long sum_R = 0;
    int size_L = 0;
    int size_R = 0;

    int size() const { return size_L + size_R; }
    bool empty() const { return size() == 0; }
    T median() { return median_left(); }

    void prune_L() {
        while (!L.empty() && !L_del.empty() && L.top() == L_del.top()) {
            L.pop(); L_del.pop();
        }
    }
    void prune_R() {
        while (!R.empty() && !R_del.empty() && R.top() == R_del.top()) {
            R.pop(); R_del.pop();
        }
    }
    void balance() {
        int tot = size();
        while (size_L > (tot + 1) / 2) {
            prune_L();
            T top = L.top(); L.pop();
            R.push(top);
            size_L--; size_R++;
            sum_L -= top; sum_R += top;
        }
        while (size_L < (tot + 1) / 2 && !R.empty()) {
            prune_R();
            T top = R.top(); R.pop();
            L.push(top);
            size_R--; size_L++;
            sum_R -= top; sum_L += top;
        }
    }

    void insert(const T& x) {
        prune_L(); // 确保 x 在 L 中的判断是准确的
        if (size_L == 0 || x <= L.top()) {
            L.push(x);
            size_L++; sum_L += x;
        } else {
            R.push(x);
            size_R++; sum_R += x;
        }
        balance();
    }

    void erase(const T& x) {
        prune_L(); // 确保 x 在 L 中的判断是准确的
        if (size_L > 0 && x <= L.top()) {
            L_del.push(x);
            size_L--; sum_L -= x;
        } else {
            R_del.push(x);
            size_R--; sum_R -= x;
        }
        balance();
    }

    T median_left() {
        assert(size_L > 0);
        prune_L();
        return L.top();
    }

    T median_right() {
        assert(size_R > 0);
        prune_R();
        return R.top();
    }

    long long get_abs_diff_sum() {
        if (empty()) return 0;
        long long mid = median();
        long long left_part = 1LL * mid * size_L - sum_L;
        long long right_part = sum_R - 1LL * mid * size_R;
        return left_part + right_part;
    }
};
```

## 数学

### 矩阵快速幂

```cpp
struct Matrix {
    int r, c;
    int p;
    vector<vector<long long>> mat;
    Matrix(int r, int c, int mod = 1) : r(r), c(c), p(mod), mat(r, vector<long long>(c, 0)) {}

    void build_identity() {
        assert(r == c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                mat[i][j] = (i == j ? 1 : 0);
            }
        }
    }

    Matrix operator*(const Matrix& other) const {
        assert(c == other.r);
        assert(p == other.p);
        Matrix res(r, other.c, p);
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < c; ++k) {
                long long tmp = mat[i][k];
                if (tmp == 0) continue;
                for (int j = 0; j < other.c; ++j) {
                    res.mat[i][j] = (res.mat[i][j] + tmp * other.mat[k][j]) % p;
                    if (res.mat[i][j] < 0) res.mat[i][j] += p;
                }
            }
        }
        return res;
    }

    Matrix operator^(long long n) const {
        assert(r == c);
        Matrix res(r, c, p);
        res.build_identity();
        Matrix a = *this;
        while (n > 0) {
            if (n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }
};
```

### 线段树

#### 维护区间和：区间加 + 区查

```cpp
struct SegTree {
private:
    int n;
    vector<int> arr;
    vector<ll> tree, addVal;

    void build(int l, int r, int p) {
        if (l == r) {
            tree[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, p << 1);
        build(m + 1, r, p << 1 | 1);
        pushUp(p);
    }

    void pushUp(int p) {
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    void pushDown(int p, int l, int r) {
        if (addVal[p]) {
            int m = (l + r) >> 1;
            addVal[p << 1] += addVal[p];
            tree[p << 1] += (m - l + 1) * addVal[p];
            addVal[p << 1 | 1] += addVal[p];
            tree[p << 1 | 1] += (r - m) * addVal[p];
            addVal[p] = 0;
        }
    }

    void rangeAdd(int ql, int qr, ll v, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            addVal[p] += v;
            tree[p] += (r - l + 1) * v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeAdd(ql, qr, v, l, m, p << 1);
        if (qr > m) rangeAdd(ql, qr, v, m + 1, r, p << 1 | 1);
        pushUp(p);
    }

    ll query(int ql, int qr, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll ans = 0;
        if (ql <= m) ans += query(ql, qr, l, m, p << 1);
        if (qr > m) ans += query(ql, qr, m + 1, r, p << 1 | 1);
        return ans;
    }

public:
    SegTree(int size) {
        n = size;
        arr.resize(n + 1);
        tree.resize((n + 1) << 2, 0);
        addVal.resize((n + 1) << 2, 0);
    }

    void read() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        build(1, n, 1);
    }

    void add(int l, int r, ll v) {
        rangeAdd(l, r, v, 1, n, 1);
    }

    void add(int i, ll v) {
        add(i, i, v);
    }

    ll query(int l, int r) {
        return query(l, r, 1, n, 1);
    }

    ll query(int i) {
        return query(i, i);
    }
};

// 使用方法
// int n, m; cin >> n >> m;
// SegTree st(n);
// st.read();
// while (m--) {
//     int f, x, y; cin >> f >> x >> y;
//     if (f == 1) {
//         st.add(x, y);
//     } else if (f == 2) {
//         cout << st.query(x, y) << endl;
//     }
// }
```

#### 维护区间和：区间赋值 + 区查

```cpp
struct SegTree {
private:
    int n;
    vector<int> arr;
    vector<ll> tree, setVal;
    vector<bool> hasSet;

    void pushDown(int p, int l, int r) {
        if (hasSet[p]) {
            int m = (l + r) >> 1;
            hasSet[p << 1] = true;
            setVal[p << 1] = setVal[p];
            tree[p << 1] = (m - l + 1) * setVal[p];
            hasSet[p << 1 | 1] = true;
            setVal[p << 1 | 1] = setVal[p];
            tree[p << 1 | 1] = (r - m) * setVal[p];
            hasSet[p] = false;
            setVal[p] = 0;
        }
    }

    void pushUp(int p) {
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    ll query(int ql, int qr, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll ans = 0;
        if (ql <= m) ans += query(ql, qr, l, m, p << 1);
        if (qr > m) ans += query(ql, qr, m + 1, r, p << 1 | 1);
        return ans;
    }

    void rangeSet(int ql, int qr, ll v, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            hasSet[p] = true;
            setVal[p] = v;
            tree[p] = (r - l + 1) * v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeSet(ql, qr, v, l, m, p << 1);
        if (qr > m) rangeSet(ql, qr, v, m + 1, r, p << 1 | 1);
        pushUp(p);
    }

    void build(int l, int r, int p) {
        if (l == r) {
            tree[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, p << 1);
        build(m + 1, r, p << 1 | 1);
        pushUp(p);
    }

public:
    SegTree(int size) {
        n = size;
        arr.resize(n + 1);
        tree.resize((n + 1) << 2, 0);
        setVal.resize((n + 1) << 2, 0);
        hasSet.resize((n + 1) << 2, false);
    }

    void read() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        build(1, n, 1);
    }

    void modify(int l, int r, ll v) {
        rangeSet(l, r, v, 1, n, 1);
    }

    void modify(int i, ll v) {
        modify(i, i, v);
    }

    ll query(int l, int r) {
        return query(l, r, 1, n, 1);
    }

    ll query(int i) {
        return query(i, i);
    }
};
```

#### 维护区间和：区间加 + 区间赋值 + 区查

```cpp
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct SegTree {
private:
    int n;
    vector<int> arr;
    vector<ll> tree, addVal, setVal;
    vector<bool> hasSet;

    inline int ls(int p) { return p << 1; }
    inline int rs(int p) { return p << 1 | 1; }

    void pushUp(int p) {
        tree[p] = tree[ls(p)] + tree[rs(p)];
    }

    void pushDown(int p, int l, int r) {
        int m = (l + r) >> 1;
        
        // 优先处理“区间赋值”标记 (赋值会覆盖之前的加法)
        if (hasSet[p]) {
            hasSet[ls(p)] = true;
            setVal[ls(p)] = setVal[p];
            addVal[ls(p)] = 0; // 覆盖赋值时，必须清空儿子原有的加法标记
            tree[ls(p)] = (m - l + 1) * setVal[p];
            hasSet[rs(p)] = true;
            setVal[rs(p)] = setVal[p];
            addVal[rs(p)] = 0; // 同上
            tree[rs(p)] = (r - m) * setVal[p];

            hasSet[p] = false;
        }
        // 然后处理“区间加法”标记
        if (addVal[p]) {
            addVal[ls(p)] += addVal[p];
            tree[ls(p)] += (m - l + 1) * addVal[p];
            addVal[rs(p)] += addVal[p];
            tree[rs(p)] += (r - m) * addVal[p];
            
            addVal[p] = 0;
        }
    }

    void build(int l, int r, int p) {
        hasSet[p] = false;
        addVal[p] = 0;
        if (l == r) {
            tree[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, ls(p));
        build(m + 1, r, rs(p));
        pushUp(p);
    }

    void rangeAdd(int ql, int qr, ll v, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            addVal[p] += v;
            tree[p] += (r - l + 1) * v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeAdd(ql, qr, v, l, m, ls(p));
        if (qr > m)  rangeAdd(ql, qr, v, m + 1, r, rs(p));
        pushUp(p);
    }

    void rangeSet(int ql, int qr, ll v, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            hasSet[p] = true;
            setVal[p] = v;
            addVal[p] = 0; // 新的区间赋值直接让该节点之前的加法标记失效
            tree[p] = (r - l + 1) * v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeSet(ql, qr, v, l, m, ls(p));
        if (qr > m)  rangeSet(ql, qr, v, m + 1, r, rs(p));
        pushUp(p);
    }

    ll query(int ql, int qr, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll ans = 0;
        if (ql <= m) ans += query(ql, qr, l, m, ls(p));
        if (qr > m)  ans += query(ql, qr, m + 1, r, rs(p));
        return ans;
    }

public:
    SegTree(int size) {
        n = size;
        arr.resize(n + 1, 0);
        tree.resize((n + 1) << 2, 0);
        addVal.resize((n + 1) << 2, 0);
        setVal.resize((n + 1) << 2, 0);
        hasSet.resize((n + 1) << 2, false);
    }

    void read() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        build(1, n, 1);
    }

    void add(int l, int r, ll v) {
        rangeAdd(l, r, v, 1, n, 1);
    }

    void assign(int l, int r, ll v) {
        rangeSet(l, r, v, 1, n, 1);
    }

    ll query(int l, int r) {
        return query(l, r, 1, n, 1);
    }
    
    void add(int i, ll v) { add(i, i, v); }
    void assign(int i, ll v) { assign(i, i, v); }
    ll query(int i) { return query(i, i); }
};
```


#### 维护区间 max/min：区间加 + 区查

如果要维护区间 min，需要修改下面两处注释的部分

```cpp
struct SegTree {
private:
    int n;
    vector<int> arr;
    vector<ll> tree, addVal;

    void pushUp(int p) {
        tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
        // tree[p] = min(tree[p << 1], tree[p << 1 | 1]); // 区间 min
    }

    void pushDown(int p, int l, int r) {
        if (addVal[p]) {
            addVal[p << 1] += addVal[p];
            tree[p << 1] += addVal[p];
            addVal[p << 1 | 1] += addVal[p];
            tree[p << 1 | 1] += addVal[p];
            addVal[p] = 0;
        }
    }

    void rangeAdd(int ql, int qr, ll v, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            addVal[p] += v;
            tree[p] += v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeAdd(ql, qr, v, l, m, p << 1);
        if (qr > m) rangeAdd(ql, qr, v, m + 1, r, p << 1 | 1);
        pushUp(p);
    }

    ll query(int ql, int qr, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll ans = -4e18;
        // ll ans = 4e18; // 区间 min
        if (ql <= m) ans = max(ans, query(ql, qr, l, m, p << 1));
        if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, p << 1 | 1));
        return ans;
    }

    void build(int l, int r, int p) {
        if (l == r) {
            tree[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, p << 1);
        build(m + 1, r, p << 1 | 1);
        pushUp(p);
    }

public:
    SegTree(int size) {
        n = size;
        arr.resize(n + 1, 0);
        tree.resize((n + 1) << 2, 0);
        addVal.resize((n + 1) << 2, 0);
    }

    void read() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        build(1, n, 1);
    }

    void add(int l, int r, ll v) {
        rangeAdd(l, r, v, 1, n, 1);
    }

    void add(int i, ll v) {
        add(i, i, v);
    }

    ll query(int l, int r) {
        return query(l, r, 1, n, 1);
    }

    ll query(int i) {
        return query(i, i);
    }
};
```

#### 维护区间 max/min：区间赋值 + 区查

```cpp
struct SegTree {
private:z
    int n;
    vector<int> arr;
    vector<ll> tree, setVal;
    vector<bool> hasSet;

    void pushUp(int p) {
        tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
    }

    void pushDown(int p, int l, int r) {
        if (hasSet[p]) {
            hasSet[p << 1] = true;
            setVal[p << 1] = setVal[p];
            tree[p << 1] = setVal[p];
            hasSet[p << 1 | 1] = true;
            setVal[p << 1 | 1] = setVal[p];
            tree[p << 1 | 1] = setVal[p];
            hasSet[p] = false;
        }
    }

    void rangeSet(int ql, int qr, ll v, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            hasSet[p] = true;
            setVal[p] = v;
            tree[p] = v;
            return;
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) rangeSet(ql, qr, v, l, m, p << 1);
        if (qr > m) rangeSet(ql, qr, v, m + 1, r, p << 1 | 1);
        pushUp(p);
    }

    ll query(int ql, int qr, int l, int r, int p) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        pushDown(p, l, r);
        int m = (l + r) >> 1;
        ll ans = -4e18; // 极大值/极小值根据需求改变，这里是求 max 的极小值
        if (ql <= m) ans = max(ans, query(ql, qr, l, m, p << 1));
        if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, p << 1 | 1));
        return ans;
    }

    void build(int l, int r, int p) {
        if (l == r) {
            tree[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, p << 1);
        build(m + 1, r, p << 1 | 1);
        pushUp(p);
    }

public:
    SegTree(int size) {
        n = size;
        arr.resize(n + 1, 0);
        tree.resize((n + 1) << 2, 0);
        setVal.resize((n + 1) << 2, 0);
        hasSet.resize((n + 1) << 2, false);
    }

    void read() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        build(1, n, 1);
    }

    void modify(int l, int r, ll v) {
        rangeSet(l, r, v, 1, n, 1);
    }

    void modify(int i, ll v) {
        modify(i, i, v);
    }

    ll query(int l, int r) {
        return query(l, r, 1, n, 1);
    }

    ll query(int i) {
        return query(i, i);
    }
};
```

