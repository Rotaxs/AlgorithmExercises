# 数论

## 常见复杂度结论

- 调和级数：$\sum_{i=1}^{n} \frac{1}{i} = \ln n + \gamma \approx O(\log n)$
- 质数倒数级数：$\sum_{p \le n, p \in \text{prime}} \frac{1}{p} = \ln(\ln n) + M \approx O(\log \log n)$
- 质数计数函数：$\pi(n) \approx \frac{n}{\ln n} \approx O(\frac{n}{\log n})$
- 整除分块：$O(\sqrt{n})$

## gcd 和 lcm

辗转相除法基于 $\gcd(a,b)=\gcd(b,a\bmod b)$，边界为 $\gcd(a,0)=a$。

- **时间复杂度**：$O(\log\min(a,b))$
- **空间复杂度**：迭代版 $O(1)$，递归版 $O(\log\min(a,b))$

```cpp
int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int gcd(int m, int n) {
    int t = 1;
    while (t != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}
```

### 求 $n$ 个数的最大公因数

- **时间复杂度**：$O(n\log M)$，$M=\max a_i$
- **空间复杂度**：$O(1)$ 额外空间

连续取 $\gcd$：

```cpp
int n_gcd(int num[], int n) {
    int ans = num[0];
    for (int i = 1; i < n; i++) {
        ans = gcd(ans, num[i]);
    }
    return ans;
}
```

方法二：找出 $n$ 个数的所有因数，如果某个因数出现了 $n$ 次，那么这个因数就是最大公因数

如果在 $n$ 个数的所有因子中，某个因子出现了 $\geq k$ 次，那么这个因子必然是某 $k$ 个数的最大公因数

- **时间复杂度**：内层循环的次数是调和级数，因此总时间复杂度为 $O(n + M\log M)$
- **空间复杂度**：需要统计每个数的次数，$O(M)$

```cpp
int find_max_k_gcd(const vector<int>& nums, int k) {
    if (nums.empty() || k < 1) return 0;
    // 记录最大值
    int M = 1e-8;
    for (int x : nums)
        M = max(M, x);
    // 统计每个数出现的次数
    vector<int> count(M + 1, 0);
    for (int x : nums)
        count[x]++;
    // 枚举 gcd：只要满足有超过 k 个数是 i 的倍数，i 就是 k_gcd
    for (int i = M; i >= 1; i--) {
        // 统计 i 的倍数的个数
        int cnt = 0;
        for (int j = i; j <= M; j += i) {
            cnt += count[j];
            if (cnt >= k) return i;
        }
    }
    return 1;
}
```

同样的倍数统计可一次求出选择 $1\sim n$ 个数时的最大 GCD，时间 $O(n+M\log M)$，空间 $O(n+M)$。

```cpp
void solve() {
    int n;
    cin >> n;
    int M = 0;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        M = max(nums[i], M);
    }

    vector<int> freq(M + 1, 0);
    for (int x : nums)
        freq[x]++;

    // 每个数至少有一个公因数为 1
    // ans[k] 表示 k 个数的最大公因数
    vector<int> ans(n + 1, 1);
    for (int i = M; i >= 1; i--) {
        // 统计 i 为因子出现的次数
        int cnt = 0;
        for (int j = i; j <= M; j += i)
            cnt += freq[j];
        // cnt 个数都有因子 i，说明这 cnt 个数的最大公因数就是 i
        // 即 ans[cnt] = i，取 i 的最大值作为 cnt 个数的最大公因数
        // 由于 i 是从最大的数开始遍历，则第一次更新 ans[cnt] 的 i 就是最大的 i
        if (cnt > 0 && ans[cnt] == 1) ans[cnt] = i;
    }
    // 将 ans 数组补充完整
    // 如果 c + 1 个数的最大公因数是 x，那么 c 个数的最大公因数至少也是 x
    int cur = 1;
    for (int i = n; i >= 1; i--) {
        cur = max(cur, ans[i]);
        ans[i] = cur;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}
```



### 求满足 $\gcd(P, Q) = x$，$\mathrm{lcm}(P, Q) = y$ 的 $P,Q$ 的个数

若 $x\nmid y$ 则无解。否则令 $y/x$ 含 $k$ 种不同质因子；每种质因子的完整幂必须分配给 $P/x$ 或 $Q/x$，故有序数对数为 $2^k$。

- **时间复杂度**：$O(\sqrt{y/x})$
- **空间复杂度**：$O(1)$

```cpp
void solve() {
    int x, y;
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0 << '\n';
    } else {
        int quotient = y / x;
        int n = 0;
        // 分解质因数
        for (int p = 2; 1LL * p * p <= quotient; p++) {
            if (quotient % p == 0) {
                n++;
                while (quotient % p == 0)
                    quotient /= p;
            }
        }
        if (quotient > 1) n++;
        cout << (1 << n) << '\n';
    }
}
```

### 求满足 $\gcd(P, Q) = x$，$\mathrm{lcm}(P, Q) = y$ 的 $P,Q$ 的所有取值

利用 $PQ=\gcd(P,Q)\operatorname{lcm}(P,Q)=xy$ 枚举 $P\in[x,y]$，再检查 $Q=xy/P$。

- **时间复杂度**：$O((y-x+1)\log y)$
- **空间复杂度**：$O(1)$ 额外空间

```cpp
void solve() {
    int x, y;
    cin >> x >> y;
    ll mult = x * y;
    int ans = 0;
    for (int i = x; i <= y; i++) {
        if (mult % i == 0 && gcd(i, mult / i) == x) {
            cout << i << ' ' << mult / i << '\n';
            ans++;
        }
    }
    cout << ans << '\n';
}
```

### 裴蜀定理

方程 $ax+by=c$ 有整数解当且仅当 $\gcd(a,b)\mid c$。若 $(x_0,y_0)$ 是一组特解，则

$$
x=x_0+\frac{b}{d}t,\qquad y=y_0-\frac{a}{d}t,\qquad d=\gcd(a,b),\ t\in\mathbb Z.
$$

### 扩展欧几里得算法

扩展欧几里得返回 $d=\gcd(a,b)$ 及 $ax+by=d$ 的一组特解。求 $ax+by=c$ 时，将特解同乘 $c/d$。

- **时间复杂度**：$O(\log\min(a,b))$
- **空间复杂度**：$O(\log\min(a,b))$ 递归栈

```cpp
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
```

### 同余方程的最小整数解

将线性同余方程化为二元不定方程，用扩展欧几里得求特解，再调整到所需的最小正整数解。

- **时间复杂度**：$O(\log\min(a,b))$
- **空间复杂度**：$O(\log\min(a,b))$ 递归栈

```cpp
void solve() {
    ll a, b, c, x, y;
    cin >> a >> b >> c;
    ll d = exgcd(a, b, x, y);
    if (c % d != 0) {
        cout << -1 << '\n';
        return;
    }
    x = x * c / d;
    y = y * c / d;
    int m = b / d, n = a / d;
    x = (x % m + m) % m;
    if (x == 0) x = m;
    y = (c - a * x) / b;
    // y > 0 说明存在正整数解（x, y 均大于等于 1）
    if (y > 0) {
        ll cnt = (y - 1) / n + 1;
        ll minx = x;
        ll miny = (y - 1) % n + 1; // y % n 防止 y 整除 n 变为 0
        ll maxx = x + (cnt - 1) * m;
        ll maxy = y;
    } else {
        ll minx = x; // 最小正整数解
        ll maxy = y; // 最大负整数解
        ll miny = (y % n + n) % n;
        if (miny == 0) miny = n;      // 最小正整数解
        ll maxx = (c - b * miny) / a; // 最大负整数解
    }
}
```

### 一些题

