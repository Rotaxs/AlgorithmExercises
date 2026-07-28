#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void print(multiset<int> &ms) 
{
    for (auto e : ms)   
        cout << e << ' ';
    cout << endl;
}

void solve()
{
    multiset<int> ms {3, 2, 1, 2, 3, 5, 2};
    ms.erase(ms.lower_bound(3));
    print(ms);
    cout << *ms.begin() << ' ' << *prev(ms.end()) << endl;
    cout << ms.count(2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    
    return 0;
}