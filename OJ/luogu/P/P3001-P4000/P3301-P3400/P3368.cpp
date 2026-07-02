#include <iostream>
using namespace std;

const int N = 5 * 1e5 + 10;
int n, m;
int tree[N];

int lowbit(int x) { return x & -x; }

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int num;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        add(i, num);
        add(i + 1, -num);
    }
    while (m--)
    {
        int op, x, y, k;
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);
            break;
        case 2:
            cin >> x;
            cout << sum(x) << '\n';
            break;
        }
    }
    return 0;
}