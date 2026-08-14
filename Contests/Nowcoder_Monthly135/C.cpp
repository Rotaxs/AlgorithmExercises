#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    if (n == 1)
    {
        int a; cin >> a;
        if (a % 9 == 0)
        {
            cout << 0 << '\n';
            return;
        }
        cout << 9 - a % 9 << '\n';
        return;
    }
    vector<int> a(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 9 == 0) cnt += 2;
        else if (a[i] % 3 == 0) cnt++;
    }
    if (cnt >= 2) { cout << "0\n"; return; }
    if (cnt == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 3 == 2)
            {
                cout << "1\n";
                return;
            }
        }
        cout << "2\n";
    }
    else if (cnt == 0)
    {
        int one = 0, two = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 3 == 1)
            {
                if ((a[i] + 2) % 9 == 0)
                {
                    cout << "2\n";
                    return;
                }
                one++;
            }
            else if (a[i] % 3 == 2)
            {
                if ((a[i] + 1) % 9 == 0)
                {
                    cout << "1\n";
                    return;
                }
                two++;
            }
        }
        if (two >= 2) cout << "2\n";
        else if (two == 1) cout << "3\n";
        else cout << "4\n";
    }
    

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) solve();
    
    return 0;
}