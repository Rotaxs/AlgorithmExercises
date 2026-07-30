#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

struct Manacher {
    string t;
    vector<int> p;
    Manacher(const string& s) {
        build(s);
    }

    void build(const string& s) {
        int n = s.length();
        if (n == 0) return;
        
        t.reserve(n * 2 + 3);
        t += '^'; t += '#';
        for (char c : s) {
            t += c;
            t += '#';
        }
        t += '$';
        p.assign(t.length(), 0);
        int c = 0, r = 0;
        for (int i = 1; i < t.length() - 1; i++) {
            int i_mirror = 2 * c - i;
            if (r > i) {
                p[i] = min(r - i, p[i_mirror]);
            } else {
                p[i] = 0;
            }
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
        }
    }
    int get_max_len() const {
        int res = 0;
        for (int x : p) {
            res = max(res, x);
        }
        return res;
    }
};

void solve()
{
    string s; cin >> s;
    Manacher m(s);
    cout << m.get_max_len() << endl;
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