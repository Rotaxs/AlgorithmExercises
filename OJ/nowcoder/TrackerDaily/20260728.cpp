#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

struct DualMultiset {
    multiset<ll> L, R;

    int size() { return L.size() + R.size(); }

    ll median() {
        return *prev(L.end());
    }

    void balance() {
        int tot = size();
        while (L.size() > (tot + 1) / 2) {
            auto it = prev(L.end());
            R.insert(L.extract(it));
        }
        while (L.size() < (tot + 1) / 2 && !R.empty()) {
            auto it = R.begin();
            L.insert(R.extract(it));
        }
    }

    void insert(const ll& x) {
        if (L.empty() || x <= median()) {
            L.insert(x);
        } else {
            R.insert(x);
        }
        balance();
    }

    void erase(const ll& x) {
        auto it = L.find(x);
        if (it != L.end()) {
            L.erase(it);
        } else {
            auto it2 = R.find(x);
            if (it2 != R.end()) {
                R.erase(it2);
            }
        }
        balance();
    }
};

struct DualPriorityQueue {
    priority_queue<ll> L, L_del;
    priority_queue<ll, vector<ll>, greater<ll>> R, R_del;
    int size_L = 0, size_R = 0;

    int size() const { return size_L + size_R; }

    ll median() {
        prune_L();
        return L.top();
    }

    void prune_L() {
        while (!L.empty() && !L_del.empty() && L.top() == L_del.top()) {
            L.pop(); L_del.pop();
        }
    }

    void prune_R() {
        while (!R.empty() && !R_del.empty() && R.top() == R_del.top()) {
            R.pop(); R_del.pop();
        }
    }

    void balance() {
        int tot = size();
        while (size_L > (tot + 1) / 2) {
            prune_L();
            ll top = L.top(); L.pop();
            R.push(top);
            size_L--; size_R++;
        }
        while (size_L < (tot + 1) / 2 && !R.empty()) {
            prune_R();
            ll top = R.top(); R.pop();
            L.push(top);
            size_R--; size_L++;
        }
    }

    void insert(const ll& x) {
        prune_L();
        if (size_L == 0 || x <= L.top()) {
            L.push(x);
            size_L++;
        } else {
            R.push(x);
            size_R++;
        }
        balance();
    }

    void erase(const ll& x) {
        prune_L();
        if (size_L > 0 && x <= L.top()) {
            L_del.push(x);
            size_L--;
        } else {
            R_del.push(x);
            size_R--;
        }
        balance();
    }
};

struct Node {
    int l, r;
};

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    vector<Node> rg(q);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int size = -1;
    for (int i = 0; i < q; i++) {
        cin >> rg[i].l >> rg[i].r;
        if (size == -1) size = rg[i].r - rg[i].l + 1;
    }
    // DualMultiset ds;
    // for (int i = 1; i <= size; i++) {
    //     ds.insert(a[i]);
    // }
    // ans[1] = ds.median();
    // for (int l = 1 + 1, r = size + 1; r <= n; l++, r++) {
    //     ds.erase(a[l - 1]);
    //     ds.insert(a[r]);
    //     ans[l] = ds.median();
    // }

    DualPriorityQueue dpq;
    for (int i = 1; i <= size; i++) {
        dpq.insert(a[i]);
    }
    ans[1] = dpq.median();
    for (int l = 1 + 1, r = size + 1; r <= n; l++, r++) {
        dpq.erase(a[l - 1]);
        dpq.insert(a[r]);
        ans[l] = dpq.median();
    }

    for (int i = 0; i < q; i++) {
        cout << ans[rg[i].l] << endl;
    }
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