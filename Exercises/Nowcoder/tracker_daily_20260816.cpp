#include <bits/stdc++.h>
#define endl '\n'
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x)  << " (Line " << __LINE__ << ")" << endl
#else
#define debug(x)
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;

typedef pair<int, int> PII;

const int N = 100010;
const int INF = 0x3f3f3f3f;
 
int n, m, q;
int h[N], e[N << 1], ne[N << 1], w[N << 1], idx;
int dist[N];
bool st[N];
 
void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
    e[idx] = a;
    w[idx] = c;
    ne[idx] = h[b];
    h[b] = idx++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
     
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> q;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dijkstra();
    long long ans = 0;
    while (q--) {
        int school;
        cin >> school;
        ans += dist[school] * 2;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}