# 图论

## 链式前向星建图

- **时间复杂度**：建图 $O(E)$，遍历全图 $O(V+E)$
- **空间复杂度**：$O(V+E)$
- **要点**：`head[u]` 指向 $u$ 的第一条边，`ne` 串起同一起点的边

```cpp
const int E = 2e5;
const int V = 1e5;
int head[V], cnt; // cnt 表示边的数量 head[u] 表示 u 节点连接的第一条边
struct {
    int to, ne, w;
} edge[E];

void add_edge(int u, int v, int w) {
    cnt++;                  // 创建新的边
    edge[cnt].to = v;       // 边指向 v
    edge[cnt].w = w;        // 边权
    edge[cnt].ne = head[u]; // 头插到 u 的第一条边
    head[u] = cnt;          // u 节点指向第 cnt 条边

    // edge[++cnt] = {v, head[u], w};
    // head[u] = cnt;
}

// 遍历与 u 相连的所有节点
void traverse(int u) {
    // i 是当前边的编号
    for (int i = head[u]; i != 0; i = edge[i].ne) {
        int v = edge[i].to; // 拿到这条边指向的终点
        cout << "从 " << u << " 连向 " << v << endl;
    }
}
```

树上 DFS 可用父节点代替 `vis`。

- **时间复杂度**：$O(V)$
- **空间复杂度**：$O(V)$ 递归栈

```cpp
function<void(int, int)> dfs = [&](int u, int fa) {
    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (v == fa) continue;
        black[v] = !black[u];
        dfs(v, u);
    }
};
```



## 拓扑排序

拓扑序满足每条有向边 $u\to v$ 中 $u$ 先于 $v$ 出现；它存在当且仅当图为 DAG。

### Kahn 算法（BFS）

- **时间复杂度**：$O(V+E)$
- **空间复杂度**：$O(V+E)$
- **判环**：反复删除入度为 $0$ 的点；最终结果少于 $V$ 个点则存在环

```cpp
const int E = 2e5;
const int V = 1e5;
int head[V], cnt;
struct {
    int to, ne;
} edge[E];
int in[V];

void add_edge(int u, int v) {
    cnt++;
    edge[cnt].to = v;
    in[v]++; // 更新入度
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

bool topo(int n, vector<int>& res) {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q.push(i);
    while (q.size()) {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int i = head[u]; i != 0; i = edge[i].ne) {
            int v = edge[i].to;
            if (--in[v] == 0) q.push(v);
        }
    }
    return res.size() == n;
}
```

### DFS 求拓扑序

- **时间复杂度**：$O(V+E)$
- **空间复杂度**：$O(V+E)$
- **判环**：反复删除入度为 $0$ 的点；最终结果少于 $V$ 个点则存在环

```cpp
int vis[N];
vector<int> res;

bool dfs(int u) {
    vis[u] = 1;
    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (vis[v] == 1) {
            return false;
        }
        if (vis[v] == 0) {
            if (!dfs(v)) {
                return false;
            }
        }
    }
    vis[u] = 2;
    res.push_back(u);
    return true;
}

bool topo(int n) {
    res.clear();
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            if (!dfs(i)) {
                return false;
            }
        }
    }
    reverse(res.begin(), res.end());
    return true;
}
```

### DAG + DP

看到这个组合，一般考虑拓扑排序

> [!note]
> 这里的 `dp` 和拓扑排序的逻辑其实是分开的，所以对 `dp` 计数时进行限制，不会影响拓扑排序的正确性

