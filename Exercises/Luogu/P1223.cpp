#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long long ll;

struct Time { int id, t; };
int n;

void merge(vector<Time> &T, int l, int m, int r)
{
    vector<Time> tmp(n + 1);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        // 必须是 <=，否则不稳定
        if (T[i].t <= T[j].t)
            tmp[k++] = T[i++];
        else
            tmp[k++] = T[j++];
    }
    while (i <= m)
        tmp[k++] = T[i++];
    while (j <= r)
        tmp[k++] = T[j++];
    for (int i = l; i <= r; i++)
        T[i] = tmp[i];
}

void merge_sort(vector<Time> &T, int l, int r)
{
    if (l == r)
        return;
    int m = l + ((r - l) >> 1);
    merge_sort(T, l, m);
    merge_sort(T, m + 1, r);
    merge(T, l, m, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<Time> T(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> T[i].t;
        T[i].id = i;
    }
    merge_sort(T, 1, n);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += T[i].t * (n - i);
    }
    
    for (int i = 1; i <= n; i++)
        cout << T[i].id << ' ';
    cout << '\n';
    cout << fixed << setprecision(2);
    double avg = (double)sum / n;
    cout << avg << '\n';

    return 0;
}