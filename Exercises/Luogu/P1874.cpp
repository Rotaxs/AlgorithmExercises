#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
string s;
int n, len;
int f[41][100010];

// 考虑完 s[0 ... p] 前是否添加号
int dfs(int p, ll sum, int cnt)
{
    if (p == len)
    {
        if (sum == n)
            return cnt;
        return 1e8;
    }
    if (f[p][sum] != -1) return f[p][sum];

    int ans = 1e8;
    ll num = 0;
    for (int i = p; i < len; i++)
    {
        num = num * 10 + s[i] - '0';
        if (sum + num > n) break;
        ans = min(dfs(i + 1, sum + num, cnt + (p != 0)), ans);
    }
    return f[p][sum] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> n;
    len = s.length();
    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 100010; j++)
            f[i][j] = -1;
    int ans = dfs(0, 0, 0);
    cout << (ans == 1e8 ? -1 : ans) << '\n';
    return 0;
}


// ========= dfs ========

// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// string s;
// int n, len;
// int ans = 1e8;

// void dfs(int p, int cnt, long long sum)
// {
//     if (cnt >= ans) return;
//     if (p == len)
//     {
//         if (sum == n)
//             ans = min(ans, cnt);
//         return;
//     }
//     long long num = 0;
//     // 遍历在 i 位置前加 +
//     for (int i = p; i < len; i++)
//     {
//         num = num * 10 + s[i] - '0';
//         if (num + sum > n) break;
//         dfs(i + 1, cnt + (p != 0), sum + num);
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> s >> n;
//     len = s.length();

//     dfs(0, 0, 0);
//     cout << (ans == 1e8 ? -1 : ans) << '\n';
//     return 0;
// }