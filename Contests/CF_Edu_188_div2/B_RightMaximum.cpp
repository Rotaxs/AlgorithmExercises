#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;
int arr[N], max_id[N], max_n[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= max_n[i - 1])
        {
            max_n[i] = arr[i];
            max_id[i] = i;
        }
        else
        {
            max_n[i] = max_n[i - 1];
            max_id[i] = max_id[i - 1];
        }
    }
    int cnt = 0;
    int p = n;
    while (max_id[p] != 0)
    {
        p = max_id[p] - 1;
        cnt++;
    }
    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    max_id[0] = max_n[0] = 0;

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}