[Luogu P1807 最长路](https://www.luogu.com.cn/problem/P1807)

> 题目大意：$G$ 为有 $n$ 个顶点的有向无环图，编号从 $1$ 到 $n$，计算 $1$ 到 $n$ 的最长距离

```cpp
void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    queue<int> q;
    vector<int> dp(n + 1, -1e9);

    for (int v = 1; v <= n; ++v) {
        if (in[v] == 0) {
            q.push(v);
        }
    }
    dp[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            int w = edge[e].w;
            if (dp[u] != -1e9) {
                dp[v] = max(dp[v], dp[u] + w);
            }
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }

    if (dp[n] == -1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[n] << endl;
    }
}
```

[Luogu P1685 游览](https://www.luogu.com.cn/problem/P1685)

> 题目大意：一个带权（时间）有向无环图有 $n$ 个结点，编号从 $1$ 到 $n$，$m$ 条边，至少存在一条从 $s$ 到达 $e$ 的线路，从 $e$ 返回 $s$ 需要时间 $t$，问走完所有从 $s$ 到 $e$ 的路线的总时间

```cpp
void solve() {
    int n, m, s, e, t;
    cin >> n >> m >> s >> e >> t;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    vector<int> cnt(n + 1, 0);
    vector<ll> sum(n + 1, 0);
    cnt[s] = 1;
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            int w = edge[e].w;
            if (--in[v] == 0) {
                q.push(v);
            }
            cnt[v] = (cnt[v] + cnt[u]) % MOD;
            sum[v] = (sum[v] + sum[u] + 1ll * w * cnt[u]) % MOD;
        }
    }

    int ans = (sum[e] + 1ll * (cnt[e] - 1) * t % MOD) % MOD;

    cout << ans << endl;
}
```

## 最短路

### Dijkstra 算法

Dijkstra 求非负权图的单源最短路。每次确定未访问点中 `dist` 最小的点，再松弛其出边。

#### 朴素实现

- **时间复杂度**：$O(V^2+E)$
- **空间复杂度**：$O(V+E)$

```cpp
const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int inf = 1e9;

struct {
    int to, ne, w;
} edge[M];
int head[N], cnt;

int dist[N];
bool vis[N];

void add_edge(int u, int v, int w) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

void dijkstra(int s, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
        vis[i] = false;
    }
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        int min_d = inf, min_id = 0;
        for (int j = 1; j <= n; j++) {
            if (vis[j]) continue;
            if (dist[j] < min_d) {
                min_d = dist[j];
                min_id = j;
            }
        }
        if (min_id == 0) break;
        vis[min_id] = true;
        int u = min_id;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            int w = edge[e].w;
            if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
        }
    }
}
```

#### 堆优化

- **时间复杂度**：$O((V+E)\log V)$
- **空间复杂度**：$O(V+E)$
- **适用**：稀疏图优先堆优化，稠密图可用朴素实现

```cpp
const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int inf = 1e9;

struct {
    int to, ne, w;
} edge[M];
int head[N], cnt;

int dist[N];
bool vis[N];

void add_edge(int u, int v, int w) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

void dijkstra(int s, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
        vis[i] = false;
    }
    dist[s] = 0;
    // {距离, 编号}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to, w = edge[e].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
```

#### 最短路计数

- **时间复杂度**：$O((V+E)\log V)$
- **空间复杂度**：$O(V+E)$
- **转移**：距离变小时令 `ans[v] = ans[u]`；距离相等时累加 `ans[u]`

```cpp
void dijkstra(int s, int n) {
    for (int i = 1; i <= n; i++)
        dist[i] = inf;
    dist[s] = 0;
    ans[s] = 1;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to, w = edge[e].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                ans[v] = ans[u];
                pq.push({dist[v], v});
            } else if (dist[v] == dist[u] + w) {
                ans[v] = (ans[v] + ans[u]) % MOD;
            }
        }
    }
}
```



### Floyd 算法

Floyd 求全源最短路，允许负边，但不允许负环。`f[i][j]` 表示当前允许的中转点集合下 $i\to j$ 的最短路。

$$
f[i][j] = \min(f[i][j], f[i][k] + f[k][j])
$$

- **时间复杂度**：$O(V^3)$
- **空间复杂度**：$O(V^2)$

```cpp
const int N = 510;

int f[N][N];

void floyd(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
}
```

`f` 数组的初始化类似如下

```cpp
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        f[i][j] = (i == j ? 0 : inf);
while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    f[u][v] = f[v][u] = min(f[u][v], w);
}
```

### Bellman-Ford 算法

Bellman-Ford 求允许负边的单源最短路。连续枚举所有边并松弛；第 $V$ 轮仍可松弛则存在从源点可达的负环。

- **时间复杂度**：$O(VE)$
- **空间复杂度**：$O(V+E)$

```cpp
const int N = 1e3 + 10;
const int M = 2e3 + 10;
const int inf = 0x3f3f3f3f;

struct {
    int to, ne, w;
} edge[M];
int head[N], cnt;
int dist[N];

void add_edge(int u, int v, int w) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

bool bellman_ford(int n, int m, int s) {
    for (int i = 1; i <= n; i++)
        dist[i] = inf;
    dist[s] = 0;
    bool relax = false;
    // n - 1 次迭代 + 1 次判负环
    for (int i = 1; i <= n; i++) {
        relax = false;
        // 遍历所有顶点，从而遍历所有的边（实际上就是在遍历所有的边）
        for (int u = 1; u <= n; u++) {
            if (dist[u] == inf) continue;
            for (int e = head[u]; e; e = edge[e].ne) {
                int v = edge[e].to, w = edge[e].w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    relax = true;
                    if (i == n) return true;
                }
            }
        }
        if (!relax) break;
    }
    // 如果第 n 次迭代仍有松弛操作，说明有负环
    return false;
}
```

只做 Bellman-Ford 时可直接存边，无需建邻接表。

```cpp
const int N = 2e3 + 10;
const int M = 6e3 + 10;
const int inf = 0x3f3f3f3f;

struct {
    int u, v, w;
} edge[M];
int dist[N];

void init(int n, int s) {
    for (int i = 1; i <= n; i++)
        dist[i] = inf;
    dist[s] = 0;
}

bool bellman_ford(int n, int m, int s) {
    init(n, s);
    for (int i = 1; i <= n; i++) {
        bool relax = false;
        for (int e = 1; e <= m; e++) {
            int u = edge[e].u, v = edge[e].v, w = edge[e].w;
            if (dist[u] == inf) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                relax = true;
                if (i == n) return true;
            }
        }
        if (!relax) break;
    }
    return false;
}
```

### SPFA 算法

SPFA 只将 `dist` 变小的点入队。`inq` 防止重复入队；到达某点的边数达到 $V$ 则存在可达负环。

- **时间复杂度**：最坏 $O(VE)$，不保证优于 Bellman-Ford
- **空间复杂度**：$O(V+E)$

```cpp
const int N = 1e3 + 10;
const int M = 2e3 + 10;
const int inf = 0x3f3f3f3f;

struct {
    int to, ne, w;
} edge[M];
int head[N], dist[N], cnt, relax_cnt[N];
bool inq[N];

void add_edge(int u, int v, int w) {
    edge[++cnt] = {v, head[u], w};
    head[u] = cnt;
}

bool spfa(int n, int m, int s) {
    for (int i = 1; i <= n; i++)
        dist[i] = inf;
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    inq[s] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to, w = edge[e].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                relax_cnt[v] = relax_cnt[u] + 1;
                if (relax_cnt[v] >= n) return true;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    return false;
}
```



## 二分图与图的匹配

### 二分图的判定

无向图是二分图当且仅当它不含奇环。从每个未染色点开始 DFS/BFS，相邻点染相反颜色；出现同色边则失败。

- **时间复杂度**：$O(V+E)$
- **空间复杂度**：$O(V+E)$

```cpp
const int N = 1e4 + 10;
const int M = 1e5 + 10;

struct edge {
    int to, ne;
} edge[M * 2];
int head[N], cnt;
int color[N];

void addEdge(int u, int v) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].ne = head[u];
    head[u] = cnt;
}

int white, black;

bool dfs(int u, int c) {
    color[u] = c;
    if (c == 0)
        white++;
    else
        black++;
    for (int e = head[u]; e; e = edge[e].ne) {
        int v = edge[e].to;
        if (color[u] == color[v]) return false;
        if (color[v] == -1 && !dfs(v, !color[u])) return false;
    }
    return true;
}
```

外层需枚举所有连通分量：

```cpp
memset(color, -1, sizeof color);
int part_min = 0;
for (int i = 1; i <= n; i++) {
    if (color[i] != -1) continue;
    white = black = 0;
    if (!dfs(i, 0)) {
        // 不是二分图
        return;
    }
    part_min += min(white, black);
}
```
