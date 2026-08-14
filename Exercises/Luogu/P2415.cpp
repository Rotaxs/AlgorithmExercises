#include <iostream>
#include <cmath>
using namespace std;

const int N = 35;
int nums[N];

int main()
{
    int n;
    int cnt = 0;
    long long res = 0;
    while (cin >> n)
    {
        res += n;
        cnt++;
    }

    long long times = (long long)pow(2, cnt - 1);
    res *= times;

    cout << res << '\n';

    return 0;
}