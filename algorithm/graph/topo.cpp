#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

const int N = 1000;
struct {
    int ne, to;
} edge[N];
int head[N], cnt, in[N];

void add_edge(int u, int v) {
    edge[++cnt] = {head[u], v};
    ++in[v];
    head[u] = cnt;
}

// bool topo(int n, vector<int>& res) {
//     res.clear();
//     queue<int> q;
//     for (int i = 1; i <= n; ++i) {
//         if (in[i] == 0) q.push(i);
//     }
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         res.push_back(u);
//         for (int e = head[u]; e; e = edge[e].ne) {
//             int v = edge[e].to;
//             if (--in[v] == 0) {
//                 q.push(v);
//             }
//         }
//     }
//     return (int)res.size() == n;
// }

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

int main() {
    return 0;
}