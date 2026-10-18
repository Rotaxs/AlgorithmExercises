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
