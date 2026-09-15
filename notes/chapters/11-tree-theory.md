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
