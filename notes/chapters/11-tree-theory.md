# 树论

## LCA

最近公共祖先是两点公共祖先中深度最大者。常用性质：

- $u$ 是 $v$ 的祖先当且仅当 $\operatorname{LCA}(u,v)=u$
- $d(u,v)=h(u)+h(v)-2h(\operatorname{LCA}(u,v))$
- $\operatorname{LCA}(A\cup B)=\operatorname{LCA}(\operatorname{LCA}(A),\operatorname{LCA}(B))$

### 朴素算法

- **时间复杂度**：预处理 $O(N)$，单次查询 $O(N)$
- **空间复杂度**：$O(N)$
- **要点**：先将较深节点爬到同一深度，再同步向上直到相遇

```cpp
struct {
    int to, ne;
} edge[M];
int head[N], cnt;
int depth[N], fa[N];

void add_edge(int u, int v) {
    edge[++cnt] = {v, head[u]};
    head[u] = cnt;
}

// 求出每个节点的深度和直接父结点
void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    fa[u] = p;
    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (v != p) dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    while (depth[u] > depth[v])
        u = fa[u];
    if (u == v) return v;
    while (u != v) {
        u = fa[u];
        v = fa[v];
    }
    return u;
}
```

以 `dfs(root, 0)` 预处理，$0$ 作为虚拟父节点。

### 倍增算法

- **时间复杂度**：预处理 $O(N\log N)$，单次查询 $O(\log N)$
- **空间复杂度**：$O(N\log N)$
- **状态**：`fa[u][j]` 表示 $u$ 的第 $2^j$ 级祖先；先倍增对齐深度，再从大到小同步上跳

```cpp
const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int LOG = 20; // 2 ^ 19 > 5e5
struct {
    int to, ne;
} edge[M];
int head[N], cnt;
int depth[N], fa[N][LOG];

void add_edge(int u, int v) {
    edge[++cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    fa[u][0] = p;
    for (int i = 1; i < LOG; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (v != p) dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[fa[u][i]] >= depth[v]) u = fa[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
```

## 树的直径

树的直径是树上最长简单路径。以下模板以无权树为例，直径长度按边数计算。

```cpp
const int N = 1e5 + 10;

struct Edge {
    int ne, to;
} edge[N << 1];

int head[N], cnt;

void addEdge(int u, int v) {
    edge[++cnt] = {head[u], v};
    head[u] = cnt;
}
```

每条无向边需要分别调用 `addEdge(u, v)` 和 `addEdge(v, u)`。

### 两次 DFS

先从任意节点找到最远点 $A$，再从 $A$ 找到最远点 $B$，则 $A$ 到 $B$
是一条直径。

- **时间复杂度**：$O(n)$
- **空间复杂度**：$O(n)$ 递归栈

```cpp
int findFarthest(int start, int& maxLen) {
    int farthest = start;
    maxLen = 0;

    function<void(int, int, int)> dfs = [&](int u, int fa, int len) {
        if (len > maxLen) {
            maxLen = len;
            farthest = u;
        }
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v != fa) dfs(v, u, len + 1);
        }
    };

    dfs(start, 0, 0);
    return farthest;
}

// int diameter;
// int A = findFarthest(1, diameter);
// int B = findFarthest(A, diameter);
```

对于非负边权树，把边结构体增加 `w`，并将 `len + 1` 改成
`len + edge[e].w` 即可。存在负边权时不能使用“两次最远点”方法。

### 树形 DP

`down[u]` 表示从 $u$ 出发、只向子树走的最长距离。经过 $u$ 的最长路径由
其子树方向的最长链和次长链拼成。

- **时间复杂度**：$O(n)$
- **空间复杂度**：$O(n)$

```cpp
int down[N];

int getDiameter(int root = 1) {
    int ans = 0;
    function<void(int, int)> dfs = [&](int u, int fa) {
        int longest = 0, second = 0;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa) continue;
            dfs(v, u);
            int len = down[v] + 1;
            if (len > longest) {
                second = longest;
                longest = len;
            } else if (len > second) {
                second = len;
            }
        }
        down[u] = longest;
        ans = max(ans, longest + second);
    };
    dfs(root, 0);
    return ans;
}
```

## 子树大小

- **时间复杂度**：$O(n)$
- 核心是使用树形 dp，表示以某个节点（一般是 1）为树的根时，某一点极其子树的大小

```cpp
void solve() {
    int n;
    cin >> n;
    for (int v = 2; v <= n; ++v) {
        int u;
        cin >> u;
        addEdge(u, v);
        addEdge(v, u);
    }

    // 递归
    // vector<int> dp(n + 1, 1);
    // function<void(int, int)> dfs = [&](int u, int fa) {
    //     for (int e = head[u]; e; e = edge[e].ne) {
    //         int v = edge[e].to;
    //         if (v == fa) continue;
    //         dfs(v, u);
    //         dp[u] += dp[v];
    //     }
    // };
    // dfs(1, 0);

    // 非递归
    vector<int> order, fa(n + 1);
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

    vector<int> dp(n + 1, 1);
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            dp[u] += dp[v] + 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << ' ';
    }
}
```

