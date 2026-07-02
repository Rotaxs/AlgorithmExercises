#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
ll ans = 0;
int n;

PII partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[l + rand() % (r - l + 1)];
    int m = l;
    while (m <= r)
    {
        if (arr[m] == pivot)
            m++;
        else if (arr[m] > pivot)
            swap(arr[m], arr[r--]);
        else
            swap(arr[m++], arr[l++]);
    }
    return {l, r};
}

void quick_sort(vector<int> &arr, int l, int r)
{
    if (l >= r) return;
    auto [low, high] = partition(arr, l, r);
    quick_sort(arr, l, low - 1);
    quick_sort(arr, high + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans * (arr[i] - i) % MOD;
    }
    cout << ans << '\n';
    return 0;
}