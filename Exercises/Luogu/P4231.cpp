#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e7 + 10;
int N, M;
long long arr[MAXN] = {0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, r, s, e, d;
    cin >> N >> M;
    while (M--)
    {
        cin >> l >> r >> s >> e;
        d = (e - s) / (r - l);
        arr[l] += s;
        arr[l + 1] += d - s;
        arr[r + 1] -= e + d;
        arr[r + 2] += e;
    }
    for (int i = 1; i <= N; i++)
        arr[i] += arr[i - 1];
    long long xor_sum = 0;
    long long max_n = 0;
    for (int i = 1; i <= N; i++)
    {
        arr[i] += arr[i - 1];
        xor_sum ^= arr[i];
        max_n = max(max_n, arr[i]);
    }
    cout << xor_sum << ' ' << max_n << '\n';
    return 0;
}