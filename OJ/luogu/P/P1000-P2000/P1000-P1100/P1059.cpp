#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 110, M = 1010;
int arr[N];
bool ha[M] = {0};
int n;

PII partition(int l, int r, int pivot)
{
    int m = l;
    while (m <= r)
    {
        if (arr[m] < pivot)
            swap(arr[m++], arr[l++]);
        else if (arr[m] == pivot)
            m++;
        else
            swap(arr[m], arr[r--]);
    }
    return {l, r};
}

void quick_sort(int l, int r)
{
    if (l >= r)
        return;
    PII bound = partition(l, r, arr[l + rand() % (r - l + 1)]);
    int low = bound.first, high = bound.second;
    quick_sort(l, low - 1);
    quick_sort(high + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int num, len = 0;
    while (n--)
    {
        cin >> num;
        if (!ha[num])
        {
            ha[num] = true;
            arr[len++] = num;
        }
    }

    quick_sort(0, len - 1);

    cout << len << '\n';
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}