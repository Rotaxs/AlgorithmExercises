#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, k;
int lens[N], max_l = 0;

// 按照 l 的长度分能分成多少段
int f(int l)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret += lens[i] / l;
    return ret;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> lens[i];
        max_l = max(max_l, lens[i]);
    }
    int le = 0, ri = max_l + 1;
    while ((le + 1) != ri)
    {
        int m = le + ((ri - le) >> 1);
        // m 越大，f(m) 越小
        if (f(m) >= k) // 说明 m 偏小或恰好
            le = m;
        else // 说明 m 偏大
            ri = m;
    }
    cout << le << '\n';
    return 0;
}