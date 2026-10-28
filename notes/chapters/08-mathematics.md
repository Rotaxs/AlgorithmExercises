# 数学

## 进制与位运算

- **时间复杂度**：以下单次操作均为 $O(1)$
- **空间复杂度**：$O(1)$
- 判断奇偶：`n & 1`
- 判断正整数是否为 $2$ 的幂：`(n & (n - 1)) == 0`

### 格雷码

- **时间复杂度**：$O(w)$，$w$ 为二进制位数
- **空间复杂度**：$O(1)$
- **公式**：二进到格雷码为 $g=m\oplus(m\mathbin{\mathtt{>>}}1)$；逆变换为各高位前缀异或

```cpp
unsigned int grayToBinary(unsigned int gray) {
    unsigned int binary = gray;
    while (gray > 0) {
        gray >>= 1;
        binary ^= gray;
    }
    return binary;
}
```

## 快速幂

### 乘法快速幂

- **时间复杂度**：$O(\log n)$
- **空间复杂度**：$O(1)$
- **要点**：从低到高遍历指数的二进制位；当前位为 $1$ 时将底数乘入答案

```cpp
long long qpow(long long a, long long n) {
    long long ret = 1;
    while (n) {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

long long qpow(long long a, long long n, int p) {
    long long ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ret;
}
```

### 矩阵快速幂

- **时间复杂度**：$k$ 阶矩阵乘法 $O(k^3)$，快速幂 $O(k^3\log p)$
- **空间复杂度**：$O(k^2)$
- **要点**：结果初始化为单位矩阵，其余流程与整数快速幂相同

$$
C_{i, j} = \sum_{r = 1}^{k}A_{i, r}\times B_{r, j}
$$

```cpp
const int N = 110;
const int MOD = 1e9 + 7;

struct matrix {
    ll m[N][N];
    matrix() {
        memset(m, 0, sizeof m);
    }
};

// a 是 n x k 矩阵，b 是 k x m 矩阵，得到 n x m 矩阵
matrix multiply(const matrix& a, const matrix& b, int n, int k, int m) {
    matrix c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int r = 1; r <= k; r++)
                c.m[i][j] = (c.m[i][j] + a.m[i][r] * b.m[r][j]) % MOD;
    return c;
}

// 返回 a^p，n 表示 a 的阶数
matrix pow_matrix(matrix a, ll p, int n) {
    matrix ans;
    for (int i = 1; i <= n; i++)
        ans.m[i][i] = 1; // 单位矩阵
    while (p) {
        if (p & 1) ans = multiply(ans, a, n, n, n);
        a = multiply(a, a, n, n, n);
        p >>= 1;
    }
    return ans;
}
```

#### 动态尺寸矩阵封装

矩阵规模在运行时确定时，可使用下面的封装。模数随矩阵保存，乘法会检查
尺寸与模数是否相容。

```cpp
struct Matrix {
    int rows, cols, mod;
    vector<vector<long long>> a;

    Matrix(int rows, int cols, int mod)
        : rows(rows), cols(cols), mod(mod),
          a(rows, vector<long long>(cols)) {}

    static Matrix identity(int n, int mod) {
        Matrix res(n, n, mod);
        for (int i = 0; i < n; ++i) res.a[i][i] = 1 % mod;
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        assert(cols == other.rows && mod == other.mod);
        Matrix res(rows, other.cols, mod);
        for (int i = 0; i < rows; ++i) {
            for (int k = 0; k < cols; ++k) {
                long long x = a[i][k];
                if (x == 0) continue;
                for (int j = 0; j < other.cols; ++j) {
                    res.a[i][j] = (res.a[i][j]
                        + (__int128)x * other.a[k][j]) % mod;
                }
            }
        }
        return res;
    }

    Matrix pow(long long exponent) const {
        assert(rows == cols && exponent >= 0);
        Matrix base = *this;
        Matrix res = identity(rows, mod);
        while (exponent > 0) {
            if (exponent & 1) res = res * base;
            base = base * base;
            exponent >>= 1;
        }
        return res;
    }
};
```

#### 矩阵快速幂加速一维 k 阶递推

将状态向量写成 $S_n=A S_{n-1}$，则 $S_n=A^{n-t}S_t$。

- **时间复杂度**：$O(k^3\log n)$
- **空间复杂度**：$O(k^2)$

状态维数取“各状态最大回看跨度之和 + 附加项维数”：常数、$n$、$n^2$、$C^n$ 分别额外占 $1,2,3,1$ 维。

【例1】$f_{n} = 4f_{n-1} - 3f_{n - 2} + 5$

$$
\begin{bmatrix} f_n \\ f_{n-1} \\ 1 \end{bmatrix} =  \begin{bmatrix}  4 & -3 & 5 \\  1 & 0 & 0 \\  0 & 0 & 1  \end{bmatrix}  \begin{bmatrix} f_{n-1} \\ f_{n-2} \\ 1 \end{bmatrix}
$$

【例2】$A_n = A_{n-1} + 2B_{n-1}$，$B_n = 3A_{n-1} + B_{n-1} + 1$

$$
\begin{bmatrix} A_n \\ B_n \\ 1 \end{bmatrix} =  \begin{bmatrix}  1 & 2 & 0 \\  3 & 1 & 1 \\  0 & 0 & 1  \end{bmatrix}  \begin{bmatrix} A_{n-1} \\ B_{n-1} \\ 1 \end{bmatrix}
$$

【例3】$f_n = 3f_{n-1} + 2^n$

