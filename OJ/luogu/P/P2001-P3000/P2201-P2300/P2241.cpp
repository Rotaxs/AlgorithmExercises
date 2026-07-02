#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long cnt_sq = 0, cnt_re, cnt;
    cnt = n * (n + 1) * m * (m + 1) / 4;
    for (int i = 1; i <= min(n, m); i++)
        cnt_sq += (m - i + 1) * (n - i + 1);
    cnt_re = cnt - cnt_sq;
    cout << cnt_sq << ' ' << cnt_re << '\n';
    return 0;
}