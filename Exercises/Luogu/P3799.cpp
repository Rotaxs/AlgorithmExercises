// 枚举长度

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXA = 5005;

int n;
int cnt[MAXA];
ll ans = 0;

ll C2(int n)
{
    return ((n * (n - 1)) >> 1);
}

int main()
{
    cin >> n;
    int tmp, max_len = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        cnt[tmp]++;
        max_len = max(max_len, tmp);
    }

    for (int l = 2; l <= max_len; l++)
    {
        if (cnt[l] < 2)
            continue;

        for (int i = 1; i <= l / 2; i++)
        {
            int j = l - i;
            if (i == j)
                ans = (ans + C2(cnt[i]) * C2(cnt[l])) % MOD;
            else
                ans = (ans + cnt[i] * cnt[j] * C2(cnt[l])) % MOD;
        }
    }

    cout << ans << '\n';
    return 0;
}

// 枚举下标，超时
// #include <iostream>
// #include <algorithm>
// using namespace std;

// typedef long long ll;
// const int MOD = 1e9 + 7;
// const int N = 1e5 + 10;
// const int MAXA = 5010;
// int n;
// ll ans = 0;
// int lens[N], ha[MAXA] = {0};

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> lens[i];
//         ha[lens[i]]++;
//     }
//     sort(lens, lens + n);
//     int max_len = lens[n - 1];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             int sum = lens[i] + lens[j];
//             if (sum > max_len)
//                 break;
//             ans += ((ll)ha[sum] * (ha[sum] - 1)) >> 1;
//         }
//     }

//     cout << ans % MOD << '\n';
//     return 0;
// }