[**ABC460E E - $x + y \equiv x + y$**](https://atcoder.jp/contests/abc460/tasks/abc460_e)

> $t$ 组数据，每组给定 $n, m$，求满足 $1 \leq x, y \leq n$ 且 $\text{concat}(x, y) \equiv xy \pmod{m}$ 的正整数数对 $(x, y)$ 的个数，其中 $\text{concat}(x, y)$ 表示将数字 $y$ 拼接到 $x$ 后
>
> - $1 \leq T \leq 10^4$
> - $1 \leq N \leq 10^{18}$
> - $2 \leq M \leq 10^{9}$

- **时间复杂度**：每组 $O(\log n\log m)$
- **空间复杂度**：$O(1)$

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

const int MOD = 998244353;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    ll p10 = 1;
    ll rem = 10 % m;
    for (int l = 1; l <= 19; l++) {
        ll L_bound = p10, R_bound;
        if (p10 > n / 10)
            R_bound = n;
        else
            R_bound = min(n, p10 * 10 - 1);
        if (L_bound > R_bound) break;

        ll cnt_y = (R_bound - L_bound + 1) % MOD;
        ll g = gcd((rem - 1 + m) % m, m);
        ll step = m / g;
        ll cnt_x = (n / step) % MOD;
        ll cur_ans = (cnt_x * cnt_y) % MOD;
        ans = (ans + cur_ans) % MOD;

        rem = (rem * 10) % m;
        if (l < 19) p10 *= 10;
    }

    cout << ans << '\n';
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



## 素数判断和素数筛

### Miller-Rabin 素性测试

- **时间复杂度**：$O(s(\log n)^3)$
- **空间复杂度**：$O(1)$

```cpp
typedef long long ll;
typedef __int128_t int128;

ll power(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = (ll)((int128)res * a % m);
        a = (ll)((int128)a * a % m);
        b /= 2;
    }
    return res;
}

bool miller_rabin(ll n, ll a) {
    if (power(a, n - 1, n) != 1) return false;
    ll d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
        ll tmp = power(a, d, n);
        if (tmp == n - 1) return true;
        if (tmp != 1) return false;
    }
    return true;
}

bool is_prime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    static const vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for (ll a : bases) {
        if (n == a) return true;
        if (!miller_rabin(n, a)) return false;
    }
    return true;
}
```



### 埃氏筛

- **时间复杂度**：$O(n\log\log n)$
- **空间复杂度**：$O(N)$

```cpp
bool is_prime[MAXN];
void Eratosthenes(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;
    for (int i = 2; i <= n / i; i++) {
        if (is_prime[i]) {
            // 这里可以从 i * i 开始是因为 i * 2 ~ i * (i - 1) 已经被前面的质数填完了
            for (ll j = (ll)i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
```

### 欧拉筛

- **时间复杂度**：$O(n)$，因此也叫线性筛
- **空间复杂度**：$O(n)$

每个合数只由其最小质因子筛掉一次。

```cpp
const int MAXN = 1000005;
int primes[MAXN], cnt;   // 存储找出的素数
bool is_not_prime[MAXN]; // 标记是否为合数

void get_primes(int n) {
    is_not_prime[0] = is_not_prime[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!is_not_prime[i]) primes[++cnt] = i;
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++) {
            is_not_prime[i * primes[j]] = true;
            // 保证 i * primes[j] 的最小质因子是 primes[j]
            if (i % primes[j] == 0) break;
        }
    }
}
```

### 区间筛

- **时间复杂度**：欧拉筛 + 埃氏筛 $O(\sqrt{R} + (R - L + 1)\log\log\sqrt{R})$
- **空间复杂度**：$O(\sqrt{R} + R - L + 1)$

先筛出 $[1,\sqrt R]$ 内的质数，再用它们标记 $[L,R]$ 内的合数。

```cpp
const int MAX_SQRT = 50005;
const int MAX_RANGE = 1000005; // 区间长度 R - L + 1

int primes[MAX_SQRT], cnt;
bool is_not_prime_small[MAX_SQRT];  // 用于筛 [1, sqrt(R)]
bool is_not_prime_range[MAX_RANGE]; // 用于映射 [L, R]

// 欧拉筛：筛出 1 ~ sqrt(R) 之间的质数
void sieve(int n) {
    memset(is_not_prime_small, 0, sizeof(is_not_prime_small));
    is_not_prime_small[0] = is_not_prime_small[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!is_not_prime_small[i]) primes[++cnt] = i;
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++) {
            is_not_prime_small[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void segmented_sieve(ll l, ll r) {
    if (l < 2) l = 2; // 1 既不是质数也不是合数
    if (l > r) return;

    for (int i = 1; i <= cnt; i++) {
        ll p = primes[i];
        if (p * p > r) break; // 说明 p 无法筛掉区间内任何新合数
        // 找到区间内第一个 >= l 且是 p 的倍数的数，即 ceil(l / p) * p
        // 如果 p 在区间 [L, R] 内，那么上式算出来的结果是 p，又 p 是个质数，不能被筛掉
        // 因此按照埃氏筛的思想，从 p * p 开始筛
        ll start = max(p * p, (l + p - 1) / p * p);
        // 筛掉 p 的倍数（不含 p）
        for (ll j = start; j <= r; j += p)
            is_not_prime_range[j - l] = true;
    }
}
```



## 分解质因数

### 求一个数的因数个数

若 $n=\prod_{i=1}^a p_i^{k_i}$，则
$$
d(n)=\prod_{i=1}^a(k_i+1).
$$

- **时间复杂度**：$O(\sqrt n)$
- **空间复杂度**：$O(1)$

```cpp
int count_divisors(int n) {
    int ans = 1;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            int cnt = 0;
            // 分解质因数
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            ans *= (cnt + 1);
        }
    }
    // 如果 n > 1，说明 n 还有一个大质数因子
    if (n > 1) ans *= 2;
    return ans;
}
```

### 求一个数的因数的和

若 $n=\prod p_i^{k_i}$，则 $\sigma(n)=\prod_i(1+p_i+\cdots+p_i^{k_i})$。

- **时间复杂度**：$O(\sqrt n)$
- **空间复杂度**：$O(1)$

```cpp
ll count_divisor_sum(int n) {
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ll sum_of_power = 1;
            ll p = i;
            while (n % i == 0) {
                n /= i;
                sum_of_power += p;
                p *= i;
            }
            ans *= sum_of_power;
        }
    }
    if (n > 1) ans *= (1 + n);

    return ans;
}
```

### 约数 DFS

先分解质因数，再 DFS 枚举每个质因子的指数。设约数个数为 $\tau(n)$。

- **时间复杂度**：$O(\sqrt n+\tau(n))$
- **空间复杂度**：$O(\tau(n)+\log n)$，包含输出与递归栈

```cpp
vector<int> get_factors(int n) {
    vector<pair<int, int>> p_factors;
    int tmp = n;
    for (int i = 2; (ll)i * i <= tmp; i++) {
        if (tmp % i == 0) {
            int cnt = 0;
            while (tmp % i == 0) {
                tmp /= i;
                cnt++;
            }
            p_factors.push_back({i, cnt});
        }
    }
    if (tmp > 1) p_factors.push_back({tmp, 1});

    vector<int> factors;
    function<void(int, int)> dfs = [&](int step, int f) {
        if (step == p_factors.size()) {
            factors.push_back(f);
            return;
        }
        auto [p, k] = p_factors[step];

        int p_pow_k = 1;

        for (int i = 0; i <= k; i++) {
            dfs(step + 1, f * p_pow_k);
            p_pow_k *= p;
        }
    };
    dfs(0, 1);
    return factors;
}
```



## 同余

### 常用性质

- 求 $2011^{2011}$ 的百位数字：可求 $2011^{2011} \mod 1000$，注意到 $2011 \equiv 11 \pmod{1000}$，因此 $2011^{2011} \equiv 11^{2011} \pmod {1000}$，利用欧拉定理可得 $2011^{2011} \equiv 11^{2011 \mod \varphi(1000)} \pmod{1000}$
- $15 \equiv 3 \pmod 4 \Rightarrow 5 \equiv 1 \pmod 4$，但是 $15 \equiv 3 \pmod 6$ 推出的 $5 \equiv 1\pmod 6$ 是错误的，要想 $ac \equiv bc \pmod d$ 约去 $c$，必须满足 $\gcd(c, d) = 1$，更一般的，如果 $ac \equiv bc \pmod d$ 那么 $a \equiv b \pmod{\frac{d}{\gcd(c, d)}}$
- 很多算法要求 $d = \gcd(a, p) | c$（比如裴蜀定理），否则无解，即判断 `c % d != 0`，实际上，很多题目也会给出 $p$ 是质数。
  - 当 $p \nmid a$ 时，$d$ 等于 $1$ 显然有解
  - 当 $p \mid a$ 时，则 $d = p$，当 $p \mid c$ 时，有解，否则无解
  - 综上可得无解的特判条件是 `a % p == 0 && c % p != 0`
- 弃九法：一个 $x$ 进制数 $n$，其与其各位数之和 $s$ 在模 $x - 1$ 的意义下同余，即  $n \equiv s\pmod{x-1}$
- $\gcd(a, b) = \gcd(a + kb, b)$
  - 假如 $b = la$，那么	 $\gcd(a, b) = \gcd(a + b, b) = \cdots = \gcd(a + (l - 1)b, b)$



### 除法同余

若 $ab\equiv1\pmod m$，则 $b$ 是 $a$ 模 $m$ 的乘法逆元；它存在当且仅当 $\gcd(a,m)=1$。模意义下的除以 $a$ 需改为乘 $a^{-1}$。

#### 快速幂求法

当 $m$ 为质数且 $m\nmid a$ 时，由费马小定理得 $a^{-1}\equiv a^{m-2}\pmod m$。

- **时间复杂度**：$O(\log m)$
- **空间复杂度**：$O(1)$

```cpp
int inv(int a, int m) {
    return pow(a, m - 2, m);
}
```

#### 扩展欧几里得求法

扩展欧几里得法不要求 $m$ 为质数，但仍需 $\gcd(a,m)=1$。时间与递归栈空间均为 $O(\log m)$。

#### 线性递推求法

预处理 $1\sim n$ 的逆元，要求 $m$ 为质数且 $n<m$。

- **时间复杂度**：预处理 $O(n)$，单次查询 $O(1)$
- **空间复杂度**：$O(n)$

```cpp
void build_inv(int n, int m) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (ll)(m - m / i) * inv[m % i] % m;
}
```

阶乘及逆阶乘也可在 $O(n)$ 时间、$O(n)$ 空间内预处理，之后 $O(1)$ 求组合数。

```cpp
void build(int n, int m) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = 1LL * fac[i - 1] * i % m;
    inv_f[n] = qpow(fac[n], m - 2, m);
    for (int i = n - 1; i >= 0; i--)
        inv_f[i] = 1LL * inv_f[i + 1] * (i + 1) % m;
}

ll C(int n, int m) {
    if (n < m || m < 0) return 0;
    return 1LL * fac[n] * inv_f[m] % MOD * inv_f[n - m] % MOD;
}
```


### 中国剩余定理

对两两互质的模数，令 $M=\prod m_i$、$c_i=M/m_i$，则

$$
x\equiv\sum_{i=1}^n r_i c_i c_i^{-1}\pmod M,
$$

其中 $c_i^{-1}$ 是 $c_i$ 模 $m_i$ 的逆元。

- **时间复杂度**：$O(n\log M)$
- **空间复杂度**：$O(n)$ 用于存储方程组，额外空间 $O(\log M)$

```cpp
int n;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll crt(ll m[], ll r[]) {
    ll M = 1, ans = 0;
    for (int i = 1; i <= n; i++)
        M *= m[i];
    for (int i = 1; i <= n; i++) {
        ll c = M / m[i], x, y;
        exgcd(c, m[i], x, y);
        ans = (ans + r[i] * c * x % M) % M;
    }
    return (ans % M + M) % M;
}
```

### 扩展中国剩余定理

模数不互质时逐个合并方程。合并 $x\equiv r_1\pmod{m_1}$ 与 $x\equiv r_2\pmod{m_2}$ 等价于求解

$$
k_1m_1-k_2m_2=r_2-r_1.
$$

若 $\gcd(m_1,m_2)\nmid(r_2-r_1)$ 则无解；否则新模数为 $\operatorname{lcm}(m_1,m_2)$。

- **时间复杂度**：$O(n\log M)$
- **空间复杂度**：$O(n)$ 用于存储方程组，额外空间 $O(\log M)$

```cpp
ll excrt(ll m[], ll r[]) {
    ll m1 = m[1], r1 = r[1], k1, k2;
    for (int i = 2; i <= n; i++) {
        ll m2 = m[i], r2 = r[i];
        ll d = exgcd(m1, m2, k1, k2);
        if ((r2 - r1) % d != 0) return -1;
        k1 = k1 * ((r2 - r1) / d);
        k1 = (k1 % (m2 / d) + m2 / d) % (m2 / d);
        r1 = k1 * m1 + r1;
        m1 = m1 * (m2 / d);
    }
    return (r1 % m1 + m1) % m1;
}
```

累积模数和余数可能溢出 `long long`，乘法中间值视范围使用 `__int128`。

### 卢卡斯定理

对质数 $p$，Lucas 定理将大组合数按 $p$ 进制逐位拆分：

$$
\binom nm\equiv\binom{n\bmod p}{m\bmod p}\binom{\lfloor n/p\rfloor}{\lfloor m/p\rfloor}\pmod p.
$$

- **时间复杂度**：预处理 $O(p)$，单次查询 $O(\log_p n)$
- **空间复杂度**：$O(p)$

```cpp
typedef long long ll;

const int MAXP = 100005;
ll fac[MAXP], inv[MAXP];

ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    a %= p;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void init(ll p) {
    fac[0] = 1;
    for (int i = 1; i < p; i++)
        fac[i] = fac[i - 1] * i % p;
    // 费马小定理求 (p-1)! 的逆元
    inv[p - 1] = qpow(fac[p - 1], p - 2, p);
    // 递推求其他逆元
    for (int i = p - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % p;
}

ll C(ll n, ll m, ll p) {
    if (m < 0 || m > n) return 0;
    return fac[n] * inv[m] % p * inv[n - m] % p;
}

ll Lucas(ll n, ll m, ll p) {
    if (m == 0) return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
```

### 扩展卢卡斯定理

将合数模数 $M$ 分解为互质的质数幂，分别计算组合数后用 CRT 合并。

- **时间复杂度**：$O(\sqrt M+\sum p_i^{q_i}\log_{p_i}n)$
- **空间复杂度**：$O(\log n+\omega(M))$

```cpp
typedef long long ll;

ll qpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

ll get_inv(ll a, ll m) {
    ll x, y;
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}

ll fac(ll n, ll p, ll pk) {
    if (!n) return 1;
    ll res = 1;
    for (ll i = 1; i <= pk; i++) {
        if (i % p) res = res * i % pk;
    }
    res = qpow(res, n / pk, pk);
    for (ll i = 1; i <= n % pk; i++) {
        if (i % p) res = res * i % pk;
    }
    return res * fac(n / p, p, pk) % pk;
}

ll C_pk(ll n, ll m, ll p, ll pk) {
    if (m < 0 || m > n) return 0;
    ll k = 0;
    // 统计分子分母中质因子 p 的总指数差
    for (ll i = n; i; i /= p)
        k += i / p;
    for (ll i = m; i; i /= p)
        k -= i / p;
    for (ll i = n - m; i; i /= p)
        k -= i / p;

    ll a = fac(n, p, pk);
    ll b = fac(m, p, pk);
    ll c = fac(n - m, p, pk);

    return a * get_inv(b, pk) % pk * get_inv(c, pk) % pk * qpow(p, k, pk) % pk;
}

ll a[100], mod[100], cnt;
ll CRT() {
    ll M = 1, ans = 0;
    for (int i = 1; i <= cnt; i++)
        M *= mod[i];
    for (int i = 1; i <= cnt; i++) {
        ll m = M / mod[i];
        ans = (ans + a[i] * m % M * get_inv(m, mod[i]) % M) % M;
    }
    return (ans + M) % M;
}

// 扩展卢卡斯主函数
ll exLucas(ll n, ll m, ll M) {
    cnt = 0;
    ll temp = M;
    for (ll i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            ll pk = 1;
            while (temp % i == 0)
                pk *= i, temp /= i;
            mod[++cnt] = pk;
            a[cnt] = C_pk(n, m, i, pk);
        }
    }
    if (temp > 1) {
        mod[++cnt] = temp;
        a[cnt] = C_pk(n, m, temp, temp);
    }
    return CRT();
}
```



### 威尔逊定理

> [!important]
>
> **威尔逊定理**：若 $p$ 为素数，则 $p$ 可以整除 $(p - 1)! + 1$，表示为
>
> - $((p - 1)! + 1) \mod{p} = 0$
> - $(p - 1)! \equiv p -1 \pmod p$
>
> 若 $n$ 为合数，则必有存在于 $2$ 到 $n - 1$ 之间的两个数的积为 $n$，因此 $(n - 1)! \mod{n} = 0$



## 欧拉函数

> [!note]
>
> 欧拉函数 $\phi(n)$ 表示不超过 $n$ 且与 $n$ 互质的整数的个数，即
> $$
> \phi(n) = \sum_{i = 1}^{n} [\gcd(n, i) = 1]
> $$
>
> > [!important]
> >
> > 欧拉函数是积性函数，即当 $\gcd(m, n) = 1$ 时，有 $\phi(mn) = \phi(m)\phi(n)$
>
> 性质：
>
> - $\sum_{d\mid n}\phi(d) = n$
> - $\phi(n) = \sum_{d \mid n}\mu(d)\frac{n}{d}$
> - $\sum_{i=1}^{n}i[\gcd(i, n)=1] = \frac{1}{2}n\phi(n),(n > 1)$

### 求单个数的欧拉函数

利用唯一分解定理：$\phi(n)=n\prod_{p\mid n}(1-1/p)$。

- **时间复杂度**：$O(\sqrt{n})$
- **空间复杂度**：$O(1)$

```cpp
int euler(int n) {
    int ans = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            ans = ans / p * (p - 1);
            while (n % p == 0)
                n /= p;
        }
    }
    if (n != 1) ans = ans / n * (n - 1);
    return ans;
}
```

### 求 $[1, n]$ 上的欧拉函数

- **时间复杂度**：$O(n)$
- **空间复杂度**：$O(n)$

主要用到欧拉函数的下面几个性质

- 如果 $n$ 是质数，那么 $\phi(n)= n - 1$
- 欧拉筛保证了 `primes[j]` 是最小因子，设为 $a$
  - 当 $\text{primes}[j] \mid i$ 时，$i$ 包含了 $i \times \text{primes}[j]$ 的所有因子，因此 $\phi(i \times \text{primes}[j]) = \phi(i)\times \text{primes}[j]$
  - 当 $\text{primes}[j] \nmid i$ 时，则 $\text{primes}[j]$ 和 $i$ 互质，因此 $\phi(i\times \text{primes}[j]) = \phi(i) \times \phi(\text{primes}[j])$

```cpp
const int N = 1e5 + 10;
bool vis[N];
int primes[N], cnt;
int phi[N];

void get_phi(int n) {
    vis[0] = vis[1] = true;
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            primes[++cnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++) // 注意这里 i * p[j] 可能溢出
        {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
}
```

### 求 $[L, R]$ 上的欧拉函数

- **时间复杂度**：区间筛的复杂度，$O(\sqrt{R} + (R-L + 1)\log\log\sqrt{R})$
- **空间复杂度**：$O(\sqrt R+R-L+1)$

先筛出 $[1,\sqrt R]$ 内的质数，再逐个更新它们对 $[L,R]$ 中数的贡献；最后处理大于 $\sqrt R$ 的剩余质因子。

```cpp
const int N = 1e6 + 10;
const int MOD = 666623333;
ll l, r;
bool vis[N];
int primes[N], cnt;
ll phi[N], rem[N];

void euler(int n) {
    vis[0] = vis[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) primes[++cnt] = i;
        for (int j = 1; j <= cnt && (ll)i * primes[j] <= n; j++) {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void get_phi() {
    // 初始化 phi[i - l] = i，即公式中的 n
    for (ll i = l; i <= r; i++)
        phi[i - l] = rem[i - l] = i;
    for (int i = 1; i <= cnt; i++) {
        ll p = primes[i];
        if (p * p > r) break;
        ll start = max(p * p, (l + p - 1) / p * p);
        for (ll j = start; j <= r; j += p) {
            phi[j - l] = phi[j - l] / p * (p - 1);
            while (rem[j - l] % p == 0)
                rem[j - l] /= p;
        }
    }
    for (ll i = l; i <= r; i++) {
        if (rem[i - l] > 1) phi[i - l] = phi[i - l] / rem[i - l] * (rem[i - l] - 1);
    }
}
```

### 欧拉定理

> [!important]
>
> **费马小定理**：设 $p$ 是素数，对于任意的 $a$ 且 $p \nmid a$，都成立 $a^{p-1} \equiv 1 \pmod p$，若并非所有的 $a$ 满足 $p \nmid a$，则仍有 $a^{p} \equiv a \pmod p$ 成立
>
> **欧拉定理**：对于整数 $m > 0$ 和整数 $a$，且 $\gcd(a, m) = 1$，有 $a^{\varphi(m)}\equiv 1\pmod m$，即每 $\varphi(m)$ 次方模 $m$ 都是 $1$，因此 $a^b \equiv a^{b \mod \varphi(m)} \pmod m$
>
> - 只有当 $\gcd(a, m) = 1$ 时，方程 $a^{x}\equiv 1\pmod {m}$ 才有解（否则 $a$ 必须是 $m$ 的倍数，但这就需要 $b = 0$）
> - $\varphi(m)$ 并不是 $x$ 的最小整数解，符合条件最小整数解是 $\varphi(m)$ 的因数（最小整数解的倍数都是解）
>
> **扩展欧拉定理**：
> $$
> a^{b} = \begin{cases}
> a^b,  & b < \varphi(m)\\
> a^{b \mod \varphi(m) + \varphi(m)}, & b \geq \varphi(m)
> \end{cases}
> \pmod  m
> $$

欧拉定理的应用可以参考前文数学章节的大指数取模

#### 卡迈克尔函数

> [!important]
>
> 卡迈克尔函数：定义卡迈克尔函数 $\lambda(m)$ 表示使得所有与 $m$ 互质的 $a$ 都满足 $a^{n} \equiv 1\pmod{m}$ 的最小正整数 $n$
>
> 必有 $\lambda(m) \mid \varphi(m)$

### BSGS 算法

BSGS 求 $a^x\equiv b\pmod p$ 的最小非负解，要求 $\gcd(a,p)=1$。取 $t=\lceil\sqrt p\rceil$、$x=At-B$，将 $ba^B$ 存入哈希表，再枚举 $a^{At}$ 匹配。

- **时间复杂度**：期望 $O(\sqrt p)$
- **空间复杂度**：$O(\sqrt p)$

```cpp
ll qpow(ll a, ll n, ll p) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ret;
}

int bsgs(ll a, ll b, ll p) {
    a %= p;
    b %= p;
    if (b == 1 || p == 1) return 0;
    if (a == 0) return (b == 0) ? 1 : -1;
    unordered_map<ll, ll> mp;
    int k = sqrt(p) + 1;
    for (ll B = 0, val = b; B < k; B++) {
        mp[val] = B;
        val = val * a % p;
    }
    ll ak = qpow(a, k, p);
    for (ll A = 1, val = ak; A <= k; A++) {
        if (mp.count(val)) return A * k - mp[val];
        val = val * ak % p;
    }
    return -1;
}
```

若题目要求最小正解，需单独处理答案 $x=0$ 及模数 $p=1$。

### 扩展 BSGS 算法

exBSGS 先反复取 $d=\gcd(a,p)$ 并约去公因子；若 $d\nmid b$ 则无解。当 $a$ 与新模数互质后，再执行 BSGS。

- **时间复杂度**：期望 $O(\sqrt p+\log p)$
- **空间复杂度**：$O(\sqrt p)$

```cpp
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    a %= p;
    while (b > 0) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll exbsgs(ll a, ll b, ll p) {
    a %= p;
    b %= p;
    if (b == 1 || p == 1) return 0;
    if (a == 0) return b == 0 ? 1 : -1;
    int d = gcd(a, p);
    ll k = 1, cnt = 0;
    while (d > 1) {
        if (b % d != 0) return -1;
        cnt++;
        b /= d;
        p /= d;
        k = k * (a / d) % p;
        if (k == b) return cnt;
        d = gcd(a, p);
    }
    ll m = sqrt(p) + 1;
    unordered_map<ll, ll> mp;
    for (ll B = 0, val = b; B < m; B++) {
        mp[val] = B;
        val = val * a % p;
    }
    int am = qpow(a, m, p);
    for (ll A = 1, val = am * k % p; A <= m; A++) {
        if (mp.count(val)) return A * m - mp[val] + cnt;
        val = val * am % p;
    }
    return -1;
}
```

竞赛环境中可使用自定义哈希函数降低被构造数据攻击的风险：

```cpp
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
```

并预留空间以减少 rehash：

```cpp
unordered_map<ll, ll, custom_hash> mp;
mp.reserve(m);
```



### 一些题

[**2026 ICPC Shenzhen Invitational Contest**](https://qoj.ac/contest/3588/problem/17763)

> 令 $f(n, k)$ 表示满足 $k(a + b) \equiv ab\pmod n$ 的整数对 $(a, b)$ 的数量（$0\leq a, b < n$）
>
> 给定 $n$ 和 $m$，求 $\sum_{k = 0}^{m}f(n, k)$
>
> $n\leq10^{14},m < n$

整理同余式
$$
ab - ka - kb + k^2 \equiv k^2\pmod n\\
(a - k)(b - k) \equiv k^2\pmod n
$$
令 $x = a - k, y = b - k$，则 $xy\equiv k ^ 2\pmod n$，那么就是找满足该同余式的 $(x, y)$ 数对的数量，其中 $x, y$ 在 $\mathrm{mod}\space n$ 意义下的范围为 $0\leq x, y < n$（模 $n$ 的剩余系）

如果固定 $x$，那么这就是一个关于 $y$ 的一阶线性同余方程，其有解的充要条件是 $\gcd(x, n) \mid k^2$，且一旦其有解，那么解的数量（$y\in [0, n)$ ）为 $\gcd(x, n)$

那么暴力解法可以考虑枚举 $x$，因为 $f(n, k) = \sum_{x = 0}^{n - 1}[\gcd(x, n) \mid k^2]\cdot\gcd(x, n)$

但是考虑到 $n$ 最大可以取到 $1\mathrm{e}14$，因此考虑枚举 $d = \gcd(x, n)$

考虑满足 $d = \gcd(x, n)$ 的 $x$ 的个数，将这个式子变形得 $\gcd\left(\frac{x}{d}, \frac{n}{d}\right) = 1$，又 $d \mid x$，因此 $1\leq\frac{x}{d}<\frac{n}{d}$，因此解的个数为 $\phi(\frac{n}{d})$

再考虑对于每一个 $k$，有多少 $d$ 能使得 $d \mid k^2$ 成立，将 $d$ 质因数分解得到 $d = p_1^{t_1}p_2^{t_2}\cdots p_a^{t_a}$，由于 $k^2$ 是 $d$ 的倍数，那么对于 $d$ 的每一个因数 $p_{l}^{t_l}$，$k$ 一定有一个因数 $p_{l}^{\lceil\frac{t_l}{2}\rceil}$，因此 $k$ 最小为 $r(d) = p_1^{\lceil t_1/2 \rceil}p_2^{\lceil t_2/2 \rceil}\cdots p_a^{\lceil t_a/2 \rceil}$，那么 $k$ 的个数为 $\lfloor \frac{m}{r(d)} \rfloor + 1$（$1$ 是 $k = 0$ 的情况

再算上每个 $x$ 都有 $d$ 个 $y$，因此结果为 $\sum_{d \mid n}d\cdot\phi(\frac{n}{d})\cdot\left(\lfloor \frac{m}{r(d)} \rfloor + 1\right)$

- **时间复杂度**：$O(\sqrt n+\tau(n)\log n)$
- **空间复杂度**：$O(\omega(n))$ 递归栈与质因子表

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, int>> factors;

    // 质因数分解
    for (int i = 2; (ll)i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            factors.push_back({i, cnt});
        }
    }
    if (n > 1) factors.push_back({n, 1});

    int sz = factors.size();
    ll ans = 0;

    // dfs 枚举 n 所有的约数 d
    function<void(int, ll, ll, ll)> dfs = [&](int step, ll d, ll phi, ll r) {
        if (step == sz) {
            ll term1 = (d * phi) % MOD;
            ll term2 = (m / r + 1) % MOD;
            ans = (ans + term1 * term2 % MOD) % MOD;
            return;
        }

        ll p = factors[step].first;
        int k = factors[step].second;

        ll p_pow_d = 1;
        ll p_pow_r = 1;

        for (int i = 0; i <= k; i++) {
            // 计算对 phi 的贡献
            ll phi_p = 1;
            if (i == k)
                phi_p = 1;
            else {
                phi_p = p - 1;
                for (int j = 1; j <= k - i - 1; j++)
                    phi_p = ((phi_p % MOD) * (p % MOD)) % MOD;
            }

            dfs(step + 1, d * p_pow_d % MOD, phi * phi_p % MOD, r * p_pow_r);

            p_pow_d = (p_pow_d % MOD) * (p % MOD) % MOD;
            if ((i & 1) == 0) p_pow_r *= p;
        }
    };
    dfs(0, 1, 1, 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
```

#### Luogu P1891 疯狂 LCM

> 给定 $t$ 组数据，每组一个 $n$，求
> $$
> \sum_{i=1}^{n}\mathrm{lcm}(i, n)
> $$

做如下变换
$$
\begin{align}
 = & \sum_{i=1}^{n}\frac{in}{\gcd(i, n)} = n\sum_{i=1}^{n}\frac{i}{\gcd(i, n)}\\
 = & n\sum_{i=1}^{n}\sum_{d \mid n}\frac{i}{d}[\gcd(i, n) = d]\\
 = & n\sum_{d \mid n}\sum_{i=1}^{n}\frac{i}{d}[\gcd(i, n) = d]\\
 = & n\sum_{d \mid n}\sum_{i=1}^{n}\frac{i}{d}\left[\gcd\left(\frac{i}{d}, \frac{n}{d}\right) = 1\right]\\
 = & n\sum_{d \mid n}\sum_{i=1}^{\frac{n}{d}}i\left[\gcd\left(i, \frac{n}{d}\right) = 1\right] & (i \leftarrow di) \\
 = & n\sum_{d \mid n}\sum_{i=1}^{d}i\left[\gcd\left(i, d\right) = 1\right]\\
 = & n \times \begin{cases} \sum_{d \mid n}\frac{\phi(d)}{2}d, & d \neq 1
 \\ 1, & d = 1 \end{cases}
\end{align}
$$

最后一步如果考虑莫比乌斯反演得到
$$
\begin{align}
= & n\sum_{d \mid n}\sum_{i=1}^{d}i\sum_{f \mid \gcd(i, d)}\mu(f)\\
= & n\sum_{d \mid n}\sum_{f \mid d}\mu(f)\sum_{i=1}^{d}i[f \mid i]\\
= & n\sum_{d \mid n}\sum_{f \mid d}\mu(f)f\sum_{i=1}^{\frac{d}{f}}i & \text(i \leftarrow fi)\\
= & n\sum_{d \mid n}\sum_{f \mid d}\mu(f)\frac{d\left(1 + \frac{d}{f}\right)}{2}\\
= & n\sum_{d \mid n}\frac{d}{2}\left(\sum_{f \mid d}\mu(f) + \sum_{f \mid d}\mu(f)\frac{d}{f}\right)\\
= & n\sum_{d \mid n}\frac{d}{2}(\varepsilon(d) + \phi(d))
\end{align}
$$
代码如下。

- **时间复杂度**：预处理 $O(N\log N)$，单次查询 $O(1)$
- **空间复杂度**：$O(N)$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

bool vis[N];
int p[N], cnt, phi[N];
ll ans[N];

void euler(int n) {
    vis[0] = vis[1] = true;
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            p[++cnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) {
                phi[i * p[j]] = p[j] * phi[i];
                break;
            }
            phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << n * ans[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    euler(N - 1);
    for (int i = 1; i <= N - 1; i++)
        ans[i] = 1;
    for (int d = 2; d <= N - 1; d++)
        for (int a = d; a <= N - 1; a += d)
            ans[a] += (ll)d * phi[d] / 2;
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
```

#### Luogu P1829 Crash 的数字表格

> 求 $\sum_{i=1}^{n}\sum_{j=1}^{m}\mathrm{lcm}(i, j)$

变换得到
$$
\begin{align}
 & = \sum_{i=1}^{n}\sum_{j=1}^{m}\frac{i \times j}{\gcd(i, j)}\\
 & = \sum_{d = 1}^{\min(n, m)}\sum_{i=1}^{n}\sum_{j=1}^{m}\frac{i\times j}{d}[\gcd(i, j) = d]\\
 & = \sum_{d = 1}^{\min(n, m)}d\sum_{i=1}^{\lfloor \frac{n}{d} \rfloor}\sum_{j=1}^{\lfloor \frac{m}{d} \rfloor} i \times j [\gcd(i, j)=1]\\
 & = \sum_{d = 1}^{\min(n, m)}d\sum_{i=1}^{\lfloor \frac{n}{d} \rfloor}\sum_{j=1}^{\lfloor \frac{m}{d} \rfloor} i \times j \sum_{g \mid \gcd(i, j)}\mu(g)\\
 & = \sum_{d = 1}^{\min(n, m)}d\sum_{g = 1}^{ \min(\lfloor \frac{n}{d} \rfloor, \lfloor \frac{m}{d} \rfloor)}\mu(g)\sum_{i=1}^{\lfloor \frac{n}{d} \rfloor}\sum_{j=1}^{\lfloor \frac{m}{d} \rfloor} ij[g \mid i][g \mid j]
\end{align}
$$
令 $x = ig$，$y = jg$，则
$$
\begin{align}
 & = \sum_{d = 1}^{\min(n, m)}d\sum_{g = 1}^{ \min(\lfloor \frac{n}{d} \rfloor, \lfloor \frac{m}{d} \rfloor)}\mu(g)\sum_{x=1}^{\lfloor \frac{n}{gd} \rfloor}\sum_{y=1}^{\lfloor \frac{m}{gd} \rfloor} xyg^2\\
 & = \sum_{d = 1}^{\min(n, m)}\sum_{g = 1}^{ \min(\lfloor \frac{n}{d} \rfloor, \lfloor \frac{m}{d} \rfloor)}\mu(g)dg^2\sum_{x=1}^{\lfloor \frac{n}{gd} \rfloor}x\sum_{y=1}^{\lfloor \frac{m}{gd} \rfloor}y
\end{align}
$$
求和区域为 $\{(d, g \mid 1\leq d \leq \min(n, m), 1 \leq g \leq  \min(\lfloor \frac{n}{d} \rfloor, \lfloor \frac{m}{d} \rfloor)\}$，令 $T = gd$，则 $1 \leq T \leq \min(n, m)$，则新的遍历区域可为 $\{(T, g) \mid 1 \leq T \leq \min(n, m), g \mid T\}$，则
$$
\begin{align}
 & = \sum_{T=1}^{\min(n, m)}T\sum_{g \mid T}\mu(g)g\sum_{x=1}^{\lfloor \frac{n}{T} \rfloor}x\sum_{y=1}^{\lfloor \frac{m}{T} \rfloor}y
\end{align}
$$
令 $F(T) = T\sum_{g \mid T}\mu(g)g$，$S(n)=\sum_{x=1}^{n}x$，则
$$
\text{Ans} = \sum_{T=1}^{\min(n, m)} F(T)\cdot S\left(\left\lfloor \frac{n}{T} \right\rfloor\right)\cdot S\left(\left\lfloor \frac{m}{T} \right\rfloor\right)
$$
其中 $F$ 可线性筛预处理，$S(x)=x(x+1)/2$。

- **时间复杂度**：预处理 $O(K)$，单次求和 $O(\sqrt n+\sqrt m)$
- **空间复杂度**：$O(K)$，$K=\min(n,m)$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7 + 10;
const int MOD = 20101009;

bool vis[N];
int p[N], cnt;
ll f[N], F[N];

void euler(int n) {
    vis[0] = vis[1] = true;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            p[++cnt] = i;
            f[i] = ((1 - i) % MOD + MOD) % MOD;
        }
        for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) {
                f[i * p[j]] = f[i];
                break;
            }
            f[i * p[j]] = (f[i] * f[p[j]]) % MOD;
        }
    }
    F[0] = 0;
    // 注意这里是 i * f[i]
    for (int i = 1; i <= n; i++)
        F[i] = (F[i - 1] + i * f[i] % MOD) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int limit = min(n, m);
    euler(limit);
    ll ans = 0;
    for (int l = 1, r; l <= limit; l = r + 1) {
        int k1 = n / l, k2 = m / l;
        r = min({n / k1, m / k2, limit});
        ll t1 = ((F[r] - F[l - 1]) % MOD + MOD) % MOD;
        ll t2 = (ll)(1 + k1) * k1 / 2 % MOD;
        ll t3 = (ll)(1 + k2) * k2 / 2 % MOD;
        ans = (ans % MOD + (t1 * t2 % MOD * t3) % MOD) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
```



## 数论分块

对固定左端点 $l$，$\lfloor n/i\rfloor$ 在 $i\in[l,\lfloor n/\lfloor n/l\rfloor\rfloor]$ 上不变，因此只有 $O(\sqrt n)$ 个值段。

### 和式变换技术

- 替换条件式

$$
\sum_{i = 1}^n\sum_{j = 1}^{m}\sum_{d \mid \gcd(i, j)}d = \sum_{i = 1}^n\sum_{j = 1}^{m}\sum_{d = 1}^{\min(n, m)}[d\mid i][d \mid j]d
$$

- 替换指标变量

$$
\sum_{i = 1}^n\sum_{j = 1}^{m}[\gcd(i, j) = k] = \sum_{i = 1}^{\lfloor \frac{n}{k} \rfloor}\sum_{j = 1}^{\lfloor \frac{m}{k} \rfloor}[\gcd(i, j) = 1]
$$

- 交换求和次序

$$
\sum_{i = 1}^n\sum_{j = 1}^{m}A(i)B(j) = \sum_{j= 1}^n\sum_{i= 1}^{m}A(i)B(j)
$$

- 分离变量

$$
\sum_{i = 1}^n\sum_{j = 1}^{m}A(i)B(j) = \sum_{i = 1}^nA(i)\sum_{j = 1}^nB(j)
$$

### 一些例子

【例1】求 $\sum_{i=1}^n\lfloor\frac{n}{i}\rfloor$

- **时间复杂度**：$O(\sqrt n)$
- **空间复杂度**：$O(1)$

```cpp
ll solve(int n) {
    ll ans = 0;
    for (int l = 1, r, k; l <= n; l = r + 1) {
        k = n / l;
        // 非必要但要知道
        if (k == 0)
            r = n;
        else
            r = min(n, n / k);
        ans += (r - l + 1) * k;
    }
    return ans;
}
```

【例2】求 $\sum_{i=1}^n\lfloor \frac{n}{i} \rfloor\lfloor \frac{m}{i} \rfloor$

- **时间复杂度**：$O(\sqrt n+\sqrt m)$
- **空间复杂度**：$O(1)$

```cpp
ll solve(int n, int m) {
    ll ans = 0;
    int limit = min(n, m);
    // 当 i 大于 R 时，其中必有一项计算结果为 0
    for (int l = 1, r; l <= limit; l = r + 1) {
        int k1 = n / l, k2 = m / l;
        r = min({n / k1, m / k2, limit});
        ans += (n / l) * (m / l) * (r - l + 1);
    }
    return ans;
}
```

【例3】求 $\sum_{i=1}^nf(i)\lfloor \frac{n}{i} \rfloor\lfloor \frac{m}{i} \rfloor$

- **时间复杂度**：已有前缀和时 $O(\sqrt n+\sqrt m)$
- **空间复杂度**：$O(1)$ 额外空间

```cpp
ll solve(int n, int m, vector<int>& sum) {
    ll ans = 0;
    int limit = min(n, m);
    for (int l = 1, r; l <= limit; l = r + 1) {
        int k1 = n / l, k2 = m / l;
        r = min({n / k1, m / k2, limit});
        ans += 1LL * (n / l) * (m / l) * (sum[r] - sum[l - 1]);
    }
    return ans;
}
```

这里的 `sum` 是 $f(x)$ 的前缀和数组

【例4】求 $\sum_{i=1}^n\sum_{j=1}^m[\gcd(i, j)=1]$

利用单位元的定义和狄利克雷卷积的性质可得 $\sum_{d \mid \gcd(i, j)}\mu(d) = \varepsilon(\gcd(i, j)) = [\gcd(i, j) = 1]$，因此原式等于 $\sum_{i=1}^n\sum_{j=1}^m\sum_{d \mid \gcd(i, j)}\mu(d)$

交换求和次序：考虑遍历所有的 $d$，对于每一个 $\mu(d)$，都有 $\sum_{i\mid d}\sum_{j\mid d}1$ 个，即 $\lfloor \frac{n}{d} \rfloor \lfloor \frac{m}{d} \rfloor$ 个，又 $d\mid \gcd(i, j)$，因此 $d \leq \min(n, m)$，因此原式可化为
$$
\sum_{d = 1}^{\min(n, m)}\mu(d)\left\lfloor \frac{n}{d} \right\rfloor \left\lfloor \frac{m}{d} \right\rfloor
$$
这个和例3的求法是一样的

【例5】求 $\sum_{p\in\text{prime}}\sum_{i=1}^{n}\sum_{j=1}^{n}[\gcd(i, j) = p]$

做如下变换
$$
\begin{align}
 & \sum_{p\in\text{prime}}\sum_{i=1}^{\lfloor \frac{n}{p} \rfloor}\sum_{j=1}^{\lfloor \frac{n}{p} \rfloor}[\gcd(i, j) = 1]\\
= &  \sum_{p\in\text{prime}}\sum_{i=1}^{\lfloor \frac{n}{p} \rfloor}\sum_{j=1}^{\lfloor \frac{n}{p} \rfloor}\sum_{d \mid \gcd(i, j)}\mu(d)\\
= & \sum_{p\in\text{prime}}\sum_{i=1}^{\lfloor \frac{n}{p} \rfloor}\sum_{j=1}^{\lfloor \frac{n}{p} \rfloor}\sum_{d = 1}^{\lfloor \frac{n}{p} \rfloor}[d\mid i][d \mid j]\mu(d)\\
= & \sum_{p \in \text{prime}}\sum_{d = 1}^{\lfloor \frac{n}{p} \rfloor}\mu(d)\sum_{i=1}^{\lfloor \frac{n}{p} \rfloor} [d \mid i]\sum_{j=1}^{\lfloor \frac{n}{p} \rfloor} [d \mid j]\\
= & \sum_{p \in \text{prime}}\sum_{d = 1}^{\lfloor \frac{n}{p} \rfloor}\mu(d)\left\lfloor \frac{n}{pd} \right\rfloor\left\lfloor \frac{n}{pd} \right\rfloor
\end{align}
$$
令 $T = pd$，则 $d = \frac{T}{p}$，则
$$
\begin{align}
= & \sum_{p \in \text{prime}}\sum_{\frac{T}{p} = 1}^{\lfloor \frac{n}{p} \rfloor}\mu\left(\frac{T}{p}\right)\left\lfloor \frac{n}{T} \right\rfloor^2\\
= & \sum_{p\in\text{prime}}\sum_{T=1}^{n}\mu\left(\frac{T}{p}\right)\left\lfloor \frac{n}{T} \right\rfloor^2 & \text{*}\\
= & \sum_{T=1}^{n}\sum_{p\in\text{prime}}\mu\left(\frac{T}{p}\right)\left\lfloor \frac{n}{T} \right\rfloor^2
\end{align}
$$
令 $F(T) = \sum_{p\in\text{prime}}\mu\left(\frac{T}{p}\right)$，则原式等于
$$
\sum_{T=1}^{n}F(T)\left\lfloor \frac{n}{T} \right\rfloor^2
$$
接下来整除分块即可

> [!note]
>
> 上面推导过程中，$\text{*}$  式上限本应为 $p \lfloor \frac{n}{p}\rfloor$，这里将上限提升至 $n$，是因为对于任意的 $p \lfloor \frac{n}{p}\rfloor < T \leq n$，$p \nmid T$，那么 $\mu(\frac{T}{p}) = 0$，因此这样的提升是合理的



## 莫比乌斯反演

### 狄利克雷卷积

> [!note]
>
> 狄利克雷卷积
> $$
> (f * g)(n) = \sum_{d \mid n}f(d)g\left(\frac{n}{d}\right)
> $$
> 并且定义
>
> - $1(n) = 1$
> - $\varepsilon(n) = [n = 1]$
> - $I(n) = n$

狄利克雷卷积满足下面的性质

- 交换律：$f*g = g * f$
- 结合律：$(f * g) * h = f * (g * h)$
- 分配律：$f * (g + h) = f * g + f * h$
- $\varepsilon * f = f$
- $f * 1 = \sum_{d \mid n} f(d)$
- $I * 1 = \sigma$
- 两个积性函数的狄利克雷卷积仍是积性函数

### 莫比乌斯函数

> [!important]
>
> 莫比乌斯函数 $\mu(n)$ 的定义如下
> $$
> \mu(n) =
> \begin{cases}
> 1 & n = 1\\
> (-1)^k & n \text{是} k \text{个互不相同的质数的积}\\
> 0 & \text{other}
> \end{cases}
> $$
> 莫比乌斯函数的一个性质如下
> $$
> (\mu * 1)(n) = \sum_{d \mid n}\mu(d) = \varepsilon(n) = [n = 1]
> $$
> 类似的有（以下三个知二推一）
>
> - $\mu * 1 = \varepsilon$
> - $\phi * 1 = I$
> - $\mu * I = \phi$

一些莫比乌斯函数的值

|   $n$    |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |  10   |  11   |  12   |
| :------: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| $\mu(n)$ |   1   |  -1   |  -1   |   0   |  -1   |   1   |  -1   |   0   |   0   |   1   |  -1   |   0   |

### 线性筛求莫比乌斯函数

- **时间复杂度**：$O(n)$
- **空间复杂度**：$O(n)$

```cpp
const int N = 1e5 + 10;
bool vis[N];
int primes[N], cnt;
int mu[N], mup[N];

void mob(int n) {
    vis[0] = vis[1] = true;
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            primes[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++) {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                mu[i * primes[j]] = 0;
                break;
            }
            mu[i * primes[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++)
        mup[i] = mup[i - 1] + mu[i];
}
```

### 一些题

> 求 $\sum_{p\in\text{prime}}\sum_{i=1}^{n}\sum_{j=1}^{m}[\gcd(i, j) = p]$

公式推导参考数论分块部分，最后的化简结果为
$$
\sum_{j=1}^{n}f(j)\left\lfloor \frac{n}{j} \right\rfloor\left\lfloor \frac{m}{j} \right\rfloor
$$
其中 $f(j) = \sum_{p\in\text{prime}}\mu\left(\frac{j}{p}\right)$，这里给出代码（注意其中细节）

- **时间复杂度**：预处理 $O(N\log\log N)$，单次求和 $O(\sqrt n+\sqrt m)$
- **空间复杂度**：$O(N)$

```cpp
const int N = 1e7 + 10;
int p[N], cnt;
bool vis[N];
int mu[N], f[N];

void euler(int n) {
    vis[0] = vis[1] = true;
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            p[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) break;
            mu[i * p[j]] = -mu[i];
        }
    }
    // 不是遍历 n，而是遍历质数（内层遍历指数的倍数，计算当前质数对其倍数的贡献）
    for (int i = 1; i <= cnt; i++)
        for (int j = p[i]; j <= n; j += p[i])
            f[j] += mu[j / p[i]];
    for (int i = 1; i <= n; i++)
        f[i] += f[i - 1];
}

