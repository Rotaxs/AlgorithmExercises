

// #include <iostream>
// #include <utility>
// using namespace std;

// typedef long long ll;
// int c, t;
// const int N = 1000;


// pair<ll, int> quick_sqrt(ll n)
// {   
//     if (n == 1)
//         return {1, 0};
//     ll l = 1, r = n;
//     while ((l + 1) != r)
//     {
//         ll m = l + ((r - l) >> 1);
//         if (m <= n / m)
//             l = m;
//         else
//             r = m;
//     }
//     return {l, ((n % l == l && n / l == l) ? 0 : -1)};

// }

// void solve()
// {
//     ll n, k;
//     cin >> n >> k;
//     ll score = 0;
//     ll cnt = 0;
//     while (score < k)
//     {
//         if (n == 1)
//         {
//             cnt += k - score;
//             score = k;
//             break;
//         }
//         if (n == 2)
//         {
//             cnt += (k - score) * 2;
//             score = k;
//             break;
//         }
//         if (n == 3)
//         {
//             cnt += (k - score) * 4;
//             score = k;
//             break;
//         }
//         auto [a, s] = quick_sqrt(n);
//         // n 不是完全平方数
//         if (s == -1)
//         {
//             // 记录当前数 n 到下一个完全平方数要几次操作
//             ll step = 0;
//             if ((n & 1) == (a & 1))
//             {
//                 cnt += ((a + 2) * (a + 2) - n) / 2;
//                 n = (a + 2) * (a + 2);
//             }
//             else
//             {
//                 cnt += ((a + 1) * (a + 1) - n) / 2;
//                 n = (a + 1) * (a + 1);
//             }
//         }
//         else
//         {
//             // 开方
//             n = a;
//             score++;
//             cnt++;
//         }
//     }
//     cout << cnt << '\n';
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> c >> t;
//     while (t--) solve();
//     // solve();
//     return 0;
// }