#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> name(n);

    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> in;

    for (int i = 0; i < n; ++i) {
        cin >> name[i];
        in[name[i]] = 0;
    }

    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        ++in[b];
    }

    priority_queue<string, vector<string>, greater<string>> q;

    for (const string& s : name) {
        if (in[s] == 0) {
            q.push(s);
        }
    }

    vector<string> res;

    while (!q.empty()) {
        string u = q.top();
        q.pop();

        res.push_back(u);

        for (const string& v : graph[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)res.size() != n) {
        cout << "I can't AK IOI." << endl;
        cout << endl;
        return;
    }

    cout << "I can AK IOI." << endl;

    for (const string& s : res) {
        cout << s << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}