#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int n, s, x;
string u;

int check(int i)
{
    int ans = 0;
    int rem = x;
    ll seats = 0;
    int a = 0;
    for (char c : u)
    {
        if (c == 'I')
        {
            if (rem > 0)
            {
                ans++;
                rem--;
                seats += s - 1;
            }
        }
        else if (c == 'A')
        {
            a++;
            if (a <= i)
            {
                if (rem > 0)
                {
                    ans++;
                    rem--;
                    seats += s - 1;
                }
            }
            else
            {
                if (seats > 0)
                {
                    seats--;
                    ans++;
                }
            }
        }
        else if (c == 'E')
        {
            if (seats > 0)
            {
                seats--;
                ans++;
            }
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> x >> s;
    cin >> u;
    int ans = 0;
    int cnt_A = 0;
    for (char c : u)
        if (c == 'A') cnt_A++;
    int l = -1, r = cnt_A + 1;
    while ((l + 1) != r)
    {
        int m = l + ((r - l) >> 1);
        if (check(m) >= check(m + 1)) r = m;
        else l = m;
    }
    cout << check(r) << '\n';
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