## 最大匹配边数量

- **时间复杂度**：$O(n)$

定义 $f_{i, 0}$ 表示节点 $i$ 的子树中，$i$ 不与其孩子节点匹配时，匹配边的最大数量，$f_{i, 1}$ 表示节点 $i$ 的子树中，$i$ 恰与其某一个孩子节点匹配时，匹配边的最大数量，那么有

$$
\begin{aligned}
f_{u, 0} & = \sum_{v \in \mathrm{child}(u)}\max(f_{v, 0}, f_{v, 1}) \\
f_{u, 1} & = \max_{v \in \mathrm{child}(u)}\left(1 + f_{v, 0} + \sum_{w \in \mathrm{child}(u), w \neq v}\max(f_{w, 0}, f_{w, 1})\right) \\
& = f_{u, 0} + \max_{v \in \mathrm{child}(u)}(1 + f_{v, 0} - \max(f_{v, 0}, f_{v, 1}))
\end{aligned}
$$

```cpp
void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        addEdge(u, v); addEdge(v, u);
    }

    vector<int> order, fa(n + 1, 0);
    order.reserve(n);
    order.push_back(1);
    fa[1] = 0;

    for (int i = 0; i < (int)order.size(); ++i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            order.push_back(v);
            fa[v] = u;
        }
    }

    vector<array<ll, 2>> f(n + 1, {0, 0});
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        ll p = -inf;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            f[u][0] += max(f[v][0], f[v][1]);
            p = max(p, 1 + f[v][0] - max(f[v][0], f[v][1]));
        }
        f[u][1] = f[u][0] + p;
    }

    cout << max(f[1][0], f[1][1]) << endl;
}
```

## 换根 DP

### 求某点到其他节点的距离和

- **时间复杂度**：$O(n)$

可以先用普通树形 dp，求出以 1 为树根时每个节点到其子树的中其他节点的距离和（需要一个 `size` 数组作为辅助），那么节点 1 到其他节点的距离和就已经求出。然后考虑换根：当移动一条边（从 `u` 移到 `v`）时，相较于 `u` 根，`v` 就是子树减少了 `size[v]` 的距离，子树以外的部分增加了 `n - size[v]` 的距离（边权为 1），然后在树上递推即可

```cpp
void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        addEdge(u, v); addEdge(v, u);
    }

    vector<int> order, fa(n + 1, 0);
    order.reserve(n); order.push_back(1);
    fa[1] = 0;

    for (int i = 0; i < (int)order.size(); ++i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            fa[v] = u;
            order.push_back(v);
        }
    }

    vector<ll> dist(n + 1, 0);
    vector<int> sz(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        ++sz[u];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            sz[u] += sz[v];
            dist[u] += dist[v] + sz[v];
        }
    }

    vector<ll> ans(n + 1, 0);
    ans[1] = dist[1];
    for (int i = 0; i < n; ++i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            ans[v] = ans[u] + n - 2 * sz[v];
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}
```

### 求某点到其他节点的最大距离

- **时间复杂度**：$O(n)$

先用普通树形 DP，求出以 1 为树根时，每个节点到其子树中其他节点的最大距离。发现只需要知道当前节点到其子树的最大距离 `down` 以及到子树以外部分的最大距离 `up` 即可，`down` 直接通过树形 dp 求解。`up` 可以考虑换根，当移动一条边时（从 `u` 移到 `v`），那么 `up[v]` 可以沿着父节点一路网上，即 `1 + up[u]`，也可以经父节点到兄弟节点，即 `1 + 1 + down[w]`，取最大值即可

```cpp
void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        addEdge(u, v); addEdge(v, u);
    }

    vector<int> order, fa(n + 1, 0);
    order.reserve(n); order.push_back(1);
    fa[1] = 0;

    for (int i = 0; i < (int)order.size(); ++i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            order.push_back(v);
            fa[v] = u;
        }
    }

    vector<int> down(n + 1, 0), up(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            down[u] = max(down[u], down[v] + 1);
        }
    }

    for (int u : order) {
        int mx1 = 0, mx2 = 0, id = 0;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            int d = down[v] + 1;
            if (d >= mx1) {
                mx2 = mx1;
                mx1 = d;
                id = v;
            } else if (d > mx2) {
                mx2 = d;
            }
        }
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa[u]) continue;
            int best = (v == id ? mx2 : mx1);
            up[v] = 1 + max(up[u], best);
        }
    }

    for (int u = 1; u <= n; ++u) {
        cout << max(down[u], up[u]) << ' ';
    }
}
```
