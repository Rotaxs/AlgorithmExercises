#include <iostream>
using namespace std;

const int N = 110;

int main()
{
    int ans = 0;
    int n;
    int arr[N];
    bool found = false;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int sum_id = 0; sum_id < n; sum_id++)
    {
        for (int a = 0; a < n; a++)
        {
            for (int b = a + 1; b < n; b++)
            {
                if (a == sum_id || b == sum_id)
                    continue;
                if (arr[a] == arr[b])
                    continue;
                if (arr[a] + arr[b] == arr[sum_id])
                {
                    ans++;
                    found = true;
                }
            }
            if (found)
            {
                found = false;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}