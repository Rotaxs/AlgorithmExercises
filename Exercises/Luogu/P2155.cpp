#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7 + 10;

int t, r, n, m;
int nf[N], mp[N];
int p[N], cnt;
bool vis[N];

ll qpow(ll a, ll n, ll p)
{
    ll ret = 1;
    a %= p;
    while (n)
    {
        if (n & 1) ret = ret * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ret;
}

void euler(int n)
{
    vis[1] = vis[0] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) p[++cnt] = i;
        for (int j = 1; j <= cnt && 1LL * i * p[j] <= n; j++)
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t >> r;

    euler(N - 1);

    nf[1] = 1; mp[1] = 1;
    nf[0] = 1; mp[0] = 1;
    for (int i = 2; i <= N - 1; i++)
    {
        if (i % r != 0) nf[i] = 1LL * nf[i - 1] * i % r;
        else
        {
            int cur = i;
            while (cur % r == 0) cur /= r;
            nf[i] = 1LL * nf[i - 1] * cur % r;
        }
    }

    for (int i = 2; i <= N - 1; i++)
    {
        if (vis[i]) mp[i] = mp[i - 1];
        else
        {
            if (i % r != 0)
                mp[i] = 1LL * mp[i - 1] * (i - 1) % r * qpow(i, r - 2, r) % r;
            else
                mp[i] = 1LL * mp[i - 1] * (i - 1) % r;
        }
    }

    while (t--)
    {
        int n, m; cin >> n >> m;
        // cout << 1LL * nf[n] * mp[m] % r << "\n";
        if ((n >= r && m < r) || n >= 2LL * r)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1LL * nf[n] * mp[m] % r << "\n";
        }
    }
    
    return 0;
}