#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

// bool check(vector<int>& a, int x) {
//     int L = -1, R = a.size();
//     while ((L + 1) != R) {
//         int M = L + ((R - L) >> 1);
//         if (a[M] >= x) R = M;
//         else L = M;
//     }
//     return a[R] == x;
// }

// void solve()
// {
//     int n, k; cin >> n >> k;
//     k %= n;
//     vector<int> a(n), ak;
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }

//     map<int, int> mp;
//     for (int i = 0; i <= k; ++i) ak.push_back(a[i]), mp[a[i]]++;
//     for (int i = n - 1; i >= n - k; --i) ak.push_back(a[i]), mp[a[i]]++;

//     int mex = 0;
//     sort(ak.begin(), ak.end());
//     for (int i = 0; i <= 2 * k + 1; ++i) {
//         if (!check(ak, i)) {
//             mex = i;
//             break;
//         }
//     }

//     vector<int> ans(n);
//     ans[0] = mex;
//     for (int L = -k, R = k; R <= n - 1 + k; ++L, ++R) {
//         int l = (L % n + n) % n, r = R % n;
//         int i = ((l + r) >> 1);
//         if (r + 1 >= n) continue;
//         mp[a[l]]--, mp[a[r + 1]]++;
//         if (!mp.count(a[l])) {
//             if (a[l] != a[r + 1])
//                 ans[i] = --mex;
//         } else if (a[r + 1] == a[l] + 1) {
//             while (mp.count(mex)) {
//                 mex++;
//             }
//             ans[i] = --mex;
//         }
//     }

//     for (int x : ans) {
//         cout << x << ' ';
//     }
//     cout << endl;
// }

int mex(int a, int b, int c) {
    for (int i = 0; i < 3; ++i) {
        if (a != i && b != i && c != i)
            return i;
    }
    return 3;
}

vector<int> transform(vector<int> &a) {
    int n = a.size();
    vector<int> b(n);
    for (int i = 0; i < n; ++i) { 
        b[i] = mex(a[i], a[(i + 1) % n], a[(i + n - 1) % n]);
    }
    return b;
}

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> b, c;
    int i;
    for (i = 1; i <= k; ++i) {
        if (i == 1) {
            b = transform(a);
        } else if (i == 2) {
            c = transform(b);
        } else {
            vector<int> tmp = c;
            c = transform(c);
            a = b;
            b = tmp;
        }
        
        if (!c.empty() && a == c) {
            if (((k - i + 1) & 1) == 0) {
                a = b;
            }
            break;
        }
    }

    if (i > k) {
        if (k == 1) a = b;
        else a = c; 
    }

    for (int x : a) {
        cout << x << ' ';
    }
    cout << endl;
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