$$
\begin{bmatrix} f_n \\ 2^n \end{bmatrix} =  \begin{bmatrix}  3 & 2 \\  0 & 2  \end{bmatrix}  \begin{bmatrix} f_{n-1} \\ 2^{n-1} \end{bmatrix}
$$

例子按列向量书写；若代码使用行向量，需将转移矩阵转置。

#### 矩阵快速幂加速 k 维一阶递推

将状态较少的一维全部列入向量，用相容关系构造转移矩阵。

- **时间复杂度**：$O(k^3\log n)$
- **空间复杂度**：$O(k^2)$

例：$1\times N$ 格子中不能相邻种树，用 `0/1` 表示当前格空/种树，相容矩阵为

|       |  `0`  |  `1`  |
| :---: | :---: | :---: |
|  `0`  |   1   |   1   |
|  `1`  |   1   |   0   |

初始向量乘该矩阵的 $N-1$ 次幂即得答案。

## 大指数取模

利用扩展欧拉定理缩小指数，再用秦九韶法逐位计算十进制大数 $b\bmod\varphi(m)$。

- **时间复杂度**：$O(\sqrt m+|b|+\log\varphi(m))$
- **空间复杂度**：$O(|b|)$ 用于存储指数字符串，额外空间 $O(1)$

```cpp
int a, m;
string b;

int get_phi(int n) {
    int ret = n;
    for (int p = 2; 1LL * p * p <= n; p++) {
        if (n % p == 0) {
            ret = ret / p * (p - 1);
            while (n % p == 0)
                n /= p;
        }
    }
    if (n > 1) ret = ret / n * (n - 1);
    return ret;
}

ll qpow(ll a, ll n) {
    int ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return ret;
}

int get_b(int phi) {
    int ret = 0;
    bool ok = false;
    for (char c : b) {
        ret = ret * 10 + (c - '0');
        if (ret >= phi) ok = true, ret %= phi;
    }
    if (ok) ret += phi;
    return ret;
}

void solve() {
    cin >> a >> m >> b;
    int phi = get_phi(m);
    int b = get_b(phi);
    cout << qpow(a, b) << '\n';
}
```

## 置换环

### 置换环的定义和性质

**置换环**：对一个**排列**，建立 $i \to a[i]$ 的边，会得到若干个环，这若干个环就是置换环
- 交换排列中的两个元素，环的数量变化 1
  - 如果交换的两个元素在同一个环中，环的数量减少 1
  - 如果交换的两个元素不在同一个环中，环的数量增加 1
- 把环数从 $c$ 增加到 $n$（有序序列），至少需要 $n - c$ 次交换，且 $n - c$ 次交换一定能做到

> [!note]
> 简单证明：假设排列大小为 $n$，置换环的数量为 $c$，每个置换环的长度为 $s_i\space(i = 1,2,\cdots,c)$。显然，将某一个置换环全部拆开（每个元素都指向自己），需要 $s_i - 1$ 次，因此，将所有的置换环拆开，需要 $\sum_{i=1}^{c}(s_i - 1) = n - c$

### 置换环判断逆序数的奇偶性

- **时间复杂度**：$O(n)$
- **空间复杂度**：$O(n)$

交换序列中的两个数，逆序对数奇偶性改变，置换环数**变化** 1，从而有 $I \equiv n - c \pmod 2$

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

> [!tip]
> 注意这并不能说明置换环能够求出逆序对的具体数量，因为逆序对交换要求相邻两数交换，而这里的交换是任意两数的交换

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

### 求原排列到目标排列的距离

将原排列通过交换任意两个元素得到有序排列，需要 $n - c$ 次

现给定两个排列 $p, q$，求将 $p$ 经过若干次交换任意两个元素得到 $q$ 所需要的最小交换次数

为此，我们可以把 $q$ 定为一个基准，比如，假设 $p = [3, 2, 1, 4]$，$q = [2, 1, 3, 4]$，在 $q$ 中，2 是第一个元素，因此把 2 映射为 1，同理，将 1 映射为 2，3 映射为 3，4 映射为 4，从而得到 $p = [3, 1, 2, 4]$

然后再求新的 $p$ 到有序排列的距离即可

- **时间复杂度**：$O(n)$
- **空间复杂度**：$O(n)$

```cpp
int getSwap(const vector<int>& a) {
    int n = a.size() - 1;
    vector<int> vis(n + 1, false);
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

    return n - cnt;
}

void solve() {
    int n = 4;
    vector<int> p = {0, 3, 2, 1, 4};
    vector<int> q = {0, 2, 1, 3, 4};

    vector<int> id(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        id[q[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        p[i] = id[p[i]];
    }

    cout << getSwap(p) << endl;
}
```

**[CF1768D](https://codeforces.com/contest/1768/problem/D) Lucky Permutation**

> 题目大意：给定一个大小为 $n$ 的排列，可以任意交换其中两个元素，求最终逆序数为 1 的排列所需要的最少交换次数

逆序数为 1 的排列就是有序排列再交换相邻两个元素得到的排列

将目标排列看作是有序排列交换了相邻的两个数，对应映射得到的原排列就是交换了相应的两个数，因此只要求新的排列到有序排列的距离即可

设原排列的置换环个数为 $k$

现分两种情况进行讨论

若交换的两个元素在同一个置换环，则交换后置换环数量为 $k + 1$，最少交换次数为 $n - k - 1$

若交换的两个元素在不同置换环，则交换后的置换环数量为 $k - 1$，最少交换次数为 $n - k + 1$

因此，只要能找到存在相邻数在同一个环，则取答案为 $n - k - 1$，否则取 $n - k + 1$