void solve() {
    int n, m;
    cin >> n >> m;
    int limit = min(n, m);
    ll ans = 0;
    for (int l = 1, r; l <= limit; l = r + 1) {
        r = min({limit, n / (n / l), m / (m / l)});
        ans += 1LL * (f[r] - f[l - 1]) * (n / l) * (m / l);
    }
    cout << ans << '\n';
}
```

#### Luogu P3911 最小公倍数之和

> 给定 $n$ 个数 $A_1, A_2, \cdots A_{n}$，求
> $$
> \sum_{i=1}^{n}\sum_{j=1}^{n}\mathrm{lcm}(A_i, A_j)
> $$

做如下变换
$$
\begin{align}
= & \sum_{i=1}^{n}\sum_{j=1}^{n}\frac{A_iA_j}{\gcd(A_{i}, A_{j})}\\
= & \sum_{i=1}^n\sum_{j=1}^{n}\sum_{d=1}^{\max(A_i)}\frac{A_iA_j}{d}[\gcd(A_i, A_j) = d]\\
= & \sum_{d=1}^{\max(A)}d\sum_{i=1}^n\frac{A_i}{d}\sum_{j=1}^{n}\frac{A_j}{d}\left[\gcd\left(\frac{A_i}{d}, \frac{A_j}{d}\right)=1\right]\\
= & \sum_{d=1}^{\max(A)}d\sum_{i=1}^n\frac{A_i}{d}\sum_{j=1}^{n}\frac{A_j}{d}\sum_{g \mid \gcd(\frac{A_i}{d}, \frac{A_j}{d})}\mu(g)\\
= & \sum_{d=1}^{\max(A)}d\sum_{i=1}^n\frac{A_i}{d}\sum_{j=1}^{n}\frac{A_j}{d}\sum_{g=1}^{\max(A)}\mu(g) \left[g \mid \frac{A_i}{d}\right]\left[g \mid \frac{A_j}{d}\right]\\
= & \sum_{d=1}^{\max(A)}d\sum_{g=1}^{\max(A)}\mu(g)\sum_{i=1}^n\frac{A_i}{d}\left[g \mid \frac{A_i}{d}\right]\sum_{j=1}^{n}\frac{A_j}{d}\left[g \mid \frac{A_j}{d}\right]\\
= & \sum_{d=1}^{\max(A)}d\sum_{g=1}^{\max(A)}\mu(g)\left(\sum_{i=1}^n\frac{A_i}{d}\left[g \mid \frac{A_i}{d}\right]\right)^2\\
= & \sum_{g=1}^{\max(A)}\sum_{d=1}^{\max(A)}d\mu(g)\left(\sum_{i=1}^n\frac{A_i}{d}\left[g \mid \frac{A_i}{d}\right]\right)^2\\
= & \sum_{T=1}^{\max(A)}T\sum_{g \mid T}g\mu(g)\left(\sum_{i=1}^{n}\frac{A_i}{T}[T \mid A_i]\right)^2
\end{align}
$$
令 $H(T) = \sum_{g \mid T}g\mu(g)$，由**积性函数与积性函数的乘积是积性函数，积性函数的的约数和是积性函数**可得，$H(T)$ 是积性函数，可以用欧拉筛预处理

- 若 $T \in \text{prime}$，$H(T) = \mu(1) + T\mu(T)=1-T$
- 若 $p \mid a,p\in\text{prime}$，$H(ap)=H(a)$，因为当 $g$ 存在偶数个相同质因数时 $\mu(g)=0$
- 若 $p \nmid a, p\in\text{prime}$，$H(ap)=H(a)H(p)=H(a)(1-p)$

令 $F(T) = \sum_{i=1}^{n}\frac{A_i}{T}[T \mid A_i]$，考虑用一个桶记录 $A_i$ 出现的次数，枚举 $T$ 对结果的贡献

则最后再枚举 $T$ 得到
$$
\mathrm{Ans} = \sum_{T=1}^{\max(A)}T\cdot H(T)\cdot F^2(T)
$$

- **时间复杂度**：$O(n+M\log M)$，$M=\max A_i$
- **空间复杂度**：$O(M)$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e4 + 10;

int p[N], cnt, c[N];
bool vis[N];
ll h[N], f[N];

void euler(int n) {
    vis[0] = vis[1] = true;
    h[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            p[++cnt] = i;
            h[i] = 1 - i;
        }
        for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) {
                h[i * p[j]] = h[i];
                break;
            }
            h[i * p[j]] = h[i] * (1 - p[j]);
        }
    }
}

void solve() {
    int mx = 0, a, n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        c[a]++;
        mx = max(mx, a);
    }
    euler(mx);
    for (int t = 1; t <= mx; t++)
        for (int j = 1; j * t <= mx; j++)
            f[t] += j * c[j * t];
    ll ans = 0;
    for (int i = 1; i <= mx; i++)
        ans += i * h[i] * f[i] * f[i];
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
```
