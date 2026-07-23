#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;


void solve()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += pow(13, i) * 12;
    }
    cout << sum << endl;
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