#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> a, b;

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int gcd(int a, int b)
{
    return (!b ? a : gcd(b, a % b));
}

void solve()
{
    string s;
    cin >> s;

    int n = 0;
    bool minus = false;
    for (char c : s)
    {
        if (is_digit(c))
        {
            n = n * 10 + c - '0';
        }
        else
        {
            if (c == '/')
            {
                if (minus) a.push_back(-n), minus = false;
                else a.push_back(n);

            }
            else
            {
                b.push_back(n);
                if (c == '-') minus = true;       
            }
            n = 0;
        }
    }
    b.push_back(n);
    int ch = a[0], mo = b[0];
    int d = gcd(ch, mo);
    ch = ch / d;
    mo = mo / d;
    for (int i = 1; i < a.size(); i++)
    {
        int ne_ch = ch * b[i] + mo * a[i];
        int ne_mo = mo * b[i];
        int d = gcd(ne_ch, ne_mo);
        ch = ne_ch / d;
        mo = ne_mo / d;
    }
    if (mo == 1) cout << ch << '\n';
    else if (mo == -1) cout << -ch << '\n';
    else
    {
        if (mo < 0)
            cout << -ch << "/" << -mo << '\n';
        else 
            cout << ch << "/" << mo << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();
    
    return 0;
}