#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e6;

int n, c;
vector<int> nums;

int biSearchLeft(int x)
{
    int l = -1, r = n;
    int m;
    while (l + 1 != r)
    {
        m = (l + r) / 2;
        if (nums[m] < x)
            l = m;
        else
            r = m;
    }
    if (r < n && nums[r] == x)
        return r;
    return -1;
}

int biSearchRight(int x)
{
    int l = -1, r = n;
    int m;
    while (l + 1 != r)
    {
        m = (l + r) / 2;
        if (nums[m] <= x)
            l = m;
        else
            r = m;
    }
    if (l >= 0 && nums[l] == x)
        return l;
    return -1;
}

int getLen(int x)
{
    int left = biSearchLeft(x);
    int right = biSearchRight(x);
    if (left == -1)
        return 0;
    return right - left + 1;
}

int main()
{
    cin >> n >> c;
    int num;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += getLen(nums[i] - c);
    }
    cout << ans << endl;
    return 0;
}
