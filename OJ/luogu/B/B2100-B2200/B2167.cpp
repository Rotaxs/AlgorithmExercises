#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int arr[N];
int n, m;

int binary(int x)
{
    int l = 0, r = n + 1;
    int m;
    while (l + 1 < r)
    {
        m = (l + r) / 2;
        if (arr[m] <= x)
            l = m;
        else
            r = m;
    }
    if (arr[l] == x)
        return l;
    return -1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    int query[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &query[i]);
    int index;
    for (int e : query)
    {
        index = binary(e);
        printf("%d\n", index);
    }
}
