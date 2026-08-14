#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n, m;
int nums[N];
int searchNum[N];

int biSearch(int x)
{
    int l = -1, r = n;
    int m;
    while ((l + 1) != r)
    {
        m = (l + r) / 2;
        if (nums[m] < x)
            l = m;
        else
            r = m;
    }
    if (nums[r] == x)
        return r + 1;
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &searchNum[i]);
    for (int i = 0; i < m; i++)
    {
        printf("%d ", biSearch(searchNum[i]));
    }

    return 0;
}
