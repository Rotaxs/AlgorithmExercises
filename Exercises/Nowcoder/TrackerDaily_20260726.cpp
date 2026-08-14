#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int pivot = 1 << 20;

vector<int> dist(pivot + 1, -1);

void bfs()
{
    queue<int> q;
    q.push(pivot);
    dist[pivot] = dist[0] = 0;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 1; i <= len; i++) {
            int u = q.front(); q.pop();
            int v = u - 1;
            if (dist[v] == -1) {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
            if ((u & 1) == 0) {
                v = u >> 1;
                if (dist[v] == -1) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                }
                v = (u >> 1) + (1 << 19);
                if (dist[v] == -1) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                }
            }
        }
    }
}

void solve()
{
    int n; cin >> n;
    cout << dist[n % pivot] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    bfs();

    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}