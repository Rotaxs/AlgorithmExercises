#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m;
vector<int> heights;

long long get_length_sum(const int h)
{
    long long sum = 0; // m 可以非常大，虽然不超过 INT_MAX，但是不能保证 sum 不会超
    for (int &e : heights)
    {
        sum += e > h ? e - h : 0;
    }
    return sum;
}

int main()
{
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        heights.push_back(tmp);
    }
    sort(heights.begin(), heights.end());
    int large = 0, small = heights[n - 1];
    int mid;
    while (large + 1 != small)
    {
        mid = (large + small) / 2;
        if (get_length_sum(mid) < m)
            small = mid;
        else
            large = mid;
    }
    cout << large << endl;
    return 0;
}