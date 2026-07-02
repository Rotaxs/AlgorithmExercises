#include <iostream>
using namespace std;

const int N = 5 * 1e5 + 10;
int n, m;
int tree[N] = {0};

int lowbit(int x)
{
    return x & -x;
}

void add(int i, int v)
{
    while (i <= n)
    {
        tree[i] += v;
        i += lowbit(i);
    }
}

int sum(int i)
{
    int ans = 0;
    while (i >= 1)
    {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    int num;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        add(i, num);
    }
    int op, x, k;
    while (m--)
    {
        cin >> op >> x >> k;
        switch (op)
        {
        case 1:
            add(x, k);
            break;
        case 2:
            cout << sum(k) - sum(x - 1) << '\n';
            break;
        }
    }
    return 0;
}