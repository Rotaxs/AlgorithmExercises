#include <iostream>
using namespace std;

const int N = 1e4 + 10;
int arr[N] = {0};
int l, m;

int main()
{
    cin >> l >> m;
    for (int i = 0; i <= l; i++)
        arr[i] = 1;
    int start, end;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        for (int j = start; j <= end; j++)
            arr[j] = 0;
    }
    int ans = 0;
    for (int i = 0; i <= l; i++)
    {
        if (arr[i] == 1)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}