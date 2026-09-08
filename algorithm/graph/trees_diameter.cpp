#include "bits/stdc++.h"
using namespace std;

const int N = 1e5;

struct {
    int to, ne;
} edge[N];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[cnt] = {v, head[u]};
    head[++cnt] = u;
}

// int findFarthest(int start, int& maxLen) {
//     function<void(int, int, int)> dfs = [&](int u, int fa, int len) {
//         if (len > maxLen) {
//         }
//         for (int e = head[u]; e; e = edge[e].ne) {
//             int v = edge[e].to;
//             if (v == fa) continue;
//             dfs(v, u, len + 1);
//         }
//     };
// }

int findFarthestRecursive(int start, int& maxLen) {
    int res = start;
    maxLen = 0;
    function<void(int, int, int)> dfs = [&](int u, int fa, int len) {
        if (len > maxLen) {
            res = u;
            maxLen = len;
        }
        maxLen = max(maxLen, len);
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa) continue;
            dfs(v, u, len + 1);
        }
    };
    dfs(start, 0, 0);
    return res;
}

int dp[N]; // dp[u]：从 u 出发，只向子树方向走的最长距离
int getDiameter() {
    int ans = 0;
    function<void(int, int)> dfs = [&](int u, int fa) {
        int max1 = 0, max2 = 0; // u 向子树方向的最长链和次长链
        for (int e = head[u]; e; e = edge[e].ne) {
            int v = edge[e].to;
            if (v == fa) continue;
            dfs(v, u);
            int len = dp[v] + 1; // 从 u 经过 v 向下走的最长距离
            if (len > max1) {
                max2 = max1;
                max1 = len;
            } else if (len > max2) {
                max2 = len;
            }
        }
        dp[u] = max1;                // 向父节点只能贡献一条最长链
        ans = max(ans, max1 + max2); // 经过 u 的最长路径由两条最长链拼成
    };
    dfs(1, 0);
    return ans;
}

int main() {
    return 0;
}