#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
vector<int> sch, stu;

int binary_search(int x)
{
    int l = -1, r = m, mid;
    while (l + 1 != r)
    {
        mid = (l + r) / 2;
        if (sch[mid] < x)
            l = mid;
        else
            r = mid;
    }
    int ret;
    if (l != -1 && r != m)
        ret = sch[r] - x < x - sch[l] ? sch[r] - x : x - sch[l];
    else if (l == -1)
        ret = sch[r] - x;
    else
        ret = x - sch[l];
    // cout << ret << '\n';
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    long long ans = 0;
    sch.resize(m);
    stu.resize(n);
    for (int i = 0; i < m; i++)
        cin >> sch[i];
    for (int i = 0; i < n; i++)
        cin >> stu[i];
    sort(sch.begin(), sch.end());
    // sort(stu.begin(), stu.end());
    for (int i = 0; i < n; i++)
        ans += binary_search(stu[i]);
    cout << ans << '\n';
    return 0;
}
