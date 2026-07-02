#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2 * 1e6 + 10;
int arr[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        scanf("%d", arr + i);
    int left = 0, right = m - 1;
    sort(arr, arr + m);
    for (int i = 0; i < m; i++)
        printf("%d ", arr[i]);
    putchar('\n');
    return 0;
}