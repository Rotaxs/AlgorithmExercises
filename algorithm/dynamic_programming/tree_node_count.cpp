#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 10;

vector<int> e[N];

void build()
{
    e[1].push_back(2);
    e[1].push_back(3);
    e[1].push_back(4);
    e[2].push_back(5);
    e[2].push_back(6);
    e[3].push_back(7);
    e[3].push_back(8);
    e[7].push_back(9);
}

int dfs(int i)
{
    int res = 0;
    for (int &v : e[i])
    {
        res += dfs(v);
    }
    return res + 1;
}

int cnt[N];
void dfs1(int i)
{
    cnt[i] += 1;
    for (int &v : e[i])
    {
        dfs1(v);
        cnt[i] += cnt[v];
    }
}

void solve()
{   
    build();
    int ans = dfs(3);
    cout << ans << endl;
    dfs1(1);
    cout << cnt[3] << endl;

    for (int i = 1; i <= 9; i++)
        cout << cnt[i] << ' ';
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