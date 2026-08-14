#include <iostream>
using namespace std;

int arr[3010];
int pre[3010];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i + m - 1 < n; i++)
    {
        for (int j = 0; j < m; j++)
            pre[i] += arr[i + j];
    }
    int min = pre[0];
    for (int i = 1; i + m - 1 < n; i++)
    {
        if (pre[i] < min)
            min = pre[i];
    }

    cout << min << '\n';
    return 0;
}