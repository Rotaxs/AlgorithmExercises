#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;

void print(string s, int c) {
    for (int i = 1; i <= c; i++) 
        cout << s;
}

void solve()
{
    int n, k; cin >> n >> k;
    int one = n / 2, zero = n - n / 2;
    int oneblock = (n - k) / 2, zeroblock = n - k - oneblock;
    if (oneblock == 0) {
        cout << "-1\n";
        return;
    }
    if (zeroblock > oneblock) {
        print("01", oneblock);
        print("1", one - oneblock);
        print("0", zero - oneblock);
    } else {
        print("01", oneblock - 1);
        print("0", zero - oneblock + 1);
        print("1", one - oneblock + 1);
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}